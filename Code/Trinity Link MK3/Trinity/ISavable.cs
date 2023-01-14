using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

namespace Trinity
{
    interface ISavable
    {
        string Name { get; set; }
        string Designer { get; set; }
        string Collection { get; set; }
        bool LatestFavourite { get; set; }

        void exportToJason();
    }
}
