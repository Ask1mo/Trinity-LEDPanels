using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using Newtonsoft.Json;

namespace Trinity
{
    public class SetupMap : PanelMap
    {
        static private string FileDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + @"\Trinity\");

        private const byte XPOSITIONS = 7;
        private const byte YPOSITIONS = 4;

        public byte AmountOfPanels { get; set; }

        public SetupMap(string name, string designer, byte amountOfPanels, byte[,] map)//Constructor
        {
            Name = name;
            Designer = designer;
            AmountOfPanels = amountOfPanels;
            Map = map;
        }


        public override void exportToJason()
        {
            StreamWriter file = new StreamWriter(FileDirectory + @"Setup Maps\" + Name + ".JSON");
            file.Write(JsonConvert.SerializeObject(this));
            file.Close();
        }
    }
}
