class IAT_SmeltingMinigameHUD extends UIScriptedMenu
{
    const int IAT_TEMPERATURE_PLOT_INTERVAL = 16;       // px space between points on the graph
    const int IAT_TEMPERATURE_NUM_POINTS = 50;          // total number of points to have in the array. the smaller the better

    protected float IAT_TEMPERATURE_UPDATE_INTERVAL = 0.33;   // dt is 0.1 scale, this controls how fast we draw the graph each interval
    protected int m_IAT_Accelerant_Min = 1;
    protected int m_IAT_Accelerant_Max = 100;
    protected int m_IAT_OreGroup_Min   = 1;
    protected int m_IAT_OreGroup1_Max   = 12;
    protected int m_IAT_OreGroup2_Max   = 12;

    protected int m_IAT_WagerCountDown = 5;             // count down for the timer. matches with the sound sets

    protected float m_IAT_TemperatureUpdateInterval = 0;// tracked dt so we can reset draw timer
    protected float m_IAT_TemperaturePlots[IAT_TEMPERATURE_NUM_POINTS]; // array of temperature points

    protected bool m_IsSyncingInputs = false;           // Prevent feedback loops slider<->edit
    protected bool m_IAT_IsInWager = false;
    // =================================================== Temperature Simulation
    protected float m_IAT_Temp_Current = 800.0;         // current temperature on the stack
    protected float m_IAT_Temp_Mean    = 800.0;         // long-term mean, of min/max temperature
    protected float m_IAT_Temp_Min     = 700.0;         // min temperature
    protected float m_IAT_Temp_Max     = 900.0;         // max temperature

    protected float m_IAT_Temp_Reversion = 0.9;         // mean-reversion strength (per second)
    protected float m_IAT_Temp_Sigma     = 150.0;       // volatility for OU noise (°C / sqrt(s))

    protected float m_IAT_Temp_SlowAmp   = 45.0;        // amplitude (°C)
    protected float m_IAT_Temp_SlowFreq  = 1.0 / 60.0;  // cycles per second (~60s period)
    protected float m_IAT_Temp_Time      = 0.0;         // decay time temp timer

    protected float m_IAT_Temp_Impulse          = 0.0;  // decaying additive term
    protected float m_IAT_Temp_ImpulseHalfLife  = 0.7;  // seconds; larger -> slower decay
    protected float m_IAT_Temp_SecondsToNextStoke = 4.0;// seconds until the next stoke event
    protected float m_IAT_Temp_StokeMinInterval   = 2.0;// min stoke interval
    protected float m_IAT_Temp_StokeMaxInterval   = 7.0;// max stoke interval

    protected float m_IAT_Temp_JitterAmp = 12.5;        // °C. jitter for randomness

    // =================================================== UI Widgets
    protected TextWidget m_LabelHeader;           // LabelHeader
    protected ButtonWidget m_ButtonCancel;        // ButtonCancel

    protected ButtonWidget m_ButtonOver;          // ButtonOver
    protected ButtonWidget m_ButtonUnder;         // ButtonUnder

    protected TextWidget m_TextStreak;            // TextStreak ("STREAK: X")
    protected TextWidget m_TextWins;              // TextWins
    protected TextWidget m_TextLoss;              // TextLoss
    protected TextWidget m_TextWnL;               // TextWin/Loss
    protected TextWidget m_WagerCountDownText;    // TextWagerCountDown

    protected SliderWidget m_SliderAccelerantHP;  // SliderAccelerantHP
    protected EditBoxWidget m_EditAccelerantHP;   // EditBoxAccelerantHP

    protected SliderWidget m_SliderOreGroup1;     // SliderOreGroup1
    protected EditBoxWidget m_EditOreGroup1;      // EditBoxOreGroup1

    protected SliderWidget m_SliderOreGroup2;     // SliderOreGroup2
    protected EditBoxWidget m_EditOreGroup2;      // EditBoxOreGroup2

    protected CanvasWidget m_CanvasTemperatureGraph; // CanvasTemperatureGraph

    protected IAT_SmeltingFurnace_ColorBase m_IAT_Furnace;

    // =========================================================== LIFECYCLE / EVENTS
    override Widget Init()
    {
        layoutRoot = g_Game.GetWorkspace().CreateWidgets("iat_smelting_metallurgy/scripts/5_mission/layouts/iat_smeltingminigamehud.layout");
        // Header and cancel
        m_LabelHeader = TextWidget.Cast(layoutRoot.FindAnyWidget("LabelHeader"));
        m_ButtonCancel = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonCancel"));

        // Action buttons
        m_ButtonOver = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonOver"));
        m_ButtonUnder = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonUnder"));

        // Streak text
        m_TextStreak = TextWidget.Cast(layoutRoot.FindAnyWidget("TextStreak"));
        m_TextWins = TextWidget.Cast(layoutRoot.FindAnyWidget("TestWins"));
        m_TextLoss = TextWidget.Cast(layoutRoot.FindAnyWidget("TextLoss"));
        m_TextWnL = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWnL"));

        m_WagerCountDownText = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWagerCountDown"));
        // hidden by default
        m_WagerCountDownText.Show(false);
        // Accelerant controls
        m_SliderAccelerantHP = SliderWidget.Cast(layoutRoot.FindAnyWidget("SliderAccelerantHP"));
        m_EditAccelerantHP   = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxAccelerantHP"));

        // Ore group 1 controls
        m_SliderOreGroup1 = SliderWidget.Cast(layoutRoot.FindAnyWidget("SliderOreGroup1"));
        m_EditOreGroup1   = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxOreGroup1"));

        // Ore group 2 controls
        m_SliderOreGroup2 = SliderWidget.Cast(layoutRoot.FindAnyWidget("SliderOreGroup2"));
        m_EditOreGroup2   = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxOreGroup2"));

        // Graph canvas
        m_CanvasTemperatureGraph = CanvasWidget.Cast(layoutRoot.FindAnyWidget("CanvasTemperatureGraph"));

        // Set ranges and initialize values from edit boxes
        SetupSliderRanges();
        InitializeInputsFromLayout();

        // initialize temperature array for graphing
        m_IAT_TemperaturePlots = {};

        UpdateWinLossUI();

        return layoutRoot;
    }

    override void OnShow()
    {
        super.OnShow();
        g_Game.GetMission().AddActiveInputExcludes({"menu"});
    }

    override void OnHide()
    {
        ClearFurnace();
        g_Game.GetMission().RemoveActiveInputExcludes({"menu"}, true);
        super.OnHide();
    }

    // cheap hook to let ESC close the widgets
    override void Update(float timeslice)
    {
        super.Update(timeslice);
        if (GetUApi().GetInputByID(UAUIBack).LocalPress())
        {
            Close();
        }
        // increment time
        m_IAT_TemperatureUpdateInterval += timeslice;
        // if we are needing a new draw call
        if (m_IAT_TemperatureUpdateInterval > IAT_TEMPERATURE_UPDATE_INTERVAL)
        {
            // draw
            DrawTemperatureLinesOnCanvas(timeslice);
            // reset the timer
            m_IAT_TemperatureUpdateInterval = 0;
        }
    }

    // =========================================================== UI INPUT HANDLERS
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_ButtonCancel)
        {
            Close();
            return true;
        }
        else if (w == m_ButtonOver)
        {
            OnPlayerWager(true);
            return true;
        }
        else if (w == m_ButtonUnder)
        {
            OnPlayerWager(false);
            return true;
        }
        return false;
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        if (m_IsSyncingInputs)
            return false;

        if (w == m_SliderAccelerantHP)
        {
            SyncEditFromSlider(m_SliderAccelerantHP, m_EditAccelerantHP);
            return true;
        }
        else if (w == m_SliderOreGroup1)
        {
            SyncEditFromSlider(m_SliderOreGroup1, m_EditOreGroup1);
            return true;
        }
        else if (w == m_SliderOreGroup2)
        {
            SyncEditFromSlider(m_SliderOreGroup2, m_EditOreGroup2);
            return true;
        }
        if (finished)
        {
            if (w == m_EditAccelerantHP)
            {
                SyncSliderFromEdit(m_EditAccelerantHP, m_SliderAccelerantHP, m_IAT_Accelerant_Min, m_IAT_Accelerant_Max);
                return true;
            }
            else if (w == m_EditOreGroup1)
            {
                SyncSliderFromEdit(m_EditOreGroup1, m_SliderOreGroup1, m_IAT_OreGroup_Min, m_IAT_OreGroup1_Max);
                return true;
            }
            else if (w == m_EditOreGroup2)
            {
                SyncSliderFromEdit(m_EditOreGroup2, m_SliderOreGroup2, m_IAT_OreGroup_Min, m_IAT_OreGroup2_Max);
                return true;
            }
        }

        return false;
    }

    // =========================================================== PUBLIC API
    void UpdateWinLossUI()
    {
        PlayerBase localPlayer;
        if (Class.CastTo(localPlayer, g_Game.GetPlayer()))
        {
            int wins = localPlayer.IAT_GetSmeltingWins();
            int loss = localPlayer.IAT_GetSmeltingLoss();
            int streak = localPlayer.IAT_GetSmeltingStreak();

            SetWinCount(wins);
            SetLossCount(loss);
            SetStreakCount(streak);
            SetWinLossRatio(wins, loss);
        }
    }
    void SetStreakCount(int streak)
    {
        if (m_TextStreak)
        {
            m_TextStreak.SetText(string.Format("STREAK: %1", streak));
        }
    }
    void SetWinCount(int wins)
    {
        if (m_TextWins)
        {
            m_TextWins.SetText(string.Format("W: %1", wins));
        }
    }
    void SetLossCount(int loss)
    {
        if (m_TextLoss)
        {
            m_TextLoss.SetText(string.Format("L: %1", loss));
        }
    }
    void SetWinLossRatio(int win, int loss)
    {
        int totalRounds = win + loss;
        float rawWnL = 0;
        if (totalRounds > 0)
        {
             rawWnL = win / totalRounds;
            rawWnL *= 100;
        }
        if (m_TextWnL)
        {
            m_TextWnL.SetText(string.Format("W/L: %1%2",  MiscGameplayFunctions.TruncateToS(rawWnL), "%"));
        }
    }
	void SetFurnaceInputValues(int accelHp, int minTemp, int maxTemp, int maxOre1, int maxOre2)
	{
		m_IAT_Accelerant_Min = 1;
    	m_IAT_Accelerant_Max = accelHp;
		m_IAT_Temp_Min = minTemp;
    	m_IAT_Temp_Max = maxTemp;
    	m_IAT_OreGroup_Min = 1;
		m_IAT_OreGroup1_Max = maxOre1;
    	m_IAT_OreGroup2_Max = maxOre2;

        SetupSliderRanges();
        InitializeInputsFromLayout();
	}
    void ClearFurnace()
    {
        m_IAT_Furnace = null;

        // sanity check and make sure players cant game it somehow
        IAT_TempSimConfigure(-1, -1);
    }
    void SetFurnace(IAT_SmeltingFurnace_ColorBase furnace)
    {
        m_IAT_Furnace = furnace;

        IAT_TempSimConfigure(furnace.IAT_GetMinTemperature(), furnace.IAT_GetMaxTemperature());
    }

    // =========================================================== INTERNAL HELPERS
    vector IAT_TransformToScreenPos(float nextX, float tempY)
    {
        // x/y of canvas "(0,0)"
        float screenX, screenY;
        // width/height of canvas
        float parent_width, parent_height;
        // new position on the screen
        vector transformed_pos;

        m_CanvasTemperatureGraph.GetScreenPos(screenX, screenY);
        m_CanvasTemperatureGraph.GetScreenSize(parent_width, parent_height);

        // Map temperature value -> canvas Y in screen space.
        // - Max temperature aligns to the canvas top (screenY)
        // - Min temperature aligns to the canvas bottom (screenY + parent_height)
        float denom = Math.Max(0.001, (m_IAT_Temp_Max - m_IAT_Temp_Min));
        float tNorm = Math.Clamp((tempY - m_IAT_Temp_Min) / denom, 0.0, 1.0);
        // float yOnCanvas = screenY + parent_height - (tNorm * parent_height);
        float yOnCanvas = parent_height - (tNorm * parent_height);

        // X: for now, treat input as pixel offset inside the canvas (no scaling)
        // float xOnCanvas = screenX + nextX;
        float xOnCanvas = nextX;

        transformed_pos[0] = xOnCanvas;
        transformed_pos[1] = yOnCanvas;

        return transformed_pos;
    };

    protected void DrawTemperatureLinesOnCanvas(float deltaT)
    {
        // clear the canvas for a new draw pass
        m_CanvasTemperatureGraph.Clear();
        if (m_IAT_Furnace)
        {
            float screenX, screenY;
            m_CanvasTemperatureGraph.GetScreenPos(screenX, screenY);

            float screen_width, screen_height;
            m_CanvasTemperatureGraph.GetScreenSize(screen_width, screen_height);

            // draw mean line at the mean temperature across the canvas width
            vector meanTempVectorFrom = IAT_TransformToScreenPos(0, m_IAT_Temp_Mean);
            vector meanTempVectorTo = IAT_TransformToScreenPos(screen_width, m_IAT_Temp_Mean);
            // draw mean line
            m_CanvasTemperatureGraph.DrawLine(meanTempVectorFrom[0], meanTempVectorFrom[1], meanTempVectorTo[0], meanTempVectorTo[1], 5, ARGB(255, 0, 0, 255));

            // draw max line at the max temperature across the canvas width
            vector maxTempVectorFrom = IAT_TransformToScreenPos(0, m_IAT_Temp_Max - 15);
            vector maxTempVectorTo = IAT_TransformToScreenPos(screen_width, m_IAT_Temp_Max - 15);
            // draw max line
            m_CanvasTemperatureGraph.DrawLine(maxTempVectorFrom[0], maxTempVectorFrom[1], maxTempVectorTo[0], maxTempVectorTo[1], 3, ARGB(255, 190, 150, 20));

            // draw min line at the min temperature across the canvas width
            vector minTempVectorFrom = IAT_TransformToScreenPos(0, m_IAT_Temp_Min + 15);
            vector minTempVectorTo = IAT_TransformToScreenPos(screen_width, m_IAT_Temp_Min + 15);
            // draw min line
            m_CanvasTemperatureGraph.DrawLine(minTempVectorFrom[0], minTempVectorFrom[1], minTempVectorTo[0], minTempVectorTo[1], 3, ARGB(255, 190, 150, 20));

            vector tempPointVectorFrom, tempPointVectorTo;
            vector nextTemp, nextPoint;
            int i2, lastpoint;
            lastpoint = IAT_TEMPERATURE_NUM_POINTS - 1;
            // draw the temperature lines
            // each temperature represents a y point. x poitns are static + interval
            for (int i = 0; i < IAT_TEMPERATURE_NUM_POINTS; i++)
            {
                i2 = i + 1;
                /*
                * The last point is special in the ring buffer I have made.
                * On the other index's we copy the next value into the previous
                * so for the last value we don't copy but rather generate a new
                * temperature value so it is "stepping" forward.
                */
                if (i == lastpoint)
                {
                    // assign a new temp into the buffer
                    m_IAT_TemperaturePlots[i] = IAT_TempSimStep(deltaT);
                }
                else // rest of the points
                {
                    // first point
                    tempPointVectorFrom[0] = i * IAT_TEMPERATURE_PLOT_INTERVAL;
                    tempPointVectorFrom[1] = m_IAT_TemperaturePlots[i];
                    // translate into screen space
                    tempPointVectorFrom = IAT_TransformToScreenPos(tempPointVectorFrom[0], tempPointVectorFrom[1]);

                    // second point
                    tempPointVectorTo[0] = i2 * IAT_TEMPERATURE_PLOT_INTERVAL;
                    tempPointVectorTo[1] = m_IAT_TemperaturePlots[i2];
                    // translate into screen space
                    tempPointVectorTo = IAT_TransformToScreenPos(tempPointVectorTo[0], tempPointVectorTo[1]);

                    // draw this line segment
                    m_CanvasTemperatureGraph.DrawLine(tempPointVectorFrom[0], tempPointVectorFrom[1], tempPointVectorTo[0], tempPointVectorTo[1], 2, ARGB(255, 255, 0, 0));

                    // copy next index value to the previous (ring buffer)
                    m_IAT_TemperaturePlots[i] = m_IAT_TemperaturePlots[i2];
                }
            }
        }
    }

    protected void SetupSliderRanges()
    {
        if (m_SliderAccelerantHP)
            m_SliderAccelerantHP.SetMinMax(m_IAT_Accelerant_Min, m_IAT_Accelerant_Max);
        if (m_SliderOreGroup1)
            m_SliderOreGroup1.SetMinMax(m_IAT_OreGroup_Min, m_IAT_OreGroup1_Max);
        if (m_SliderOreGroup2)
            m_SliderOreGroup2.SetMinMax(m_IAT_OreGroup_Min, m_IAT_OreGroup2_Max);
    }

    protected void InitializeInputsFromLayout()
    {
        // Initialize accelerant from edit text → slider
        if (m_EditAccelerantHP && m_SliderAccelerantHP)
            SyncSliderFromEdit(m_EditAccelerantHP, m_SliderAccelerantHP, m_IAT_Accelerant_Min, m_IAT_Accelerant_Max);
        // Initialize ore groups
        if (m_EditOreGroup1 && m_SliderOreGroup1)
            SyncSliderFromEdit(m_EditOreGroup1, m_SliderOreGroup1, m_IAT_OreGroup_Min, m_IAT_OreGroup1_Max);
        if (m_EditOreGroup2 && m_SliderOreGroup2)
            SyncSliderFromEdit(m_EditOreGroup2, m_SliderOreGroup2, m_IAT_OreGroup_Min, m_IAT_OreGroup2_Max);
    }
    protected void SyncEditFromSlider(SliderWidget slider, EditBoxWidget edit)
    {
        if (!slider || !edit)
            return;

        m_IsSyncingInputs = true;
        float v = slider.GetCurrent();

        // Round to int for display
        // int iv = Math.Round(v);
        edit.SetText(v.ToString());
        m_IsSyncingInputs = false;

        // If this is the accelerant slider, recompute draw speed
        if (slider == m_SliderAccelerantHP)
        {
            SetDrawModfierFromAccelerantWager();
        }
    }

    protected void SyncSliderFromEdit(EditBoxWidget edit, SliderWidget slider, float minV, float maxV)
    {
        if (!edit || !slider)
            return;

        string txt = edit.GetText();
        int val = txt.ToInt();
        val = Math.Clamp(val, (int)minV, (int)maxV);

        m_IsSyncingInputs = true;
        slider.SetCurrent(val);
        // normalize edit text as clamped integer
        edit.SetText(val.ToString());
        m_IsSyncingInputs = false;

        // If this is the accelerant edit box, recompute draw speed
        if (edit == m_EditAccelerantHP)
        {
            SetDrawModfierFromAccelerantWager();
        }
    }

    // this is so we can modify in real time how fast the draw update is.
    protected void SetDrawModfierFromAccelerantWager()
    {
        if (!m_SliderAccelerantHP)
            return;

        // do not allow modifying while already in a wager
        if (IsInWager())
            return;

        // Map accelerant wager (min -> max) to update interval (slow -> fast)
        // Lowest wager => 0.8s (slowest draw), Highest wager => 0.25s (fastest)
        float accel = m_SliderAccelerantHP.GetCurrent();
        float range = Math.Max(1.0, m_IAT_Accelerant_Max - m_IAT_Accelerant_Min); // prevent divide-by-zero
        float t = Math.Clamp((accel - m_IAT_Accelerant_Min) / range, 0.0, 1.0);    // normalized [0,1]
        // Linear interpolation without relying on Math.Lerp (0.8 -> 0.25)
        IAT_TEMPERATURE_UPDATE_INTERVAL = Math.Lerp(0.033, 0.016, t);
    }

    protected bool IsInWager()
    {
        return m_IAT_IsInWager;
    }

    protected void DisableWagerButtons()
    {
        m_ButtonOver.Enable(false);
        m_ButtonUnder.Enable(false);
    }

    protected void EnableWagerButtons()
    {
        m_ButtonOver.Enable(true);
        m_ButtonUnder.Enable(true);
    }

    protected void OnPlayerWager(bool isOver)
    {
        int accelerantHpWager = m_EditAccelerantHP.GetText().ToInt();
        int ore1Wager = m_EditOreGroup1.GetText().ToInt();
        int ore2Wager = m_EditOreGroup2.GetText().ToInt();
        // rpc to the server about the wager
        m_IAT_Furnace.ClientRPC_MakeWager(isOver, accelerantHpWager, ore1Wager, ore2Wager);

        DisableWagerButtons();
        // start timer for cool downs (5 s)
        StartWagerCountDown();

        m_IAT_IsInWager = true;
    }

    protected void StartWagerCountDown()
    {
        if (m_WagerCountDownText)
        {
            m_WagerCountDownText.SetText(string.Format("WAGER PLACED - Results In: %1", m_IAT_WagerCountDown));
        }
        m_WagerCountDownText.Show(true);

        // reset wager countdown
        m_IAT_WagerCountDown = 5;
        g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(WagerCountDown, 100, false);
    }

    protected void WagerCountDown()
    {
        // keep counting until we are
        if (m_IAT_WagerCountDown > -1)
        {
            if (m_WagerCountDownText)
            {
                m_WagerCountDownText.SetText(string.Format("WAGER PLACED - Results In: %1", m_IAT_WagerCountDown));
            }
            m_IAT_WagerCountDown -= 1;
            g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(WagerCountDown, 1000, false);
        }
        else
        {
            if (m_WagerCountDownText)
            {
                m_WagerCountDownText.Show(false);
            }
            m_IAT_Furnace.ClientRPC_EvaluateResults(m_IAT_Temp_Mean, m_IAT_Temp_Current);
            EnableWagerButtons();
            m_IAT_IsInWager = false;
        }
    }

    // =========================================================== TEMPERATURE SIMULATION
    void IAT_PrepopulateTemperatures()
    {
        float deltaT = 0;
        for (int i = 0; i < IAT_TEMPERATURE_NUM_POINTS; i++)
        {
            deltaT = Math.RandomFloat01();
            float nextTempY = IAT_TempSimStep(deltaT);
            m_IAT_TemperaturePlots[i] = nextTempY;
        }
    }
    void IAT_TempSimConfigure(float minTemp = 700.0, float maxTemp = 900.0, float reversion = 0.9, float sigma = 10.0, float slowAmp = 12.0, float slowPeriodSeconds = 60.0, float stokeMinInterval = 40.0, float stokeMaxInterval = 55.0, float impulseHalfLifeSeconds = 6.0)
    {
        m_IAT_Temp_Min = minTemp;
        m_IAT_Temp_Max = maxTemp;
        // get half of max - min and add it to min to get the mean
        m_IAT_Temp_Mean = (minTemp + ((maxTemp - minTemp) / 2));
        m_IAT_Temp_Reversion = reversion;
        m_IAT_Temp_Sigma = sigma;
        m_IAT_Temp_SlowAmp = slowAmp;
        m_IAT_Temp_SlowFreq = 1.0 / Math.Max(1.0, slowPeriodSeconds);
        m_IAT_Temp_StokeMinInterval = Math.Max(5.0, stokeMinInterval);
        m_IAT_Temp_StokeMaxInterval = Math.Max(m_IAT_Temp_StokeMinInterval + 1.0, stokeMaxInterval);
        m_IAT_Temp_ImpulseHalfLife = Math.Max(0.5, impulseHalfLifeSeconds);

        // Initialize near mean with small random offset
        float r = Math.RandomFloat(-35.0, 35.0);
        m_IAT_Temp_Current = Math.Clamp(m_IAT_Temp_Mean + r, m_IAT_Temp_Min, m_IAT_Temp_Max);
        m_IAT_Temp_Impulse = 0.0;
        m_IAT_Temp_Time = 0.0;
        m_IAT_Temp_SecondsToNextStoke = Math.RandomFloat(m_IAT_Temp_StokeMinInterval, m_IAT_Temp_StokeMaxInterval);

        // simualte some temps so we have a graph to start from
        IAT_PrepopulateTemperatures();
    }

    // Force a stoke event immediately.
    void IAT_TempSimForceStoke()
    {
        float amp = Math.RandomFloat(45.0, 120.0);
        // 1-in-4 chance to be a downward plunge instead
        if (Math.RandomFloat01() < 0.25)
        {
            amp = -Math.RandomFloat(40.0, 100.0);
        }
        m_IAT_Temp_Impulse += amp;
        m_IAT_Temp_SecondsToNextStoke = Math.RandomFloat(m_IAT_Temp_StokeMinInterval, m_IAT_Temp_StokeMaxInterval);
    }

    // One integration step; returns the new temperature. dtSeconds should be real frame delta time in seconds.
    float IAT_TempSimStep(float dtSeconds)
    {
        // Guard
        if (dtSeconds <= 0)
        {
            return m_IAT_Temp_Mean;
        }

        m_IAT_Temp_Time += dtSeconds;

        // Slow drift target around the long-term mean
        float slowOffset = m_IAT_Temp_SlowAmp * Math.Sin(2.0 * Math.PI * (m_IAT_Temp_SlowFreq * m_IAT_Temp_Time));
        float targetMean = m_IAT_Temp_Mean + slowOffset;

        // Ornstein–Uhlenbeck mean reversion + Gaussian-like noise using sum-of-uniforms
        float n = (Math.RandomFloat01() + Math.RandomFloat01() + Math.RandomFloat01() + Math.RandomFloat01()) - 2.0; // ~N(0,1)
        float dOU = m_IAT_Temp_Reversion * (targetMean - m_IAT_Temp_Current) * dtSeconds + m_IAT_Temp_Sigma * Math.Sqrt(dtSeconds) * n;

        // Stoke/impulse: exponential-like decay using half-life
        float decay = Math.Pow(0.5, dtSeconds / m_IAT_Temp_ImpulseHalfLife);
        m_IAT_Temp_Impulse *= decay;

        // Schedule and trigger next stoke if the timer elapses
        m_IAT_Temp_SecondsToNextStoke -= dtSeconds;
        if (m_IAT_Temp_SecondsToNextStoke <= 0.0)
        {
            IAT_TempSimForceStoke();
        }

        // Small extra jitter
        float jitter = m_IAT_Temp_JitterAmp * ((Math.RandomFloat01() * 2.0) - 1.0);

        // Integrate
        m_IAT_Temp_Current = m_IAT_Temp_Current + dOU + m_IAT_Temp_Impulse * dtSeconds * 0.2 + jitter;

        // Soft bounds with reflection to keep within visual rails
        if (m_IAT_Temp_Current > m_IAT_Temp_Max)
        {
            float over = m_IAT_Temp_Current - m_IAT_Temp_Max;
            m_IAT_Temp_Current = m_IAT_Temp_Max - over * 0.15; // reflect with damping
        }
        else if (m_IAT_Temp_Current < m_IAT_Temp_Min)
        {
            float under = m_IAT_Temp_Min - m_IAT_Temp_Current;
            m_IAT_Temp_Current = m_IAT_Temp_Min + under * 0.15;
        }
        // PrintFormat("============================================ GENERATING NEW TEMPERATURE: %1", m_IAT_Temp_Current);
        return m_IAT_Temp_Current;
    }
};