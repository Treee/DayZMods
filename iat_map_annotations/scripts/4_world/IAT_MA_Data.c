enum IAT_MA_Operation
{
	PAGE = 0,
	ADD,
	UNDO,
	CLEAR
}

enum IAT_MA_Result
{
	OK = 0,
	INVALID,
	STALE,
	FULL,
	BUSY,
	WRONG_TERRAIN
}

class IAT_MA_Limits
{
	static const int VERSION = 1;
	static const int RPC_REQUEST = 7346211;
	static const int RPC_REPLY = 7346212;
	static const int MAX_STROKE_POINTS = 128;
	static const int MAX_STROKES = 256;
	static const int MAX_MAP_POINTS = 8192;
	static const int PAGE_STROKES = 16;
	static const int PAGE_POINTS = 512;
	static const int REQUEST_INTERVAL_MS = 100;
	static const int CLIENT_INTERVAL_MS = 200;
	static const int TIMEOUT_MS = 8000;

	static int Color(int index)
	{
		switch (index)
		{
			case 1: return ARGB(255, 180, 25, 25);
			case 2: return ARGB(255, 25, 55, 190);
			case 3: return ARGB(255, 20, 110, 35);
		}
		return ARGB(255, 20, 20, 20);
	}

	static string ResultText(int result)
	{
		switch (result)
		{
			case IAT_MA_Result.INVALID: return "Invalid annotation data; reload the map.";
			case IAT_MA_Result.STALE: return "Map changed; reloading annotations.";
			case IAT_MA_Result.FULL: return "Map is full. Undo or clear some strokes.";
			case IAT_MA_Result.BUSY: return "Please wait briefly and try again.";
			case IAT_MA_Result.WRONG_TERRAIN: return "These annotations belong to another terrain.";
		}
		return "Saved";
	}
}

class IAT_MA_Stroke
{
	int Color;
	int Width = 2;
	ref array<int> Points = new array<int>;

	bool IsValid()
	{
		return Color >= 0 && Color <= 3 && Width >= 1 && Width <= 6 && Points.Count() >= 1 && Points.Count() <= IAT_MA_Limits.MAX_STROKE_POINTS;
	}

	IAT_MA_Stroke Copy()
	{
		IAT_MA_Stroke copy = new IAT_MA_Stroke;
		copy.Color = Color;
		copy.Width = Width;
		copy.Points.Copy(Points);
		return copy;
	}

	void Write(ParamsWriteContext ctx)
	{
		ctx.Write(Color);
		ctx.Write(Width);
		ctx.Write(Points.Count());
		foreach (int point : Points)
			ctx.Write(point);
	}

	bool Read(ParamsReadContext ctx)
	{
		Points.Clear();
		int count;
		if (!ctx.Read(Color) || !ctx.Read(Width) || !ctx.Read(count))
			return false;
		// Read the scalar count before allocating or decoding any point data.
		if (Color < 0 || Color > 3 || Width < 1 || Width > 6 || count < 1 || count > IAT_MA_Limits.MAX_STROKE_POINTS)
			return false;
		for (int i = 0; i < count; i++)
		{
			int point;
			if (!ctx.Read(point))
				return false;
			Points.Insert(point);
		}
		return true;
	}
}

class IAT_MA_Geometry
{
	//! Two unsigned 16-bit terrain coordinates carried by one signed 32-bit int.
	static int Pack(vector position, float worldSize)
	{
		if (worldSize <= 0)
			return 0;
		int x = Math.Round(Math.Clamp(position[0] / worldSize, 0, 1) * 65535);
		int z = Math.Round(Math.Clamp(position[2] / worldSize, 0, 1) * 65535);
		return (x << 16) | z;
	}

	static vector Unpack(int point, float worldSize)
	{
		int x = (point >> 16) & 65535;
		int z = point & 65535;
		return Vector(x * worldSize / 65535, 0, z * worldSize / 65535);
	}

	static float SegmentDistanceSq(vector point, vector a, vector b)
	{
		vector delta = b - a;
		float lengthSq = delta.LengthSq();
		if (lengthSq == 0)
			return vector.DistanceSq(point, a);
		float fraction = Math.Clamp(vector.Dot(point - a, delta) / lengthSq, 0, 1);
		return vector.DistanceSq(point, a + delta * fraction);
	}

	//! Iterative Ramer-Douglas-Peucker; retry tolerance rather than truncating a route.
	static void Simplify(array<vector> source, float tolerance, array<vector> output)
	{
		output.Clear();
		if (source.Count() < 2)
		{
			output.Copy(source);
			return;
		}
		ref array<int> keep = new array<int>;
		keep.Resize(source.Count());
		keep[0] = 1;
		keep[source.Count() - 1] = 1;
		ref array<int> stack = new array<int>;
		stack.Insert(0);
		stack.Insert(source.Count() - 1);
		while (stack.Count() > 0)
		{
			int last = stack[stack.Count() - 1];
			stack.Remove(stack.Count() - 1);
			int first = stack[stack.Count() - 1];
			stack.Remove(stack.Count() - 1);
			float greatest = tolerance * tolerance;
			int selected = -1;
			for (int i = first + 1; i < last; i++)
			{
				float distanceSq = SegmentDistanceSq(source[i], source[first], source[last]);
				if (distanceSq > greatest)
				{
					greatest = distanceSq;
					selected = i;
				}
			}
			if (selected != -1)
			{
				keep[selected] = 1;
				stack.Insert(first);
				stack.Insert(selected);
				stack.Insert(selected);
				stack.Insert(last);
			}
		}
		for (int j = 0; j < source.Count(); j++)
		{
			if (keep[j])
				output.Insert(source[j]);
		}
	}

	static IAT_MA_Stroke MakeStroke(array<vector> source, float worldSize, float tolerance, int color, int width)
	{
		IAT_MA_Stroke stroke = new IAT_MA_Stroke;
		stroke.Color = color;
		stroke.Width = width;
		if (worldSize <= 0)
			return stroke;
		ref array<vector> simplified = new array<vector>;
		tolerance = Math.Max(tolerance, worldSize / 65535);
		Simplify(source, tolerance, simplified);
		while (simplified.Count() > IAT_MA_Limits.MAX_STROKE_POINTS)
		{
			tolerance *= 2;
			Simplify(source, tolerance, simplified);
		}
		foreach (vector point : simplified)
		{
			int packed = Pack(point, worldSize);
			if (stroke.Points.Count() == 0 || stroke.Points[stroke.Points.Count() - 1] != packed)
				stroke.Points.Insert(packed);
		}
		return stroke;
	}

	protected static bool ClipBoundary(float p, float q, inout float lower, inout float upper)
	{
		if (p == 0)
			return q >= 0;
		float fraction = q / p;
		if (p < 0)
		{
			if (fraction > upper)
				return false;
			lower = Math.Max(lower, fraction);
		}
		else
		{
			if (fraction < lower)
				return false;
			upper = Math.Min(upper, fraction);
		}
		return true;
	}

	static bool ClipLine(vector a, vector b, float width, float height, out vector start, out vector end)
	{
		vector delta = b - a;
		float lower = 0;
		float upper = 1;
		if (!ClipBoundary(-delta[0], a[0], lower, upper) || !ClipBoundary(delta[0], width - a[0], lower, upper) || !ClipBoundary(-delta[1], a[1], lower, upper) || !ClipBoundary(delta[1], height - a[1], lower, upper))
			return false;
		start = a + delta * lower;
		end = a + delta * upper;
		return true;
	}
}

class IAT_MA_Document
{
	protected ref array<ref IAT_MA_Stroke> m_Strokes = new array<ref IAT_MA_Stroke>;
	protected int m_PointCount;
	protected int m_Revision;
	protected string m_World;
	protected int m_WorldSize;

	array<ref IAT_MA_Stroke> GetStrokes() { return m_Strokes; }
	int GetPointCount() { return m_PointCount; }
	int GetRevision() { return m_Revision; }

	bool MatchesTerrain(string world, int worldSize)
	{
		return m_Strokes.Count() == 0 || (m_World == world && m_WorldSize == worldSize);
	}

	int Apply(int operation, int expectedRevision, IAT_MA_Stroke stroke, string world, int worldSize)
	{
		if (expectedRevision != m_Revision)
			return IAT_MA_Result.STALE;
		if (!MatchesTerrain(world, worldSize) || worldSize <= 0)
			return IAT_MA_Result.WRONG_TERRAIN;
		switch (operation)
		{
			case IAT_MA_Operation.ADD:
				if (!stroke || !stroke.IsValid())
					return IAT_MA_Result.INVALID;
				if (m_Strokes.Count() >= IAT_MA_Limits.MAX_STROKES || m_PointCount + stroke.Points.Count() > IAT_MA_Limits.MAX_MAP_POINTS)
					return IAT_MA_Result.FULL;
				m_Strokes.Insert(stroke.Copy());
				m_PointCount += stroke.Points.Count();
				m_World = world;
				m_WorldSize = worldSize;
				break;
			case IAT_MA_Operation.UNDO:
				if (m_Strokes.Count() == 0)
					return IAT_MA_Result.INVALID;
				m_PointCount -= m_Strokes[m_Strokes.Count() - 1].Points.Count();
				m_Strokes.Remove(m_Strokes.Count() - 1);
				break;
			case IAT_MA_Operation.CLEAR:
				m_Strokes.Clear();
				m_PointCount = 0;
				break;
			default:
				return IAT_MA_Result.INVALID;
		}
		m_Revision++;
		return IAT_MA_Result.OK;
	}

	void Save(ParamsWriteContext ctx)
	{
		ctx.Write(IAT_MA_Limits.VERSION);
		ctx.Write(m_World);
		ctx.Write(m_WorldSize);
		ctx.Write(m_Strokes.Count());
		foreach (IAT_MA_Stroke stroke : m_Strokes)
			stroke.Write(ctx);
	}

	bool Load(ParamsReadContext ctx)
	{
		int version;
		// Maps saved before this mod have no extension. Only an absent first field is optional.
		if (!ctx.Read(version))
			return true;
		if (version != IAT_MA_Limits.VERSION)
			return false;
		string world;
		int worldSize;
		int count;
		if (!ctx.Read(world) || !ctx.Read(worldSize) || !ctx.Read(count))
			return false;
		if (count < 0 || count > IAT_MA_Limits.MAX_STROKES || (count > 0 && (world == "" || worldSize <= 0)))
			return false;
		ref array<ref IAT_MA_Stroke> loaded = new array<ref IAT_MA_Stroke>;
		int pointCount;
		for (int i = 0; i < count; i++)
		{
			IAT_MA_Stroke stroke = new IAT_MA_Stroke;
			if (!stroke.Read(ctx))
				return false;
			pointCount += stroke.Points.Count();
			if (pointCount > IAT_MA_Limits.MAX_MAP_POINTS)
				return false;
			loaded.Insert(stroke);
		}
		m_Strokes = loaded;
		m_PointCount = pointCount;
		m_World = world;
		m_WorldSize = worldSize;
		m_Revision = 0;
		return true;
	}
}
