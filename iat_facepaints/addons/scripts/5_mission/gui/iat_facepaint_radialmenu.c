class IAT_FP_RadialMenuDisplay extends UIScriptedMenu
{
	protected Widget 							m_ItemCardPanel;
	protected ref array<ref IAT_FP_RadialMenuItem> 	m_RadialItems;
	protected Widget 							m_ToolbarPanel;

	protected TextWidget						m_CategoryNameText;

	//
	const string 								GESTURE_TEXT	= "GestureNameText";
	const string 								INPUT_TEXT		= "InputActionText";
	const string 								CATEGORY_NAME	= "CategoryName";
	//selections
	protected Widget 							m_SelectedItem;
	protected bool 								m_IsCategorySelected;
	protected bool 								m_IsMenuClosing;
	protected int 								m_CurrentCategory;

	//instance
	static IAT_FP_RadialMenuDisplay							instance;

	//============================================
	// IAT_FP_RadialMenuDisplay
	//============================================
	void IAT_FP_RadialMenuDisplay()
	{
		m_RadialItems = new array<ref IAT_FP_RadialMenuItem>;
		if ( !instance )
			instance = this;
	}

	void ~IAT_FP_RadialMenuDisplay()
	{
		if (GetGame() && GetGame().GetMission())
			GetGame().GetMission().RemoveActiveInputExcludes({"radialmenu"},false);
	}

	//============================================
	// Menu Controls
	//============================================
	static void OpenMenu()
	{
		GetGame().GetUIManager().EnterScriptedMenu( IAT_MENU_RADIAL_MULTI, NULL );
	}

	static void CloseMenu()
	{
		//execute on menu release
		GetGame().GetUIManager().Back();
	}

	//============================================
	// Init & Widget Events
	//============================================
	override Widget Init()
	{
		m_CurrentCategory = -1;

		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/radial_menu/radial_gestures/day_z_gestures.layout" );
		m_ItemCardPanel = layoutRoot.FindAnyWidget( RadialMenu.RADIAL_ITEM_CARD_CONTAINER );

		//register radial menu
		RadialMenu.GetInstance().RegisterClass( this );

		//delay updates until fully initialized
		RadialMenu.GetInstance().SetWidgetInitialized(false);

		//set radial menu properties
		RadialMenu.GetInstance().SetWidgetProperties( "gui/layouts/radial_menu/radial_gestures/day_z_gesture_delimiter.layout" );

		//create content (widgets) for items
		RefreshRadialOptions();

		m_ToolbarPanel = layoutRoot.FindAnyWidget( "toolbar_bg" );
		m_ToolbarPanel.Show( true );

		//clear category name text
		UpdateCategoryName( "" );

		return layoutRoot;
	}

	override void OnShow()
	{
		super.OnShow();

		Mission mission = GetGame().GetMission();
		if (mission)
		{
			IngameHud hud = IngameHud.Cast(mission.GetHud());
			if (hud)
			{
				hud.ShowQuickbarUI(false);
			}
		}

		SetFocus(layoutRoot);
		m_IsMenuClosing = false;
	}

	override void OnHide()
	{
		super.OnHide();

		Mission mission = GetGame().GetMission();
		if (mission)
		{
			IngameHud hud = IngameHud.Cast(mission.GetHud());
			if (hud)
			{
				hud.ShowQuickbarUI(true);
			}
		}

		m_IsMenuClosing = true;
	}

	override bool OnController( Widget w, int control, int value )
	{
		super.OnController( w, control, value );

		RadialMenu.GetInstance().SetControlType( RadialMenuControlType.CONTROLLER );

		return false;
	}

	override bool OnMouseEnter( Widget w, int x, int y )
	{
		super.OnMouseEnter( w, x, y );

		RadialMenu.GetInstance().SetControlType( RadialMenuControlType.MOUSE );

		return false;
	}

	override bool UseMouse()
	{
		return true;
	}

	override bool UseGamepad()
	{
		return true;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		// if the category has changed AND is not the root AND player exists
		if (m_CurrentCategory != IAT_FP_RadialMenuCategories.CATEGORIES && m_CurrentCategory != -1 && player)
		{
			// update all radial items
			for (int i = 0; i < m_RadialItems.Count(); i++)
			{
				UpdateQuickbarItemCard(m_RadialItems[i]);
			}
		}
	}
	//============================================
	// Gestures
	//============================================
	protected void RefreshRadialOptions( IAT_FP_RadialMenuCategories category_id = -1 )
	{
		//create gestures content (widgets) based on categories
		if ( category_id > -1 )
		{
			GetGestureItems( m_RadialItems, category_id);
			m_CurrentCategory = category_id;
		}
		// root selection, shows all categories
		else
		{
			GetGestureItems( m_RadialItems, IAT_FP_RadialMenuCategories.CATEGORIES );
			m_CurrentCategory = -1;
			instance.m_IsCategorySelected = false;
		}
		// do the thing joo lee
		CreateGestureContent();
		UpdateControlsElements();
	}

	protected void GetGestureItems( out array<ref IAT_FP_RadialMenuItem> gesture_items, IAT_FP_RadialMenuCategories category)
	{
		gesture_items.Clear();

		PlayerBase player;
		if (!Class.CastTo(player, GetGame().GetPlayer()))
			return;

		IAT_FacePaintsConfig iat_fp_config;
		if (GetDayZGame())
		{
			if (Class.CastTo(iat_fp_config, GetDayZGame().GetIATFacePaintConfig()))
			{
				IAT_FacePaintOptions fp_options = iat_fp_config.GetFacePaintOptions();
				TStringArray categories = fp_options.GetCategories();

				// set up initial root category	(value is -1)
				if ( category == -1 )
				{
					for (int categoryIndex = 0; categoryIndex < categories.Count(); categoryIndex++)
					{
						gesture_items.Insert(new IAT_FP_RadialMenuItem( categoryIndex, categories.Get(categoryIndex), category));
					}
				}
				// populate the item list (values starting at 0)
				else
				{
					string categoryName = categories.Get(category);
					TStringArray paintItems = fp_options.GetCategoryItems(categoryName);

					for (int paintIndex = 0; paintIndex < paintItems.Count(); paintIndex++)
					{
						gesture_items.Insert(new IAT_FP_RadialMenuItem( paintIndex, paintItems.Get(paintIndex), category));
					}
				}
			}
		}
	}

	protected void CreateGestureContent()
	{
		//delete existing gesture widgets
		DeleteRadialMenuItems();

		for ( int i = 0; i < m_RadialItems.Count(); ++i )
		{
			IAT_FP_RadialMenuItem iat_radialmenu_item = m_RadialItems.Get( i );

			//create item card
			Widget iat_menuitem_card_widget = Widget.Cast( GetGame().GetWorkspace().CreateWidgets( "gui/layouts/radial_menu/radial_gestures/day_z_gesture_item_card.layout", m_ItemCardPanel ) );
			iat_radialmenu_item.SetRadialItemCard( iat_menuitem_card_widget );

			//update item card widget
			UpdateQuickbarItemCard( iat_radialmenu_item );

			//set data
			iat_menuitem_card_widget.SetUserData( iat_radialmenu_item );
		}

		//set radial parameters for content
		if ( m_RadialItems.Count() > 0 )
		{
			RadialMenu radial_menu = RadialMenu.GetInstance();
			radial_menu.SetRadiusOffset( 0 );
			radial_menu.SetExecuteDistOffset( 0.5 );
			radial_menu.SetOffsetFromTop( 0 );
			radial_menu.SetItemCardRadiusOffset( 0.25 );
			radial_menu.ActivateControllerTimeout( false );
		}

		//refresh radial menu
		RadialMenu.GetInstance().Refresh();
	}

	protected void UpdateQuickbarItemCard( IAT_FP_RadialMenuItem iat_radialmenu_item )
	{
		Widget iat_menuitem_card_widget = iat_radialmenu_item.GetRadialItemCard();
		//texts
		RichTextWidget iat_radialmenu_name_text = RichTextWidget.Cast( iat_menuitem_card_widget.FindAnyWidget( GESTURE_TEXT ) );
		RichTextWidget iat_radialmenu_input_text = RichTextWidget.Cast( iat_menuitem_card_widget.FindAnyWidget( INPUT_TEXT ) );
		iat_radialmenu_name_text.SetText( iat_radialmenu_item.GetName() );
		//coloring
		iat_menuitem_card_widget.SetFlags(WidgetFlags.DISABLED); //flag just seems to be...'there', useful for showing radial selector. Still...
		iat_radialmenu_name_text.SetColor(ARGB(255,255,255,255));
		iat_radialmenu_input_text.SetColor(ARGB(255,255,255,255));
	}

	protected void DeleteRadialMenuItems()
	{
		Widget child;
		Widget child_to_destroy;

		child = m_ItemCardPanel.GetChildren();
		while ( child )
		{
			child_to_destroy = child;
			child = child.GetSibling();

			delete child_to_destroy;
		}
	}

	protected void UpdateCategoryName( string name )
	{
		if ( !m_CategoryNameText )
		{
			m_CategoryNameText = TextWidget.Cast( layoutRoot.FindAnyWidget( CATEGORY_NAME ) );
		}

		m_CategoryNameText.SetText( name );
	}

	//============================================
	// Radial Menu Events
	//============================================
	//Common
	void OnControlsChanged( RadialMenuControlType type ){}

	//Mouse
	void OnMouseSelect( Widget w )
	{
		MarkSelected( w );
	}

	void OnMouseDeselect( Widget w )
	{
		UnmarkSelected( w );
	}

	void OnMouseExecute( Widget w )	{}

	//! LMB
	void OnMousePressLeft( Widget w )
	{
		if (instance.m_IsCategorySelected)
		{
			ExecuteSelectedItem();
		}
		else
		{
			ExecuteSelectedCategory( w );
		}
	}

	//! RMB
	void OnMousePressRight( Widget w )
	{
		BackOneLevel();
	}

	//Controller
	void OnControllerSelect( Widget w )
	{
		MarkSelected( w );
	}

	void OnControllerDeselect( Widget w )
	{
		UnmarkSelected( w );
	}

	void OnControllerExecute( Widget w ) {}

	void OnControllerPressSelect( Widget w )
	{
		if (instance.m_IsCategorySelected)
		{
			ExecuteSelectedItem();
		}
		else
		{
			ExecuteSelectedCategory( w );
		}
	}

	void OnControllerPressBack( Widget w )
	{
		BackOneLevel();
	}

	//Actions
	protected void MarkSelected( Widget w )
	{
		instance.m_SelectedItem = w;

		if ( w )
		{
			IAT_FP_RadialMenuItem iat_radialmenu_item;
			w.GetUserData( iat_radialmenu_item );
		}
	}

	protected void UnmarkSelected( Widget w )
	{
		instance.m_SelectedItem = NULL;

		if ( w )
		{
			IAT_FP_RadialMenuItem iat_radialmenu_item;
			w.GetUserData( iat_radialmenu_item );
		}
	}

	protected void ExecuteSelectedCategory( Widget w )
	{
		//only when category is not picked yet
		if ( w )
		{
			IAT_FP_RadialMenuItem iat_radialmenu_item;
			w.GetUserData( iat_radialmenu_item );

			//is category
			if ( !instance.m_IsCategorySelected && iat_radialmenu_item.GetCategory() == IAT_FP_RadialMenuCategories.CATEGORIES )
			{
				//set category selected
				instance.m_IsCategorySelected = true;

				//show selected category gestures
				//PrintFormat("Client--ExecuteSelectedCategory--Category: %1 ID: %2", iat_radialmenu_item.GetCategory(), iat_radialmenu_item.GetID());
				GetGestureItems( m_RadialItems, iat_radialmenu_item.GetID() );
				CreateGestureContent();
				RefreshRadialOptions( iat_radialmenu_item.GetID() );

				//update category name text
				UpdateCategoryName( iat_radialmenu_item.GetName() );
			}
		}
	}

	protected void ExecuteSelectedItem()
	{
		if ( instance.m_IsCategorySelected && instance.m_SelectedItem )
		{
			// client side script rpc to sync data from client -> server -> clients
			if ( !GetGame().IsDedicatedServer() )
			{
				PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );

				IAT_FP_RadialMenuItem iat_radialmenu_item;
				instance.m_SelectedItem.GetUserData( iat_radialmenu_item );

				if ( iat_radialmenu_item )
				{
					ScriptRPC rpc = new ScriptRPC();
					rpc.Write(iat_radialmenu_item.GetCategory());
					rpc.Write(iat_radialmenu_item.GetID());
					rpc.Send(player, IAT_FACEPAINT_RPC.IAT_RPC_FP_RADIAL_MENU, true, player.GetIdentity());
					CloseMenu();
				}
			}
		}
	}

	//only moves to the IAT_FP_RadialMenuCategories.CATEGORIES for now
	protected void BackOneLevel()
	{
		RefreshRadialOptions();
		UpdateCategoryName("");
	}

	bool IsMenuClosing()
	{
		return m_IsMenuClosing;
	}

	void SetMenuClosing(bool state)
	{
		m_IsMenuClosing = state;
	}

	protected void UpdateControlsElements()
	{
		Widget toolbarBackSpacer = layoutRoot.FindAnyWidget("BackSpacer");
		//Widget toolbarNavigateSpacer = layoutRoot.FindAnyWidget("NavigateSpacer");

		RichTextWidget toolbarSelectIcon = RichTextWidget.Cast(layoutRoot.FindAnyWidget("SelectIcon"));
		RichTextWidget toolbarBackIcon = RichTextWidget.Cast(layoutRoot.FindAnyWidget("BackIcon"));

		string selectAction;
		string backAction;
		int controllerID;

		if (GetGame().GetInput().IsEnabledMouseAndKeyboardEvenOnServer())
		{
			selectAction = "UAMenuSelect";
			backAction = "UAMenuBack";
			controllerID = EUAINPUT_DEVICE_KEYBOARDMOUSE;
		}
		else
		{
			selectAction = "UAUISelect";
			backAction = "UAUIBack";
			controllerID = EUAINPUT_DEVICE_CONTROLLER;
		}

		toolbarSelectIcon.SetText(InputUtils.GetRichtextButtonIconFromInputAction(selectAction, "", controllerID, InputUtils.ICON_SCALE_TOOLBAR));
		toolbarBackIcon.SetText(InputUtils.GetRichtextButtonIconFromInputAction(backAction, "", controllerID, InputUtils.ICON_SCALE_TOOLBAR));
		toolbarBackSpacer.Show(instance.m_IsCategorySelected);
	}
};