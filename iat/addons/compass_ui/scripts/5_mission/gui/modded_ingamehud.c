modded class IngameHud
{
  	private Widget m_CompassHeadingRootWidget;
	private Widget m_CompassFrameWidget;
  	private TextWidget m_CompassHeadingText;
  	private ImageWidget m_CompassImageWidget;

	private int m_CompassUIState = 0; //0,1,2: hidden,sundial,heading
	protected float debouncer = 0.0; // keeps the ui from flipping between hide/show

	void ~IngameHud()
	{
		if (!m_CompassHeadingRootWidget)
		{
			m_CompassHeadingRootWidget.Show(false);
			m_CompassHeadingRootWidget.Unlink();
		}
	}

	override void Init( Widget hud_panel_widget )
	{
		super.Init(hud_panel_widget);
		// if the root widget doesnt already exist AND we are on the client
		if (!m_CompassHeadingRootWidget && !GetGame().IsDedicatedServer())
		{
			// initialize the layout and set the widgets to their references
			m_CompassHeadingRootWidget = GetGame().GetWorkspace().CreateWidgets("iat/compass_ui/gui/layouts/compass.layout");
			m_CompassHeadingText = TextWidget.Cast(m_CompassHeadingRootWidget.FindAnyWidget("TextHeading"));
			m_CompassFrameWidget = m_CompassHeadingRootWidget.FindAnyWidget("FrameCompass");
			m_CompassImageWidget = ImageWidget.Cast(m_CompassHeadingRootWidget.FindAnyWidget("ImageCompass"));
			if (m_CompassHeadingRootWidget)
				m_CompassHeadingRootWidget.Show(false);
		}
  	}

	override void RefreshHudVisibility()
	{
		super.RefreshHudVisibility();
		bool genericShow = ( !m_HudHidePlayer && !m_HudHideUI && m_HudState ) || m_HudInventory;
		// show the compass heading like any other vanilla widget
		m_CompassHeadingRootWidget.Show(genericShow);
	}

	override void Update( float timeslice )
	{
		super.Update( timeslice );
		if( debouncer > 0.15 && GetGame() && GetGame().GetInput() && GetGame().GetInput().LocalPress("UACompassToggle", false) )
		{
			CompassToggleHeading();
      		debouncer = 0.0;
		}
		CompassUpdate();
		debouncer+= timeslice;
	}

	void CompassUpdate()
	{
		if(HasCompass())
		{
			float angle = CompassGetAngle();
			SetCompassPos(angle);
			switch(m_CompassUIState)
			{
				case 0: // no UI
				m_CompassHeadingRootWidget.Show(false);
				break;
				case 1: // sun dial UI
				m_CompassFrameWidget.Show(true);
				m_CompassHeadingText.Show(false);
				m_CompassHeadingText.SetText(CompassGetHeading(angle));
				m_CompassHeadingRootWidget.Update();
				m_CompassHeadingRootWidget.Show(true);
				break;
				case 2: // heading only
				m_CompassFrameWidget.Show(false);
				m_CompassHeadingText.Show(true);
				m_CompassHeadingText.SetText(CompassGetHeading(angle));
				m_CompassHeadingRootWidget.Update();
				m_CompassHeadingRootWidget.Show(true);
				break;
			}
		}
		else
		{
			m_CompassHeadingRootWidget.Show(false);
		}
	}

	string CompassGetHeading(float angle)
	{
		float rounded = Math.Round(5 * Math.Round(angle / 5.0));
		return rounded.ToString();
	}

	void SetCompassPos(float angle)
	{
		float width, height, x, y;
		m_CompassImageWidget.GetPos(x, y);
		m_CompassImageWidget.GetSize(width, height);

		float center_offset = width / -2.0 + 0.5;

		if(angle > 180)
		{
			angle = angle - 360;
		}
		float offset = angle *(center_offset / 180.0) + center_offset;

		m_CompassImageWidget.SetPos(offset, y);
	}

	float CompassGetAngle()
	{
		vector direction = GetGame().GetCurrentCameraDirection();
		float angle = direction.VectorToAngles()[0];
		return angle;
	}

	void CompassToggleHeading()
	{
		if(HasCompass())
		{
			IncrementCompassUIState();
		}
	}

	void IncrementCompassUIState()
	{
		m_CompassUIState = (m_CompassUIState + 1) % 3;
	}

	bool HasCompass()
	{
		PlayerBase pb;
		if(Class.CastTo(pb, GetGame().GetPlayer()))
		{
			MapNavigationBehaviour navigationBehavior;
			if (Class.CastTo(navigationBehavior, pb.GetMapNavigationBehaviour()))
			{
				return navigationBehavior.GetNavigationType() > 0;
			}
		}
		return false;
	}
};