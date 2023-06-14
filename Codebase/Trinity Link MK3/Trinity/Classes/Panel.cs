using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trinity
{
    public class Panel
    {
        static int AMOUNTOFCOLOURS = 8;


        public List<Diode> diodes = new List<Diode>();

        byte number;
        byte compassDir;
        bool clockDir;
        byte diodeAmount;

        byte brightness;
        byte effect;
        byte colour;
        Int16 offset;
        byte speed;
        bool repeat;
        bool detailed;

        ColourRGB rgb = new ColourRGB();

        byte customRGBAmount;
        ColourRGB[] customRGB = new ColourRGB[AMOUNTOFCOLOURS];

        byte d;
        byte c;
        byte progFx;
        Int16 offsetTimer;
        EffectApplications effectApplications;

        public Panel(byte number, byte compassDir, bool clockDir, byte diodeAmount)
        {
          //diodes = (Diode**) malloc(sizeof(Diode*)* diodeAmount);
          for (byte i = 0; i<diodeAmount; i++)
          {
                addDiode(new Diode(number, i));
          }

          this.number        = number;
          this.compassDir    = compassDir;
          this.clockDir      = clockDir;
          this.diodeAmount   = diodeAmount;
          //this.diodeStart    = 0;  // The coordinate of the first LED

          brightness   = 255;
          effect       = 0;
          colour       = 0;
          offset       = 0;
          speed        = 1;
          //this.rCustom      = 255;
          //this.gCustom      = 255;
          //this.bCustom      = 255;
  
          this.rgb.r                   = 0;
          this.rgb.g                   = 0;
          this.rgb.b                   = 0;
          this.d                   = 0;
          this.progFx       = 0;      // In effect cycling
          this.c  = 0; // Cycles of the whole effect (But with different colourss)
          this.offsetTimer         = 0;
            }

        private Diode getDiode(byte panelNumber) //Searches for a panel in active panel storage
        {
            foreach (Diode diode in diodes)
            {
                if (diode.getNumber() == panelNumber)
                {
                    return diode;
                }
            }
            return null;
        }

        private void addDiode(Diode diodeToAdd)
        {
            Diode existingDiode = getDiode(diodeToAdd.getNumber());
            if (existingDiode == null)
            {
                diodes.Add(diodeToAdd);
                return;
            }
            return;
        }

        public void tick()
        {
            printDebug();


            if (offsetTimer < offset)
            {
                offsetTimer++;
            }
            else
            {
                for (byte i = 0; i < diodeAmount; i++)
                {
                    diodes[i].tick();
                }
            }
        }
        //Setters
        public void setDataFromTransmisison(Transmission_Panel data)
        {
            compassDir = data.compassDir;
            clockDir = data.clockDir;
            diodeAmount = data.diodeAmount;

            brightness = data.brightness;
            effect = data.effect;
            colour = data.colour;
            offset = data.offset;
            speed = data.speed;
            repeat = data.repeat;
            detailed = data.detailed;

            rgb.r = data.r;
            rgb.g = data.g;
            rgb.b = data.b;
    }
        public void setDiodeDataFromTransmisison(Transmission_Diode data)
        {
            Diode existingDiode = getDiode(data.number);
            if (existingDiode == null) //If the diode doesn't exist in the panel (Create new one)
            {
                Diode newDiode = new Diode(data.panelNumber, data.number);
                newDiode.setDataFromTransmission(data);
                addDiode(newDiode);
            }
            else //If the panel exists in the ledmanager (Update it)
            {
                existingDiode.setDataFromTransmission(data);
            }
        }
        //Getters
        public ColourRGB getPanelRGB()
        {
            ColourRGB colourRGB;
            colourRGB.r = (byte)((rgb.r * brightness) / 255);
            colourRGB.g = (byte)((rgb.g * brightness) / 255);
            colourRGB.b = (byte)((rgb.b * brightness) / 255);

            return colourRGB;
        }
        public ColourRGB getDiodeRGB(byte number, byte brightness)
        {
            return diodes[number].getRGB(brightness);
        }
        public byte getDiodeAmount()
        {
            return diodeAmount;
        }
        public byte getNumber()
        {
            return number;
        }
        //Prints and Converts
        public void printDebug()
        {
            Console.WriteLine();
            Console.Write("Panel ");
            Console.WriteLine(number);

            Console.Write("compassDir ");
            Console.Write(compassDir);
            Console.Write(" | clockDir ");
            Console.Write(clockDir);
            Console.Write(" | diodeAmount ");
            Console.Write(diodeAmount);

            Console.Write("brightness ");
            Console.Write(brightness);
            Console.Write(" | effect ");
            Console.Write(effect);
            Console.Write(" | colour ");
            Console.Write(colour);
            Console.Write(" | offset ");
            Console.Write(offset);
            Console.Write(" | speed ");
            Console.WriteLine(speed);


            Console.Write("r ");
            Console.Write(rgb.r);
            Console.Write(" | g ");
            Console.Write(rgb.g);
            Console.Write(" | b ");
            Console.Write(rgb.b);
            Console.Write(" | d ");
            Console.Write(d);
            Console.Write(" | progFx ");
            Console.Write(progFx);
            Console.Write(" | offsetTimer ");
            Console.WriteLine(offsetTimer);

        }
        public string convertToTransmission()
        {
            String data = "";

            data += (char)number;
            data += (char)compassDir;
            data += Convert.ToChar(clockDir);
            data += (char)diodeAmount; // Amount of leds in this panel

            data += (char)brightness;
            data += (char)effect;
            data += (char)colour;
            data += (char)offset;
            data += (char)speed;
            data += Convert.ToChar(repeat);
            data += Convert.ToChar(detailed);

            data += (char)rgb.r;
            data += (char)rgb.g;
            data += (char)rgb.b;

            return data;
        }
        public String convertDiodeToTransmission(byte diodeNumber)
        {
            return diodes[diodeNumber].convertToTransmission();
        }
    }
}
