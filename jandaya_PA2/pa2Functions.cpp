#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

#include "pa2Functions.h"

int ENTRIES = 10;
double first, last, delta;
int INT_RESULT;
double DOUBLE_RESULT;
char COMMAND;
char IN_FILENAME[50];
char CHAR_FROM_INFILE[1000];
double DOUBLE_FROM_INFILE[1000];
char OUT_FILENAME[50];
bool OUTFILE_SWITCH = false;
bool INFILE_SWITCH = false;
bool NO_COMPUTATION = false;

using namespace std;

void initialize()                                    //Prints stuff
{
        cout << "EC327: Introduction to Software Engineering" <<endl
             << "Fall 2015" <<endl
             << "Programming Assignment 2" <<endl
             << "Value of Entries is: ";
        cout << ENTRIES <<endl;
};

bool checkCode(char input)                          //Returns false if not a valid function
{
    bool output = false;                            //output default false

    if (input == 'F' || input == 'f' ||
        input == 'B' || input == 'b' ||
        input == 'R' || input == 'r' ||
        input == 'D' || input == 'd' ||
        input == 'L' || input == 'l' ||
        input == 'N' || input == 'n' ||
        input == 'I' || input == 'i' ||
        input == 'O' || input == 'o' ||
        input == 'Q' || input == 'q' )
        output = true;                              //output only true if valid function

    return output;
};

double findNyanCatValue(double num)
{
    return (2 * num) + (num * pow (6, num));
};

int factorial(int num)
{
	if (num == 0)
		return  1;
	else
		return num * factorial(num - 1);
};

int fibonacci(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	else
		return fibonacci(index - 1) + fibonacci(index - 2);
};


double findSqrtValue(double num)
{
    return sqrt(num);
};

double naturalLog(double num)
{
    return log(num);
};
int findNextOddValue(int num)
{
    int output;
    if (num % 2 == 0)
        output = num + 1;
    else
        output = num;

    return output;
};

void writeDataToFile(const char* filename)          //Initializes writing to file.
{
    if (OUTFILE_SWITCH == true)
    {
        static bool writeSwitch = false;

        ofstream outfile;
        if (writeSwitch == false)
        {
            outfile.open(filename);
            writeSwitch = true;


        }

        else if (writeSwitch == true)
        {
            outfile.open(filename, ios_base::app);
            outfile.precision(4);
            outfile << fixed;

            if (INFILE_SWITCH == false && (COMMAND != 'Q' || COMMAND != 'q'))
                outfile << "Please enter command code: " << COMMAND <<endl;

            if (COMMAND != 'Q' || COMMAND != 'q')
            {
                if (INFILE_SWITCH == false)
                    outfile << "Please enter command parameters: ";

                if (COMMAND == 'F' || COMMAND == 'f')
                    outfile << first <<endl
                            << "factorial(" << first <<") = " << INT_RESULT <<endl;

                if (COMMAND == 'B' || COMMAND == 'b')
                    outfile << first <<endl
                            << "fibonacci(" << first <<") = " << INT_RESULT <<endl;

                if (COMMAND == 'R' || COMMAND == 'r')
                    {
                        outfile << (int)first << " " << (int)last << " " << (int)delta <<endl;

                        if (NO_COMPUTATION == true)
                            outfile <<"No computation needed." << endl;
                        else if (NO_COMPUTATION == false)
                            for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                                {
                                    DOUBLE_RESULT = findSqrtValue(first + (i * delta));

                                    outfile << "Square root of " << first + (i * delta) << " = "
                                         << DOUBLE_RESULT << endl;
                                }

                    }

                if (COMMAND == 'D' || COMMAND == 'd')
                    {
                        for(int i = 0, j = 0; ((i < ENTRIES) && (j < 1 + (last - first) / 2)); i++, j++)
                        {
                            INT_RESULT = findNextOddValue(first) + (i * 2);
                            outfile << INT_RESULT;

                            if (i < (ENTRIES - 1) && j < (last - first) / 2)
                                outfile << ", ";
                        }

                            outfile << endl;
                    }

                if (COMMAND == 'L' || COMMAND == 'l')
                    {
                        outfile << (int)first << " " << (int)last << " " << (int)delta <<endl;

                        if (NO_COMPUTATION == true)
                            outfile <<"No computation needed." << endl;
                        else if (NO_COMPUTATION == false)
                            for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                                {
                                    DOUBLE_RESULT = naturalLog(first + (i * delta));

                                    outfile << "Natural log of " << first + (i * delta) << " = "
                                            << DOUBLE_RESULT << endl;
                                }
                    }

                if (COMMAND == 'N' || COMMAND == 'n')
                    {
                        outfile << (int)first << " " << (int)last << " " << (int)delta <<endl;

                        if (NO_COMPUTATION == true)
                            outfile <<"No computation needed." << endl;
                        else if (NO_COMPUTATION == false)
                           for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                            {
                                DOUBLE_RESULT = findNyanCatValue(first + (i * delta));

                                outfile << "NyanCat value of " << first + (i * delta) << " = "
                                        << DOUBLE_RESULT << endl;
                            }

                    }
                if (COMMAND == 'I' || COMMAND == 'i')
                    {
                        INFILE_SWITCH = true;

                        readDataFromFile(IN_FILENAME);
                        //INFILE_SWITCH = true;

                        int dblIndex = 0;
                        int charIndex = 0;

                        while (CHAR_FROM_INFILE[charIndex])
                        {
                            NO_COMPUTATION = false;
                            if (CHAR_FROM_INFILE[charIndex] == 'F' || CHAR_FROM_INFILE[charIndex] == 'f')
                            {
                                first = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                INT_RESULT = factorial(first);

                                outfile << "factorial(" << (int)first << ") = "
                                        << INT_RESULT << endl;
                            }

                            else if (CHAR_FROM_INFILE[charIndex] == 'B' || CHAR_FROM_INFILE[charIndex] == 'b')
                            {
                                first = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                INT_RESULT = fibonacci(first);

                                outfile << "fibonacci(" << (int)first << ") = "
                                        << INT_RESULT << endl;
                            }
                            else if (CHAR_FROM_INFILE[charIndex] == 'R' || CHAR_FROM_INFILE[charIndex] == 'r')
                            {
                                first = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                last = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                delta = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                if(delta <= 0 || first > last)
                                    {
                                        outfile << "No computation needed." <<endl;

                                        NO_COMPUTATION = true;
                                    }

                                else
                                {
                                    for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                                    {
                                        DOUBLE_RESULT = findSqrtValue(first + (i * delta));

                                        outfile <<"Square root of " << first + (i * delta) << " = "
                                                <<DOUBLE_RESULT << endl;

                                    }
                                }
                            }

                            else if (CHAR_FROM_INFILE[charIndex] == 'D' || CHAR_FROM_INFILE[charIndex] == 'd')
                            {
                                first = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                last = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                //Should probably print out something for when first > last
                                for(int i = 0, j = 0; ((i < ENTRIES) && (j < 1 + (last - first) / 2)); i++, j++)
                                {
                                    INT_RESULT = findNextOddValue(first) + (i * 2);
                                    outfile << INT_RESULT;

                                    if (i < (ENTRIES - 1) && j < (last - first) / 2)
                                        {
                                            outfile << ", ";
                                        }
                                }

                                outfile << endl;
                            }

                            else if (CHAR_FROM_INFILE[charIndex] == 'L' || CHAR_FROM_INFILE[charIndex] == 'l')
                            {
                                first = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                last = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                delta = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                if(delta <= 0 || first > last)
                                    {
                                        outfile << "No computation needed." <<endl;

                                        NO_COMPUTATION = true;
                                    }

                                else
                                {
                                    for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                                    {
                                        DOUBLE_RESULT = naturalLog(first + (i * delta));

                                        outfile <<"Natural log of " << first + (i * delta) << " = "
                                                <<DOUBLE_RESULT << endl;

                                    }
                                }
                            }
                            else if (CHAR_FROM_INFILE[charIndex] == 'N' || CHAR_FROM_INFILE[charIndex] == 'n')
                            {
                                first = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                last = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                delta = DOUBLE_FROM_INFILE[dblIndex];
                                dblIndex++;

                                if(delta <= 0 || first > last)
                                    {
                                        outfile << "No computation needed." <<endl;
                                        NO_COMPUTATION = true;
                                    }

                                else
                                {
                                    for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                                    {
                                        DOUBLE_RESULT = findNyanCatValue(first + (i * delta));

                                        outfile <<"NyanCat value of " << first + (i * delta) << " = "
                                                <<DOUBLE_RESULT << endl;

                                    }
                                }

                            }

                            charIndex++;
                        }
                    }

            }
            else if (COMMAND == 'Q' || COMMAND == 'q')
                outfile << COMMAND;

            cout <<"O ran once ";
            return;
        }
    }
};


void readDataFromFile(const char* filename)
{
    int line = 1;
    int dblIndex = 0;
    int chrIndex = 0;

    string inString;

    ifstream infile;
    infile.open(filename, ios::in);

    while (getline(infile,inString))
    {
        stringstream stream(inString);

        if (line % 2 == 1)
        {
            stream >> CHAR_FROM_INFILE[chrIndex];
            chrIndex++;
            if (!stream)
                break;
        }

        else if (line % 2 == 0)
        {
            while (true)
            {
                stream >> DOUBLE_FROM_INFILE[dblIndex];
                dblIndex++;
                if (!stream)
                    break;
            }
        }

        line++;
    }
};
