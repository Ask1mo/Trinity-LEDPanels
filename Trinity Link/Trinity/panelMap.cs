using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using Newtonsoft.Json;

namespace Trinity
{
    public abstract class PanelMap : ISavable
    {
        

        public byte[,] Map { get; set; }
        public string Name { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }
        public string Designer { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }
        public string Collection { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }
        public bool LatestFavourite { get/* => throw new NotImplementedException()*/; set/* => throw new NotImplementedException()*/; }



        public abstract void exportToJason();
    }
}

