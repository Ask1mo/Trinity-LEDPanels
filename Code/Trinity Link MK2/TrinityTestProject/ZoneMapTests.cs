using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Trinity;

using System.IO;

namespace TrinityTestProject
{
    [TestClass]
    public class MultiplierMapTests
    {
        static string testFileDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + @"\TrinityTest\");
        static string MissingFileDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + @"\MissingTrinityTest\");
        static string[] effectNumbers = new String[16]
        {
            " Custom",              //0
            "   Static",            //1
            "    Blink",            //2
            "    Blink\n   Twice",  //3
            "Breathing",            //4
            "  Pause\nBreathing",   //5
            "   Flash",             //6
            "Heartbeat",            //7

            "   Sound",             //8
            "!Range 9",             //9
            "Breathing",            //10
            "  Pause\nBreathing",   //11
            "!Range 12",            //12
            "!Range 13",            //13
            "!Range 14",            //14
            "    RGB",              //15
        };
        static string[,] effectColours = new String[2, 16]
        {
            {
                "   White",         //0
                "    Red",          //1
                "  Yellow",         //2
                "   Green",         //3
                "   Cyan",          //4
                "    Blue",         //5
                "   Violet",        //6
                "  Colour\n  Cycle",//7
                "!Range 8",         //8
                "!Range 9",         //9
                "!Range 10",        //10
                "!Range 11",        //11
                "!Range 12",        //12
                "!Range 13",        //13
                "!Range 14",        //14
                "    RGB",          //15
            },

            {
                "Off",              //0
                "Rainbow",          //1
                "Synthbow",         //2
                " Strobe",          //3
                "   Fire",          //4
                "  Sound",          //5
                "Not\nBound",       //6
                "Not\nBound",       //7
                "!Range 8",         //8
                "!Range 9",         //9
                "!Range 10",        //10
                "!Range 11",        //11
                "!Range 12",        //12
                "!Range 13",        //13
                "!Range 14",        //14
                "!Range 15\n   RGB",//15
            }
        };

        public const byte XPOSITIONS = 7;
        public const byte YPOSITIONS = 4;

        /*----------CONSTRUCTOR----------*/
        [TestMethod]
        public void Test_MultiplierMap_Constructor()
        {
            string name = "testName";
            string designer = "testDesigner";
            string collection = "testCollection";
            string designedFor = "testDesignedFor";
            byte[,] map = new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000}
            };

            MultiplierMap multiplierMap = new MultiplierMap(name, designer, collection, designedFor, map);
            Assert.AreEqual(name, multiplierMap.Name);
            Assert.AreEqual(designer, multiplierMap.Designer);
            Assert.AreEqual(collection, multiplierMap.Collection);
            Assert.AreEqual(designedFor, multiplierMap.DesignedFor);
            Assert.AreEqual(map, multiplierMap.Map);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void Test_MultiplierMap_Constructor_TooSmallYInArray()
        {
            string name = "testName";
            string designer = "testDesigner";
            string collection = "testCollection";
            string designedFor = "testDesignedFor";
            byte[,] map = new byte[3, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000}
            };

            MultiplierMap multiplierMap = new MultiplierMap(name, designer, collection, designedFor, map);
            Assert.AreEqual(multiplierMap, null);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void Test_MultiplierMap_Constructor_TooLargeXInArray()
        {
            string name = "testName";
            string designer = "testDesigner";
            string collection = "testCollection";
            string designedFor = "testDesignedFor";
            byte[,] map = new byte[YPOSITIONS, 8]
            {
                {000, 000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000, 000}
            };

            MultiplierMap multiplierMap = new MultiplierMap(name, designer, collection, designedFor, map);
            Assert.AreEqual(multiplierMap, null);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void Test_MultiplierMap_Constructor_mapXYSwapped()
        {
            string name = "testName";
            string designer = "testDesigner";
            string collection = "testCollection";
            string designedFor = "testDesignedFor";
            byte[,] map = new byte[XPOSITIONS, YPOSITIONS]
            {
                {000, 000, 000, 000},
                {000, 000, 000, 000},
                {000, 000, 000, 000},
                {000, 000, 000, 000},
                {000, 000, 000, 000},
                {000, 000, 000, 000},
                {000, 000, 000, 000}
            };

            MultiplierMap multiplierMap = new MultiplierMap(name, designer, collection, designedFor, map);
            Assert.AreEqual(multiplierMap, null);
        }
        [TestMethod]
        public void Test_MultiplierMap_Constructor_EmptyValues()
        {
            string designedFor = "testDesignedFor";
            byte[,] map = new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000}
            };

            MultiplierMap multiplierMap = new MultiplierMap("", "", "", designedFor, map);

            Assert.AreEqual(multiplierMap.Name, "noName");
            Assert.AreEqual(multiplierMap.Designer, "noDesigner");
            Assert.AreEqual(multiplierMap.Collection, "noCollection");
            Assert.AreEqual(multiplierMap.DesignedFor, designedFor);
            Assert.AreEqual(multiplierMap.Map, map);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void Test_MultiplierMap_Constructor_NoDesignedFor()
        {
            byte[,] map = new byte[YPOSITIONS, XPOSITIONS]
            {
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000},
                {000, 000, 000, 000, 000, 000, 000}
            };

            MultiplierMap multiplierMap = new MultiplierMap("", "", "", "", map);
            Assert.AreEqual(multiplierMap, null);
        }
    }
}
