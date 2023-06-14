using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System.IO.Ports;
using System.Threading;

namespace Trinity
{

    public struct Transmission_Panel
    {
        public byte number;
        public byte compassDir;
        public bool clockDir;
        public byte diodeAmount;

        public byte brightness;
        public byte effect;
        public byte colour;
        public byte offset;
        public byte speed;
        public bool repeat;
        public bool detailed;

        public byte r;
        public byte g;
        public byte b;
    };
    public struct Transmission_Diode
    {
        public byte panelNumber;
        public byte number;

        public byte brightness;
        public byte effect;
        public byte colour;
        public byte offset;
        public byte speed;
        public bool repeat;

        public byte r;
        public byte g;
        public byte b;
    };
    public struct Transmission_LedManager
    {
        public byte brightness;
        public byte speed;
        public bool enabled;
    };
}
