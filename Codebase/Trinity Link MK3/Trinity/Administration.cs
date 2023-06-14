using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using Newtonsoft.Json;

namespace Trinity
{

    public class Administration
    {
        string[] EffectNumbers { get; set; }
        string[,] EffectColours { get; set; }
        string FileDirectory { get; set; }

        private const byte XPOSITIONS = 7;
        private const byte YPOSITIONS = 4;

        public List<Preset> Presets = new List<Preset>();
        public List<Panel> Panels = new List<Panel>();
        public List<SetupMap> SetupMaps = new List<SetupMap>();
        public List<MultiplierMap> MultiplierMaps = new List<MultiplierMap>();



        public Administration(string directory, string[] effectNumbers, string[,] effectColours)//Constructor
        {
            FileDirectory = directory;
            EffectNumbers = effectNumbers;
            EffectColours = effectColours;
        }

        /*--------------------MISC STUFF--------------------*/
        public void interpretPanelTransmission(Panel receivedPanel)//Takes the information taken from the serial monitor and makes/updates panels.
        {

            //Panel foundPanel = getPanel(receivedPanel.PanelNumber);
            //if (foundPanel == null) AddPanel(receivedPanel);
            //else
            {
               // foundPanel.UpdatePanel(receivedPanel.PanelNumber, receivedPanel.FxOffset, receivedPanel.FxSpeed, receivedPanel.FxType, receivedPanel.FxNumber, receivedPanel.RedValue, receivedPanel.GreenValue, receivedPanel.BlueValue);
                //foundPanel.Changed = false;
            }
            //receivedPanel.Changed = false;
        }
        public bool brokenDataTester() //Tests if broken data has been added to one of the panels.
        {
            string invisiString = "";
            foreach (Panel panel in Panels)
            {
                try
                {
                    byte effectColourArraySelector = 0;
                    //if (panel.FxType == 0) effectColourArraySelector = 1;

                    //invisiString = EffectNumbers[panel.FxType];
                    //invisiString = EffectColours[effectColourArraySelector, panel.FxNumber];
                }
                catch (System.IndexOutOfRangeException)
                {
                    return true;
                }
            }
            return false;
        }
        public void createFoldersAndFiles() //When first starting the program, files and folders need to be created
        {
            Directory.CreateDirectory(FileDirectory + @"Presets\");
            Directory.CreateDirectory(FileDirectory + @"Setup Maps\");
            Directory.CreateDirectory(FileDirectory + @"Multiplier Maps\");


            AddSetupMap(new SetupMap("Hex", "Ask Blommaert", 6, new byte[YPOSITIONS, XPOSITIONS]
            {
                {255, 255, 255, 255, 255, 255, 255},
                {255, 255, 002, 003, 004, 255, 255},
                {255, 255, 001, 000, 005, 255, 255},
                {255, 255, 255, 255, 255, 255, 255}
            }));

            AddSetupMap(new SetupMap("Trinity Prime", "Ask Blommaert", 16, new byte[YPOSITIONS, XPOSITIONS]
            {
                {255, 255, 255, 011, 255, 255, 255},
                {255, 255, 012, 010, 009, 255, 255},
                {255, 014, 013, 015, 008, 007, 255},
                {000, 001, 002, 003, 004, 005, 006}
            }));

            AddSetupMap(new SetupMap("Bill", "Eva van der Made", 4, new byte[YPOSITIONS, XPOSITIONS]
            {
                {255, 255, 255, 255, 255, 255, 255},
                {255, 255, 255, 255, 255, 255, 255},
                {255, 255, 255, 003, 255, 255, 255},
                {255, 255, 000, 001, 002, 255, 255}
            }));

            AddSetupMap(new SetupMap("DualHex", "Liam van Leusden", 10, new byte[YPOSITIONS, XPOSITIONS]
            {
                {255, 255, 255, 255, 255, 255, 255},
                {255, 255, 255, 255, 255, 255, 255},
                {255, 009, 008, 007, 006, 005, 255},
                {255, 000, 001, 002, 003, 004, 255}  
            }));







            MultiplierMap north = new MultiplierMap("North", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {007, 006, 007, 006, 007, 006, 007},
                {004, 005, 004, 005, 004, 005, 004},
                {003, 002, 003, 002, 003, 002, 003},
                {000, 001, 000, 001, 000, 001, 000}
            });
            //exportToJason(north, @"Multiplier Maps\");
            //north.exportFile2(@"Multiplier Maps\", north.ToTextFile());
            north.exportToJason();

            

            MultiplierMap northEast = new MultiplierMap("NorthEast", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {003, 004, 005, 006, 007, 008, 009},
                {002, 003, 004, 005, 006, 007, 008},
                {001, 002, 003, 004, 005, 006, 007},
                {000, 001, 002, 003, 004, 005, 006}
            });
            //exportToJason(northEast, @"Multiplier Maps\");
            //northEast.exportFile2(@"Multiplier Maps\", northEast.ToTextFile());
            northEast.exportToJason();

            MultiplierMap east = new MultiplierMap("East", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 001, 002, 003, 004, 005, 006},
                {000, 001, 002, 003, 004, 005, 006},
                {000, 001, 002, 003, 004, 005, 006},
                {000, 001, 002, 003, 004, 005, 006}
            });
            //exportToJason(east, @"Multiplier Maps\");
            //east.exportFile2(@"Multiplier Maps\", east.ToTextFile());
            east.exportToJason();

            MultiplierMap southEast = new MultiplierMap("SouthEast", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 001, 002, 003, 004, 005, 006},
                {001, 002, 003, 004, 005, 006, 007},
                {002, 003, 004, 005, 006, 007, 008},
                {003, 004, 005, 006, 007, 008, 009}
            });
            //exportToJason(southEast, @"Multiplier Maps\");
            //southEast.exportFile2(@"Multiplier Maps\", southEast.ToTextFile());
            southEast.exportToJason();

            MultiplierMap south = new MultiplierMap("South", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 001, 000, 001, 000, 001, 000},
                {003, 002, 003, 002, 003, 002, 003},
                {004, 005, 004, 005, 004, 005, 004},
                {007, 006, 007, 006, 007, 006, 007}
            });
            //exportToJason(south, @"Multiplier Maps\");
            //south.exportFile2(@"Multiplier Maps\", south.ToTextFile());
            south.exportToJason();

            MultiplierMap southWest = new MultiplierMap("SouthWest", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {007, 006, 005, 004, 003, 002, 001},
                {008, 007, 006, 005, 004, 003, 002},
                {009, 008, 007, 006, 005, 004, 003},
                {010, 009, 008, 007, 006, 005, 004}
            });
            //exportToJason(southWest, @"Multiplier Maps\");
            //southWest.exportFile2(@"Multiplier Maps\", southWest.ToTextFile());
            southWest.exportToJason();

            MultiplierMap west = new MultiplierMap("West", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {006, 005, 004, 003, 002, 001, 000},
                {006, 005, 004, 003, 002, 001, 000},
                {006, 005, 004, 003, 002, 001, 000},
                {006, 005, 004, 003, 002, 001, 000}
            });
            //exportToJason(west, @"Multiplier Maps\");
            //west.exportFile2(@"Multiplier Maps\", west.ToTextFile());
            west.exportToJason();

            MultiplierMap northWest = new MultiplierMap("NorthWest", "Ask Blommaert", "Compass", "All", new byte[YPOSITIONS, XPOSITIONS]
            {
                {009, 008, 007, 006, 005, 004, 003},
                {008, 007, 006, 005, 004, 003, 002},
                {007, 006, 005, 004, 003, 002, 001},
                {006, 005, 004, 003, 002, 001, 000}
            });
            //exportToJason(northWest, @"Multiplier Maps\");
            //northWest.exportFile2(@"Multiplier Maps\", northWest.ToTextFile());
            northWest.exportToJason();

            MultiplierMap implosion = new MultiplierMap("Implosion", "Ask Blommaert", "Nova", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 001, 002, 001, 002, 001, 000},
                {001, 002, 003, 002, 003, 002, 001},
                {002, 003, 004, 005, 004, 003, 002},
                {001, 002, 003, 004, 003, 002, 001}
            });
            //exportToJason(implosion, @"Multiplier Maps\");
            //implosion.exportFile2(@"Multiplier Maps\", implosion.ToTextFile());
            implosion.exportToJason();

            MultiplierMap explosion = new MultiplierMap("Explosion", "Ask Blommaert", "Nova", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {005, 004, 003, 004, 003, 004, 005},
                {004, 003, 002, 003, 002, 003, 004},
                {003, 002, 001, 000, 001, 002, 003},
                {004, 003, 002, 001, 002, 003, 004}
            });
            //exportToJason(explosion, @"Multiplier Maps\");
            //explosion.exportFile2(@"Multiplier Maps\", explosion.ToTextFile());
            explosion.exportToJason();

            MultiplierMap cauldron = new MultiplierMap("Cauldron", "Ask Blommaert", "Rock", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 003, 000, 000, 000},
                {000, 000, 003, 002, 003, 000, 000},
                {000, 003, 002, 001, 002, 003, 000},
                {003, 002, 001, 000, 001, 002, 003}
            });
            //exportToJason(cauldron, @"Multiplier Maps\");
            //cauldron.exportFile2(@"Multiplier Maps\", cauldron.ToTextFile());
            cauldron.exportToJason();

            MultiplierMap cauldronMin = new MultiplierMap("Cauldron-", "Ask Blommaert", "Rock", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 001, 000, 000, 000},
                {000, 000, 001, 002, 001, 000, 000},
                {000, 001, 002, 003, 002, 001, 000}
            });
            //exportToJason(cauldronMin, @"Multiplier Maps\");
            //cauldronMin.exportFile2(@"Multiplier Maps\", cauldronMin.ToTextFile());
            cauldronMin.exportToJason();

            MultiplierMap collapse = new MultiplierMap("Collapse", "Ask Blommaert", "Rock", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 002, 001, 002, 000, 000},
                {000, 004, 003, 002, 003, 004, 000},
                {006, 005, 004, 003, 004, 005, 006}
            });
            //exportToJason(collapse, @"Multiplier Maps\");
            //collapse.exportFile2(@"Multiplier Maps\", collapse.ToTextFile());
            collapse.exportToJason();

            MultiplierMap collapseMin = new MultiplierMap("Collapse-", "Ask Blommaert", "Rock", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 006, 000, 000, 000},
                {000, 000, 004, 005, 004, 000, 000},
                {000, 002, 003, 004, 003, 002, 000},
                {000, 001, 002, 003, 002, 001, 000}
            });
            //exportToJason(collapseMin, @"Multiplier Maps\");
            //collapseMin.exportFile2(@"Multiplier Maps\", collapseMin.ToTextFile());
            collapseMin.exportToJason();

            MultiplierMap miamiBeach = new MultiplierMap("Miami Beach", "Ask Blommaert", "Razor", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {004, 005, 004, 005, 004, 005, 004},
                {003, 002, 003, 002, 003, 002, 003},
                {000, 001, 000, 001, 000, 001, 000},
                {001, 002, 001, 002, 001, 002, 001}
            });
            //exportToJason(miamiBeach, @"Multiplier Maps\");
            //miamiBeach.exportFile2(@"Multiplier Maps\", miamiBeach.ToTextFile());
            miamiBeach.exportToJason();

            MultiplierMap miamiBeachMin = new MultiplierMap("Miami Beach-", "Ask Blommaert", "Razor", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {001, 000, 001, 000, 001, 000, 001},
                {002, 003, 002, 003, 002, 003, 002},
                {005, 004, 005, 004, 005, 004, 005},
                {004, 003, 004, 003, 004, 003, 004}
            });
            //exportToJason(miamiBeachMin, @"Multiplier Maps\");
            //miamiBeachMin.exportFile2(@"Multiplier Maps\", miamiBeachMin.ToTextFile());
            miamiBeachMin.exportToJason();

            MultiplierMap split = new MultiplierMap("Split", "Ask Blommaert", "Razor", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {003, 002, 001, 000, 001, 002, 003},
                {003, 002, 001, 000, 001, 002, 003},
                {003, 002, 001, 000, 001, 002, 003},
                {003, 002, 001, 000, 001, 002, 003}
            });
            //exportToJason(split, @"Multiplier Maps\");
            //split.exportFile2(@"Multiplier Maps\", split.ToTextFile());
            split.exportToJason();

            MultiplierMap splitMin = new MultiplierMap("Split-", "Ask Blommaert", "Razor", "Trinity Prime", new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 001, 002, 003, 002, 001, 000},
                {000, 001, 002, 003, 002, 001, 000},
                {000, 001, 002, 003, 002, 001, 000},
                {000, 001, 002, 003, 002, 001, 000}
            });
            //exportToJason(splitMin, @"Multiplier Maps\");
            //splitMin.exportFile2(@"Multiplier Maps\", splitMin.ToTextFile());
            splitMin.exportToJason();
        }

        

        public void exportPresetToJason(Preset preset, string destination)
        {
                var presetJson = JsonConvert.SerializeObject(preset);



                StreamWriter file = new StreamWriter(FileDirectory + destination + preset.Name + ".JSON");
                file.Write(presetJson);
                file.Close();
        }



        /*--------------------Presets--------------------*/
        public bool AddPreset(Preset preset) //Adds a preset to preset storage, if that preset has not already been created
        {
            if (preset != null)
            {
                Preset presetToAdd = FindPreset(preset.Name);
                if (presetToAdd == null)
                {
                    Presets.Add(preset);
                    return true;
                }
            }
            return false;
        }
        public Preset FindPreset(string name) //Searches though preset storage for a preset, and returns that preset if it has been found.
        {
            foreach (Preset preset in Presets)
            {
                if (preset.Name == name)
                {
                    return preset;
                }
            }
            return null; //Stuurt niets door.
        }
        public Preset updatePreset(string presetName, byte brightness, byte slowness) //Updates data and panel storage of a preset.
        {
            Preset preset = FindPreset(presetName);

            preset.Brightness = brightness;
            preset.Slowness = slowness;

            preset.PresetPanels.Clear();
            foreach (Panel panel in Panels)
            {
                //preset.PresetPanels.Add(new Panel(panel.PanelNumber, panel.FxOffset, panel.FxSpeed, panel.FxType, panel.FxNumber, panel.RedValue, panel.GreenValue, panel.BlueValue));
            }
            return preset;
        }
        public void applyPreset(Preset preset) //Activates a preset and loads in all predetermined data
        {
            Panels.Clear();
            foreach (Panel presetPanel in preset.PresetPanels)
            {
                //Panels.Add(new Panel(presetPanel.PanelNumber, presetPanel.FxOffset, presetPanel.FxSpeed, presetPanel.FxType, presetPanel.FxNumber, presetPanel.RedValue, presetPanel.GreenValue, presetPanel.BlueValue));
            }

            foreach (Panel panel in Panels)
            {
                //panel.Changed = true;
            }
        }
        public void importPresets() //Importing presets
        {
            string[] names = Directory.GetFiles(FileDirectory + @"Presets\");
            for (byte k = 0; k < names.Length; k++)
            {
                var jsonString = File.ReadAllText(names[k]);
                Preset preset = JsonConvert.DeserializeObject<Preset>(jsonString);
                AddPreset(preset);
            }
        }


        /*--------------------Panels--------------------*/
        public bool AddPanel(Panel panel) //Adds a panel to active panel storage, if that panel didn't already exist
        {
            if (panel != null)
            {
                //Panel panelToAdd = getPanel(panel.PanelNumber);
                //if (panelToAdd == null)
                {
                    Panels.Add(panel);
                    return true;
                }
            }
            return false;
        }
        public Panel getPanel(byte panelNumber) //Searches for a panel in active panel storage
        {
            foreach (Panel panel in Panels)
            {
                //if (panel.PanelNumber == panelNumber)
                {
                    return panel;
                }
            }
            return null;
        }


        /*--------------------SetupMaps--------------------*/
        public bool AddSetupMap(SetupMap setupMap) //Adds a location map to storage, if it didn't already exist.
        {
            if (setupMap != null)
            {
                SetupMap setupMapToAdd = FindSetupMap(setupMap.Name);
                if (setupMapToAdd == null)
                {
                    SetupMaps.Add(setupMap);
                    return true;
                }
            }
            return false;
        }
        public SetupMap FindSetupMap(string name) //Searches for a locmap in locmap storage.
        {
            foreach (SetupMap setupMap in SetupMaps)
            {
                if (setupMap.Name == name)
                {
                    return setupMap;
                }
            }
            return null;
        }
        public void importSetupMaps() //Importing setupMap from file
        {
            string[] files = Directory.GetFiles(FileDirectory + @"Setup Maps\");
            for (byte k = 0; k < files.Length; k++)
            {
                var jsonString = File.ReadAllText(files[k]);
                SetupMap setupMap = JsonConvert.DeserializeObject<SetupMap>(jsonString);
                AddSetupMap(setupMap);
            }
        }


        /*--------------------MultiplierMaps--------------------*/
        public bool AddMultiplierMap(MultiplierMap multiplierMap) //Adds a muffmap to storage, if it didn't already exist
        {
            if (multiplierMap != null)
            {
                MultiplierMap multiplierMapToAdd = getMultiplierMap(multiplierMap.Name);
                if (multiplierMapToAdd == null)
                {
                    MultiplierMaps.Add(multiplierMap);
                    return true;
                }
            }
            return false;
        }
        public MultiplierMap getMultiplierMap(string name) //Searches for a muffmap in muffmap storage
        {
            foreach (MultiplierMap multiplierMap in MultiplierMaps) 
            {
                if (multiplierMap.Name == name) 
                {
                    return multiplierMap;
                }
            }
            return null;
        }
        public void importMultiplierMaps() //Importing zone maps
        {
            string[] files = Directory.GetFiles(FileDirectory + @"Multiplier Maps\");
            for (byte k = 0; k < files.Length; k++)
            {
                var jsonString = File.ReadAllText(files[k]);
                MultiplierMap multiplierMap = JsonConvert.DeserializeObject<MultiplierMap>(jsonString);
                AddMultiplierMap(multiplierMap);
            }
        }

    }
}
