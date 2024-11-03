using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class clsCalculator
    {
        private string _lastOperation = "Clear";
        private float _result = 0;
        private float _lastNumber = 0;


        private bool _IsZero(float Number)
        {
            return (Number == 0);
        }


        public void Clear()
        {
            _lastOperation = "Clear";
            _lastNumber = 0;
            _result = 0;
        }

        public void Add(float num)
        {
            _result += num;
            _lastOperation = "Adding";
            _lastNumber = num;
        }

        public void Subtract(float num)
        {
            _result -= num;
            _lastOperation = "Subtracting";
            _lastNumber = num;
        }

        public void Multiply(float num)
        {
            _result *= num;
            _lastOperation = "Multiplying";
            _lastNumber = num;
        }

        public bool Divide(float num)
        {
            bool Succeeded = true;
            _lastOperation = "Dividing";
            _lastNumber = num;

            if (_IsZero(num))
            {
                num = 1;
                Succeeded = false;
            }

            _result /= num;
            return Succeeded;
        }

        public float GetFinalResults()
        {
            return _result;
        }

        public void PrintResult()
        {
            Console.WriteLine($"Result After {_lastOperation} {_lastNumber} is : {_result}");
        }

    }

    internal class Program
    {
        static void Main(string[] args)
        {
            clsCalculator Calculator1 = new clsCalculator();

            Calculator1.Clear();

            Calculator1.Add(10);
            Calculator1.PrintResult();

            Calculator1.Add(100);
            Calculator1.PrintResult();

            Calculator1.Subtract(20);
            Calculator1.PrintResult();

            Calculator1.Divide(0);
            Calculator1.PrintResult();

            Calculator1.Divide(2);
            Calculator1.PrintResult();

            Calculator1.Multiply(3);
            Calculator1.PrintResult();

            Calculator1.Clear();
            Calculator1.PrintResult();

            Console.ReadKey();

        }
    }
}
