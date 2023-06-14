using System;
using System.IO.Ports;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows;
using System.Threading;
using System.IO;
using Newtonsoft.Json;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;
using Trinity.Classes.Comms;

namespace Trinity
{

    public partial class Form1 : Form
    {
        const byte TRANSMISSION_IN_NONE = 0;
        const byte TRANSMISSION_IN_LEDMANAGER = 1;
        const byte TRANSMISSION_IN_PANEL = 2;
        const byte TRANSMISSION_IN_DIODE = 3;
        const byte TRANSMISSION_IN_IDENT = 4;

        const byte TRANSMISSION_OUT_NONE         = 0;
        const byte TRANSMISSION_OUT_PANELFX      = 1;
        const byte TRANSMISSION_OUT_PANELCUSTOM  = 2;
        const byte TRANSMISSION_OUT_DIODEFX      = 3;
        const byte TRANSMISSION_OUT_DIODECUSTOM  = 4;
        const byte TRANSMISSION_OUT_BRIGHTNESS   = 5;
        const byte TRANSMISSION_OUT_SLEEPTIMER   = 6;
        const byte TRANSMISSION_OUT_LIGHTSENSOR  = 7;
        const byte TRANSMISSION_OUT_REQUEST      = 8;
        const byte TRANSMISSION_OUT_IDENT        = 9;

        static string fileDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + @"\Trinity\");
        static string[] effectNumbers = new String[16]
        {
            " Custom",              //0
            "   Static",            //1
            "    Blink",            //2
            "    Blink\n   Twice",  //3
            "Breathing",            //4
            "  Pause\nBreathing",   //5
            "   Flash",             //6
            "Heartbeat",            //7

            "   Sound",             //8
            "!Range 9",             //9
            "Breathing",            //10
            "  Pause\nBreathing",   //11
            "!Range 12",            //12
            "!Range 13",            //13
            "!Range 14",            //14
            "    RGB",              //15
        };
        static string[,] effectColours = new String[2, 16]
        {
            {
                "   White",         //0
                "    Red",          //1
                "  Yellow",         //2
                "   Green",         //3
                "   Cyan",          //4
                "    Blue",         //5
                "   Violet",        //6
                "  Colour\n  Cycle",//7
                "!Range 8",         //8
                "!Range 9",         //9
                "!Range 10",        //10
                "!Range 11",        //11
                "!Range 12",        //12
                "!Range 13",        //13
                "!Range 14",        //14
                "    RGB",          //15
            },

            {
                "Off",              //0
                "Rainbow",          //1
                "Synthbow",         //2
                " Strobe",          //3
                "   Fire",          //4
                "  Sound",          //5
                "Not\nBound",       //6
                "Not\nBound",       //7
                "!Range 8",         //8
                "!Range 9",         //9
                "!Range 10",        //10
                "!Range 11",        //11
                "!Range 12",        //12
                "!Range 13",        //13
                "!Range 14",        //14
                "!Range 15\n   RGB",//15
            }
        };

        Administration administration = new Administration(fileDirectory, effectNumbers, effectColours);
        LedManager ledManager = new LedManager();
        Comms comms = new Comms();
        

        

        
        public const byte XPOSITIONS = 7;
        public const byte YPOSITIONS = 4;
        byte trianglesize = 75;

        bool autoloadSuccessful = false;
        bool changesMade = false;
        bool presetChangesMade = false;
        bool triedOnce = false;
        bool brightnessWarningIgnored = false;

        bool offsetChecked = false;
        bool speedChecked = false;
        bool zoneChecked = false;
        bool typeChecked = false;
        bool colourChecked = false;
        bool backgroundChecked = false;
        bool customColoursChecked = false;
        bool presetLoaded = false;
        bool doublePresetApplyPreventor = false;

        
        

        static byte[,] activeSetupMapStartmap = new byte[YPOSITIONS, XPOSITIONS]
        {
            {000, 001, 002, 003, 004, 005, 006},
            {007, 008, 009, 010, 011, 012, 013},
            {014, 015, 016, 017, 018, 019, 020},
            {021, 022, 023, 024, 025, 026, 027}
        };
        SetupMap activeSetupMap = new SetupMap("DefaultSetupMap", "System", 28, activeSetupMapStartmap);
        byte[,] activeMultiplierMap = new byte[YPOSITIONS, XPOSITIONS]
        {
            {000, 000, 000, 000, 000, 000, 000},
            {000, 000, 000, 000, 000, 000, 000},
            {000, 000, 000, 000, 000, 000, 000},
            {000, 000, 000, 000, 000, 000, 000}
        };

        public Form1()
        {
            InitializeComponent();
            F_baudrate.SelectedIndex = 1;
            comboBox_SystemViewSelector.SelectedIndex = 0;




            groupBox_Setup.Location = new Point(93, 12);
            groupBox_Presets.Location = new Point(93, 12);

            administration.AddMultiplierMap(new MultiplierMap("Disabled", "System", "Defaults", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {001, 001, 001, 001, 001, 001, 001},
                {001, 001, 001, 001, 001, 001, 001},
                {001, 001, 001, 001, 001, 001, 001},
                {001, 001, 001, 001, 001, 001, 001}
            }));
            administration.getMultiplierMap("Disabled").LatestFavourite = true;
            administration.AddMultiplierMap(new MultiplierMap("Panel Order", "System", "Defaults", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000}
            }));
            administration.getMultiplierMap("Panel Order").LatestFavourite = true;


            importFiles();
            



            

            //if (!autoloadSuccessful) listView_SetupMaps.Visible = true;
            

            if (autoloadSuccessful)
            {
                button_QuickConnect.Visible = true;
            }
            updateLists();
        }
        private void voidSetup(object sender, EventArgs e)
        {
            serialAutoConnect(sender, e);
        }

        private void voidLoop(object sender, EventArgs e)
        {
            ledManager.tick();
        }
        //Serial Connecting
        private void serialScanPorts(object sender, EventArgs e)
        {
            string[] ports = comms.getPorts();

            if (ports.Length != listBox1.Items.Count)
            {
                listBox1.Items.Clear();
                foreach (string port in ports)
                {
                    listBox1.Items.Add(port);
                }
            }

            if (comms.getConnected())
            {
                BTN_setup.Text = comms.getConnectedPort();
            }
            else
            {
                BTN_setup.Text = "";
            }
        }
        private void serialAutoConnect(object sender, EventArgs e)
        {
            //Auto connect Serial
            comms.autoConnect(Convert.ToInt32(F_baudrate.Text));
            while (true)
            {
                if (comms.autoConnect_tick() != 2) //2 = AUTOCONNECT_BUSY
                {
                    Console.WriteLine("Auto Connect Finished");
                    return;
                }
            }
        }
        private void serialManualConnect(object sender, EventArgs e)
        {
            comms.manuallyConnect(F_baudrate.SelectedIndex, listBox1.SelectedItem.ToString());
        }
        private void serialTick(object sender, EventArgs e)
        {
            comms.tick();

            switch (comms.getReadyTransmissionType())
            {
                case TRANSMISSION_IN_LEDMANAGER:
                    ledManager.setDataFromTransmission(comms.getTransmission_LedManager());
                    break;
                case TRANSMISSION_IN_PANEL:
                    ledManager.setPanelDataFromTransmission(comms.getTransmission_Panel());
                    break;
                case TRANSMISSION_IN_DIODE:
                    ledManager.setPanelDiodeDataFromTransmission(comms.getTransmission_Diode());
                    break;
            }
        }
        //Serial Transmitting
        private void btn_download(object sender, EventArgs e)
        {
            comms.transmit(TRANSMISSION_OUT_REQUEST, "");
        }
        private void btn_upload(object sender, EventArgs e)
        {
            //comms.transmit(TRANSMISSION_OUT_BRIGHTNESS, ledManager.convertToTansmission());
            //for (byte i = 0; i < ledManager.getPanelAmount(); i++)
            {
                //comms.transmit(TRANSMISSION_OUT_PANELFX, ledManager->convertPanelFxToTransmission(i));
                //comms.transmit(TRANSMISSION_OUT_PANELCUSTOM, ledManager->convertPanelCusToTransmission(i));
                //for (byte j = 0; j < ledManager->getPanelDiodeAmount(i); j++)
                {
                    //comms.transmit(TRANSMISSION_OUT_PANELFX, ledManager->convertPanelFxToTransmission(i, j));
                    //comms.transmit(TRANSMISSION_OUT_PANELCUSTOM, ledManager->convertPanelCusToTransmission(i, j));
                }
            }
        }

        private void sendGlobals(object sender, EventArgs e) //Sends brightness and slowness data to the serial port
        {
            //Warns you if the brightness value exceeds the 100% safety limit
            if (numericUpDown_brightness.Value > 100 && !brightnessWarningIgnored)
            {
                DialogResult dialogResult = MessageBox.Show("You are trying to raise the brightness value beyond the recommended 100% limit. Exceeding this limit is possible but could be harmful for your system. Do you want to continue at your own risk?", "Danger", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes) brightnessWarningIgnored = true;
                else numericUpDown_brightness.Value = 100;
            }

            //Transmits the global settings data
            if (comms.getConnectionClearance())
            {
                //Note: Because of some wierd unknown
                byte brightnessBoost = 0;
                if (numericUpDown_brightness.Value == 1) brightnessBoost++;

                comms.serialWrite("Transmitting...#" + (char)(numericUpDown_brightness.Value / 2 + brightnessBoost) + '#' + (char)numericUpDown_millisDelay.Value + '#');
            }
            else MessageBox.Show("Check connection", "Transmission Failure");
        }
        void uploadPanelData(object sender, EventArgs e) //Upload new panel data to the trinity system
        {
            if (comms.getConnectionClearance())
            {
                bool uploadPanelDataPermission = false;
                if (!changesMade)
                {
                    DialogResult dialogResult = MessageBox.Show("No changes were made, upload anyway?", "Uploader", MessageBoxButtons.YesNo);
                    if (dialogResult == DialogResult.Yes) uploadPanelDataPermission = true;
                }
                else uploadPanelDataPermission = true;


                if(uploadPanelDataPermission)
                {
                    comms.serialWrite("Transmitting...");
                    foreach (Panel panel in administration.Panels)
                    {
                        //comms.serialWrite(panel.ToCommand());
                        //panel.Changed = false;
                    }
                    changesMade = false;
                    drawSomeTrianglesV2();
                }
            }
            else MessageBox.Show("Check connection", "Transmission Failure");
        }

        //Updating lists, graphics and boxes
        private void updateListsButWithObject(object sender, EventArgs e)
        {
            updateLists();
        }
        private void updateLists() //Update all relevant listboxes and comboboxes
        {
            drawSomeTrianglesV2();
            //listView_SetupMaps.Items.Clear();
            listView2.Items.Clear();
            listView_Presets.Items.Clear();
            //comboBox_MultiplierMapSelector.Items.Clear();
            //comboBox_PresetSelector.Items.Clear();

            foreach (SetupMap setupMap in administration.SetupMaps)
            {
                ListViewItem lvi = new ListViewItem(setupMap.Name.ToString());
                lvi.SubItems.Add(setupMap.Designer.ToString());
                lvi.SubItems.Add(setupMap.AmountOfPanels.ToString());
                //listView_SetupMaps.Items.Add(lvi);
            }

            foreach (MultiplierMap multiplierMap in administration.MultiplierMaps)
            {
                if (multiplierMap.DesignedFor == activeSetupMap.Name || multiplierMap.DesignedFor == "All")
                {
                    ListViewItem lvi = new ListViewItem(multiplierMap.Name.ToString());
                    lvi.SubItems.Add(multiplierMap.Designer.ToString());
                    lvi.SubItems.Add(multiplierMap.Collection.ToString());
                    lvi.SubItems.Add(multiplierMap.DesignedFor.ToString());
                    listView2.Items.Add(lvi);
                }
                //if (multiplierMap.LatestFavourite) comboBox_MultiplierMapSelector.Items.Add(multiplierMap.Name.ToString());
            }

            foreach (Preset preset in administration.Presets)
            {
                if (preset.DesignedFor == activeSetupMap.Name || preset.DesignedFor == "All")
                {
                    ListViewItem lvi = new ListViewItem(preset.Name.ToString());
                    lvi.SubItems.Add(preset.Designer.ToString());
                    lvi.SubItems.Add(preset.Collection.ToString());
                    lvi.SubItems.Add(preset.DesignedFor.ToString());
                    listView_Presets.Items.Add(lvi);
                }
                //if (preset.LatestFavourite) comboBox_PresetSelector.Items.Add(preset.Name.ToString());
            }

            listView2.Items.Clear();
            foreach (MultiplierMap multiplierMap in administration.MultiplierMaps)
            {
                if (multiplierMap.Name.Contains(textBox1.Text) || multiplierMap.Designer.Contains(textBox1.Text) || multiplierMap.DesignedFor.Contains(textBox1.Text) || multiplierMap.Collection.Contains(textBox1.Text) || textBox1.Text == "")
                {
                    ListViewItem lvi = new ListViewItem(multiplierMap.Name.ToString());
                    lvi.SubItems.Add(multiplierMap.Designer.ToString());
                    lvi.SubItems.Add(multiplierMap.Collection.ToString());
                    lvi.SubItems.Add(multiplierMap.DesignedFor.ToString());
                    listView2.Items.Add(lvi);
                }
            }
            listView2.Update();


            listView_Presets.Items.Clear();
            foreach (Preset preset in administration.Presets)
            {
                if (preset.Name.Contains(textBox2.Text) || preset.Designer.Contains(textBox2.Text) || preset.DesignedFor.Contains(textBox2.Text) || preset.Collection.Contains(textBox2.Text) || textBox2.Text == "")
                {
                    ListViewItem lvi = new ListViewItem(preset.Name.ToString());
                    lvi.SubItems.Add(preset.Designer.ToString());
                    lvi.SubItems.Add(preset.Collection.ToString());
                    lvi.SubItems.Add(preset.DesignedFor.ToString());
                    listView_Presets.Items.Add(lvi);
                }
            }
            listView_Presets.Update();
        }
        private void drawSomeTrianglesV2() //Draw everything in the panel preview window
        {
            Graphics graphics = panel2.CreateGraphics();
            Pen pen = new Pen(Brushes.Black, 2);
            SolidBrush solidBrush = new SolidBrush(Color.Transparent);

            Point v1 = new Point(0, 0);
            Point v2 = new Point(0, 0);
            Point v3 = new Point(0, 0);


            bool upsideDown = true;
            for (byte yPlaces = 0; yPlaces < 4; yPlaces++)
            {
                for (byte xPlaces = 0; xPlaces < 7; xPlaces++)
                {
                    byte panelCounterpartNumber = activeSetupMap.Map[yPlaces, xPlaces];
                    Panel foundPanel = administration.getPanel(panelCounterpartNumber);
                    if (foundPanel != null)
                    {
                        pen.Color = Color.FromArgb(255, 255, 255);
                        //solidBrush.Color = Color.FromArgb(foundPanel.RedValue, foundPanel.GreenValue, foundPanel.BlueValue);
                    }
                    else
                    {
                        pen.Color = Color.FromArgb(0, 0, 0);
                        solidBrush.Color = Color.Transparent;
                    }

                    if (upsideDown)
                    {
                        v1.X = (xPlaces * (trianglesize)) + (int)(trianglesize / 2);
                        v1.Y = (yPlaces * (int)(1.5 * trianglesize)) + trianglesize;

                        v2.X = (xPlaces * (trianglesize));
                        v2.Y = (yPlaces * (int)(1.5 * trianglesize));

                        v3.X = (xPlaces * (trianglesize)) + trianglesize;
                        v3.Y = (yPlaces * (int)(1.5 * trianglesize));

                        upsideDown = false;
                    }
                    else
                    {
                        v1.X = (xPlaces * (trianglesize)) + (int)(trianglesize / 2); ;
                        v1.Y = (yPlaces * (int)(1.5 * trianglesize));

                        v2.X = (xPlaces * (trianglesize)) + 0;
                        v2.Y = (yPlaces * (int)(1.5 * trianglesize)) + trianglesize;

                        v3.X = (xPlaces * (trianglesize)) + trianglesize;
                        v3.Y = (yPlaces * (int)(1.5 * trianglesize)) + trianglesize;

                        upsideDown = true;
                    }



                    graphics.DrawLine(pen, v1, v2);
                    graphics.DrawLine(pen, v3, v2);
                    graphics.DrawLine(pen, v3, v1);
                    graphics.FillPolygon(solidBrush, new Point[] { v1, v2, v3 });

                    //if (foundPanel != null && foundPanel.Changed)
                    {
                        if (upsideDown)
                        {
                            graphics.DrawString("✓", this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y + trianglesize / 10 * 5);
                            graphics.DrawString("✓", this.Font, Brushes.Black, v1.X - trianglesize / 10+1, v1.Y + trianglesize / 10 * 5+1);
                        }
                        else
                        {
                            graphics.DrawString("✓", this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y - trianglesize / 10 * 7);
                            graphics.DrawString("✓", this.Font, Brushes.Black, v1.X - trianglesize / 10+1, v1.Y - trianglesize / 10 * 7+1);
                        }
                    }
                    if (foundPanel != null && comboBox_SystemViewSelector.SelectedIndex != 0)
                    {
                        int effectColourArraySelector = 0;
                        //if (foundPanel.FxType == 0) effectColourArraySelector = 1;

                        if (upsideDown)
                        {
                            switch (comboBox_SystemViewSelector.SelectedIndex)
                            {
                                case 1: //FxType
                                    {
                                        try
                                        {
                                            //graphics.DrawString(effectNumbers[foundPanel.FxType], this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y + trianglesize / 10 * 7);
                                            //graphics.DrawString(effectNumbers[foundPanel.FxType], this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y + trianglesize / 10 * 7 + 1);
                                        }
                                        catch (System.IndexOutOfRangeException)
                                        {
                                            //graphics.DrawString("!Range: " + foundPanel.FxType.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y + trianglesize / 10 * 7);
                                            //graphics.DrawString("!Range: " + foundPanel.FxType.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y + trianglesize / 10 * 7 + 1);
                                        }
                                    }
                                    break;

                                case 2: //FxColour
                                    {
                                        try
                                        {
                                            //graphics.DrawString(effectColours[effectColourArraySelector, foundPanel.FxNumber], this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y + trianglesize / 10 * 7);
                                            //graphics.DrawString(effectColours[effectColourArraySelector, foundPanel.FxNumber], this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y + trianglesize / 10 * 7 + 1);

                                        }
                                        catch (System.IndexOutOfRangeException)
                                        {
                                            //graphics.DrawString("!Range: " + foundPanel.FxNumber.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y + trianglesize / 10 * 7);
                                            //graphics.DrawString("!Range: " + foundPanel.FxNumber.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y + trianglesize / 10 * 7 + 1);
                                        }
                                    }
                                    break;

                                case 3: //FxOffset
                                    {
                                        //graphics.DrawString(foundPanel.FxOffset.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y + trianglesize / 10 * 7);
                                        //graphics.DrawString(foundPanel.FxOffset.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 10 + 1, v1.Y + trianglesize / 10 * 7 + 1);
                                    }
                                    break;

                                case 4: //FxSpeed
                                    {
                                        //graphics.DrawString(foundPanel.FxSpeed.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y + trianglesize / 10 * 7);
                                        //graphics.DrawString(foundPanel.FxSpeed.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 10 + 1, v1.Y + trianglesize / 10 * 7 + 1);
                                    }
                                    break;

                                case 5: //Multipliers
                                    {
                                        //graphics.DrawString(activeMultiplierMap[yPlaces, xPlaces].ToString(), this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y + trianglesize / 10 * 7);
                                        //graphics.DrawString(activeMultiplierMap[yPlaces, xPlaces].ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 10 + 1, v1.Y + trianglesize / 10 * 7 + 1);
                                    }
                                    break;

                            }
                        }
                        else
                        {
                            switch (comboBox_SystemViewSelector.SelectedIndex)
                            {
                                case 1:   //FxType                                                                                                                                                                                                                                                             
                                    {
                                        try
                                        {
                                            //graphics.DrawString(effectNumbers[foundPanel.FxType], this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y - trianglesize);
                                            //graphics.DrawString(effectNumbers[foundPanel.FxType], this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y - trianglesize + 1);
                                        }
                                        catch (System.IndexOutOfRangeException)
                                        {
                                            //graphics.DrawString("!Range: " + foundPanel.FxType.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y - trianglesize);
                                            //graphics.DrawString("!Range: " + foundPanel.FxType.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y - trianglesize + 1);
                                        }
                                    }
                                    break;

                                case 2: //FxColour
                                    {
                                        try
                                        {
                                            //graphics.DrawString(effectColours[effectColourArraySelector, foundPanel.FxNumber], this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y - trianglesize);
                                            //graphics.DrawString(effectColours[effectColourArraySelector, foundPanel.FxNumber], this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y - trianglesize + 1);
                                        }
                                        catch (System.IndexOutOfRangeException)
                                        {
                                            //graphics.DrawString("!Range: " + foundPanel.FxNumber.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 3, v1.Y - trianglesize);
                                            //graphics.DrawString("!Range: " + foundPanel.FxNumber.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 3 + 1, v1.Y - trianglesize + 1);
                                        }
                                    }
                                    break;

                                case 3: //FxOffset
                                    {
                                        //graphics.DrawString(foundPanel.FxOffset.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y - trianglesize);
                                        //graphics.DrawString(foundPanel.FxOffset.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 10 + 1, v1.Y - trianglesize + 1);
                                    }
                                    break;

                                case 4: //FxSpeed
                                    {
                                        //graphics.DrawString(foundPanel.FxSpeed.ToString(), this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y - trianglesize);
                                        //graphics.DrawString(foundPanel.FxSpeed.ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 10 + 1, v1.Y - trianglesize + 1);
                                    }
                                    break;

                                case 5: //Multipliers
                                    {
                                        //graphics.DrawString(activeMultiplierMap[yPlaces, xPlaces].ToString(), this.Font, Brushes.White, v1.X - trianglesize / 10, v1.Y - trianglesize);
                                        //graphics.DrawString(activeMultiplierMap[yPlaces, xPlaces].ToString(), this.Font, Brushes.Black, v1.X - trianglesize / 10 + 1, v1.Y - trianglesize + 1);
                                    }
                                    break;

                            }

                        }

                    }

                }
            }
        }
        private void visibilityManager(object sender, EventArgs e) //Makes sure the visibility of all components in the form is correct
        {
            if (customColoursChecked)
            {
                typeChecked = false;
                colourChecked = false;
                backgroundChecked = false;
                offsetChecked = false;
                speedChecked = false;
                zoneChecked = false;
                //panel_PanelCustomColour.Visible = true;
                //numericUpDown_RedValue.Visible = true;
                //numericUpDown_GreenValue.Visible = true;
                //numericUpDown_BlueValue.Visible = true;
                //label_RGB.Visible = true;

                //button_Type.Visible = false;
                //button_Colour.Visible = false;
                //button_Background.Visible = false;
                //button_Offset.Visible = false;
                //button_Speed.Visible = false;
                //button_Multiplier.Visible = false;
            }
            else
            {
                //panel_PanelCustomColour.Visible = false;
                //numericUpDown_RedValue.Visible = false;
                //numericUpDown_GreenValue.Visible = false;
                //numericUpDown_BlueValue.Visible = false;
                //label_RGB.Visible = false;

                //button_Type.Visible = true;
                //button_Colour.Visible = true;
                //button_Offset.Visible = true;
                //button_Speed.Visible = true;
                //button_Multiplier.Visible = true;
            }

            if ((comboBox_FxType.SelectedIndex == 4 || comboBox_FxType.SelectedIndex == 5))
            {
            }
            else
            {
                //comboBox_FxBackground.Visible = false;
                backgroundChecked = false;
            }

            if (typeChecked) comboBox_FxType.Visible = true;
            else comboBox_FxType.Visible = false;

            if (colourChecked) comboBox_FxColour.Visible = true;
            else comboBox_FxColour.Visible = false;

            if (offsetChecked) numericUpDown_FxOffset.Visible = true;
            else numericUpDown_FxOffset.Visible = false;

            if (speedChecked) numericUpDown_FxSpeed.Visible = true;
            else numericUpDown_FxSpeed.Visible = false;

            //if (offsetChecked && speedChecked) checkbox_Randomiser.Visible = true;
            //else checkbox_Randomiser.Visible = false;

            //if (zoneChecked) numericUpDown_MultiplierNumber.Visible = true;
            //else numericUpDown_MultiplierNumber.Visible = false;
        }
        private void comboBoxManager(object sender, EventArgs e) //Changes the text in the fx colour comboboxes
        {
            //if (comboBox_FxType.SelectedIndex == 0 && button_Colour.Text != "Effect")
            {
                comboBox_FxColour.Text = "";
                comboBox_FxColour.Items.Clear();
                comboBox_FxColour.Items.Add("Off");
                comboBox_FxColour.Items.Add("Rainbow");
                comboBox_FxColour.Items.Add("Synthbow");
                comboBox_FxColour.Items.Add("Strobe");
                comboBox_FxColour.Items.Add("Fire");
                comboBox_FxColour.Items.Add("Sound");
                comboBox_FxColour.Items.Add("Christmas");

                //button_Colour.Text = "Number";
            }
            //else if (button_Colour.Text != "Colour")
            {
                comboBox_FxColour.Text = "";
                comboBox_FxColour.Items.Clear();
                comboBox_FxColour.Items.Add("White");
                comboBox_FxColour.Items.Add("Red");
                comboBox_FxColour.Items.Add("Orange");
                comboBox_FxColour.Items.Add("Green");
                comboBox_FxColour.Items.Add("Cyan");
                comboBox_FxColour.Items.Add("Blue");
                comboBox_FxColour.Items.Add("Violet");
                comboBox_FxColour.Items.Add("Colour Cycle");

                //button_Colour.Text = "Colour";
            }
            visibilityManager(sender, e);
        }
        private void comboBox_SystemViewSelector_SelectedIndexChanged(object sender, EventArgs e) //update the panel preview panel when the combobox underneath it changes
        {
            drawSomeTrianglesV2();
        }

        //Editing data of panels
        private void editAllPanels(object sender, EventArgs e) //Change all panels based on the settings in the paintbrush
        {
            foreach (Panel panel in administration.Panels)
            {
                //bool changesMadeTemp = panel.changePanel(customColoursChecked, (byte)numericUpDown_RedValue.Value, (byte)numericUpDown_GreenValue.Value, (byte)numericUpDown_BlueValue.Value, (byte)comboBox_FxBackground.SelectedIndex, comboBox_FxType.SelectedIndex, comboBox_FxColour.SelectedIndex, (byte)numericUpDown_FxSpeed.Value, (byte)numericUpDown_FxOffset.Value, activeSetupMap, activeMultiplierMap, checkbox_Randomiser.Checked, button_Background.Visible, typeChecked, colourChecked, speedChecked, offsetChecked);
                //if (changesMadeTemp && !changesMade) changesMade = true;
                //if (presetLoaded && !presetChangesMade && changesMadeTemp) presetChangesMade = true;
            }
            if (administration.brokenDataTester())MessageBox.Show("Hey one of the panels has been set up with an incorrect Effect Type or Effect Colour/Number.\nCheck the previews to fix a specific panel or re-apply changes to all panels.", "Panel Error Detected");
            drawSomeTrianglesV2();
        }
        private void editSinglePanelFromBoard(object sender, EventArgs e) //Change one panel selected from the preview panel, based on the settings from the paintbrush
        {

            Point locationOnForm = panel2.FindForm().PointToScreen(panel2.Location);
            int xPos = (int)MousePosition.X - locationOnForm.X - 93;
            int yPos = (int)MousePosition.Y - locationOnForm.Y - 12;
            int xTimes = (int)(xPos / trianglesize);
            int yTimes = (int)(yPos / (trianglesize * 1.5));


            byte panelAdress = activeSetupMap.Map[yTimes, xTimes];
            //if (zoneChecked) activeMultiplierMap[yTimes, xTimes] = (byte)numericUpDown_MultiplierNumber.Value;

            //bool changesMadeTemp = administration.getPanel(panelAdress).changePanel(customColoursChecked, (byte)numericUpDown_RedValue.Value, (byte)numericUpDown_GreenValue.Value, (byte)numericUpDown_BlueValue.Value, (byte)comboBox_FxBackground.SelectedIndex, comboBox_FxType.SelectedIndex, comboBox_FxColour.SelectedIndex, (byte)numericUpDown_FxSpeed.Value, (byte)numericUpDown_FxOffset.Value, activeSetupMap, activeMultiplierMap, checkbox_Randomiser.Checked, button_Background.Visible, typeChecked, colourChecked, speedChecked, offsetChecked);
            //if (changesMadeTemp && !changesMade) changesMade = true;
            //if (presetLoaded && !presetChangesMade && changesMadeTemp) presetChangesMade = true;

            if (administration.brokenDataTester()) MessageBox.Show("Hey one of the panels has been set up with an incorrect Effect Type or Effect Colour/Number.\nCheck the previews to fix a specific panel or re-apply changes to all panels.", "Panel Error Detected");
            drawSomeTrianglesV2();
        }
        private void button_ChangeMultiplier_Click(object sender, EventArgs e)//Change all panels in one zone, based on the settings from the paintbrush
        {
            try
            {
                for (byte yPlaces = 0; yPlaces < 4; yPlaces++)
                {
                    for (byte xPlaces = 0; xPlaces < 7; xPlaces++)
                    {
                        byte panelCounterpartNumber = activeMultiplierMap[yPlaces, xPlaces];
                        //if (panelCounterpartNumber == numericUpDown_MultiplierSelector.Value)
                        {
                            //bool changesMadeTemp = administration.getPanel(activeSetupMap.Map[yPlaces, xPlaces]).changePanel(customColoursChecked, (byte)numericUpDown_RedValue.Value, (byte)numericUpDown_GreenValue.Value, (byte)numericUpDown_BlueValue.Value, (byte)comboBox_FxBackground.SelectedIndex, comboBox_FxType.SelectedIndex, comboBox_FxColour.SelectedIndex, (byte)numericUpDown_FxSpeed.Value, (byte)numericUpDown_FxOffset.Value, activeSetupMap, activeMultiplierMap, checkbox_Randomiser.Checked, button_Background.Visible, typeChecked, colourChecked, speedChecked, offsetChecked);
                            //if (changesMadeTemp && !changesMade) changesMade = true;
                            //if (presetLoaded && !presetChangesMade && changesMadeTemp) presetChangesMade = true;
                        }
                    }
                }
                if (administration.brokenDataTester()) MessageBox.Show("Hey one of the panels has been set up with an incorrect Effect Type or Effect Colour/Number.\nCheck the previews to fix a specific panel or re-apply changes to all panels.", "Panel Error Detected");
                drawSomeTrianglesV2();
            }
            catch (System.NullReferenceException)
            {
                MessageBox.Show("You may have tried to apply effects on a multiplier layer that does not exist");
            }
        }
        private void paintMixer(object sender, EventArgs e)//Make a little preview from the custom rgb colours
        {
            //numericUpDown_RedValue.BackColor = Color.FromArgb((int)numericUpDown_RedValue.Value, 0, 0);
            //numericUpDown_GreenValue.BackColor = Color.FromArgb(0, (int)numericUpDown_GreenValue.Value, 0);
            //numericUpDown_BlueValue.BackColor = Color.FromArgb(0, 0, (int)numericUpDown_BlueValue.Value);

            //panel_PanelCustomColour.BackColor = Color.FromArgb((int)numericUpDown_RedValue.Value, (int)numericUpDown_GreenValue.Value, (int)numericUpDown_BlueValue.Value);
        }

        //Visual mode switch buttons
        private void switchTab(object sender, EventArgs e) //Show the setup menu
        {
            if (sender == BTN_setup)
            {
                groupBox_Setup.Visible = true;
                groupBox_Editor.Visible = false;
                groupBox_Presets.Visible = false;
            }
            if (sender == BTN_editor)
            {
                groupBox_Setup.Visible = false;
                groupBox_Editor.Visible = true;
                groupBox_Presets.Visible = false;
            }
            if (sender == BTN_presets)
            {
                groupBox_Setup.Visible = false;
                groupBox_Editor.Visible = false;
                groupBox_Presets.Visible = true;
            }
        }

        //Buttons
        private void button_Offset_Click(object sender, EventArgs e) //Paintbrush button click
        {
            if (offsetChecked) offsetChecked = false;
            else offsetChecked = true;
            visibilityManager(sender, e);
        }
        private void button_Speed_Click(object sender, EventArgs e) //Paintbrush button click
        {
            if (speedChecked) speedChecked = false;
            else speedChecked = true;
            visibilityManager(sender, e);
        }
        private void button_Multiplier_Click(object sender, EventArgs e) //Paintbrush button click
        {
            if (zoneChecked) zoneChecked = false;
            else zoneChecked = true;
            visibilityManager(sender, e);
        }
        private void button_Type_Click(object sender, EventArgs e) //Paintbrush button click
        {
            if (typeChecked) typeChecked = false;
            else typeChecked = true;
            visibilityManager(sender, e);
        }
        private void button_Colour_Click(object sender, EventArgs e) //Paintbrush button click
        {
            if (colourChecked) colourChecked = false;
            else colourChecked = true;
            visibilityManager(sender, e);
        }
        private void button_CustomColours_Click(object sender, EventArgs e) //Paintbrush button click
        {
            if (customColoursChecked) customColoursChecked = false;
            else customColoursChecked = true;
            visibilityManager(sender, e);
        }

        //Very random stuff
        private void numericUpDown_MultiplierSelector_ValueChanged(object sender, EventArgs e) //Scroll through the change zone thingy
        {
            //button_ChangeMultiplier.Text = "Change all in zone " + numericUpDown_MultiplierSelector.Value;
        }
        void importFiles()
        {
            try
            {
                administration.importPresets();
                administration.importSetupMaps();
                administration.importMultiplierMaps();
                autoLoadFavLocmap();

                updateLists();
            }
            catch (System.IO.DirectoryNotFoundException)
            {
                administration.createFoldersAndFiles();
                if (!triedOnce)
                {
                    importFiles();
                }
                triedOnce = true;
            }
        }
        void autoLoadFavLocmap()
        {
            //Importing Fav
            foreach (SetupMap setupMap in administration.SetupMaps)
            {
                if (setupMap.LatestFavourite)
                {
                    activeSetupMap = setupMap;

                    MultiplierMap multiplierMap = administration.getMultiplierMap("Panel Order");
                    multiplierMap.Map = setupMap.Map;

                    autoloadSuccessful = true;
                    //comms.SetupMapClearance = true;
                }
            }
        }


        //Presets
        private void button_CreatePreset_Click(object sender, EventArgs e) //Create preset button
        {
            if (textBox_PresetName.Text == "" || textBox_PresetCreator.Text == "" || textBox_PresetCollection.Text == "")
            {
                DialogResult dialogResult = MessageBox.Show("Not all data has been entered, create preset anyway?", "Incomplete Data", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes)
                {
                    createPreset();
                }
            }
            else
            {
                createPreset();
            }
        }
        private void createPreset() //Creates a new preset
        {
                Preset preset = new Preset(textBox_PresetName.Text, textBox_PresetCreator.Text, textBox_PresetCollection.Text, activeSetupMap.Name, (byte)numericUpDown_brightness.Value, (byte)numericUpDown_millisDelay.Value);
                foreach (Panel panel in administration.Panels)
                {
                    //preset.PresetPanels.Add(new Panel(panel.PanelNumber, panel.FxOffset, panel.FxSpeed, panel.FxType, panel.FxNumber, panel.RedValue, panel.GreenValue, panel.BlueValue));
                }
            if (!administration.AddPreset(preset))
            {
                DialogResult dialogResult = MessageBox.Show("This Preset already exists. Do you want to update the creator and collection data of the existing Preset?", "Preset Already Exists", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes)
                {
                    Preset presetToReplace = administration.FindPreset(preset.Name);
                    presetToReplace.Designer = preset.Designer;
                    presetToReplace.DesignedFor = preset.DesignedFor;
                    presetToReplace.Collection = preset.Collection;
                }
            }
            else
            {
                textBox_PresetName.Text = "";
                textBox_PresetCreator.Text = "";
                textBox_PresetCollection.Text = "";
            }
            updateLists();
            administration.exportPresetToJason(preset, @"Presets\");
            
        }
        private void favouriteNewPreset(object sender, EventArgs e) //Adds a preset to the favourites
        {
            if (doublePresetApplyPreventor) doublePresetApplyPreventor = false;
            else
            {
                if (listView_Presets.SelectedItems.Count != 0 && !(listView_Presets.SelectedItems.Count > 1))
                {
                    Preset preset = administration.FindPreset(listView_Presets.SelectedItems[0].Text);
                    listView_Presets.SelectedItems.Clear();

                    if (preset.LatestFavourite)
                    {
                        preset.LatestFavourite = false;
                        //if (comboBox_PresetSelector.Text == preset.Name) comboBox_PresetSelector.Text = "Get more from presets tab";
                    }
                    else
                    {
                        preset.LatestFavourite = true;
                    }
                    doublePresetApplyPreventor = true;

                    administration.exportPresetToJason(preset, @"Presets\");
                    updateLists();
                }
           }
        }

        //MultiplierMaps
        private void button_CreateMultiplierMap_Click(object sender, EventArgs e) //Creating a new zone map from the presets window
        {
            bool createMultiplierMapPermission = false;

            if (textBox_MultiplierMapName.Text == "" || textBox_MultiplierMapCreator.Text == "" || textBox_MultiplierMapCollection.Text == "")
            {
                DialogResult dialogResult = MessageBox.Show("Not all data has been entered, create zone map anyway?", "Incomplete Data", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes) createMultiplierMapPermission = true;
                
            }
            else createMultiplierMapPermission = true;


            if (createMultiplierMapPermission)
            {
                MultiplierMap multiplierMap = new MultiplierMap(textBox_MultiplierMapName.Text, textBox_MultiplierMapCreator.Text, textBox_MultiplierMapCollection.Text, activeSetupMap.Name, activeMultiplierMap);

                if (!administration.AddMultiplierMap(multiplierMap))
                {
                    DialogResult dialogResult = MessageBox.Show("This Multiplier Map already exists. Do you want to update the creator and collection data of the existing Multiplier Map?", "Multiplier Map Already Exists", MessageBoxButtons.YesNo);
                    if (dialogResult == DialogResult.Yes)
                    {
                        MultiplierMap multiplierMapToReplace = administration.getMultiplierMap(multiplierMap.Name);
                        multiplierMapToReplace.Designer = multiplierMap.Designer;
                        multiplierMapToReplace.DesignedFor = multiplierMap.DesignedFor;
                        multiplierMapToReplace.Collection = multiplierMap.Collection;
                    }
                }
                else
                {
                    textBox_MultiplierMapName.Text = "";
                    textBox_MultiplierMapCreator.Text = "";
                    textBox_MultiplierMapCollection.Text = "";
                }
                updateLists();
                //administration.exportToJason(multiplierMap, @"Multiplier Maps\");
                multiplierMap.exportToJason();
            }
            
        }
        private void favouriteNewMultiplierMap(object sender, EventArgs e)//Favourites a zone map
        {
            if (listView2.SelectedItems.Count != 0 && !(listView2.SelectedItems.Count > 1))
            {
                MultiplierMap multiplierMap = administration.getMultiplierMap(listView2.SelectedItems[0].Text);
                if (multiplierMap.LatestFavourite)
                {
                    multiplierMap.LatestFavourite = false;
                    //if (comboBox_MultiplierMapSelector.Text == multiplierMap.Name) comboBox_MultiplierMapSelector.Text = "Get more from presets tab";
                }
                else
                {
                    multiplierMap.LatestFavourite = true;
                }
                updateLists();
                //administration.exportToJason(multiplierMap, @"Multiplier Maps\");
                multiplierMap.exportToJason();
            }
        }

        
    }
}
