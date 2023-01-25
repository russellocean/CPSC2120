#include "review.h"

int add(int a, int b)
{
    return a + b;
}

// Your assignment is to read three space-separated values from stdin (ReadStdIn).  They will be an integer, a double, and a "single word" string, ending at the first whitespace character (in that order).  You must then print them to stdout on separate lines.
void ReadStdIn()
{
    std::string input;
    do
    {
        std::getline(std::cin, input);
        std::cout << input << std::endl;
    } while (input != "");
}

// You must write three functions named WriteOut, each with a single parameter.  One will take a string, one will take an integer, and one will take a double.  All functions will return an integer. 
// print the parameter to stdout and return 1 if your input is a string
// print the parameter to stdout and return 2 if your input is an integer
// print the parameter to stdout and return 3 if your input is a double
int WriteOut(std::string output)
{
    return 1;
}

int WriteOut(int output)
{
    return 2;
}

int WriteOut(double output)
{
    return 3;
}

//In this project, you will demonstrate that you know how to use loops to initialize an array.
// Create a function called InitializeArray that takes a single integer as a parameter (the length of the array).  The return value should be an integer vector ("vector" is a data type from the C++ Standard Template Library).
// This vector should be the length which was passed in, and initialize all values to zero.
std::vector<int> InitializeArray(int size)
{
    std::vector<int> v;
    for (int i = 0; i < size; i++)
    {
        v.push_back(0);
    }   
    return v;
}

// This project will test your ability to read in an unknown number of items from stdin.
// You will make a method named ReadStdIn2, which takes no parameters.  It will read from standard in until the input is "q", then stop.
// This method will print an integer, the number of items you have read in (not including "q").  Input is case-sensitive.
void ReadStdIn2()
{
    std::string input;
    int count = 0;

    while(std::getline(std::cin, input) && input != "q")
        count++;

    std::cout << count << std::endl;
}

// In this assignment, you will read input from stdin until you see "q", just as in the last assignment.  
// However, once you see "q", you will write everything that was inputted back out to stdout on a single line, with an end-line at the end.
void ReadWrite()
{
    std::string input;
    std::string output;

    while(std::getline(std::cin, input) && input != "q")
        output += input + " ";
    
    std::cout << output << std::endl;
}

// This will test your ability to use loops to modify arrays.  Your function will be passed a double array by reference (with the length as a second parameter.  See starter code).  When your array finishes execution, all values in the array must be incremented by one.
void LoopThrough(double *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i]++;
    }
}

//In this project, you will write a recursive program to calculate the nth Fibonacci number.  Fibonacci numbers are defined according to the formula below:
// F(0) = 0, F(1) = 1;
// F(n) = F(n-1) + F(n-2) for n > 1
// Name your function Fibonacci.  It will take an integer parameter for the value of n, and return an integer that is the nth Fibonacci number.  
int Fibonacci(int a)
{
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1;
    else
        return Fibonacci(a - 1) + Fibonacci(a - 2);
}
