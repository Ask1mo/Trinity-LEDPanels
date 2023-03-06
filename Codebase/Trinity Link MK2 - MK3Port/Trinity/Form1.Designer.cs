namespace Trinity
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button_Connect = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.timer_SerialPoller = new System.Windows.Forms.Timer(this.components);
            this.label12 = new System.Windows.Forms.Label();
            this.numericUpDown_millisDelay = new System.Windows.Forms.NumericUpDown();
            this.label13 = new System.Windows.Forms.Label();
            this.numericUpDown_brightness = new System.Windows.Forms.NumericUpDown();
            this.button_updateSystemInstruction = new System.Windows.Forms.Button();
            this.groupBox_Editor_Globals = new System.Windows.Forms.GroupBox();
            this.comboBox_PortSelector = new System.Windows.Forms.ComboBox();
            this.groupBox_Setup_Connect = new System.Windows.Forms.GroupBox();
            this.button_ActiveSetupMap = new System.Windows.Forms.Button();
            this.button_NerdMode = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.groupBox_Editor_Paintbrush = new System.Windows.Forms.GroupBox();
            this.button_ChangeMultiplier = new System.Windows.Forms.Button();
            this.label_RGB = new System.Windows.Forms.Label();
            this.button_CustomColour = new System.Windows.Forms.Button();
            this.button_Background = new System.Windows.Forms.Button();
            this.button_Colour = new System.Windows.Forms.Button();
            this.button_Type = new System.Windows.Forms.Button();
            this.button_Multiplier = new System.Windows.Forms.Button();
            this.button_Speed = new System.Windows.Forms.Button();
            this.button_Offset = new System.Windows.Forms.Button();
            this.numericUpDown_MultiplierNumber = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_MultiplierSelector = new System.Windows.Forms.NumericUpDown();
            this.button_changeAllPanels = new System.Windows.Forms.Button();
            this.panel_PanelCustomColour = new System.Windows.Forms.Panel();
            this.numericUpDown_BlueValue = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_GreenValue = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_RedValue = new System.Windows.Forms.NumericUpDown();
            this.checkbox_Randomiser = new System.Windows.Forms.CheckBox();
            this.comboBox_FxBackground = new System.Windows.Forms.ComboBox();
            this.comboBox_FxType = new System.Windows.Forms.ComboBox();
            this.comboBox_FxColour = new System.Windows.Forms.ComboBox();
            this.numericUpDown_FxOffset = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_FxSpeed = new System.Windows.Forms.NumericUpDown();
            this.comboBox_MultiplierMapSelector = new System.Windows.Forms.ComboBox();
            this.comboBox_SystemViewSelector = new System.Windows.Forms.ComboBox();
            this.groupBox_Editor_SystemView = new System.Windows.Forms.GroupBox();
            this.listView_SetupMaps = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listView2 = new System.Windows.Forms.ListView();
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.button_SetupMode = new System.Windows.Forms.Button();
            this.button_EditorMode = new System.Windows.Forms.Button();
            this.button_PresetsMode = new System.Windows.Forms.Button();
            this.button_QuickConnect = new System.Windows.Forms.Button();
            this.groupBox_Presets = new System.Windows.Forms.GroupBox();
            this.label14 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.textBox_MultiplierMapCollection = new System.Windows.Forms.TextBox();
            this.textBox_MultiplierMapCreator = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox_MultiplierMapName = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox_PresetCollection = new System.Windows.Forms.TextBox();
            this.textBox_PresetCreator = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox_PresetName = new System.Windows.Forms.TextBox();
            this.button4 = new System.Windows.Forms.Button();
            this.listView_Presets = new System.Windows.Forms.ListView();
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader11 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.button_Create = new System.Windows.Forms.Button();
            this.groupBox_Setup = new System.Windows.Forms.GroupBox();
            this.groupBox_NerdStuff = new System.Windows.Forms.GroupBox();
            this.checkBox_ComportScanner = new System.Windows.Forms.CheckBox();
            this.checkBox_AllowDifferentPresets = new System.Windows.Forms.CheckBox();
            this.textBox_BaudRate = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_Transmittor_Translated = new System.Windows.Forms.TextBox();
            this.textBox_Receiver = new System.Windows.Forms.TextBox();
            this.groupBox_Editor = new System.Windows.Forms.GroupBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.button3 = new System.Windows.Forms.Button();
            this.comboBox_PresetSelector = new System.Windows.Forms.ComboBox();
            this.button_Update = new System.Windows.Forms.Button();
            this.timer_ComPortPoller = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_millisDelay)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_brightness)).BeginInit();
            this.groupBox_Editor_Globals.SuspendLayout();
            this.groupBox_Setup_Connect.SuspendLayout();
            this.groupBox_Editor_Paintbrush.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_MultiplierNumber)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_MultiplierSelector)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_BlueValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_GreenValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_RedValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxOffset)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxSpeed)).BeginInit();
            this.groupBox_Editor_SystemView.SuspendLayout();
            this.groupBox_Presets.SuspendLayout();
            this.groupBox_Setup.SuspendLayout();
            this.groupBox_NerdStuff.SuspendLayout();
            this.groupBox_Editor.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_Connect
            // 
            this.button_Connect.BackColor = System.Drawing.Color.Transparent;
            this.button_Connect.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_Connect.ForeColor = System.Drawing.Color.White;
            this.button_Connect.Location = new System.Drawing.Point(6, 69);
            this.button_Connect.Name = "button_Connect";
            this.button_Connect.Size = new System.Drawing.Size(203, 32);
            this.button_Connect.TabIndex = 3;
            this.button_Connect.Text = "Connect";
            this.button_Connect.UseVisualStyleBackColor = false;
            this.button_Connect.Click += new System.EventHandler(this.comPortConnect);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Transparent;
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button1.Cursor = System.Windows.Forms.Cursors.Default;
            this.button1.FlatAppearance.BorderSize = 0;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(6, 22);
            this.button1.Name = "button1";
            this.button1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.button1.Size = new System.Drawing.Size(154, 43);
            this.button1.TabIndex = 45;
            this.button1.Text = "Get Data";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.sendRequest);
            // 
            // timer_SerialPoller
            // 
            this.timer_SerialPoller.Tick += new System.EventHandler(this.transmissionReader);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.ForeColor = System.Drawing.Color.White;
            this.label12.Location = new System.Drawing.Point(6, 66);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(115, 33);
            this.label12.TabIndex = 72;
            this.label12.Text = "Slowness";
            // 
            // numericUpDown_millisDelay
            // 
            this.numericUpDown_millisDelay.Location = new System.Drawing.Point(141, 71);
            this.numericUpDown_millisDelay.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_millisDelay.Name = "numericUpDown_millisDelay";
            this.numericUpDown_millisDelay.Size = new System.Drawing.Size(60, 32);
            this.numericUpDown_millisDelay.TabIndex = 71;
            this.numericUpDown_millisDelay.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown_millisDelay.ValueChanged += new System.EventHandler(this.sendGlobals);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.ForeColor = System.Drawing.Color.White;
            this.label13.Location = new System.Drawing.Point(6, 28);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(130, 33);
            this.label13.TabIndex = 74;
            this.label13.Text = "Brightness";
            // 
            // numericUpDown_brightness
            // 
            this.numericUpDown_brightness.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown_brightness.Location = new System.Drawing.Point(141, 33);
            this.numericUpDown_brightness.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_brightness.Name = "numericUpDown_brightness";
            this.numericUpDown_brightness.Size = new System.Drawing.Size(60, 32);
            this.numericUpDown_brightness.TabIndex = 73;
            this.numericUpDown_brightness.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericUpDown_brightness.ValueChanged += new System.EventHandler(this.sendGlobals);
            // 
            // button_updateSystemInstruction
            // 
            this.button_updateSystemInstruction.BackColor = System.Drawing.Color.Transparent;
            this.button_updateSystemInstruction.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button_updateSystemInstruction.FlatAppearance.BorderSize = 0;
            this.button_updateSystemInstruction.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_updateSystemInstruction.Font = new System.Drawing.Font("Calibri", 20F);
            this.button_updateSystemInstruction.ForeColor = System.Drawing.Color.Transparent;
            this.button_updateSystemInstruction.Location = new System.Drawing.Point(207, 33);
            this.button_updateSystemInstruction.Name = "button_updateSystemInstruction";
            this.button_updateSystemInstruction.Size = new System.Drawing.Size(195, 70);
            this.button_updateSystemInstruction.TabIndex = 77;
            this.button_updateSystemInstruction.Text = "Update Settings";
            this.button_updateSystemInstruction.UseVisualStyleBackColor = false;
            this.button_updateSystemInstruction.Click += new System.EventHandler(this.sendGlobals);
            // 
            // groupBox_Editor_Globals
            // 
            this.groupBox_Editor_Globals.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Editor_Globals.Controls.Add(this.button_updateSystemInstruction);
            this.groupBox_Editor_Globals.Controls.Add(this.numericUpDown_millisDelay);
            this.groupBox_Editor_Globals.Controls.Add(this.label12);
            this.groupBox_Editor_Globals.Controls.Add(this.numericUpDown_brightness);
            this.groupBox_Editor_Globals.Controls.Add(this.label13);
            this.groupBox_Editor_Globals.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox_Editor_Globals.ForeColor = System.Drawing.Color.White;
            this.groupBox_Editor_Globals.Location = new System.Drawing.Point(6, 370);
            this.groupBox_Editor_Globals.Name = "groupBox_Editor_Globals";
            this.groupBox_Editor_Globals.Size = new System.Drawing.Size(420, 122);
            this.groupBox_Editor_Globals.TabIndex = 90;
            this.groupBox_Editor_Globals.TabStop = false;
            this.groupBox_Editor_Globals.Text = "Settings";
            // 
            // comboBox_PortSelector
            // 
            this.comboBox_PortSelector.FormattingEnabled = true;
            this.comboBox_PortSelector.Location = new System.Drawing.Point(6, 31);
            this.comboBox_PortSelector.Name = "comboBox_PortSelector";
            this.comboBox_PortSelector.Size = new System.Drawing.Size(203, 32);
            this.comboBox_PortSelector.TabIndex = 55;
            this.comboBox_PortSelector.Text = "Select";
            // 
            // groupBox_Setup_Connect
            // 
            this.groupBox_Setup_Connect.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Setup_Connect.Controls.Add(this.button_ActiveSetupMap);
            this.groupBox_Setup_Connect.Controls.Add(this.button_NerdMode);
            this.groupBox_Setup_Connect.Controls.Add(this.comboBox_PortSelector);
            this.groupBox_Setup_Connect.Controls.Add(this.button_Connect);
            this.groupBox_Setup_Connect.Font = new System.Drawing.Font("Calibri", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox_Setup_Connect.ForeColor = System.Drawing.Color.White;
            this.groupBox_Setup_Connect.Location = new System.Drawing.Point(6, 31);
            this.groupBox_Setup_Connect.Name = "groupBox_Setup_Connect";
            this.groupBox_Setup_Connect.Size = new System.Drawing.Size(215, 228);
            this.groupBox_Setup_Connect.TabIndex = 91;
            this.groupBox_Setup_Connect.TabStop = false;
            this.groupBox_Setup_Connect.Text = "Connecting";
            // 
            // button_ActiveSetupMap
            // 
            this.button_ActiveSetupMap.BackColor = System.Drawing.Color.Transparent;
            this.button_ActiveSetupMap.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_ActiveSetupMap.Location = new System.Drawing.Point(6, 145);
            this.button_ActiveSetupMap.Name = "button_ActiveSetupMap";
            this.button_ActiveSetupMap.Size = new System.Drawing.Size(203, 76);
            this.button_ActiveSetupMap.TabIndex = 131;
            this.button_ActiveSetupMap.Text = "No active setup";
            this.button_ActiveSetupMap.UseVisualStyleBackColor = false;
            this.button_ActiveSetupMap.Click += new System.EventHandler(this.button_ActiveSetupMap_Click);
            // 
            // button_NerdMode
            // 
            this.button_NerdMode.BackColor = System.Drawing.Color.Transparent;
            this.button_NerdMode.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_NerdMode.ForeColor = System.Drawing.Color.White;
            this.button_NerdMode.Location = new System.Drawing.Point(6, 107);
            this.button_NerdMode.Name = "button_NerdMode";
            this.button_NerdMode.Size = new System.Drawing.Size(203, 32);
            this.button_NerdMode.TabIndex = 124;
            this.button_NerdMode.Text = "Nerd Stuff";
            this.button_NerdMode.UseVisualStyleBackColor = false;
            this.button_NerdMode.Click += new System.EventHandler(this.button_NerdMode_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.Transparent;
            this.button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button2.Cursor = System.Windows.Forms.Cursors.Default;
            this.button2.FlatAppearance.BorderSize = 0;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button2.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.Color.White;
            this.button2.Location = new System.Drawing.Point(355, 22);
            this.button2.Name = "button2";
            this.button2.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.button2.Size = new System.Drawing.Size(154, 43);
            this.button2.TabIndex = 46;
            this.button2.Text = "Send Data";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.uploadPanelData);
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Transparent;
            this.panel2.Location = new System.Drawing.Point(747, 31);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(525, 420);
            this.panel2.TabIndex = 101;
            this.panel2.Click += new System.EventHandler(this.editSinglePanelFromBoard);
            // 
            // groupBox_Editor_Paintbrush
            // 
            this.groupBox_Editor_Paintbrush.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_ChangeMultiplier);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.label_RGB);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_CustomColour);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_Background);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_Colour);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_Type);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_Multiplier);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_Speed);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_Offset);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_MultiplierNumber);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_MultiplierSelector);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.button_changeAllPanels);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.panel_PanelCustomColour);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_BlueValue);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_GreenValue);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_RedValue);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.checkbox_Randomiser);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.comboBox_FxBackground);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.comboBox_FxType);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.comboBox_FxColour);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_FxOffset);
            this.groupBox_Editor_Paintbrush.Controls.Add(this.numericUpDown_FxSpeed);
            this.groupBox_Editor_Paintbrush.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.groupBox_Editor_Paintbrush.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox_Editor_Paintbrush.ForeColor = System.Drawing.Color.White;
            this.groupBox_Editor_Paintbrush.Location = new System.Drawing.Point(6, 31);
            this.groupBox_Editor_Paintbrush.Name = "groupBox_Editor_Paintbrush";
            this.groupBox_Editor_Paintbrush.Size = new System.Drawing.Size(735, 333);
            this.groupBox_Editor_Paintbrush.TabIndex = 102;
            this.groupBox_Editor_Paintbrush.TabStop = false;
            this.groupBox_Editor_Paintbrush.Text = "Paintbrush Settings";
            // 
            // button_ChangeMultiplier
            // 
            this.button_ChangeMultiplier.BackColor = System.Drawing.Color.Transparent;
            this.button_ChangeMultiplier.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_ChangeMultiplier.ForeColor = System.Drawing.Color.White;
            this.button_ChangeMultiplier.Location = new System.Drawing.Point(492, 289);
            this.button_ChangeMultiplier.Name = "button_ChangeMultiplier";
            this.button_ChangeMultiplier.Size = new System.Drawing.Size(220, 32);
            this.button_ChangeMultiplier.TabIndex = 138;
            this.button_ChangeMultiplier.Text = "Change all in zone 0";
            this.button_ChangeMultiplier.UseVisualStyleBackColor = false;
            this.button_ChangeMultiplier.Click += new System.EventHandler(this.button_ChangeMultiplier_Click);
            // 
            // label_RGB
            // 
            this.label_RGB.AutoSize = true;
            this.label_RGB.Font = new System.Drawing.Font("Calibri", 12F);
            this.label_RGB.Location = new System.Drawing.Point(397, 133);
            this.label_RGB.Name = "label_RGB";
            this.label_RGB.Size = new System.Drawing.Size(19, 95);
            this.label_RGB.TabIndex = 147;
            this.label_RGB.Text = "R\r\n\r\nG\r\n\r\nB";
            this.label_RGB.Visible = false;
            // 
            // button_CustomColour
            // 
            this.button_CustomColour.FlatAppearance.BorderSize = 0;
            this.button_CustomColour.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_CustomColour.Font = new System.Drawing.Font("Calibri", 12F);
            this.button_CustomColour.ForeColor = System.Drawing.Color.White;
            this.button_CustomColour.Image = ((System.Drawing.Image)(resources.GetObject("button_CustomColour.Image")));
            this.button_CustomColour.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_CustomColour.Location = new System.Drawing.Point(403, 29);
            this.button_CustomColour.Name = "button_CustomColour";
            this.button_CustomColour.Size = new System.Drawing.Size(70, 96);
            this.button_CustomColour.TabIndex = 146;
            this.button_CustomColour.Text = "Custom";
            this.button_CustomColour.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_CustomColour.UseVisualStyleBackColor = true;
            this.button_CustomColour.Click += new System.EventHandler(this.button_CustomColours_Click);
            // 
            // button_Background
            // 
            this.button_Background.FlatAppearance.BorderSize = 0;
            this.button_Background.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_Background.Font = new System.Drawing.Font("Calibri", 12F);
            this.button_Background.ForeColor = System.Drawing.Color.White;
            this.button_Background.Image = ((System.Drawing.Image)(resources.GetObject("button_Background.Image")));
            this.button_Background.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_Background.Location = new System.Drawing.Point(302, 31);
            this.button_Background.Name = "button_Background";
            this.button_Background.Size = new System.Drawing.Size(70, 96);
            this.button_Background.TabIndex = 145;
            this.button_Background.Text = "Backcol";
            this.button_Background.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_Background.UseVisualStyleBackColor = true;
            this.button_Background.Visible = false;
            this.button_Background.Click += new System.EventHandler(this.button_Background_Click);
            // 
            // button_Colour
            // 
            this.button_Colour.FlatAppearance.BorderSize = 0;
            this.button_Colour.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_Colour.Font = new System.Drawing.Font("Calibri", 12F);
            this.button_Colour.ForeColor = System.Drawing.Color.White;
            this.button_Colour.Image = ((System.Drawing.Image)(resources.GetObject("button_Colour.Image")));
            this.button_Colour.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_Colour.Location = new System.Drawing.Point(190, 31);
            this.button_Colour.Name = "button_Colour";
            this.button_Colour.Size = new System.Drawing.Size(70, 96);
            this.button_Colour.TabIndex = 144;
            this.button_Colour.Text = "Colour";
            this.button_Colour.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_Colour.UseVisualStyleBackColor = true;
            this.button_Colour.Click += new System.EventHandler(this.button_Colour_Click);
            // 
            // button_Type
            // 
            this.button_Type.FlatAppearance.BorderSize = 0;
            this.button_Type.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_Type.ForeColor = System.Drawing.Color.White;
            this.button_Type.Image = ((System.Drawing.Image)(resources.GetObject("button_Type.Image")));
            this.button_Type.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_Type.Location = new System.Drawing.Point(50, 31);
            this.button_Type.Name = "button_Type";
            this.button_Type.Size = new System.Drawing.Size(70, 96);
            this.button_Type.TabIndex = 143;
            this.button_Type.Text = "Type";
            this.button_Type.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_Type.UseVisualStyleBackColor = true;
            this.button_Type.Click += new System.EventHandler(this.button_Type_Click);
            // 
            // button_Multiplier
            // 
            this.button_Multiplier.FlatAppearance.BorderSize = 0;
            this.button_Multiplier.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_Multiplier.ForeColor = System.Drawing.Color.White;
            this.button_Multiplier.Image = ((System.Drawing.Image)(resources.GetObject("button_Multiplier.Image")));
            this.button_Multiplier.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_Multiplier.Location = new System.Drawing.Point(659, 29);
            this.button_Multiplier.Name = "button_Multiplier";
            this.button_Multiplier.Size = new System.Drawing.Size(70, 96);
            this.button_Multiplier.TabIndex = 142;
            this.button_Multiplier.Text = "Multiplier";
            this.button_Multiplier.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_Multiplier.UseVisualStyleBackColor = true;
            this.button_Multiplier.Click += new System.EventHandler(this.button_Multiplier_Click);
            // 
            // button_Speed
            // 
            this.button_Speed.FlatAppearance.BorderSize = 0;
            this.button_Speed.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_Speed.ForeColor = System.Drawing.Color.White;
            this.button_Speed.Image = ((System.Drawing.Image)(resources.GetObject("button_Speed.Image")));
            this.button_Speed.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_Speed.Location = new System.Drawing.Point(583, 29);
            this.button_Speed.Name = "button_Speed";
            this.button_Speed.Size = new System.Drawing.Size(70, 96);
            this.button_Speed.TabIndex = 141;
            this.button_Speed.Text = "Speed";
            this.button_Speed.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_Speed.UseVisualStyleBackColor = true;
            this.button_Speed.Click += new System.EventHandler(this.button_Speed_Click);
            // 
            // button_Offset
            // 
            this.button_Offset.FlatAppearance.BorderSize = 0;
            this.button_Offset.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_Offset.ForeColor = System.Drawing.Color.White;
            this.button_Offset.Image = ((System.Drawing.Image)(resources.GetObject("button_Offset.Image")));
            this.button_Offset.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button_Offset.Location = new System.Drawing.Point(507, 29);
            this.button_Offset.Name = "button_Offset";
            this.button_Offset.Size = new System.Drawing.Size(70, 96);
            this.button_Offset.TabIndex = 112;
            this.button_Offset.Text = "Offset";
            this.button_Offset.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button_Offset.UseVisualStyleBackColor = true;
            this.button_Offset.Click += new System.EventHandler(this.button_Offset_Click);
            // 
            // numericUpDown_MultiplierNumber
            // 
            this.numericUpDown_MultiplierNumber.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_MultiplierNumber.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_MultiplierNumber.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_MultiplierNumber.Location = new System.Drawing.Point(659, 130);
            this.numericUpDown_MultiplierNumber.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDown_MultiplierNumber.Name = "numericUpDown_MultiplierNumber";
            this.numericUpDown_MultiplierNumber.Size = new System.Drawing.Size(70, 28);
            this.numericUpDown_MultiplierNumber.TabIndex = 140;
            this.numericUpDown_MultiplierNumber.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown_MultiplierNumber.Visible = false;
            // 
            // numericUpDown_MultiplierSelector
            // 
            this.numericUpDown_MultiplierSelector.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_MultiplierSelector.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_MultiplierSelector.Location = new System.Drawing.Point(672, 289);
            this.numericUpDown_MultiplierSelector.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_MultiplierSelector.Name = "numericUpDown_MultiplierSelector";
            this.numericUpDown_MultiplierSelector.Size = new System.Drawing.Size(57, 32);
            this.numericUpDown_MultiplierSelector.TabIndex = 139;
            this.numericUpDown_MultiplierSelector.ValueChanged += new System.EventHandler(this.numericUpDown_MultiplierSelector_ValueChanged);
            // 
            // button_changeAllPanels
            // 
            this.button_changeAllPanels.BackColor = System.Drawing.Color.Transparent;
            this.button_changeAllPanels.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_changeAllPanels.ForeColor = System.Drawing.Color.White;
            this.button_changeAllPanels.Location = new System.Drawing.Point(6, 250);
            this.button_changeAllPanels.Name = "button_changeAllPanels";
            this.button_changeAllPanels.Size = new System.Drawing.Size(126, 71);
            this.button_changeAllPanels.TabIndex = 99;
            this.button_changeAllPanels.Text = "Change All";
            this.button_changeAllPanels.UseVisualStyleBackColor = false;
            this.button_changeAllPanels.Click += new System.EventHandler(this.editAllPanels);
            // 
            // panel_PanelCustomColour
            // 
            this.panel_PanelCustomColour.Location = new System.Drawing.Point(138, 250);
            this.panel_PanelCustomColour.Name = "panel_PanelCustomColour";
            this.panel_PanelCustomColour.Size = new System.Drawing.Size(348, 71);
            this.panel_PanelCustomColour.TabIndex = 134;
            // 
            // numericUpDown_BlueValue
            // 
            this.numericUpDown_BlueValue.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_BlueValue.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_BlueValue.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_BlueValue.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown_BlueValue.Location = new System.Drawing.Point(422, 207);
            this.numericUpDown_BlueValue.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_BlueValue.Name = "numericUpDown_BlueValue";
            this.numericUpDown_BlueValue.Size = new System.Drawing.Size(51, 28);
            this.numericUpDown_BlueValue.TabIndex = 133;
            this.numericUpDown_BlueValue.Visible = false;
            this.numericUpDown_BlueValue.ValueChanged += new System.EventHandler(this.paintMixer);
            // 
            // numericUpDown_GreenValue
            // 
            this.numericUpDown_GreenValue.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_GreenValue.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_GreenValue.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_GreenValue.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown_GreenValue.Location = new System.Drawing.Point(422, 169);
            this.numericUpDown_GreenValue.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_GreenValue.Name = "numericUpDown_GreenValue";
            this.numericUpDown_GreenValue.Size = new System.Drawing.Size(51, 28);
            this.numericUpDown_GreenValue.TabIndex = 132;
            this.numericUpDown_GreenValue.Visible = false;
            this.numericUpDown_GreenValue.ValueChanged += new System.EventHandler(this.paintMixer);
            // 
            // numericUpDown_RedValue
            // 
            this.numericUpDown_RedValue.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_RedValue.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_RedValue.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_RedValue.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown_RedValue.Location = new System.Drawing.Point(422, 130);
            this.numericUpDown_RedValue.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_RedValue.Name = "numericUpDown_RedValue";
            this.numericUpDown_RedValue.Size = new System.Drawing.Size(51, 28);
            this.numericUpDown_RedValue.TabIndex = 131;
            this.numericUpDown_RedValue.Visible = false;
            this.numericUpDown_RedValue.ValueChanged += new System.EventHandler(this.paintMixer);
            // 
            // checkbox_Randomiser
            // 
            this.checkbox_Randomiser.AutoSize = true;
            this.checkbox_Randomiser.Location = new System.Drawing.Point(533, 171);
            this.checkbox_Randomiser.Name = "checkbox_Randomiser";
            this.checkbox_Randomiser.Size = new System.Drawing.Size(99, 28);
            this.checkbox_Randomiser.TabIndex = 118;
            this.checkbox_Randomiser.Text = "Random";
            this.checkbox_Randomiser.UseVisualStyleBackColor = true;
            this.checkbox_Randomiser.Visible = false;
            this.checkbox_Randomiser.CheckedChanged += new System.EventHandler(this.visibilityManager);
            // 
            // comboBox_FxBackground
            // 
            this.comboBox_FxBackground.BackColor = System.Drawing.Color.Black;
            this.comboBox_FxBackground.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_FxBackground.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBox_FxBackground.ForeColor = System.Drawing.Color.White;
            this.comboBox_FxBackground.FormattingEnabled = true;
            this.comboBox_FxBackground.Items.AddRange(new object[] {
            "Black",
            "White"});
            this.comboBox_FxBackground.Location = new System.Drawing.Point(302, 133);
            this.comboBox_FxBackground.Name = "comboBox_FxBackground";
            this.comboBox_FxBackground.Size = new System.Drawing.Size(75, 32);
            this.comboBox_FxBackground.TabIndex = 110;
            this.comboBox_FxBackground.Visible = false;
            // 
            // comboBox_FxType
            // 
            this.comboBox_FxType.BackColor = System.Drawing.Color.Black;
            this.comboBox_FxType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_FxType.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBox_FxType.ForeColor = System.Drawing.Color.White;
            this.comboBox_FxType.FormattingEnabled = true;
            this.comboBox_FxType.Items.AddRange(new object[] {
            "Custom",
            "Static",
            "Blink",
            "Blink twice",
            "Breathing",
            "Pause Breathing",
            "Flash",
            "Heartbeat",
            "Sound"});
            this.comboBox_FxType.Location = new System.Drawing.Point(6, 133);
            this.comboBox_FxType.Name = "comboBox_FxType";
            this.comboBox_FxType.Size = new System.Drawing.Size(158, 32);
            this.comboBox_FxType.TabIndex = 109;
            this.comboBox_FxType.Visible = false;
            this.comboBox_FxType.SelectedIndexChanged += new System.EventHandler(this.comboBoxManager);
            // 
            // comboBox_FxColour
            // 
            this.comboBox_FxColour.BackColor = System.Drawing.Color.Black;
            this.comboBox_FxColour.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_FxColour.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBox_FxColour.ForeColor = System.Drawing.Color.White;
            this.comboBox_FxColour.FormattingEnabled = true;
            this.comboBox_FxColour.Items.AddRange(new object[] {
            "White",
            "Red",
            "Yellow",
            "Green",
            "Cyan",
            "Blue",
            "Violet",
            "Colour Cycle"});
            this.comboBox_FxColour.Location = new System.Drawing.Point(170, 133);
            this.comboBox_FxColour.Name = "comboBox_FxColour";
            this.comboBox_FxColour.Size = new System.Drawing.Size(126, 32);
            this.comboBox_FxColour.TabIndex = 108;
            this.comboBox_FxColour.Visible = false;
            // 
            // numericUpDown_FxOffset
            // 
            this.numericUpDown_FxOffset.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_FxOffset.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_FxOffset.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_FxOffset.Location = new System.Drawing.Point(507, 130);
            this.numericUpDown_FxOffset.Maximum = new decimal(new int[] {
            127,
            0,
            0,
            0});
            this.numericUpDown_FxOffset.Name = "numericUpDown_FxOffset";
            this.numericUpDown_FxOffset.Size = new System.Drawing.Size(70, 28);
            this.numericUpDown_FxOffset.TabIndex = 85;
            this.numericUpDown_FxOffset.Visible = false;
            // 
            // numericUpDown_FxSpeed
            // 
            this.numericUpDown_FxSpeed.BackColor = System.Drawing.Color.Black;
            this.numericUpDown_FxSpeed.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_FxSpeed.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_FxSpeed.Location = new System.Drawing.Point(583, 130);
            this.numericUpDown_FxSpeed.Maximum = new decimal(new int[] {
            127,
            0,
            0,
            0});
            this.numericUpDown_FxSpeed.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown_FxSpeed.Name = "numericUpDown_FxSpeed";
            this.numericUpDown_FxSpeed.Size = new System.Drawing.Size(70, 28);
            this.numericUpDown_FxSpeed.TabIndex = 97;
            this.numericUpDown_FxSpeed.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown_FxSpeed.Visible = false;
            // 
            // comboBox_MultiplierMapSelector
            // 
            this.comboBox_MultiplierMapSelector.BackColor = System.Drawing.Color.Black;
            this.comboBox_MultiplierMapSelector.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_MultiplierMapSelector.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.comboBox_MultiplierMapSelector.Font = new System.Drawing.Font("Calibri", 13F);
            this.comboBox_MultiplierMapSelector.ForeColor = System.Drawing.Color.White;
            this.comboBox_MultiplierMapSelector.FormattingEnabled = true;
            this.comboBox_MultiplierMapSelector.Location = new System.Drawing.Point(87, 55);
            this.comboBox_MultiplierMapSelector.Name = "comboBox_MultiplierMapSelector";
            this.comboBox_MultiplierMapSelector.Size = new System.Drawing.Size(216, 29);
            this.comboBox_MultiplierMapSelector.TabIndex = 124;
            this.comboBox_MultiplierMapSelector.SelectedIndexChanged += new System.EventHandler(this.applyNewMultiplierMap);
            // 
            // comboBox_SystemViewSelector
            // 
            this.comboBox_SystemViewSelector.BackColor = System.Drawing.Color.Black;
            this.comboBox_SystemViewSelector.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_SystemViewSelector.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.comboBox_SystemViewSelector.ForeColor = System.Drawing.Color.White;
            this.comboBox_SystemViewSelector.FormattingEnabled = true;
            this.comboBox_SystemViewSelector.Items.AddRange(new object[] {
            "Snapshot View",
            "Effect Type View",
            "Effect Colour View",
            "Effect Offset View",
            "Effect Speed View",
            "Multiplier Order View"});
            this.comboBox_SystemViewSelector.Location = new System.Drawing.Point(166, 31);
            this.comboBox_SystemViewSelector.Name = "comboBox_SystemViewSelector";
            this.comboBox_SystemViewSelector.Size = new System.Drawing.Size(183, 32);
            this.comboBox_SystemViewSelector.TabIndex = 110;
            this.comboBox_SystemViewSelector.SelectedIndexChanged += new System.EventHandler(this.comboBox_SystemViewSelector_SelectedIndexChanged);
            // 
            // groupBox_Editor_SystemView
            // 
            this.groupBox_Editor_SystemView.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Editor_SystemView.Controls.Add(this.button2);
            this.groupBox_Editor_SystemView.Controls.Add(this.comboBox_SystemViewSelector);
            this.groupBox_Editor_SystemView.Controls.Add(this.button1);
            this.groupBox_Editor_SystemView.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox_Editor_SystemView.ForeColor = System.Drawing.Color.White;
            this.groupBox_Editor_SystemView.Location = new System.Drawing.Point(747, 457);
            this.groupBox_Editor_SystemView.Name = "groupBox_Editor_SystemView";
            this.groupBox_Editor_SystemView.Size = new System.Drawing.Size(525, 79);
            this.groupBox_Editor_SystemView.TabIndex = 111;
            this.groupBox_Editor_SystemView.TabStop = false;
            this.groupBox_Editor_SystemView.Text = "System View";
            // 
            // listView_SetupMaps
            // 
            this.listView_SetupMaps.BackColor = System.Drawing.Color.Black;
            this.listView_SetupMaps.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3});
            this.listView_SetupMaps.Font = new System.Drawing.Font("Calibri", 12F);
            this.listView_SetupMaps.ForeColor = System.Drawing.Color.White;
            this.listView_SetupMaps.HideSelection = false;
            this.listView_SetupMaps.Location = new System.Drawing.Point(227, 42);
            this.listView_SetupMaps.Name = "listView_SetupMaps";
            this.listView_SetupMaps.Size = new System.Drawing.Size(358, 503);
            this.listView_SetupMaps.TabIndex = 130;
            this.listView_SetupMaps.UseCompatibleStateImageBehavior = false;
            this.listView_SetupMaps.View = System.Windows.Forms.View.Details;
            this.listView_SetupMaps.Visible = false;
            this.listView_SetupMaps.SelectedIndexChanged += new System.EventHandler(this.applyNewSetupMap);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Name";
            this.columnHeader1.Width = 128;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Creator";
            this.columnHeader2.Width = 169;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Panels";
            this.columnHeader3.Width = 56;
            // 
            // listView2
            // 
            this.listView2.BackColor = System.Drawing.Color.Black;
            this.listView2.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7});
            this.listView2.Font = new System.Drawing.Font("Calibri", 12F);
            this.listView2.ForeColor = System.Drawing.Color.White;
            this.listView2.HideSelection = false;
            this.listView2.Location = new System.Drawing.Point(6, 61);
            this.listView2.Name = "listView2";
            this.listView2.Size = new System.Drawing.Size(587, 329);
            this.listView2.TabIndex = 131;
            this.listView2.UseCompatibleStateImageBehavior = false;
            this.listView2.View = System.Windows.Forms.View.Details;
            this.listView2.SelectedIndexChanged += new System.EventHandler(this.favouriteNewMultiplierMap);
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Name";
            this.columnHeader4.Width = 181;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Creator";
            this.columnHeader5.Width = 138;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Collection";
            this.columnHeader6.Width = 141;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Designed For";
            this.columnHeader7.Width = 102;
            // 
            // button_SetupMode
            // 
            this.button_SetupMode.BackColor = System.Drawing.Color.Transparent;
            this.button_SetupMode.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_SetupMode.ForeColor = System.Drawing.Color.White;
            this.button_SetupMode.Location = new System.Drawing.Point(12, 12);
            this.button_SetupMode.Name = "button_SetupMode";
            this.button_SetupMode.Size = new System.Drawing.Size(75, 75);
            this.button_SetupMode.TabIndex = 114;
            this.button_SetupMode.Text = "Setup";
            this.button_SetupMode.UseVisualStyleBackColor = false;
            this.button_SetupMode.Click += new System.EventHandler(this.button_SetupMode_Click);
            // 
            // button_EditorMode
            // 
            this.button_EditorMode.BackColor = System.Drawing.Color.Transparent;
            this.button_EditorMode.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_EditorMode.ForeColor = System.Drawing.Color.White;
            this.button_EditorMode.Location = new System.Drawing.Point(12, 93);
            this.button_EditorMode.Name = "button_EditorMode";
            this.button_EditorMode.Size = new System.Drawing.Size(75, 75);
            this.button_EditorMode.TabIndex = 116;
            this.button_EditorMode.Text = "Editor";
            this.button_EditorMode.UseVisualStyleBackColor = false;
            this.button_EditorMode.Click += new System.EventHandler(this.button_EditorMode_Click);
            // 
            // button_PresetsMode
            // 
            this.button_PresetsMode.BackColor = System.Drawing.Color.Transparent;
            this.button_PresetsMode.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_PresetsMode.ForeColor = System.Drawing.Color.White;
            this.button_PresetsMode.Location = new System.Drawing.Point(12, 174);
            this.button_PresetsMode.Name = "button_PresetsMode";
            this.button_PresetsMode.Size = new System.Drawing.Size(75, 75);
            this.button_PresetsMode.TabIndex = 117;
            this.button_PresetsMode.Text = "Presets";
            this.button_PresetsMode.UseVisualStyleBackColor = false;
            this.button_PresetsMode.Click += new System.EventHandler(this.button_PresetsMode_Click);
            // 
            // button_QuickConnect
            // 
            this.button_QuickConnect.BackColor = System.Drawing.Color.Transparent;
            this.button_QuickConnect.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_QuickConnect.ForeColor = System.Drawing.Color.White;
            this.button_QuickConnect.Location = new System.Drawing.Point(12, 488);
            this.button_QuickConnect.Name = "button_QuickConnect";
            this.button_QuickConnect.Size = new System.Drawing.Size(75, 75);
            this.button_QuickConnect.TabIndex = 118;
            this.button_QuickConnect.Text = "Quick Connect";
            this.button_QuickConnect.UseVisualStyleBackColor = false;
            this.button_QuickConnect.Visible = false;
            this.button_QuickConnect.Click += new System.EventHandler(this.quickConnect);
            // 
            // groupBox_Presets
            // 
            this.groupBox_Presets.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Presets.Controls.Add(this.label14);
            this.groupBox_Presets.Controls.Add(this.textBox2);
            this.groupBox_Presets.Controls.Add(this.label11);
            this.groupBox_Presets.Controls.Add(this.textBox1);
            this.groupBox_Presets.Controls.Add(this.label8);
            this.groupBox_Presets.Controls.Add(this.label9);
            this.groupBox_Presets.Controls.Add(this.textBox_MultiplierMapCollection);
            this.groupBox_Presets.Controls.Add(this.textBox_MultiplierMapCreator);
            this.groupBox_Presets.Controls.Add(this.label10);
            this.groupBox_Presets.Controls.Add(this.textBox_MultiplierMapName);
            this.groupBox_Presets.Controls.Add(this.label7);
            this.groupBox_Presets.Controls.Add(this.label6);
            this.groupBox_Presets.Controls.Add(this.textBox_PresetCollection);
            this.groupBox_Presets.Controls.Add(this.textBox_PresetCreator);
            this.groupBox_Presets.Controls.Add(this.label5);
            this.groupBox_Presets.Controls.Add(this.textBox_PresetName);
            this.groupBox_Presets.Controls.Add(this.button4);
            this.groupBox_Presets.Controls.Add(this.listView_Presets);
            this.groupBox_Presets.Controls.Add(this.button_Create);
            this.groupBox_Presets.Controls.Add(this.listView2);
            this.groupBox_Presets.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox_Presets.ForeColor = System.Drawing.Color.White;
            this.groupBox_Presets.Location = new System.Drawing.Point(93, 1212);
            this.groupBox_Presets.Name = "groupBox_Presets";
            this.groupBox_Presets.Size = new System.Drawing.Size(1286, 551);
            this.groupBox_Presets.TabIndex = 120;
            this.groupBox_Presets.TabStop = false;
            this.groupBox_Presets.Text = "Multiplier Map Control";
            this.groupBox_Presets.Visible = false;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("Calibri", 10F);
            this.label14.Location = new System.Drawing.Point(695, 33);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(46, 17);
            this.label14.TabIndex = 149;
            this.label14.Text = "Search";
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.Color.Black;
            this.textBox2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox2.Font = new System.Drawing.Font("Calibri", 10F);
            this.textBox2.ForeColor = System.Drawing.Color.White;
            this.textBox2.Location = new System.Drawing.Point(743, 31);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(537, 24);
            this.textBox2.TabIndex = 148;
            this.textBox2.TextChanged += new System.EventHandler(this.updateListsButWithObject);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Calibri", 10F);
            this.label11.Location = new System.Drawing.Point(6, 33);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(46, 17);
            this.label11.TabIndex = 147;
            this.label11.Text = "Search";
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.Black;
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox1.Font = new System.Drawing.Font("Calibri", 10F);
            this.textBox1.ForeColor = System.Drawing.Color.White;
            this.textBox1.Location = new System.Drawing.Point(56, 31);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(537, 24);
            this.textBox1.TabIndex = 146;
            this.textBox1.TextChanged += new System.EventHandler(this.updateListsButWithObject);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(2, 516);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(93, 24);
            this.label8.TabIndex = 145;
            this.label8.Text = "Collection";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(2, 478);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(73, 24);
            this.label9.TabIndex = 144;
            this.label9.Text = "Creator";
            // 
            // textBox_MultiplierMapCollection
            // 
            this.textBox_MultiplierMapCollection.BackColor = System.Drawing.Color.Black;
            this.textBox_MultiplierMapCollection.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox_MultiplierMapCollection.ForeColor = System.Drawing.Color.White;
            this.textBox_MultiplierMapCollection.Location = new System.Drawing.Point(110, 513);
            this.textBox_MultiplierMapCollection.Name = "textBox_MultiplierMapCollection";
            this.textBox_MultiplierMapCollection.Size = new System.Drawing.Size(483, 32);
            this.textBox_MultiplierMapCollection.TabIndex = 143;
            // 
            // textBox_MultiplierMapCreator
            // 
            this.textBox_MultiplierMapCreator.BackColor = System.Drawing.Color.Black;
            this.textBox_MultiplierMapCreator.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox_MultiplierMapCreator.ForeColor = System.Drawing.Color.White;
            this.textBox_MultiplierMapCreator.Location = new System.Drawing.Point(110, 475);
            this.textBox_MultiplierMapCreator.Name = "textBox_MultiplierMapCreator";
            this.textBox_MultiplierMapCreator.Size = new System.Drawing.Size(483, 32);
            this.textBox_MultiplierMapCreator.TabIndex = 142;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(2, 440);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(59, 24);
            this.label10.TabIndex = 141;
            this.label10.Text = "Name";
            // 
            // textBox_MultiplierMapName
            // 
            this.textBox_MultiplierMapName.BackColor = System.Drawing.Color.Black;
            this.textBox_MultiplierMapName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox_MultiplierMapName.ForeColor = System.Drawing.Color.White;
            this.textBox_MultiplierMapName.Location = new System.Drawing.Point(110, 437);
            this.textBox_MultiplierMapName.Name = "textBox_MultiplierMapName";
            this.textBox_MultiplierMapName.Size = new System.Drawing.Size(483, 32);
            this.textBox_MultiplierMapName.TabIndex = 140;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(689, 513);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(93, 24);
            this.label7.TabIndex = 139;
            this.label7.Text = "Collection";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(689, 475);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(73, 24);
            this.label6.TabIndex = 138;
            this.label6.Text = "Creator";
            // 
            // textBox_PresetCollection
            // 
            this.textBox_PresetCollection.BackColor = System.Drawing.Color.Black;
            this.textBox_PresetCollection.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox_PresetCollection.ForeColor = System.Drawing.Color.White;
            this.textBox_PresetCollection.Location = new System.Drawing.Point(797, 510);
            this.textBox_PresetCollection.Name = "textBox_PresetCollection";
            this.textBox_PresetCollection.Size = new System.Drawing.Size(483, 32);
            this.textBox_PresetCollection.TabIndex = 137;
            // 
            // textBox_PresetCreator
            // 
            this.textBox_PresetCreator.BackColor = System.Drawing.Color.Black;
            this.textBox_PresetCreator.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox_PresetCreator.ForeColor = System.Drawing.Color.White;
            this.textBox_PresetCreator.Location = new System.Drawing.Point(797, 472);
            this.textBox_PresetCreator.Name = "textBox_PresetCreator";
            this.textBox_PresetCreator.Size = new System.Drawing.Size(483, 32);
            this.textBox_PresetCreator.TabIndex = 136;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(689, 437);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(59, 24);
            this.label5.TabIndex = 135;
            this.label5.Text = "Name";
            // 
            // textBox_PresetName
            // 
            this.textBox_PresetName.BackColor = System.Drawing.Color.Black;
            this.textBox_PresetName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox_PresetName.ForeColor = System.Drawing.Color.White;
            this.textBox_PresetName.Location = new System.Drawing.Point(797, 434);
            this.textBox_PresetName.Name = "textBox_PresetName";
            this.textBox_PresetName.Size = new System.Drawing.Size(483, 32);
            this.textBox_PresetName.TabIndex = 134;
            // 
            // button4
            // 
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button4.Font = new System.Drawing.Font("Calibri", 15F);
            this.button4.Location = new System.Drawing.Point(6, 396);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(587, 33);
            this.button4.TabIndex = 133;
            this.button4.Text = "Create new Multiplier Map from current settings";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button_CreateMultiplierMap_Click);
            // 
            // listView_Presets
            // 
            this.listView_Presets.BackColor = System.Drawing.Color.Black;
            this.listView_Presets.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader8,
            this.columnHeader9,
            this.columnHeader10,
            this.columnHeader11});
            this.listView_Presets.Font = new System.Drawing.Font("Calibri", 12F);
            this.listView_Presets.ForeColor = System.Drawing.Color.White;
            this.listView_Presets.HideSelection = false;
            this.listView_Presets.Location = new System.Drawing.Point(693, 61);
            this.listView_Presets.Name = "listView_Presets";
            this.listView_Presets.Size = new System.Drawing.Size(587, 329);
            this.listView_Presets.TabIndex = 132;
            this.listView_Presets.UseCompatibleStateImageBehavior = false;
            this.listView_Presets.View = System.Windows.Forms.View.Details;
            this.listView_Presets.SelectedIndexChanged += new System.EventHandler(this.favouriteNewPreset);
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "Name";
            this.columnHeader8.Width = 181;
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "Creator";
            this.columnHeader9.Width = 138;
            // 
            // columnHeader10
            // 
            this.columnHeader10.Text = "Collection";
            this.columnHeader10.Width = 141;
            // 
            // columnHeader11
            // 
            this.columnHeader11.Text = "Designed For";
            this.columnHeader11.Width = 102;
            // 
            // button_Create
            // 
            this.button_Create.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_Create.Font = new System.Drawing.Font("Calibri", 15F);
            this.button_Create.Location = new System.Drawing.Point(693, 396);
            this.button_Create.Name = "button_Create";
            this.button_Create.Size = new System.Drawing.Size(587, 32);
            this.button_Create.TabIndex = 112;
            this.button_Create.Text = "Create new Preset from current settings";
            this.button_Create.UseVisualStyleBackColor = true;
            this.button_Create.Click += new System.EventHandler(this.button_CreatePreset_Click);
            // 
            // groupBox_Setup
            // 
            this.groupBox_Setup.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Setup.Controls.Add(this.groupBox_NerdStuff);
            this.groupBox_Setup.Controls.Add(this.groupBox_Setup_Connect);
            this.groupBox_Setup.Controls.Add(this.listView_SetupMaps);
            this.groupBox_Setup.Font = new System.Drawing.Font("Calibri", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox_Setup.ForeColor = System.Drawing.Color.White;
            this.groupBox_Setup.Location = new System.Drawing.Point(93, 612);
            this.groupBox_Setup.Name = "groupBox_Setup";
            this.groupBox_Setup.Size = new System.Drawing.Size(1286, 551);
            this.groupBox_Setup.TabIndex = 121;
            this.groupBox_Setup.TabStop = false;
            this.groupBox_Setup.Text = "Setup";
            // 
            // groupBox_NerdStuff
            // 
            this.groupBox_NerdStuff.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_NerdStuff.Controls.Add(this.checkBox_ComportScanner);
            this.groupBox_NerdStuff.Controls.Add(this.checkBox_AllowDifferentPresets);
            this.groupBox_NerdStuff.Controls.Add(this.textBox_BaudRate);
            this.groupBox_NerdStuff.Controls.Add(this.label2);
            this.groupBox_NerdStuff.Controls.Add(this.label1);
            this.groupBox_NerdStuff.Controls.Add(this.textBox_Transmittor_Translated);
            this.groupBox_NerdStuff.Controls.Add(this.textBox_Receiver);
            this.groupBox_NerdStuff.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox_NerdStuff.ForeColor = System.Drawing.Color.White;
            this.groupBox_NerdStuff.Location = new System.Drawing.Point(591, 31);
            this.groupBox_NerdStuff.Name = "groupBox_NerdStuff";
            this.groupBox_NerdStuff.Size = new System.Drawing.Size(681, 514);
            this.groupBox_NerdStuff.TabIndex = 123;
            this.groupBox_NerdStuff.TabStop = false;
            this.groupBox_NerdStuff.Text = "Nerd Stuff";
            this.groupBox_NerdStuff.Visible = false;
            // 
            // checkBox_ComportScanner
            // 
            this.checkBox_ComportScanner.AutoSize = true;
            this.checkBox_ComportScanner.Checked = true;
            this.checkBox_ComportScanner.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_ComportScanner.Location = new System.Drawing.Point(12, 364);
            this.checkBox_ComportScanner.Name = "checkBox_ComportScanner";
            this.checkBox_ComportScanner.Size = new System.Drawing.Size(227, 28);
            this.checkBox_ComportScanner.TabIndex = 124;
            this.checkBox_ComportScanner.Text = "Auto COM port scanner";
            this.checkBox_ComportScanner.UseVisualStyleBackColor = true;
            // 
            // checkBox_AllowDifferentPresets
            // 
            this.checkBox_AllowDifferentPresets.AutoSize = true;
            this.checkBox_AllowDifferentPresets.Location = new System.Drawing.Point(12, 330);
            this.checkBox_AllowDifferentPresets.Name = "checkBox_AllowDifferentPresets";
            this.checkBox_AllowDifferentPresets.Size = new System.Drawing.Size(323, 28);
            this.checkBox_AllowDifferentPresets.TabIndex = 123;
            this.checkBox_AllowDifferentPresets.Text = "Show presets from different setups";
            this.checkBox_AllowDifferentPresets.UseVisualStyleBackColor = true;
            this.checkBox_AllowDifferentPresets.CheckedChanged += new System.EventHandler(this.updateListsButWithObject);
            // 
            // textBox_BaudRate
            // 
            this.textBox_BaudRate.BackColor = System.Drawing.Color.Black;
            this.textBox_BaudRate.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_BaudRate.ForeColor = System.Drawing.Color.White;
            this.textBox_BaudRate.Location = new System.Drawing.Point(288, 31);
            this.textBox_BaudRate.Name = "textBox_BaudRate";
            this.textBox_BaudRate.Size = new System.Drawing.Size(100, 25);
            this.textBox_BaudRate.TabIndex = 5;
            this.textBox_BaudRate.Text = "115200";
            this.textBox_BaudRate.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.label2.Location = new System.Drawing.Point(469, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(208, 24);
            this.label2.TabIndex = 4;
            this.label2.Text = "Outgoing Transmissions";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.Aqua;
            this.label1.Location = new System.Drawing.Point(8, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(208, 24);
            this.label1.TabIndex = 3;
            this.label1.Text = "Incoming Transmissions";
            // 
            // textBox_Transmittor_Translated
            // 
            this.textBox_Transmittor_Translated.BackColor = System.Drawing.Color.Black;
            this.textBox_Transmittor_Translated.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_Transmittor_Translated.Font = new System.Drawing.Font("Calibri", 10F);
            this.textBox_Transmittor_Translated.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.textBox_Transmittor_Translated.Location = new System.Drawing.Point(385, 69);
            this.textBox_Transmittor_Translated.Multiline = true;
            this.textBox_Transmittor_Translated.Name = "textBox_Transmittor_Translated";
            this.textBox_Transmittor_Translated.Size = new System.Drawing.Size(290, 255);
            this.textBox_Transmittor_Translated.TabIndex = 2;
            // 
            // textBox_Receiver
            // 
            this.textBox_Receiver.BackColor = System.Drawing.Color.Black;
            this.textBox_Receiver.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_Receiver.Font = new System.Drawing.Font("Calibri", 10F);
            this.textBox_Receiver.ForeColor = System.Drawing.Color.Aqua;
            this.textBox_Receiver.Location = new System.Drawing.Point(6, 69);
            this.textBox_Receiver.Multiline = true;
            this.textBox_Receiver.Name = "textBox_Receiver";
            this.textBox_Receiver.Size = new System.Drawing.Size(290, 255);
            this.textBox_Receiver.TabIndex = 0;
            // 
            // groupBox_Editor
            // 
            this.groupBox_Editor.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Editor.Controls.Add(this.groupBox1);
            this.groupBox_Editor.Controls.Add(this.groupBox_Editor_Paintbrush);
            this.groupBox_Editor.Controls.Add(this.panel2);
            this.groupBox_Editor.Controls.Add(this.groupBox_Editor_Globals);
            this.groupBox_Editor.Controls.Add(this.groupBox_Editor_SystemView);
            this.groupBox_Editor.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox_Editor.ForeColor = System.Drawing.Color.White;
            this.groupBox_Editor.Location = new System.Drawing.Point(93, 12);
            this.groupBox_Editor.Name = "groupBox_Editor";
            this.groupBox_Editor.Size = new System.Drawing.Size(1286, 551);
            this.groupBox_Editor.TabIndex = 122;
            this.groupBox_Editor.TabStop = false;
            this.groupBox_Editor.Text = "Editor";
            this.groupBox_Editor.Visible = false;
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Transparent;
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.button3);
            this.groupBox1.Controls.Add(this.comboBox_PresetSelector);
            this.groupBox1.Controls.Add(this.button_Update);
            this.groupBox1.Controls.Add(this.comboBox_MultiplierMapSelector);
            this.groupBox1.Font = new System.Drawing.Font("Calibri", 15F);
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(432, 370);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(309, 166);
            this.groupBox1.TabIndex = 116;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Multiplier Maps and Presets";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(233, 98);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 24);
            this.label4.TabIndex = 128;
            this.label4.Text = "Presets";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(166, 28);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(143, 24);
            this.label3.TabIndex = 127;
            this.label3.Text = "Multiplier Maps";
            // 
            // button3
            // 
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button3.Font = new System.Drawing.Font("Calibri", 10F);
            this.button3.Location = new System.Drawing.Point(6, 55);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 29);
            this.button3.TabIndex = 126;
            this.button3.Text = "Update";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button_updateMultiplierMap_Click);
            // 
            // comboBox_PresetSelector
            // 
            this.comboBox_PresetSelector.BackColor = System.Drawing.Color.Black;
            this.comboBox_PresetSelector.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_PresetSelector.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.comboBox_PresetSelector.Font = new System.Drawing.Font("Calibri", 13F);
            this.comboBox_PresetSelector.ForeColor = System.Drawing.Color.White;
            this.comboBox_PresetSelector.FormattingEnabled = true;
            this.comboBox_PresetSelector.Location = new System.Drawing.Point(87, 128);
            this.comboBox_PresetSelector.Name = "comboBox_PresetSelector";
            this.comboBox_PresetSelector.Size = new System.Drawing.Size(216, 29);
            this.comboBox_PresetSelector.TabIndex = 125;
            this.comboBox_PresetSelector.SelectedIndexChanged += new System.EventHandler(this.applyPreset);
            // 
            // button_Update
            // 
            this.button_Update.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_Update.Font = new System.Drawing.Font("Calibri", 10F);
            this.button_Update.Location = new System.Drawing.Point(6, 128);
            this.button_Update.Name = "button_Update";
            this.button_Update.Size = new System.Drawing.Size(75, 29);
            this.button_Update.TabIndex = 113;
            this.button_Update.Text = "Update";
            this.button_Update.UseVisualStyleBackColor = true;
            this.button_Update.Click += new System.EventHandler(this.updatePreset);
            // 
            // timer_ComPortPoller
            // 
            this.timer_ComPortPoller.Enabled = true;
            this.timer_ComPortPoller.Interval = 1000;
            this.timer_ComPortPoller.Tick += new System.EventHandler(this.comPortScanner);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(1391, 574);
            this.Controls.Add(this.groupBox_Editor);
            this.Controls.Add(this.groupBox_Setup);
            this.Controls.Add(this.groupBox_Presets);
            this.Controls.Add(this.button_QuickConnect);
            this.Controls.Add(this.button_PresetsMode);
            this.Controls.Add(this.button_EditorMode);
            this.Controls.Add(this.button_SetupMode);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Trinity";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_millisDelay)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_brightness)).EndInit();
            this.groupBox_Editor_Globals.ResumeLayout(false);
            this.groupBox_Editor_Globals.PerformLayout();
            this.groupBox_Setup_Connect.ResumeLayout(false);
            this.groupBox_Editor_Paintbrush.ResumeLayout(false);
            this.groupBox_Editor_Paintbrush.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_MultiplierNumber)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_MultiplierSelector)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_BlueValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_GreenValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_RedValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxOffset)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxSpeed)).EndInit();
            this.groupBox_Editor_SystemView.ResumeLayout(false);
            this.groupBox_Presets.ResumeLayout(false);
            this.groupBox_Presets.PerformLayout();
            this.groupBox_Setup.ResumeLayout(false);
            this.groupBox_NerdStuff.ResumeLayout(false);
            this.groupBox_NerdStuff.PerformLayout();
            this.groupBox_Editor.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button button_Connect;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Timer timer_SerialPoller;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.NumericUpDown numericUpDown_millisDelay;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.NumericUpDown numericUpDown_brightness;
        private System.Windows.Forms.Button button_updateSystemInstruction;
        private System.Windows.Forms.GroupBox groupBox_Editor_Globals;
        private System.Windows.Forms.ComboBox comboBox_PortSelector;
        private System.Windows.Forms.GroupBox groupBox_Setup_Connect;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.GroupBox groupBox_Editor_Paintbrush;
        private System.Windows.Forms.ComboBox comboBox_FxBackground;
        private System.Windows.Forms.ComboBox comboBox_FxType;
        private System.Windows.Forms.ComboBox comboBox_FxColour;
        private System.Windows.Forms.NumericUpDown numericUpDown_FxOffset;
        private System.Windows.Forms.NumericUpDown numericUpDown_FxSpeed;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.CheckBox checkbox_Randomiser;
        private System.Windows.Forms.ComboBox comboBox_SystemViewSelector;
        private System.Windows.Forms.GroupBox groupBox_Editor_SystemView;
        private System.Windows.Forms.NumericUpDown numericUpDown_BlueValue;
        private System.Windows.Forms.NumericUpDown numericUpDown_GreenValue;
        private System.Windows.Forms.NumericUpDown numericUpDown_RedValue;
        private System.Windows.Forms.Panel panel_PanelCustomColour;
        private System.Windows.Forms.ListView listView_SetupMaps;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.NumericUpDown numericUpDown_MultiplierSelector;
        private System.Windows.Forms.Button button_ChangeMultiplier;
        private System.Windows.Forms.ComboBox comboBox_MultiplierMapSelector;
        private System.Windows.Forms.Button button_changeAllPanels;
        private System.Windows.Forms.NumericUpDown numericUpDown_MultiplierNumber;
        private System.Windows.Forms.ListView listView2;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.Button button_SetupMode;
        private System.Windows.Forms.Button button_EditorMode;
        private System.Windows.Forms.Button button_PresetsMode;
        private System.Windows.Forms.Button button_QuickConnect;
        private System.Windows.Forms.GroupBox groupBox_Presets;
        private System.Windows.Forms.GroupBox groupBox_Setup;
        private System.Windows.Forms.GroupBox groupBox_Editor;
        private System.Windows.Forms.Button button_ActiveSetupMap;
        private System.Windows.Forms.Button button_Offset;
        private System.Windows.Forms.Button button_Multiplier;
        private System.Windows.Forms.Button button_Speed;
        private System.Windows.Forms.Button button_Background;
        private System.Windows.Forms.Button button_Colour;
        private System.Windows.Forms.Button button_Type;
        private System.Windows.Forms.Label label_RGB;
        private System.Windows.Forms.Button button_CustomColour;
        private System.Windows.Forms.GroupBox groupBox_NerdStuff;
        private System.Windows.Forms.TextBox textBox_Transmittor_Translated;
        private System.Windows.Forms.TextBox textBox_Receiver;
        private System.Windows.Forms.Button button_NerdMode;
        private System.Windows.Forms.TextBox textBox_BaudRate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_Create;
        private System.Windows.Forms.Button button_Update;
        private System.Windows.Forms.ListView listView_Presets;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.ColumnHeader columnHeader10;
        private System.Windows.Forms.ColumnHeader columnHeader11;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox comboBox_PresetSelector;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.CheckBox checkBox_AllowDifferentPresets;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBox_PresetCollection;
        private System.Windows.Forms.TextBox textBox_PresetCreator;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox_PresetName;
        private System.Windows.Forms.CheckBox checkBox_ComportScanner;
        private System.Windows.Forms.Timer timer_ComPortPoller;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBox_MultiplierMapCollection;
        private System.Windows.Forms.TextBox textBox_MultiplierMapCreator;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox_MultiplierMapName;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox textBox2;
    }
}

