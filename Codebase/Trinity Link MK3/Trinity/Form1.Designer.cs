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
            this.label12 = new System.Windows.Forms.Label();
            this.numericUpDown_millisDelay = new System.Windows.Forms.NumericUpDown();
            this.label13 = new System.Windows.Forms.Label();
            this.numericUpDown_brightness = new System.Windows.Forms.NumericUpDown();
            this.panel2 = new System.Windows.Forms.Panel();
            this.comboBox_FxType = new System.Windows.Forms.ComboBox();
            this.comboBox_FxColour = new System.Windows.Forms.ComboBox();
            this.numericUpDown_FxOffset = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_FxSpeed = new System.Windows.Forms.NumericUpDown();
            this.comboBox_SystemViewSelector = new System.Windows.Forms.ComboBox();
            this.listView2 = new System.Windows.Forms.ListView();
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.BTN_setup = new System.Windows.Forms.Button();
            this.BTN_editor = new System.Windows.Forms.Button();
            this.BTN_presets = new System.Windows.Forms.Button();
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
            this.button5 = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.F_baudrate = new System.Windows.Forms.ComboBox();
            this.groupBox_Editor = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.asdasd = new System.Windows.Forms.Button();
            this.timer_PortPoller = new System.Windows.Forms.Timer(this.components);
            this.timerSerial = new System.Windows.Forms.Timer(this.components);
            this.loop = new System.Windows.Forms.Timer(this.components);
            this.listBox2 = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_millisDelay)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_brightness)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxOffset)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxSpeed)).BeginInit();
            this.groupBox_Presets.SuspendLayout();
            this.groupBox_Setup.SuspendLayout();
            this.groupBox_Editor.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.ForeColor = System.Drawing.Color.White;
            this.label12.Location = new System.Drawing.Point(944, 97);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(81, 33);
            this.label12.TabIndex = 72;
            this.label12.Text = "Speed";
            // 
            // numericUpDown_millisDelay
            // 
            this.numericUpDown_millisDelay.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.numericUpDown_millisDelay.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_millisDelay.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_millisDelay.Location = new System.Drawing.Point(1079, 105);
            this.numericUpDown_millisDelay.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_millisDelay.Name = "numericUpDown_millisDelay";
            this.numericUpDown_millisDelay.Size = new System.Drawing.Size(60, 28);
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
            this.label13.Location = new System.Drawing.Point(917, 58);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(130, 33);
            this.label13.TabIndex = 74;
            this.label13.Text = "Brightness";
            // 
            // numericUpDown_brightness
            // 
            this.numericUpDown_brightness.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.numericUpDown_brightness.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_brightness.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_brightness.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown_brightness.Location = new System.Drawing.Point(1079, 63);
            this.numericUpDown_brightness.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDown_brightness.Name = "numericUpDown_brightness";
            this.numericUpDown_brightness.Size = new System.Drawing.Size(60, 28);
            this.numericUpDown_brightness.TabIndex = 73;
            this.numericUpDown_brightness.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericUpDown_brightness.ValueChanged += new System.EventHandler(this.sendGlobals);
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Transparent;
            this.panel2.Location = new System.Drawing.Point(351, 58);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(525, 420);
            this.panel2.TabIndex = 101;
            this.panel2.Click += new System.EventHandler(this.editSinglePanelFromBoard);
            // 
            // comboBox_FxType
            // 
            this.comboBox_FxType.BackColor = System.Drawing.Color.Black;
            this.comboBox_FxType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_FxType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.comboBox_FxType.ForeColor = System.Drawing.Color.White;
            this.comboBox_FxType.FormattingEnabled = true;
            this.comboBox_FxType.Items.AddRange(new object[] {
            "Static",
            "Blink",
            "Plane",
            "Breathing",
            "PausedBreathing",
            "Flash",
            "PausedFlash",
            "Heartbeat",
            "Appear",
            "Rainbow",
            "Fire",
            "Sound"});
            this.comboBox_FxType.Location = new System.Drawing.Point(9, 43);
            this.comboBox_FxType.Name = "comboBox_FxType";
            this.comboBox_FxType.Size = new System.Drawing.Size(194, 32);
            this.comboBox_FxType.TabIndex = 109;
            this.comboBox_FxType.Visible = false;
            this.comboBox_FxType.SelectedIndexChanged += new System.EventHandler(this.comboBoxManager);
            // 
            // comboBox_FxColour
            // 
            this.comboBox_FxColour.BackColor = System.Drawing.Color.Black;
            this.comboBox_FxColour.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_FxColour.FlatStyle = System.Windows.Forms.FlatStyle.System;
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
            this.comboBox_FxColour.Location = new System.Drawing.Point(9, 81);
            this.comboBox_FxColour.Name = "comboBox_FxColour";
            this.comboBox_FxColour.Size = new System.Drawing.Size(194, 32);
            this.comboBox_FxColour.TabIndex = 108;
            this.comboBox_FxColour.Visible = false;
            // 
            // numericUpDown_FxOffset
            // 
            this.numericUpDown_FxOffset.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.numericUpDown_FxOffset.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_FxOffset.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_FxOffset.Location = new System.Drawing.Point(9, 162);
            this.numericUpDown_FxOffset.Maximum = new decimal(new int[] {
            127,
            0,
            0,
            0});
            this.numericUpDown_FxOffset.Name = "numericUpDown_FxOffset";
            this.numericUpDown_FxOffset.Size = new System.Drawing.Size(194, 28);
            this.numericUpDown_FxOffset.TabIndex = 85;
            // 
            // numericUpDown_FxSpeed
            // 
            this.numericUpDown_FxSpeed.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.numericUpDown_FxSpeed.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown_FxSpeed.ForeColor = System.Drawing.Color.White;
            this.numericUpDown_FxSpeed.Location = new System.Drawing.Point(9, 196);
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
            this.numericUpDown_FxSpeed.Size = new System.Drawing.Size(194, 28);
            this.numericUpDown_FxSpeed.TabIndex = 97;
            this.numericUpDown_FxSpeed.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // comboBox_SystemViewSelector
            // 
            this.comboBox_SystemViewSelector.BackColor = System.Drawing.Color.Black;
            this.comboBox_SystemViewSelector.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_SystemViewSelector.ForeColor = System.Drawing.Color.Black;
            this.comboBox_SystemViewSelector.FormattingEnabled = true;
            this.comboBox_SystemViewSelector.Items.AddRange(new object[] {
            "Snapshot View",
            "Effect Type View",
            "Effect Colour View",
            "Effect Offset View",
            "Effect Speed View",
            "Multiplier Order View"});
            this.comboBox_SystemViewSelector.Location = new System.Drawing.Point(1089, 158);
            this.comboBox_SystemViewSelector.Name = "comboBox_SystemViewSelector";
            this.comboBox_SystemViewSelector.Size = new System.Drawing.Size(183, 32);
            this.comboBox_SystemViewSelector.TabIndex = 110;
            this.comboBox_SystemViewSelector.SelectedIndexChanged += new System.EventHandler(this.comboBox_SystemViewSelector_SelectedIndexChanged);
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
            // BTN_setup
            // 
            this.BTN_setup.BackColor = System.Drawing.Color.Transparent;
            this.BTN_setup.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.BTN_setup.ForeColor = System.Drawing.Color.White;
            this.BTN_setup.Location = new System.Drawing.Point(12, 12);
            this.BTN_setup.Name = "BTN_setup";
            this.BTN_setup.Size = new System.Drawing.Size(75, 75);
            this.BTN_setup.TabIndex = 114;
            this.BTN_setup.Text = "Setup";
            this.BTN_setup.UseVisualStyleBackColor = false;
            this.BTN_setup.Click += new System.EventHandler(this.switchTab);
            // 
            // BTN_editor
            // 
            this.BTN_editor.BackColor = System.Drawing.Color.Transparent;
            this.BTN_editor.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.BTN_editor.ForeColor = System.Drawing.Color.White;
            this.BTN_editor.Location = new System.Drawing.Point(12, 93);
            this.BTN_editor.Name = "BTN_editor";
            this.BTN_editor.Size = new System.Drawing.Size(75, 75);
            this.BTN_editor.TabIndex = 116;
            this.BTN_editor.Text = "Editor";
            this.BTN_editor.UseVisualStyleBackColor = false;
            this.BTN_editor.Click += new System.EventHandler(this.switchTab);
            // 
            // BTN_presets
            // 
            this.BTN_presets.BackColor = System.Drawing.Color.Transparent;
            this.BTN_presets.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.BTN_presets.ForeColor = System.Drawing.Color.White;
            this.BTN_presets.Location = new System.Drawing.Point(12, 174);
            this.BTN_presets.Name = "BTN_presets";
            this.BTN_presets.Size = new System.Drawing.Size(75, 75);
            this.BTN_presets.TabIndex = 117;
            this.BTN_presets.Text = "Presets";
            this.BTN_presets.UseVisualStyleBackColor = false;
            this.BTN_presets.Click += new System.EventHandler(this.switchTab);
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
            this.groupBox_Setup.Controls.Add(this.button5);
            this.groupBox_Setup.Controls.Add(this.listBox1);
            this.groupBox_Setup.Controls.Add(this.F_baudrate);
            this.groupBox_Setup.Font = new System.Drawing.Font("Calibri", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox_Setup.ForeColor = System.Drawing.Color.White;
            this.groupBox_Setup.Location = new System.Drawing.Point(93, 612);
            this.groupBox_Setup.Name = "groupBox_Setup";
            this.groupBox_Setup.Size = new System.Drawing.Size(1286, 551);
            this.groupBox_Setup.TabIndex = 121;
            this.groupBox_Setup.TabStop = false;
            this.groupBox_Setup.Text = "Setup";
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.Transparent;
            this.button5.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button5.ForeColor = System.Drawing.Color.White;
            this.button5.Location = new System.Drawing.Point(51, 193);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 75);
            this.button5.TabIndex = 123;
            this.button5.Text = "Refresh";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.serialAutoConnect);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 24;
            this.listBox1.Location = new System.Drawing.Point(144, 92);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(566, 268);
            this.listBox1.TabIndex = 149;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.serialManualConnect);
            // 
            // F_baudrate
            // 
            this.F_baudrate.BackColor = System.Drawing.Color.Black;
            this.F_baudrate.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.F_baudrate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.F_baudrate.ForeColor = System.Drawing.Color.White;
            this.F_baudrate.FormattingEnabled = true;
            this.F_baudrate.Items.AddRange(new object[] {
            "9600",
            "115200"});
            this.F_baudrate.Location = new System.Drawing.Point(387, 40);
            this.F_baudrate.MaxDropDownItems = 2;
            this.F_baudrate.Name = "F_baudrate";
            this.F_baudrate.Size = new System.Drawing.Size(126, 32);
            this.F_baudrate.TabIndex = 148;
            // 
            // groupBox_Editor
            // 
            this.groupBox_Editor.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_Editor.Controls.Add(this.listBox2);
            this.groupBox_Editor.Controls.Add(this.label3);
            this.groupBox_Editor.Controls.Add(this.label2);
            this.groupBox_Editor.Controls.Add(this.label1);
            this.groupBox_Editor.Controls.Add(this.numericUpDown1);
            this.groupBox_Editor.Controls.Add(this.comboBox_FxType);
            this.groupBox_Editor.Controls.Add(this.comboBox_FxColour);
            this.groupBox_Editor.Controls.Add(this.numericUpDown_millisDelay);
            this.groupBox_Editor.Controls.Add(this.numericUpDown_FxOffset);
            this.groupBox_Editor.Controls.Add(this.asdasd);
            this.groupBox_Editor.Controls.Add(this.numericUpDown_FxSpeed);
            this.groupBox_Editor.Controls.Add(this.label12);
            this.groupBox_Editor.Controls.Add(this.comboBox_SystemViewSelector);
            this.groupBox_Editor.Controls.Add(this.numericUpDown_brightness);
            this.groupBox_Editor.Controls.Add(this.label13);
            this.groupBox_Editor.Controls.Add(this.panel2);
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
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(215, 196);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(81, 33);
            this.label3.TabIndex = 114;
            this.label3.Text = "Speed";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(215, 162);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 33);
            this.label2.TabIndex = 113;
            this.label2.Text = "Offset";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(215, 128);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(130, 33);
            this.label1.TabIndex = 112;
            this.label1.Text = "Brightness";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.numericUpDown1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown1.ForeColor = System.Drawing.Color.White;
            this.numericUpDown1.Location = new System.Drawing.Point(9, 128);
            this.numericUpDown1.Maximum = new decimal(new int[] {
            127,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(194, 28);
            this.numericUpDown1.TabIndex = 111;
            // 
            // asdasd
            // 
            this.asdasd.BackColor = System.Drawing.Color.Transparent;
            this.asdasd.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.asdasd.Cursor = System.Windows.Forms.Cursors.Default;
            this.asdasd.FlatAppearance.BorderSize = 0;
            this.asdasd.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.asdasd.Font = new System.Drawing.Font("Calibri", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.asdasd.ForeColor = System.Drawing.Color.White;
            this.asdasd.Location = new System.Drawing.Point(1118, 14);
            this.asdasd.Name = "asdasd";
            this.asdasd.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.asdasd.Size = new System.Drawing.Size(154, 43);
            this.asdasd.TabIndex = 45;
            this.asdasd.Text = "Download";
            this.asdasd.UseVisualStyleBackColor = false;
            this.asdasd.Click += new System.EventHandler(this.btn_download);
            // 
            // timer_PortPoller
            // 
            this.timer_PortPoller.Enabled = true;
            this.timer_PortPoller.Interval = 1000;
            this.timer_PortPoller.Tick += new System.EventHandler(this.serialScanPorts);
            // 
            // timerSerial
            // 
            this.timerSerial.Enabled = true;
            this.timerSerial.Tick += new System.EventHandler(this.serialTick);
            // 
            // loop
            // 
            this.loop.Enabled = true;
            this.loop.Tick += new System.EventHandler(this.voidLoop);
            // 
            // listBox2
            // 
            this.listBox2.FormattingEnabled = true;
            this.listBox2.ItemHeight = 24;
            this.listBox2.Location = new System.Drawing.Point(896, 147);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(171, 364);
            this.listBox2.TabIndex = 115;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1446, 1061);
            this.Controls.Add(this.groupBox_Editor);
            this.Controls.Add(this.groupBox_Setup);
            this.Controls.Add(this.groupBox_Presets);
            this.Controls.Add(this.button_QuickConnect);
            this.Controls.Add(this.BTN_presets);
            this.Controls.Add(this.BTN_editor);
            this.Controls.Add(this.BTN_setup);
            this.ForeColor = System.Drawing.Color.Black;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Trinity";
            this.Load += new System.EventHandler(this.voidSetup);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_millisDelay)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_brightness)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxOffset)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_FxSpeed)).EndInit();
            this.groupBox_Presets.ResumeLayout(false);
            this.groupBox_Presets.PerformLayout();
            this.groupBox_Setup.ResumeLayout(false);
            this.groupBox_Editor.ResumeLayout(false);
            this.groupBox_Editor.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.NumericUpDown numericUpDown_millisDelay;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.NumericUpDown numericUpDown_brightness;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.ComboBox comboBox_FxType;
        private System.Windows.Forms.ComboBox comboBox_FxColour;
        private System.Windows.Forms.NumericUpDown numericUpDown_FxOffset;
        private System.Windows.Forms.NumericUpDown numericUpDown_FxSpeed;
        private System.Windows.Forms.ComboBox comboBox_SystemViewSelector;
        private System.Windows.Forms.ListView listView2;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.Button BTN_setup;
        private System.Windows.Forms.Button BTN_editor;
        private System.Windows.Forms.Button BTN_presets;
        private System.Windows.Forms.Button button_QuickConnect;
        private System.Windows.Forms.GroupBox groupBox_Presets;
        private System.Windows.Forms.GroupBox groupBox_Setup;
        private System.Windows.Forms.GroupBox groupBox_Editor;
        private System.Windows.Forms.Button button_Create;
        private System.Windows.Forms.ListView listView_Presets;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.ColumnHeader columnHeader10;
        private System.Windows.Forms.ColumnHeader columnHeader11;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBox_PresetCollection;
        private System.Windows.Forms.TextBox textBox_PresetCreator;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox_PresetName;
        private System.Windows.Forms.Timer timer_PortPoller;
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
        private System.Windows.Forms.ComboBox F_baudrate;
        private System.Windows.Forms.Timer timerSerial;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button asdasd;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Timer loop;
        private System.Windows.Forms.ListBox listBox2;
    }
}

