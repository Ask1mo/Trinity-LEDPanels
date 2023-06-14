using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trinity
{
    public class EffectApplications
    {
        const int AMOUNTOFCOLOURS = 8;

        const byte EFFECT_STOCK_const = 0;
        const byte EFFECT_STOCK_BLINK = 1;
        const byte EFFECT_STOCK_PLANE = 2;
        const byte EFFECT_STOCK_BREATHING = 3;
        const byte EFFECT_STOCK_PAUSEDBREATHING = 4;
        const byte EFFECT_STOCK_FLASH = 5;
        const byte EFFECT_STOCK_PAUSEDFLASH = 6;
        const byte EFFECT_STOCK_HEARTBEAT = 7;
        const byte EFFECT_STOCK_APPEAR = 8;
        const byte EFFECT_CUSTOM_const = 9;
        const byte EFFECT_CUSTOM_BLINK = 10;
        const byte EFFECT_CUSTOM_PLANE = 11;
        const byte EFFECT_CUSTOM_BREATHING = 12;
        const byte EFFECT_CUSTOM_PAUSEDBREATHING = 13;
        const byte EFFECT_CUSTOM_FLASH = 14;
        const byte EFFECT_CUSTOM_PAUSEDFLASH = 15;
        const byte EFFECT_CUSTOM_HEARTBEAT = 16;
        const byte EFFECT_SPECIAL_RAINBOW = 17;
        const byte EFFECT_SPECIAL_FIRE = 18;
        const byte EFFECT_SPECIAL_SOUND = 19;

        const byte COLOUR_BLACK = 0;
        const byte COLOUR_RED = 1;
        const byte COLOUR_YELLOW = 2;
        const byte COLOUR_GREEN = 3;
        const byte COLOUR_CYAN = 4;
        const byte COLOUR_BLUE = 5;
        const byte COLOUR_VIOLET = 6;
        const byte COLOUR_WHITE = 7;
        const byte COLOUR_CYCLE = 8;

        public EffectApplications()
        {
          
        }

        private bool getColourClearance(byte colourToClear, byte colourChannel)
        {
            switch (colourChannel)
            {
                case COLOUR_RED:
                    {
                        if (colourToClear == COLOUR_WHITE || colourToClear == COLOUR_RED || colourToClear == COLOUR_YELLOW || colourToClear == COLOUR_VIOLET)
                            return true;
                        return false;
                    }
                    break;

                case COLOUR_GREEN:
                    {
                        if (colourToClear == COLOUR_WHITE || colourToClear == COLOUR_YELLOW || colourToClear == COLOUR_GREEN || colourToClear == COLOUR_CYAN)
                            return true;
                        return false;
                    }
                    break;

                case COLOUR_BLUE:
                    {
                        if (colourToClear == COLOUR_WHITE || colourToClear == COLOUR_CYAN || colourToClear == COLOUR_BLUE || colourToClear == COLOUR_VIOLET)
                            return true;
                        return false;
                    }
                    break;
            }
            return false;
        }

        //Public
        public bool stock_static(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 0;

                    (progFx)++;
                    break;

                case 1:
                    (d)++;

                    if (d == 255)
                    {
                        (progFx) = 0;
                        return true;
                    }
                    break;
            }

            return false;
        }
        public bool stock_blink(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 0;

                    (progFx)++;
                    break;

                case 1:
                    (d)++;

                    if (d == 20) (progFx)++;
                    break;

                case 2:
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 0;

                    (progFx)++;
                    break;

                case 3:
                    (d)++;

                    if (d == 255)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_plane(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 0;

                    (progFx)++;
                    break;

                case 1:
                    (d)++;

                    if (d == 20) (progFx)++;
                    break;

                case 2:
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 0;

                    (progFx)++;
                    break;

                case 3:
                    (d)++;

                    if (d == 40) (progFx)++;
                    break;

                case 4:
                    if (allowR) rgb.r = 255;
                    if (allowG) rgb.g = 255;
                    if (allowB) rgb.b = 255;

                    (progFx)++;
                    break;

                case 5:
                    (d)++;

                    if (d == 60) (progFx)++;
                    break;

                case 6:
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 0;

                    (progFx)++;
                    break;

                case 7:
                    (d)++;

                    if (d == 255)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_breathing(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 0;
                    d = 0;

                    (progFx)++;
                    break;

                case 1:
                    if (allowR) rgb.r++;
                    if (allowG) rgb.g++;
                    if (allowB) rgb.b++;
                    (d)++;

                    if (d == 255) (progFx)++;
                    break;

                case 2:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 0)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_pausedbreathing(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 0;
                    d = 0;

                    (progFx)++;
                    break;

                case 1:
                    if (allowR) rgb.r++;
                    if (allowG) rgb.g++;
                    if (allowB) rgb.b++;
                    (d)++;

                    if (d == 255) (progFx)++;
                    break;

                case 2:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 0) (progFx)++;
                    break;

                case 3:
                    (d)++;

                    if (d == 255) (progFx)++;
                    break;

                case 4:
                    (d)--;

                    if (d == 0)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_flash(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 255;

                    (progFx)++;
                    break;

                case 1:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 0)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_pausedFlash(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 255;

                    (progFx)++;
                    break;

                case 1:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 0) (progFx)++;
                    break;

                case 2:
                    (d)++;
                    if (d == 255)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_heartbeat(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 255;

                    (progFx)++;
                    break;

                case 1:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 100) (progFx)++;
                    break;

                case 2:
                    if (allowR) rgb.r = 255;
                    if (allowG) rgb.g = 255;
                    if (allowB) rgb.b = 255;
                    d = 255;

                    (progFx)++;
                    break;

                case 3:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 0)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }
        public bool stock_appear(ColourRGB rgb, byte d, byte progFx, byte colour)
        {
            bool allowR = getColourClearance(colour, COLOUR_RED);
            bool allowG = getColourClearance(colour, COLOUR_GREEN);
            bool allowB = getColourClearance(colour, COLOUR_BLUE);

            switch (progFx)
            {
                case 0:
                    if (allowR) rgb.r = 255;
                    else rgb.r = 0;
                    if (allowG) rgb.g = 255;
                    else rgb.g = 0;
                    if (allowB) rgb.b = 255;
                    else rgb.b = 0;
                    d = 255;

                    (progFx)++;
                    break;

                case 1:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 100) (progFx)++;
                    break;

                case 2:
                    (d)++;
                    if (d == 255) (progFx)++;
                    break;

                case 3:
                    if (allowR) rgb.r = 255;
                    if (allowG) rgb.g = 255;
                    if (allowB) rgb.b = 255;
                    d = 255;

                    (progFx)++;
                    break;

                case 4:
                    if (allowR) rgb.r--;
                    if (allowG) rgb.g--;
                    if (allowB) rgb.b--;
                    (d)--;

                    if (d == 0) (progFx)++;
                    break;

                case 5:
                    (d)++;
                    if (d == 223)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;
            }
            return false;
        }


        public bool special_rainbow(ColourRGB rgb, byte d, byte progFx)
        {
            switch (progFx)
            {
                case 0:
                    rgb.r = 0;
                    rgb.g = 0;
                    rgb.b = 255;

                    (progFx)++;
                    break;

                case 1:
                    (rgb.r)++;
                    if (rgb.r == 255) (progFx)++;
                    break;

                case 2:
                    rgb.b--;
                    if (rgb.b == 0) (progFx)++;
                    break;

                case 3:
                    rgb.g++;
                    if (rgb.g == 255) (progFx)++;
                    break;

                case 4:
                    rgb.r--;
                    if (rgb.r == 0) (progFx)++;
                    break;

                case 5:
                    rgb.b++;
                    if (rgb.b == 255) (progFx)++;
                    break;

                case 6:
                    rgb.g--;
                    if (rgb.g == 0)
                    {
                        progFx = 0;
                        return true;
                    }
                    break;

                default:
                    progFx = 0;
                    break;
            }
            return false;
        }
    }
}
