using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using Newtonsoft.Json;

namespace Trinity
{
    [Serializable]
    public class Preset : ISavable
    {
        static private string FileDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + @"\Trinity\");


        
        public string Name { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }
        public string Designer { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }
        public string Collection { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }
        public bool LatestFavourite { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }

        public string DesignedFor { get; set; }
        public byte Brightness { get; set; }
        public byte Slowness { get; set; }


        public List<Panel> PresetPanels = new List<Panel>();

        public Preset(string name, string designer, string collection, string designedFor, byte brightness, byte slowness)//Constructor
        {
            if (name == "")
            {
                name = "noName";
            }
            if (designer == "")
            {
                designer = "noDesigner";
            }
            if (collection == "")
            {
                collection = "noCollection";
            }
            if (designedFor == "")
            {
                throw new ArgumentException("DesignedFor is not defined", nameof(designedFor));
            }

            Name = name;
            Designer = designer;
            Collection = collection;
            DesignedFor = designedFor;

            Brightness = brightness;
            Slowness = slowness;

            LatestFavourite = false;
        }

        public bool AddPresetPanel(Panel panel)//Add a panel from a preset and add it to active panel storage
        {
            if (panel != null)
            {
                Panel panelToAdd = FindPresetPanel(panel.PanelNumber); 
                if (panelToAdd == null)
                {
                    PresetPanels.Add(panel);
                    return true; 
                }
            }
            return false;
        }
        public Panel FindPresetPanel(byte panelNumber) //Finds a panel stored in a preset
        {
            foreach (Panel panel in PresetPanels)
            {
                if (panel.PanelNumber == panelNumber)
                {
                    return panel;
                }
            }
            return null;
        }


        public void exportToJason()
        {
            StreamWriter file = new StreamWriter(FileDirectory + @"Presets\" + Name + ".JSON");
            file.Write(JsonConvert.SerializeObject(this));
            file.Close();
        }
    }
}
