#include <fstream>
#include <stdio.H>
#include <stdlib.h>
#include <time.h>

#include "q3func.h"

int DataToFile(const char* filename, int N, int M)
{
    srand(time(NULL));

    std::ofstream outfile;
    outfile.open(filename);

    for (int i = 0; i < N; i++)
    {
        outfile << rand() % (M + 1);
        if (i < N - 1)
            outfile << '\n';
    }

    return 0;
}


int DataFromFile(const char* filename, int myArray[], int &size)
{
    std::ifstream infile;
    infile.open(filename);

    if(infile.fail())
        return 1;

    else
    {
        int temp = 0;

        for (int i = 0; !infile.eof(); i++)
        {
            infile >> myArray[i];
            temp = i;
        }

        size = temp;

        if (size == 0)
            return 1;

        return 0;
    }

}
