using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trinity
{
    public class Panel
    {
        public byte PanelNumber { get; set; }

        public byte FxOffset { get; set; }
        public byte FxSpeed { get; set; }
        public byte FxType { get; set; }
        public byte FxNumber { get; set; }

        public byte RedValue { get; set; }
        public byte GreenValue { get; set; }
        public byte BlueValue { get; set; }

        public bool Changed { get; set; }


        public Panel(byte panelNumber, byte fxOffset, byte fxSpeed, byte fxType, byte fxNumber, byte redValue, byte greenValue, byte blueValue)//Constructor
        {
            /*
            if(panelNumber > 15) panelNumber = 15;
            if (fxOffset > 255) fxOffset = 255;
            if (fxSpeed > 31) fxSpeed = 31;
            if (fxType > 15) fxType = 15;
            if (fxNumber > 15) fxNumber = 15;
            if (redValue > 255) redValue = 255;
            if (greenValue > 255) greenValue = 255;
            if (blueValue > 255) blueValue = 255;
            */





            PanelNumber = panelNumber;

            FxOffset = fxOffset;
            FxSpeed = fxSpeed;
            FxType = fxType;
            FxNumber = fxNumber;

            RedValue = redValue;
            GreenValue = greenValue;
            BlueValue = blueValue;
        }
        public bool UpdatePanel(byte panelNumber, byte fxOffset, byte fxSpeed, byte fxType, byte fxNumber, byte redValue, byte greenValue, byte blueValue)//Updates a panel from a couple of pre-determined parameters
        {
            if (PanelNumber == panelNumber)
            {
                FxOffset = fxOffset;
                FxSpeed = fxSpeed;
                FxType = fxType;
                FxNumber = fxNumber;

                RedValue = redValue;
                GreenValue = greenValue;
                BlueValue = blueValue;
                return true;
            }
            return false;
        }
        public bool changePanel(bool customColoursChecked, byte redValue, byte greenValue, byte blueValue, int fxType, int fxColour, byte fxSpeed, byte fxOffset, SetupMap activeSetupMap, byte[,] activeMultiplierMap, bool random, bool typeChecked, bool colourChecked, bool speedChecked, bool offsetChecked)//Updates a panel based upon the settings in the paintbrush
        {
            if (customColoursChecked)
            {
                RedValue = (byte)(redValue / 2);
                GreenValue = (byte)(greenValue / 2);
                BlueValue = (byte)(blueValue / 2);
                FxType = 15;
                FxNumber = 15;

                Changed = true;
                return true;
            }
            else
            {
                int offset = 0;
                byte speed = (byte)fxSpeed;

                for (byte yPlaces = 0; yPlaces < 4; yPlaces++)
                {
                    for (byte xPlaces = 0; xPlaces < 7; xPlaces++)
                    {
                        byte panelCounterpartNumber = activeSetupMap.Map[yPlaces, xPlaces];
                        if (panelCounterpartNumber == PanelNumber)
                        {
                            offset = ((activeMultiplierMap[yPlaces, xPlaces]) * fxOffset);
                        }
                    }
                }
                if (random)
                {
                    speed = GetSomeRandomNumber(1, speed);
                    offset = GetSomeRandomNumber(0, offset);
                }
                if (typeChecked) FxType = (byte)(fxType);
                if (colourChecked) FxNumber = (byte)fxColour;
                if (speedChecked) FxSpeed = speed;
                if (offsetChecked) FxOffset = (byte)offset;

                if (typeChecked || colourChecked || speedChecked || offsetChecked)
                {
                    Changed = true;
                    return true;
                }
            }
            return false;
        }
        public override string ToString() //Converts a panel into human-readable text
        {

            string panelStringToSend = "/ "
                + PanelNumber
                + " / "
                + FxOffset + ", "
                + FxSpeed + ", "
                + FxType + ", "
                + FxNumber
                + " / "
                + RedValue + ", "
                + GreenValue + ", "
                + BlueValue
                + " /";

            return panelStringToSend;
        }
        public string ToCommand() //Converts a panel into a serial-transmittable command
        {
            string panelStringToSend = "Panel"
                + (char)PanelNumber
                + (char)FxType
                + (char)FxNumber
                + (char)FxOffset
                + (char)FxSpeed
                + "Clear";
                

            return panelStringToSend;
        }


        //Stuff required for a randomiser
        private static Random random = new Random();
        public static byte GetSomeRandomNumber(int min, int max)
        {
            return (byte)random.Next(min, max);
        }
    }
}
