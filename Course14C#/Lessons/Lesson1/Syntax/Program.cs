using System;

//// provides us various methods to use in an array
using System.Linq;

namespace Syntax
{
    internal class Program
    {
        enum enWeekDays
        {
            Monday,     // 0
            Tuesday,    // 1
            Wednesday,  // 2
            Thursday,   // 3
            Friday,     // 4
            Saturday,   // 5
            Sunday      // 6
        }

        //if you set a value , it will auto number everything after it.
        enum enCategories
        {
            Electronics,    // 0
            Food,           // 1
            Automotive = 6, // 6
            Arts,           // 7
            BeautyCare,     // 8
            Fashion         // 9
        }


        //Enum can have any numarical data type byte, sbyte, short, ushort, int, uint, long, or ulong
        //but not string

        enum enCategories2 : byte
        {
            Electronics = 1,
            Food = 5,
            Automotive = 6,
            Arts = 10,
            BeautyCare = 11,
            Fashion = 15
        }

        struct stStudent
        {
            public string FirstName;
            public string LastName;
        }

        static void SeparationLine()
        {
            Console.WriteLine("\n_______________________________________\n");
        }

        static void Outputs()
        {
            //Console.WriteLine = cout + \n
            Console.WriteLine("My name is Omar Bahaeldin Abdalla");
            Console.WriteLine("I am learning C#");

            //Console.Write = cout
            Console.Write("It is an easy language to learn :-)\n");
            Console.Write("The sum of 10 + 20 is " + (10 + 20) + "\n"); // Without parantheses, string concatenation occurs

            //Formatted String
            Console.WriteLine("{0} {1}", "Welcome to", "KFUPM");
            Console.WriteLine("Hi My name is: {0} I live in {1}", "Omar", "Egypt");

            //Escape Characters
            Console.WriteLine("_______________________________________");
            Console.WriteLine("\nUseful Escape Characters:\n");

            Console.WriteLine("Newline:");
            Console.WriteLine("Welcome to \n KFUPM\n");

            Console.WriteLine("Tab:");
            Console.WriteLine("Welcome to \tKFUPM\n");


            Console.WriteLine("Backspace:");
            Console.WriteLine("Welcome to \bKFUPM\n");


            Console.WriteLine("Single Quote:");
            Console.WriteLine("Welcome to \' KFUPM\n");


            Console.WriteLine("Double Quote:");
            Console.WriteLine("Welcome to \" KFUPM\n");


            Console.WriteLine("Backslash:");
            Console.WriteLine("Welcome to \\ KFUPM\n");


            Console.WriteLine("Alert:");
            Console.WriteLine("\a");
        }

        static void Variables()
        {
            string MyName = "Omar Bahaeldin Abdalla";
            Console.WriteLine(MyName);

            int x = 10, y = 20;

            Console.WriteLine("x = " + x);
            Console.WriteLine("y = " + y);

            Console.WriteLine("x + y = " + x + y); // wrong
            Console.WriteLine("x + y = " + (x + y)); // correct

            double MyDouble = 25.89D;
            char MyLetter = 'M';
            bool MyBool = true;
        }

        static void ImplicitTypedVariables()
        {
            var implicit_x = 10;
            var implixit_y = 20.5;
            var implicit_z = "Omar";

            Console.WriteLine("x={0}, y={1}, z={2}", implicit_x, implixit_y, implicit_z);

        }

        static void NumbersDatatypes()
        {
            byte b1 = 255;

            //byte b2 = -128; // error
            sbyte sb1 = -128;
            sbyte sb2 = 127;

            Console.WriteLine("\nByte:");
            Console.WriteLine("Min={0} , Max={1}", Byte.MinValue, Byte.MaxValue);


            Console.WriteLine("\nSByte:");
            Console.WriteLine("Min={0} , Max={1}", SByte.MinValue, SByte.MaxValue);

            //Short
            short s1 = -32768;
            short s2 = 32767;

            // short s3 = 35000;//Compile-time error: Constant value '35000' cannot be converted to a 'short'

            ushort us1 = 65535;
            //  ushort us2 = -32000; //Compile-time error: Constant value '-32000' cannot be converted to a 'ushort'

            Console.WriteLine("\nShort:");
            Console.WriteLine("Min={0} , Max={1}", Int16.MinValue, Int16.MaxValue);

            Console.WriteLine("\nUShort:");
            Console.WriteLine("Min={0} , Max={1}", UInt16.MinValue, UInt16.MaxValue);

            //int
            int i = -2147483648;
            int j = 2147483647;
            //  int k = 4294967295; //Compile-time error: Cannot implicitly convert type 'uint' to 'int'.

            uint ui1 = 4294967295;
            // uint ui2 = -1; //Compile-time error: Constant value '-1' cannot be converted to a 'uint'

            Console.WriteLine("\nInt:");
            Console.WriteLine("Min={0} , Max={1}", Int32.MinValue, Int32.MaxValue);

            Console.WriteLine("\nUInt:");
            Console.WriteLine("Min={0} , Max={1}", UInt32.MinValue, UInt32.MaxValue);

            //Long
            long l1 = -9223372036854775808;
            long l2 = 9223372036854775807;

            ulong ul1 = 18223372036854775808ul;
            ulong ul2 = 18223372036854775808UL;

            Console.WriteLine("\nLong:");
            Console.WriteLine("Min={0} , Max={1}", Int64.MinValue, Int64.MaxValue);

            Console.WriteLine("\nULong:");
            Console.WriteLine("Min={0} , Max={1}", UInt64.MinValue, UInt64.MaxValue);


            //Float
            float f1 = 123456.5F;
            float f2 = 1.123456f;

            Console.WriteLine("\nFloat:");
            Console.WriteLine("Min={0} , Max={1}", float.MinValue, float.MaxValue);


            //double
            double d1 = 12345678912345.5d;
            double d2 = 1.123456789123456d;

            Console.WriteLine("\nDouble:");
            Console.WriteLine("Min={0} , Max={1}", double.MinValue, double.MaxValue);



            //Decimal
            //The decimal type has more precision and a smaller range
            //than both float and double,
            //and so it is appropriate for financial and monetary calculations.
            decimal d3 = 123456789123456789123456789.5m;
            decimal d4 = 1.1234567891345679123456789123m;

            Console.WriteLine("\nDecimal:");
            Console.WriteLine("Min={0} , Max={1}", decimal.MinValue, decimal.MaxValue);


            //Scientific Notation
            //Use e or E to indicate the power of 10 
            //as exponent part of scientific notation with float, double or decimal.

            double d = 0.12e2;
            Console.WriteLine(d);  // 12;

            float f = 123.45e-2f;
            Console.WriteLine(f);  // 1.2345

            decimal m = 1.2e6m;
            Console.WriteLine(m);// 1200000



            //hex & Binary
            int hex = 0x2F;
            int binary = 0b_0010_1111;

            Console.WriteLine(hex);
            Console.WriteLine(binary);
        }
        
        static void DefaultValues()
        {
            //get default value using default(type)
            int i2 = default(int); // 0
            float f3 = default(float);// 0
            decimal d5 = default(decimal);// 0
            bool b = default(bool);// false
            char c = default(char);// '\0'

            // C# 7.1 onwards
            //get default value using default
            int i3 = default; // 0
            float f4 = default;// 0
            decimal d6 = default;// 0
            bool b2 = default;// false
            char c2 = default;// '\0'
        }
        
        static void Enums()
        {
            enWeekDays WeekDays;
            WeekDays = enWeekDays.Friday;
            Console.WriteLine(WeekDays);
        }
        
        static void NullableTypes()
        {
            Nullable<int> i4 = null;
            if (i4.HasValue)
                Console.WriteLine(i4);
            else
                Console.WriteLine("NULL");
        }

        static void AnonymousTypes()
        {
            //You don't specify any type here , automatically will be specified
            var student = new { Id = 20, FirstName = "Omar", LastName = "Abdalla" };

            Console.WriteLine("\nExample1:\n");
            Console.WriteLine(student.Id); //output: 20
            Console.WriteLine(student.FirstName); //output: Omar
            Console.WriteLine(student.LastName); //output: Abdalla

            //You can print like this:
            Console.WriteLine(student);

            //anonymous types are read-only
            //you cannot change the values of properties as they are read-only.

            // student.Id = 2;//Error: cannot change value
            // student.FirstName = "Ali";//Error: cannot change value


            //An anonymous type's property can include another anonymous type.
            var student2 = new
            {
                Id = 20,
                FirstName = "Omar",
                LastName = "Abdalla",
                Address = new { Id = 1, City = "Riyadh", Country = "Saudi Arabia" }
            };

            Console.WriteLine("\nExample2:\n");
            Console.WriteLine(student2.Id);
            Console.WriteLine(student2.FirstName);
            Console.WriteLine(student2.LastName);

            Console.WriteLine(student2.Address.Id);
            Console.WriteLine(student2.Address.City);
            Console.WriteLine(student2.Address.Country);
            Console.WriteLine(student2.Address);

            Console.WriteLine(student2);

        }

        static void Struct()
        {
            SeparationLine();
            //A struct object can be created with or without the new operator,
            //same as primitive type variables.

            stStudent Student;
            stStudent Student2 = new stStudent();


            Student.FirstName = "Omar"; //if not assigned, compile error
            Student.LastName = "Abdalla";


            Console.WriteLine(Student.FirstName);
            Console.WriteLine(Student.LastName);


            Student2.FirstName = "Ali";
            Student2.LastName = "Ahmed";


            Console.WriteLine(Student2.FirstName);
            Console.WriteLine(Student2.LastName);
        }

        static void DynamicType()
        {
            dynamic MyDynamicVar = 100;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = "Hello World!!";
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = true;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = DateTime.Now;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

        }

        static void Dates()
        {
            //assigns default value 01/01/0001 00:00:00
            DateTime dt1 = new DateTime();

            //assigns year, month, day
            DateTime dt2 = new DateTime(2023, 12, 31);

            //assigns year, month, day, hour, min, seconds
            DateTime dt3 = new DateTime(2023, 12, 31, 5, 10, 20);

            //assigns year, month, day, hour, min, seconds, UTC timezone
            DateTime dt4 = new DateTime(2023, 12, 31, 5, 10, 20, DateTimeKind.Utc);

            Console.WriteLine(dt1);
            Console.WriteLine(dt2);
            Console.WriteLine(dt3);
            Console.WriteLine(dt4);

            // Get Current Date
            DateTime dt5 = new DateTime();
            dt5 = DateTime.Now;
            Console.WriteLine(dt5);


            //Ticks
            //number of 100-nanosecond intervals that have elapsed
            //since January 1, 0001, at 00:00:00.000 in the Gregorian calendar. 
            SeparationLine();
            DateTime dt6 = new DateTime();
            Console.WriteLine(DateTime.MinValue.Ticks);  //min value of ticks
            Console.WriteLine(DateTime.MaxValue.Ticks); // max value of ticks



            //Static Fields
            SeparationLine();

            DateTime currentDateTime = DateTime.Now;  //returns current date and time
            DateTime todaysDate = DateTime.Today; // returns today's date
            DateTime currentDateTimeUTC = DateTime.UtcNow;// returns current UTC date and time
            DateTime maxDateTimeValue = DateTime.MaxValue; // returns max value of DateTime
            DateTime minDateTimeValue = DateTime.MinValue; // returns min value of DateTime

            Console.WriteLine("currentDateTime: " + currentDateTime);
            Console.WriteLine("Today: " + todaysDate);
            Console.WriteLine("currentDateTimeUTC: " + currentDateTimeUTC);
            Console.WriteLine("minDateTimeValue: " + minDateTimeValue);
            Console.WriteLine("maxDateTimeValue: " + maxDateTimeValue);


            SeparationLine();
            DateTime dt7 = new DateTime(2023, 2, 21);

            // Hours, Minutes, Seconds
            TimeSpan ts = new TimeSpan(49, 25, 34);
            Console.WriteLine(ts);
            Console.WriteLine(ts.Days);
            Console.WriteLine(ts.Hours);
            Console.WriteLine(ts.Minutes);
            Console.WriteLine(ts.Seconds);

            //this will add time span to the date.
            DateTime newDate = dt7.Add(ts);


            Console.WriteLine(newDate);

            SeparationLine();
            DateTime dt8 = new DateTime(2023, 2, 21);
            DateTime dt9 = new DateTime(2023, 2, 25);
            TimeSpan result = dt9.Subtract(dt8);

            Console.WriteLine(result.Days);


            SeparationLine();
            DateTime dt10 = new DateTime(2015, 12, 20);
            DateTime dt11 = new DateTime(2016, 12, 31, 5, 10, 20);
            TimeSpan time = new TimeSpan(10, 5, 25, 50);

            Console.WriteLine(dt11 + time); // 1/10/2017 10:36:10 AM
            Console.WriteLine(dt11 - dt10); //377.05:10:20
            Console.WriteLine(dt10 == dt11); //False
            Console.WriteLine(dt10 != dt11); //True
            Console.WriteLine(dt10 > dt11); //False
            Console.WriteLine(dt10 < dt11); //True
            Console.WriteLine(dt10 >= dt11); //False
            Console.WriteLine(dt10 <= dt11);//True


            // Convert String to DateTime
            //ParseEaxct TryParseExact
            SeparationLine();
            var str = "6/12/2023";
            DateTime dt12;

            var isValidDate = DateTime.TryParse(str, out dt12);

            if (isValidDate)
                Console.WriteLine(dt12);
            else
                Console.WriteLine($"{str} is not a valid date string");

            //invalid string date
            var str2 = "6/65/2023";
            DateTime dt13;

            var isValidDate2 = DateTime.TryParse(str2, out dt13);

            if (isValidDate2)
                Console.WriteLine(dt13);
            else
                Console.WriteLine($"{str2} is not a valid date string");

        }

        static void Strings()
        {

            string S1 = "Omar Bahaeldin Abdalla";

            Console.WriteLine(S1.Length);

            //this will take 5 characters starting position 2
            Console.WriteLine(S1.Substring(2, 5));
            Console.WriteLine(S1.ToLower());
            Console.WriteLine(S1.ToUpper());
            Console.WriteLine(S1[2]);
            Console.WriteLine(S1.Insert(3, "KKKK"));
            Console.WriteLine(S1.Replace("m", "*"));
            Console.WriteLine(S1.IndexOf("m"));
            Console.WriteLine(S1.Contains("m"));
            Console.WriteLine(S1.Contains("x"));
            Console.WriteLine(S1.LastIndexOf("a"));
            // string[] NamesList = S1.Split(new char[] { '#', '/', '/', '#' }, StringSplitOptions.RemoveEmptyEntries);

            string S2 = "Ali,Ahmed,Khalid";

            string[] NamesList = S2.Split(',');

            Console.WriteLine(NamesList[0]);
            Console.WriteLine(NamesList[1]);
            Console.WriteLine(NamesList[2]);

            string S3 = "  Abu-Hadhoud  ";
            Console.WriteLine(S3.Trim());
            Console.WriteLine(S3.TrimStart());
            Console.WriteLine(S3.TrimEnd());
        
        
        }

        static void StringInterpolation()
        {
            string firstName = "Omar";
            string lastName = "Abdalla";
            string code = "107";

            //You shold use $ to $ to identify an interpolated string 
            string fullName = $"Mr. {firstName} {lastName}, Code: {code}";

            Console.WriteLine(fullName);
        }

        static void ImplicitCasting()
        {
            int myInt = 17;
            double myDouble = myInt;       // Automatic casting: int to double

            Console.WriteLine(myInt);      // Outputs 17
            Console.WriteLine(myDouble);   // Outputs 17
        }

        static void ExplicitCasting()
        {
            double myDouble = 17.58;
            int myInt = (int)myDouble;    // Manual casting: double to int

            Console.WriteLine(myDouble);   // Outputs 17.58
            Console.WriteLine(myInt);      // Outputs 17

        }

        static void TypeConversionMethods()
        {
            int myInt = 20;
            double myDouble = 7.25;
            bool myBool = true;

            Console.WriteLine(Convert.ToString(myInt));    // convert int to string
            Console.WriteLine(Convert.ToDouble(myInt));    // convert int to double
            Console.WriteLine(Convert.ToInt32(myDouble));  // convert double to int
            Console.WriteLine(Convert.ToString(myBool));   // convert bool to string

        }

        static void EnumsConversion()
        {

            Console.WriteLine(enWeekDays.Friday); //output: Friday 
            int day = (int)enWeekDays.Friday; // enum to int conversion
            Console.WriteLine(day); //output: 4 

            var wd = (enWeekDays)5; // int to enum conversion
            Console.WriteLine(wd);//output: Saturday 
        }

        static void UserInput()
        {
            // Type your username and press enter
            Console.WriteLine("Enter username?");

            string userName = Console.ReadLine();
            Console.WriteLine("Username is: " + userName);

            Console.WriteLine("\nEnter your age?");
            //if you dont convert you will get error, and if you enter string you will get error
            short age = Convert.ToInt16(Console.ReadLine());
            Console.WriteLine("Your age is: " + age);

        }

        static void UnaryOperator()
        {
            int number = 10, result;
            bool flag = true;

            result = +number;
            Console.WriteLine("+number = " + result);

            result = -number;
            Console.WriteLine("-number = " + result);

            result = ++number;
            Console.WriteLine("++number = " + result);

            result = --number;
            Console.WriteLine("--number = " + result);

            Console.WriteLine("!flag = " + (!flag));

            Console.WriteLine((number++));
            Console.WriteLine((number));

            Console.WriteLine((++number));
            Console.WriteLine((number));
        }

        static void TernaryOperator()
        {
            int number = 12;
            string result;

            result = (number % 2 == 0) ? "Even Number" : "Odd Number";
            Console.WriteLine("{0} is {1}", number, result);
        }

        static void ControlFlow()
        {
            //ifs
            int x = 10; int y = 20;

            //if then statement
            if (x == 10 && y <= 20)
            {
                Console.WriteLine("yes x = 10 and y<=20");
            }



            //if then else statement
            if (x == 11)
            {
                Console.WriteLine("yes x = 11 ");
            }
            else
            {
                Console.WriteLine("yes x != 11 ");
            }


            //if else if statement
            int number = 12;

            if (number < 5)
            {
                Console.WriteLine("{0} is less than 5", number);
            }
            else if (number > 5)
            {
                Console.WriteLine($"{number} is greater than 5");
            }
            else
            {
                Console.WriteLine("{0} is equal to 5");
            }

            SeparationLine();

            // switch - Example1
            char ch;
            Console.WriteLine("Enter a letter?");
            ch = Convert.ToChar(Console.ReadLine());

            switch (Char.ToLower(ch))
            {
                case 'a':
                    Console.WriteLine("Vowel");
                    break;
                case 'e':
                    Console.WriteLine("Vowel");
                    break;
                case 'i':
                    Console.WriteLine("Vowel");
                    break;
                case 'o':
                    Console.WriteLine("Vowel");
                    break;
                case 'u':
                    Console.WriteLine("Vowel");
                    break;
                default:
                    Console.WriteLine("Not a vowel");
                    break;
            }

            SeparationLine();

            // Example 2
            //switch statement with grouped cases

            char ch1;
            Console.WriteLine("Enter a letter");
            ch1 = Convert.ToChar(Console.ReadLine());

            switch (Char.ToLower(ch1))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    Console.WriteLine("Vowel");
                    break;
                default:
                    Console.WriteLine("Not a vowel");
                    break;
            }

            //String Compare
            SeparationLine();
            string Name = "Mohammed";

            //You can compare string as well using switch
            switch (Name.ToLower())
            {
                case "mohammed":

                    Console.WriteLine("Yes Mohammed");
                    break;

                case "ali":

                    Console.WriteLine("Yes ALi");
                    break;

                default:
                    Console.WriteLine("No Name Matched!");
                    break;

            }



        }

        static void SimpleCalculator()
        {
            //Simple Calculator
            char op;
            double first, second, result;

            Console.Write("Enter first number: ");
            first = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter second number: ");
            second = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter operator (+, -, *, /): ");
            op = (char)Console.Read();

            switch (op)
            {
                case '+':
                    result = first + second;
                    Console.WriteLine("{0} + {1} = {2}", first, second, result);
                    break;

                case '-':
                    result = first - second;
                    Console.WriteLine("{0} - {1} = {2}", first, second, result);
                    break;

                case '*':
                    result = first * second;
                    Console.WriteLine("{0} * {1} = {2}", first, second, result);
                    break;

                case '/':
                    result = first / second;
                    Console.WriteLine("{0} / {1} = {2}", first, second, result);
                    break;

                default:
                    Console.WriteLine("Invalid Operator");
                    break;

            }
        }

        static void Loops()
        {
            Console.WriteLine("\nForward Loop:");
            //forward loop
            for (int i = 1; i <= 10; i++)

            {
                Console.WriteLine(i);

            }

            Console.WriteLine("\nBackword Loop:");
            //backword loop
            for (int i = 10; i >= 1; i--)

            {

                Console.WriteLine(i);

            }


            Console.WriteLine("\nNested Loops:");
            //forward loop
            for (int i = 1; i <= 10; i++)

            {

                for (int j = 0; j < 10; j++)

                {

                    Console.WriteLine("i={0} and j={1}", i, j);

                }

            }

            SeparationLine();

            int k = 1;
            while (k <= 5)
            {
                Console.WriteLine("C# while Loop: Iteration {0}", k);
                k++;
            }

            SeparationLine();

            int m = 1;
            do
            {
                Console.WriteLine("C# while Loop: Iteration {0}", m);
                m++;

            } while (m <= 5);

            SeparationLine();


            char[] myArray = { 'H', 'e', 'l', 'l', 'o' };

            foreach (char ch in myArray)
            {
                Console.WriteLine(ch);
            }


            char[] gender = { 'm', 'f', 'm', 'm', 'm', 'f', 'f', 'm', 'm', 'f' };
            int male = 0, female = 0;
            foreach (char g in gender)
            {
                if (g == 'm')
                    male++;
                else if (g == 'f')
                    female++;
            }
            Console.WriteLine("Number of male = {0}", male);
            Console.WriteLine("Number of female = {0}", female);




        }

        static void BreakStatement()
        {
            int i = 1;
            do
            {

                Console.WriteLine("C# while Loop: Iteration {0}", i);

                if (i == 3)
                    break;

                i++;

            } while (i <= 5);
        }
        
        static void ContinueStatement()
        {
            for (int i = 1; i <= 5; ++i)
            {

                if (i == 3)
                {
                    continue;
                }

                Console.WriteLine(i);
            }

        }

        static void ArrayMethods()
        {
            // create an array
            int[] numbers = { 1, 2, 3 };

            //access first element
            Console.WriteLine("Element in first index : " + numbers[0]);

            //access second element
            Console.WriteLine("Element in second index : " + numbers[1]);

            //access third element
            Console.WriteLine("Element in third index : " + numbers[2]);


            //through loop
            Console.WriteLine("\nAccess array using loop:\n");
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.WriteLine("Element in index {0} : {1} ", i, numbers[0]);
            }

            SeparationLine();
            //initializing 2D array
            int[,] numbers2d = { { 12, 13 }, { 55, 77 } };

            // access first element from the first row
            Console.WriteLine("Element at index [0, 0] : " + numbers2d[0, 0]);

            // access first element from second row
            Console.WriteLine("Element at index [1, 0] : " + numbers2d[1, 0]);



            // Note that we used System.Linq above.
            SeparationLine();
            int[] numbers2 = { 51, -1, 2, 14, 18, 40, 178 };

            // get the minimum element
            Console.WriteLine("Smallest  Element: " + numbers2.Min());

            // Max() returns the largest number in array
            Console.WriteLine("Largest Element: " + numbers2.Max());

            int[] numbers3 = { 20, 22, 19, 18, 1 };

            // compute Count
            Console.WriteLine("Count : " + numbers3.Count());

            // compute Sum
            Console.WriteLine("Sum : " + numbers3.Sum());

            // compute the average
            Console.WriteLine("Average: " + numbers3.Average());


        }

        static void MathLibrary()
        {
            Console.WriteLine("Max of 5, 10 is: {0}", Math.Max(5, 10));
            Console.WriteLine("Min of 5, 10 is: {0}", Math.Min(5, 10));
            Console.WriteLine("Squir Root of 64 is: {0}", Math.Sqrt(64));
            Console.WriteLine("Absolute (positive) value of  -4.7 is: {0}", Math.Abs(-4.7));
            Console.WriteLine("Round of 9.99 is: {0}", Math.Round(9.99));
        }

        static void PrintMyInfo(string Name, byte Age, string Address = "No Address")
        {
            Console.WriteLine("Name= {0} , Age= {1}, Address= {2}", Name, Age, Address);
        }

        static void MyMethod(string child1, string child2, string child3)
        {
            Console.WriteLine("The youngest child is: " + child3);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            //Outputs
            Outputs();


            // Variables
            Variables();


            //Implicitly Typed Variables (var) must be initialized at declaration time.
            ImplicitTypedVariables();

            Console.WriteLine("_______________________________________\n");

            //Numbers DataTypes
            NumbersDatatypes();


            //Console.WriteLine("_______________________________________\n");
            //Default Values
            DefaultValues();


            // Enums
            Console.WriteLine("_______________________________________\n");
            Enums();

            //  Nullable Types
            //  Nullable<int> can be assigned any value
            //  from -2147483648 to 2147483647, or a null value.

            Console.WriteLine("_______________________________________\n");
            NullableTypes();


            Console.WriteLine("_______________________________________\n");

            //Anonymous Types
            AnonymousTypes();


            //Struct
            Struct();
 

            //Dynamic Type
            SeparationLine();
            DynamicType();


            //Date & Time
            SeparationLine();
            Dates();

            //Strings
            SeparationLine();
            Strings();

            //  String Interpolation
            SeparationLine();
            StringInterpolation();

            // C# Type Casting
            /*
             * Implicit Casting (automatically) convert to larger
             * char -> int -> long -> float -> double

             * Explicit Casting (manually) convert to smaller
             * double -> float -> long -> int -> char
             */
            SeparationLine();
            ImplicitCasting();

            SeparationLine();
            ExplicitCasting();

            SeparationLine();
            TypeConversionMethods();

            // Enums Conversion
            // Explicit casting is required to convert from an enum type to its underlying integral type.
            SeparationLine();
            EnumsConversion();

            //User Input
            SeparationLine();
            UserInput();

            //Assignment Operators
            SeparationLine();
            /*
             * ^= bitwise xor
             * <<= left shift assign
             * >>= right shift assign
             * => lambda operator
             */

            //Arithmetic Operators
            //Relational Operators
            //Logical Operators

            //Unary Operators
            UnaryOperator();

            //Ternary Operator
            SeparationLine();
            TernaryOperator();

            // BItwise and Bit Shift Operators
            // ~ Bitwise complement
            SeparationLine();
            ControlFlow();

            SeparationLine();
            SimpleCalculator();


            SeparationLine();
            // Loops
            Loops();

            //Break
            SeparationLine();
            BreakStatement();

            //Continue
            SeparationLine();
            ContinueStatement();

            // Arrays
            SeparationLine();
            ArrayMethods();

            // Math
            SeparationLine();
            MathLibrary();

            SeparationLine();
            PrintMyInfo("Omar", 19, "Dhahran");

            //see the order of sending parameters is not important.
            MyMethod(child3: "Omar", child1: "Saqer", child2: "Hamza");

            // Exceptions
            try
            {
                int[] myNumbers = { 1, 2, 3 };
                Console.WriteLine(myNumbers[10]);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Random rnd = new Random();

            for (int j = 0; j < 4; j++)
            {
                Console.WriteLine(rnd.Next(10, 20)); // returns random integers >= 10 and < 20
            }

            Console.ReadKey();

        }
    }
}
