using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trinity
{
    public class Diode
    {
        const int AMOUNTOFCOLOURS = 8;

        const byte EFFECT_STOCK_const           = 0;
        const byte EFFECT_STOCK_BLINK            = 1;
        const byte EFFECT_STOCK_PLANE            = 2;
        const byte EFFECT_STOCK_BREATHING        = 3;
        const byte EFFECT_STOCK_PAUSEDBREATHING  = 4;
        const byte EFFECT_STOCK_FLASH            = 5;
        const byte EFFECT_STOCK_PAUSEDFLASH      = 6;
        const byte EFFECT_STOCK_HEARTBEAT        = 7;
        const byte EFFECT_STOCK_APPEAR           = 8;
        const byte EFFECT_CUSTOM_const          = 9;
        const byte EFFECT_CUSTOM_BLINK           = 10;
        const byte EFFECT_CUSTOM_PLANE           = 11;
        const byte EFFECT_CUSTOM_BREATHING       = 12;
        const byte EFFECT_CUSTOM_PAUSEDBREATHING = 13;
        const byte EFFECT_CUSTOM_FLASH           = 14;
        const byte EFFECT_CUSTOM_PAUSEDFLASH     = 15;
        const byte EFFECT_CUSTOM_HEARTBEAT       = 16;
        const byte EFFECT_SPECIAL_RAINBOW        = 17;
        const byte EFFECT_SPECIAL_FIRE           = 18;
        const byte EFFECT_SPECIAL_SOUND          = 19;

        const byte COLOUR_BLACK    = 0;
        const byte COLOUR_RED      = 1;
        const byte COLOUR_YELLOW   = 2;
        const byte COLOUR_GREEN    = 3;
        const byte COLOUR_CYAN     = 4;
        const byte COLOUR_BLUE     = 5;
        const byte COLOUR_VIOLET   = 6;
        const byte COLOUR_WHITE    = 7;
        const byte COLOUR_CYCLE    = 8;

        byte panelNumber;
        byte number;

        byte brightness;
        byte effect;
        byte colour;
        Int16 offset;
        byte speed;
        bool repeat;

        ColourRGB rgb = new ColourRGB();
        byte customRGBAmount;
        ColourRGB[] customRGB = new ColourRGB[AMOUNTOFCOLOURS];

        byte d;
        byte c;
        byte progFx;
        Int16 offsetTimer;
        EffectApplications effectApplications = new EffectApplications();


        public Diode(byte panelNumber, byte number)
        {
            this.number = number;
            
            brightness  = 255;
            effect      = new byte();
            colour      = new byte();
            effect      = 0;
            colour      = 0;
            offset      = 0;
            speed       = 1;

            for (byte i = 0; i<AMOUNTOFCOLOURS; i++)
            {
                customRGB[i].r = 255;
                customRGB[i].g = 63;
                customRGB[i].b = 127;
                //These are some preset empty colours for the custom RGB values.
            }
            rgb.r           = 0;
            rgb.g           = 0;
            rgb.b           = 0;
            d               = 0;
            c               = 0;
            progFx          = 0;          //In effect cycling
            offsetTimer     = 0;
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
                for (byte i = 0; i < speed; i++)
                {
                    if (colour != COLOUR_CYCLE)
                    {
                        c = colour;
                    }


                    bool effectFinished = false;
                    switch (effect)
                    {
                        case EFFECT_STOCK_const:
                            effectFinished = effectApplications.stock_static(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_BLINK:
                            effectFinished = effectApplications.stock_blink(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_PLANE:
                            effectFinished = effectApplications.stock_plane(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_BREATHING:
                            effectFinished = effectApplications.stock_breathing(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_PAUSEDBREATHING:
                            effectFinished = effectApplications.stock_pausedbreathing(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_FLASH:
                            effectFinished = effectApplications.stock_flash(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_PAUSEDFLASH:
                            effectFinished = effectApplications.stock_pausedFlash(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_HEARTBEAT:
                            effectFinished = effectApplications.stock_heartbeat(rgb, d, progFx, c);
                            break;

                        case EFFECT_STOCK_APPEAR:
                            effectFinished = effectApplications.stock_appear(rgb, d, progFx, c);
                            break;

                        case EFFECT_SPECIAL_RAINBOW:
                            effectFinished = effectApplications.special_rainbow(rgb, d, progFx);
                            break;

                        case EFFECT_SPECIAL_FIRE:
                            //effectFinished = special_fire();
                            break;

                        case EFFECT_SPECIAL_SOUND:
                            //effectFinished = progressFX_sound();
                            break;
                    }

                    if (colour == COLOUR_CYCLE && effectFinished)
                    {
                        c++;
                        if (c == AMOUNTOFCOLOURS) c = (COLOUR_BLACK + 1);
                    }
                }
            }
        }
        //Getters and setters
        public void setDataFromTransmission(Transmission_Diode data)
        {
            if (panelNumber != data.panelNumber)
            {
                throw new ArgumentException("Diode wanted to update but the panelNumber was not right.");
            }

            brightness = data.brightness;
            effect = data.effect;
            colour = data.colour;
            offset = data.offset;
            speed = data.speed;
            repeat = data.repeat;

            rgb.r = data.r;
            rgb.g = data.g;
            rgb.b = data.b;
    }
        public ColourRGB getRGB(byte sysBrightness)
        {
            ColourRGB colourRGB;
            colourRGB.r = (byte)((((rgb.r * brightness) / 255) * sysBrightness) / 255);
            colourRGB.g = (byte)((((rgb.g * brightness) / 255) * sysBrightness) / 255);
            colourRGB.b = (byte)((((rgb.b * brightness) / 255) * sysBrightness) / 255);
            return colourRGB;
        }
        public byte getNumber()
        {
            return number;
        }
        //Printing and converting
        public void printDebug()
        {
            Console.Write("Diode ");
            Console.WriteLine(number);

            Console.Write("brightness ");
            Console.Write(brightness);
            Console.Write(" | effect ");
            Console.Write(effect);
            Console.Write(" | colour ");
            Console.Write(colour);
            Console.Write(" | offset ");
            Console.Write(offset);
            Console.Write(" | speed ");
            Console.Write(speed);

            Console.Write(" === r ");
            Console.Write(rgb.r);
            Console.Write(" | g ");
            Console.Write(rgb.g);
            Console.Write(" | b ");
            Console.Write(rgb.b);
            Console.Write(" | d ");
            Console.Write(d);
            Console.Write(" | c ");
            Console.Write(c);
            Console.Write(" | progFx ");
            Console.Write(progFx);
            Console.Write(" | offsetTimer ");
            Console.WriteLine(offsetTimer);
        }
        public String convertToTransmission()
        {
            String data = "";

            data += number;

            data += brightness;
            data += effect;
            data += colour;
            data += offset;
            data += speed;
            data += repeat;

            data += rgb.r;
            data += rgb.g;
            data += rgb.b;

            return data;
        }
    }
}
