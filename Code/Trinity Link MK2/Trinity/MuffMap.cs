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
    public class MultiplierMap : PanelMap
    {
        static private string FileDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + @"\Trinity\");
        private const byte XPOSITIONS = 7;
        private const byte YPOSITIONS = 4;

        public string DesignedFor { get; set; }



        public MultiplierMap(string name, string designer, string collection, string designedFor, byte[,] map)//Constructor
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
            if (map.GetLength(0) != YPOSITIONS)
            {
                throw new ArgumentException("Map array Y Length incorrect", nameof(map.Length));
            }
            if (map.GetLength(1) != XPOSITIONS)
            {
                throw new ArgumentException("Map array X Length incorrect", nameof(map.Length));
            }

            Name = name;
            Designer = designer;
            Collection = collection;
            DesignedFor = designedFor;
            Map = map;
            LatestFavourite = false;



        }



        public override void exportToJason()
        {
            StreamWriter file = new StreamWriter(FileDirectory + @"Multiplier Maps\" + Name + ".JSON");
            file.Write(JsonConvert.SerializeObject(this));
            file.Close();
        }








    }
}
