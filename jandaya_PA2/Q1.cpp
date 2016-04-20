#include <fstream>
#include <iostream>
#include <string>


#include "pa2Functions.h"

using namespace std;

int main()
{
    //Program setup
    char code;
    initialize();
    cout.precision(4);
    cout << fixed;

    //Continue loop until code == 'Q' or code code == 'q'
    while(code != 'Q' && code != 'q') //Quit
    {
        do
        {
            cout << "Please enter command code: ";
            cin >> code;
            COMMAND = code;

        }while(checkCode(code) == false);               //If input is wrong (false) keep asking

        if (code == 'Q' || code == 'q')
        {
            writeDataToFile(OUT_FILENAME);
            break;
        }

        else
            cout << "Please enter command parameters: ";
            NO_COMPUTATION = false; //Reset new computation

        {
            if(code == 'F' || code == 'f') //Factorial
            {
                cin >> first;

                INT_RESULT = factorial(first);

                cout << "factorial(" << (int)first << ") = "
                     << INT_RESULT << endl;

                writeDataToFile(OUT_FILENAME);
            }

            else if(code == 'B' || code == 'b') //Fibonacci
            {
                cin >> first;

                INT_RESULT = fibonacci(first);

                cout << "fibonacci(" << (int)first << ") = "
                     << INT_RESULT << endl;

                writeDataToFile(OUT_FILENAME);
            }

            else if(code == 'R' || code == 'r') //Roots
            {
                cin >> first >> last >> delta;

                if(delta <= 0 || first > last)
                    {
                        cout << "No computation needed." <<endl;
                        NO_COMPUTATION = true;
                        writeDataToFile(OUT_FILENAME);
                    }

                else
                {
                    for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                    {
                        DOUBLE_RESULT = findSqrtValue(first + (i * delta));

                        cout <<"Square root of " << first + (i * delta) << " = "
                             <<DOUBLE_RESULT << endl;
                    }
                    writeDataToFile(OUT_FILENAME);
                }
            }

            else if(code == 'D' || code == 'd') //Odd Numbers
            {
                cin >> first >> last;

                //Should probably print out something for when first > last
                for(int i = 0, j = 0; ((i < ENTRIES) && (j < 1 + (last - first) / 2)); i++, j++)
                {
                    INT_RESULT = findNextOddValue(first) + (i * 2);
                    cout << INT_RESULT;

                    if (i < (ENTRIES - 1) && j < (last - first) / 2)
                        cout << ", ";
                }

                cout << endl;

                writeDataToFile(OUT_FILENAME);
            }

            else if(code == 'L' || code == 'l') //Log
            {
                cin >> first >> last >> delta;

                if(delta <= 0 || first > last)
                    {
                        cout << "No computation needed." <<endl;
                        NO_COMPUTATION = true;
                        writeDataToFile(OUT_FILENAME);
                    }

                else
                {
                    for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                    {
                        DOUBLE_RESULT = naturalLog(first + (i * delta));

                        cout <<"Natural log of " << first + (i * delta) << " = "
                             <<DOUBLE_RESULT << endl;
                    }
                    writeDataToFile(OUT_FILENAME);
                }
            }
            else if(code == 'N' || code == 'n') //NyanCat
            {
                cin >> first >> last >> delta;

                if(delta <= 0 || first > last)
                    {
                        cout << "No computation needed." <<endl;
                        NO_COMPUTATION = true;
                        writeDataToFile(OUT_FILENAME);
                    }

                else
                {
                    for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                    {
                        DOUBLE_RESULT = findNyanCatValue(first + (i * delta));

                        cout <<"NyanCat value of " << first + (i * delta) << " = "
                             <<DOUBLE_RESULT << endl;
                    }
                    writeDataToFile(OUT_FILENAME);
                }
            }

            else if(code == 'O' || code == 'o') //Output to file
            {
                OUTFILE_SWITCH = true;
                cin >> OUT_FILENAME;
                writeDataToFile(OUT_FILENAME);
            }

            else if(code == 'I' || code == 'i') //Input from file
            {
                INFILE_SWITCH = true;
                cin >> IN_FILENAME;
                if (OUTFILE_SWITCH == true)
                    writeDataToFile(OUT_FILENAME);
                readDataFromFile(IN_FILENAME);

                int dblIndex = 0;
                int charIndex = 0;

                while (CHAR_FROM_INFILE[charIndex] != 0)
                {
                    NO_COMPUTATION = false;

                    if (CHAR_FROM_INFILE[charIndex] == 'F' || CHAR_FROM_INFILE[charIndex] == 'f')
                    {
                        first = DOUBLE_FROM_INFILE[dblIndex];
                        dblIndex++;

                        INT_RESULT = factorial(first);

                        cout << "factorial(" << (int)first << ") = "
                             << INT_RESULT << endl;

                        writeDataToFile(OUT_FILENAME);
                    }

                    else if (CHAR_FROM_INFILE[charIndex] == 'B' || CHAR_FROM_INFILE[charIndex] == 'b')
                    {
                        first = DOUBLE_FROM_INFILE[dblIndex];
                        dblIndex++;

                        INT_RESULT = fibonacci(first);

                        cout << "fibonacci(" << (int)first << ") = "
                             << INT_RESULT << endl;

                        writeDataToFile(OUT_FILENAME);
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
                                cout << "No computation needed." <<endl;
                                NO_COMPUTATION = true;
                                writeDataToFile(OUT_FILENAME);
                            }

                        else
                        {
                            for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                            {
                                DOUBLE_RESULT = findSqrtValue(first + (i * delta));

                                cout <<"Square root of " << first + (i * delta) << " = "
                                     <<DOUBLE_RESULT << endl;
                            }
                            writeDataToFile(OUT_FILENAME);
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
                            cout << INT_RESULT;

                            if (i < (ENTRIES - 1) && j < (last - first) / 2)
                                cout << ", ";
                        }

                        cout << endl;

                        writeDataToFile(OUT_FILENAME);
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
                                cout << "No computation needed." <<endl;
                                NO_COMPUTATION = true;
                                writeDataToFile(OUT_FILENAME);
                            }

                        else
                        {
                            for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                            {
                                DOUBLE_RESULT = naturalLog(first + (i * delta));

                                cout <<"Natural log of " << first + (i * delta) << " = "
                                     <<DOUBLE_RESULT << endl;
                            }
                            writeDataToFile(OUT_FILENAME);
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
                                cout << "No computation needed." <<endl;
                                NO_COMPUTATION = true;
                                writeDataToFile(OUT_FILENAME);
                            }

                        else
                        {
                            for(int i = 0, j = 0; ((i < ENTRIES) && (j < (last - first) / delta + 1)); i++, j++)
                            {
                                DOUBLE_RESULT = findNyanCatValue(first + (i * delta));

                                cout <<"NyanCat value of " << first + (i * delta) << " = "
                                     <<DOUBLE_RESULT << endl;
                            }
//                            writeDataToFile(OUT_FILENAME);
                        }

                    }

                    charIndex++;
                }

                INFILE_SWITCH = false;
            }
        }
    }
}

