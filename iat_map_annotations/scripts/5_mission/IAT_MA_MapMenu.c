class IAT_MA_MapInput : ScriptedWidgetEventHandler
{
	protected MapMenu m_Menu;

	void IAT_MA_MapInput(MapMenu menu)
	{
		m_Menu = menu;
	}

	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		if (m_Menu && button == MouseState.LEFT)
			m_Menu.IAT_MA_BeginStroke(x, y);
		return true;
	}

	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		if (m_Menu && button == MouseState.LEFT)
			m_Menu.IAT_MA_FinishAt(x, y);
		return true;
	}

	override bool OnClick(Widget w, int x, int y, int button) { return true; }
	override bool OnDoubleClick(Widget w, int x, int y, int button) { return true; }
	override bool OnMouseWheel(Widget w, int x, int y, int wheel) { return true; }
}

modded class MapMenu
{
	protected ChernarusMap m_IAT_MA_Map;
	protected Widget m_IAT_MA_Overlay;
	protected Widget m_IAT_MA_Toolbar;
	protected Widget m_IAT_MA_Capture;
	protected CanvasWidget m_IAT_MA_Canvas;
	protected TextWidget m_IAT_MA_Status;
	protected ButtonWidget m_IAT_MA_Mode;
	protected ButtonWidget m_IAT_MA_Color;
	protected ButtonWidget m_IAT_MA_Width;
	protected ButtonWidget m_IAT_MA_Clear;
	protected ButtonWidget m_IAT_MA_Visibility;
	protected ref IAT_MA_MapInput m_IAT_MA_Input;
	protected ref array<vector> m_IAT_MA_Draft = new array<vector>;
	protected ref IAT_MA_Stroke m_IAT_MA_Preview;
	protected bool m_IAT_MA_DrawMode;
	protected bool m_IAT_MA_Drawing;
	protected bool m_IAT_MA_ShowInk = true;
	protected bool m_IAT_MA_Dirty = true;
	protected int m_IAT_MA_Ink;
	protected int m_IAT_MA_BrushWidth = 2;
	protected int m_IAT_MA_NextSample;
	protected int m_IAT_MA_ClearUntil;
	protected int m_IAT_MA_LastGeneration = -1;
	protected int m_IAT_MA_PreviewGeneration;
	protected float m_IAT_MA_Tolerance;
	protected float m_IAT_MA_LastScale;
	protected vector m_IAT_MA_LastPosition;
	protected vector m_IAT_MA_LastBounds;
	protected vector m_IAT_MA_LastOrigin;
	protected string m_IAT_MA_LocalStatus;
	protected int m_IAT_MA_LocalStatusUntil;

	override void InitMapItem(EntityAI item)
	{
		super.InitMapItem(item);
		m_IAT_MA_Map = ChernarusMap.Cast(item);
		if (!m_IAT_MA_Map || !m_MapWidgetInstance)
			return;
		m_IAT_MA_Overlay = g_Game.GetWorkspace().CreateWidgets("iat_map_annotations/scripts/ui/overlay.layout", m_MapWidgetInstance);
		m_IAT_MA_Toolbar = g_Game.GetWorkspace().CreateWidgets("iat_map_annotations/scripts/ui/toolbar.layout", layoutRoot);
		if (!m_IAT_MA_Overlay || !m_IAT_MA_Toolbar)
			return;
		m_IAT_MA_Canvas = CanvasWidget.Cast(m_IAT_MA_Overlay.FindAnyWidget("IAT_MA_Canvas"));
		m_IAT_MA_Capture = m_IAT_MA_Overlay.FindAnyWidget("IAT_MA_Capture");
		m_IAT_MA_Status = TextWidget.Cast(m_IAT_MA_Toolbar.FindAnyWidget("IAT_MA_Status"));
		m_IAT_MA_Mode = ButtonWidget.Cast(m_IAT_MA_Toolbar.FindAnyWidget("IAT_MA_Mode"));
		m_IAT_MA_Color = ButtonWidget.Cast(m_IAT_MA_Toolbar.FindAnyWidget("IAT_MA_Color"));
		m_IAT_MA_Width = ButtonWidget.Cast(m_IAT_MA_Toolbar.FindAnyWidget("IAT_MA_Width"));
		m_IAT_MA_Clear = ButtonWidget.Cast(m_IAT_MA_Toolbar.FindAnyWidget("IAT_MA_Clear"));
		m_IAT_MA_Visibility = ButtonWidget.Cast(m_IAT_MA_Toolbar.FindAnyWidget("IAT_MA_Visibility"));
		m_IAT_MA_Input = new IAT_MA_MapInput(this);
		m_IAT_MA_Capture.SetHandler(m_IAT_MA_Input);
		m_IAT_MA_Map.IAT_MA_Open();
	}

	override void LoadMapMarkers()
	{
		// Custom image maps may deliberately omit the vanilla marker collection.
		if (m_Map && m_Map.GetMarkerArray())
			super.LoadMapMarkers();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (!m_IAT_MA_Toolbar || !m_IAT_MA_Map || button != MouseState.LEFT)
			return super.OnClick(w, x, y, button);
		string name = w.GetName();
		if (name.IndexOf("IAT_MA_") != 0)
			return super.OnClick(w, x, y, button);
		// Finish with the old brush before a toolbar click changes color or width.
		IAT_MA_EndStroke();
		switch (name)
		{
			case "IAT_MA_Mode":
				m_IAT_MA_DrawMode = !m_IAT_MA_DrawMode;
				if (m_IAT_MA_DrawMode)
					m_IAT_MA_Mode.SetText("Mode: Draw");
				else
					m_IAT_MA_Mode.SetText("Mode: Pan");
				break;
			case "IAT_MA_Color":
				m_IAT_MA_Ink = (m_IAT_MA_Ink + 1) % 4;
				ref array<string> colors = { "Black", "Red", "Blue", "Green" };
				m_IAT_MA_Color.SetText("Ink: " + colors[m_IAT_MA_Ink]);
				break;
			case "IAT_MA_Width":
				m_IAT_MA_BrushWidth += 2;
				if (m_IAT_MA_BrushWidth > 6)
					m_IAT_MA_BrushWidth = 2;
				m_IAT_MA_Width.SetText("Width: " + m_IAT_MA_BrushWidth.ToString());
				break;
			case "IAT_MA_Undo":
				m_IAT_MA_Map.IAT_MA_Submit(IAT_MA_Operation.UNDO);
				break;
			case "IAT_MA_Clear":
				if (!m_IAT_MA_Map.IAT_MA_CanEdit())
					break;
				if (g_Game.GetTime() < m_IAT_MA_ClearUntil)
				{
					m_IAT_MA_Map.IAT_MA_Submit(IAT_MA_Operation.CLEAR);
					m_IAT_MA_ClearUntil = 0;
				}
				else
				{
					m_IAT_MA_ClearUntil = g_Game.GetTime() + 5000;
					m_IAT_MA_Clear.SetText("Confirm clear");
				}
				break;
			case "IAT_MA_Reload":
				m_IAT_MA_Preview = null;
				m_IAT_MA_Map.IAT_MA_Open();
				break;
			case "IAT_MA_Visibility":
				m_IAT_MA_ShowInk = !m_IAT_MA_ShowInk;
				if (m_IAT_MA_ShowInk)
					m_IAT_MA_Visibility.SetText("Hide ink");
				else
					m_IAT_MA_Visibility.SetText("Show ink");
				m_IAT_MA_Dirty = true;
				break;
		}
		return true;
	}

	void IAT_MA_BeginStroke(int x, int y)
	{
		if (!m_IAT_MA_Map || !m_IAT_MA_ShowInk || !m_IAT_MA_DrawMode)
			return;
		if (!m_IAT_MA_Map.IAT_MA_CanEdit())
		{
			IAT_MA_Notice("Wait for the map to finish loading or saving before drawing.");
			return;
		}
		m_IAT_MA_Draft.Clear();
		m_IAT_MA_Drawing = true;
		m_IAT_MA_NextSample = 0;
		m_IAT_MA_LocalStatusUntil = 0;
		vector start = m_MapWidgetInstance.ScreenToMap(Vector(x, y, 0));
		vector nearby = m_MapWidgetInstance.ScreenToMap(Vector(x + 1.5, y, 0));
		start[1] = 0;
		nearby[1] = 0;
		m_IAT_MA_Tolerance = vector.Distance(start, nearby);
		IAT_MA_Sample(x, y, true);
	}

	protected void IAT_MA_Sample(int x, int y, bool force)
	{
		if (!force && g_Game.GetTime() < m_IAT_MA_NextSample)
			return;
		m_IAT_MA_NextSample = g_Game.GetTime() + 33;
		vector position = m_MapWidgetInstance.ScreenToMap(Vector(x, y, 0));
		position[1] = 0;
		int worldSize = g_Game.GetWorld().GetWorldSize();
		if (position[0] < 0 || position[2] < 0 || position[0] > worldSize || position[2] > worldSize)
			return;
		int count = m_IAT_MA_Draft.Count();
		if (count > 0)
		{
			vector last = m_MapWidgetInstance.MapToScreen(m_IAT_MA_Draft[count - 1]);
			vector current = m_MapWidgetInstance.MapToScreen(position);
			if (vector.DistanceSq(last, current) < 9 && !force)
				return;
		}
		m_IAT_MA_Draft.Insert(position);
		m_IAT_MA_Dirty = true;
		if (m_IAT_MA_Draft.Count() >= 512)
		{
			IAT_MA_EndStroke();
			IAT_MA_Notice("Long stroke saved. Release and press again to continue.");
		}
	}

	void IAT_MA_EndStroke()
	{
		if (!m_IAT_MA_Drawing)
			return;
		m_IAT_MA_Drawing = false;
		m_IAT_MA_Dirty = true;
		if (m_IAT_MA_Draft.Count() == 0)
			return;
		IAT_MA_Stroke stroke = IAT_MA_Geometry.MakeStroke(m_IAT_MA_Draft, g_Game.GetWorld().GetWorldSize(), m_IAT_MA_Tolerance, m_IAT_MA_Ink, m_IAT_MA_BrushWidth);
		m_IAT_MA_Draft.Clear();
		if (m_IAT_MA_Map && m_IAT_MA_Map.IAT_MA_Submit(IAT_MA_Operation.ADD, stroke))
		{
			m_IAT_MA_Preview = stroke;
			m_IAT_MA_PreviewGeneration = m_IAT_MA_Map.IAT_MA_GetGeneration();
		}
		else
			IAT_MA_Notice("Stroke was not sent. Wait for the map to finish loading or saving.");
	}

	void IAT_MA_FinishAt(int x, int y)
	{
		if (!m_IAT_MA_Drawing)
			return;
		IAT_MA_Sample(x, y, true);
		IAT_MA_EndStroke();
	}

	protected void IAT_MA_Notice(string message)
	{
		m_IAT_MA_LocalStatus = message;
		m_IAT_MA_LocalStatusUntil = g_Game.GetTime() + 4000;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);
		if (!m_IAT_MA_Map || !m_IAT_MA_Canvas || !m_IAT_MA_Toolbar)
			return;
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player || player.GetItemInHands() != m_Map || !player.IsAlive() || player.IsUnconscious() || player.IsRestrained())
		{
			m_IAT_MA_Drawing = false;
			m_IAT_MA_Draft.Clear();
			m_IAT_MA_Capture.Show(false);
			m_IAT_MA_Toolbar.Show(false);
			m_IAT_MA_Canvas.Clear();
			return;
		}
		m_IAT_MA_Map.IAT_MA_Update();
		m_IAT_MA_Capture.Show(m_IAT_MA_DrawMode && m_IAT_MA_ShowInk);
		if (m_IAT_MA_Drawing)
		{
			int mouseX, mouseY;
			GetMousePos(mouseX, mouseY);
			if (!(GetMouseState(MouseState.LEFT) & 0x80000000) || GetWidgetUnderCursor() != m_IAT_MA_Capture)
			{
				if (GetWidgetUnderCursor() == m_IAT_MA_Capture)
					IAT_MA_Sample(mouseX, mouseY, true);
				IAT_MA_EndStroke();
			}
			else
				IAT_MA_Sample(mouseX, mouseY, false);
		}
		if (m_IAT_MA_Preview && (m_IAT_MA_Map.IAT_MA_GetGeneration() != m_IAT_MA_PreviewGeneration || m_IAT_MA_Map.IAT_MA_GetStatus() != "Saving..."))
		{
			m_IAT_MA_Preview = null;
			m_IAT_MA_Dirty = true;
		}
		if (m_IAT_MA_ClearUntil && g_Game.GetTime() >= m_IAT_MA_ClearUntil)
			m_IAT_MA_ClearUntil = 0;
		if (!m_IAT_MA_ClearUntil)
			m_IAT_MA_Clear.SetText("Clear map");
		if (g_Game.GetTime() < m_IAT_MA_LocalStatusUntil)
			m_IAT_MA_Status.SetText(m_IAT_MA_LocalStatus);
		else
			m_IAT_MA_Status.SetText(m_IAT_MA_Map.IAT_MA_GetStatus());
		IAT_MA_Render();
	}

	override void OnHide()
	{
		// Abandon an unfinished stroke on close/death; completed RPCs remain in flight.
		m_IAT_MA_Drawing = false;
		m_IAT_MA_Draft.Clear();
		super.OnHide();
	}

	protected void IAT_MA_Render()
	{
		float width, height, x, y;
		m_IAT_MA_Canvas.GetScreenSize(width, height);
		m_IAT_MA_Canvas.GetScreenPos(x, y);
		vector bounds = Vector(width, height, 0);
		vector origin = Vector(x, y, 0);
		vector position = m_MapWidgetInstance.GetMapPos();
		float scale = m_MapWidgetInstance.GetScale();
		int generation = m_IAT_MA_Map.IAT_MA_GetGeneration();
		if (!m_IAT_MA_Dirty && generation == m_IAT_MA_LastGeneration && scale == m_IAT_MA_LastScale && position == m_IAT_MA_LastPosition && bounds == m_IAT_MA_LastBounds && origin == m_IAT_MA_LastOrigin)
			return;
		m_IAT_MA_Dirty = false;
		m_IAT_MA_LastGeneration = generation;
		m_IAT_MA_LastScale = scale;
		m_IAT_MA_LastPosition = position;
		m_IAT_MA_LastBounds = bounds;
		m_IAT_MA_LastOrigin = origin;
		m_IAT_MA_Canvas.Clear();
		if (!m_IAT_MA_ShowInk)
			return;
		// Derive the projection's origin so the canvas also works in offset layouts.
		vector anchor = m_MapWidgetInstance.MapToScreen(m_MapWidgetInstance.ScreenToMap(origin));
		float worldSize = g_Game.GetWorld().GetWorldSize();
		foreach (IAT_MA_Stroke stroke : m_IAT_MA_Map.IAT_MA_GetView())
			IAT_MA_DrawStroke(stroke, worldSize, anchor, width, height);
		if (m_IAT_MA_Preview)
			IAT_MA_DrawStroke(m_IAT_MA_Preview, worldSize, anchor, width, height);
		for (int i = 0; i < m_IAT_MA_Draft.Count(); i++)
		{
			vector a = m_MapWidgetInstance.MapToScreen(m_IAT_MA_Draft[i]) - anchor;
			vector b = a + Vector(1, 0, 0);
			if (i > 0)
				b = m_MapWidgetInstance.MapToScreen(m_IAT_MA_Draft[i - 1]) - anchor;
			IAT_MA_DrawSegment(a, b, width, height, m_IAT_MA_BrushWidth, IAT_MA_Limits.Color(m_IAT_MA_Ink));
		}
	}

	protected void IAT_MA_DrawStroke(IAT_MA_Stroke stroke, float worldSize, vector anchor, float width, float height)
	{
		int color = IAT_MA_Limits.Color(stroke.Color);
		for (int i = 0; i < stroke.Points.Count(); i++)
		{
			vector a = m_MapWidgetInstance.MapToScreen(IAT_MA_Geometry.Unpack(stroke.Points[i], worldSize)) - anchor;
			vector b = a + Vector(1, 0, 0);
			if (i > 0)
				b = m_MapWidgetInstance.MapToScreen(IAT_MA_Geometry.Unpack(stroke.Points[i - 1], worldSize)) - anchor;
			IAT_MA_DrawSegment(a, b, width, height, stroke.Width, color);
		}
	}

	protected void IAT_MA_DrawSegment(vector a, vector b, float width, float height, int brushWidth, int color)
	{
		vector start, end;
		if (IAT_MA_Geometry.ClipLine(a, b, width, height, start, end))
			m_IAT_MA_Canvas.DrawLine(start[0], start[1], end[0], end[1], brushWidth, color);
	}
}
