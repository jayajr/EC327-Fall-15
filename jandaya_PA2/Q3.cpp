#include <iostream>
#include "statistics.h"
#include "q3func.h"

using namespace std;

int main()
{
    char* filename = "numbers.txt";

    int size = 0;
    int* myArray = new int;

    if (DataFromFile(filename, myArray, size) == 0)
    {
        int maximum = myArray[0];
        int minimum = myArray[0];
        float mean = getMean(myArray, size);
        float stdev = getStdDev(myArray, size);

        cout.precision(2);
        cout << fixed
             << "Array size is: " << size << endl
             << "Mean is: " << mean << endl
             << "StdDev is: " << stdev << endl
             << "Array values forward are: ";

        for (int i = 0; i < size; i++)
        {
            cout << myArray[i];
            if (myArray[i] > maximum)
                maximum = myArray[i];

            if (myArray[i] < minimum)
                minimum = myArray[i];

            if (i < size - 1)
                cout << ", ";
            else if (i == size - 1)
                cout << endl;
        }

        cout << "Array values reverse are: ";

        for (int i = size - 1; i >= 0; i--)
        {
            cout << myArray[i];

            if (i > 0)
                cout << ", ";

            else if (i == 0)
                cout << endl;
        }

        cout << "The largest array value is: " << maximum << endl
             << "The smallest array value is: " << minimum;
    }

    if (DataFromFile(filename, myArray, size) == 1)
        cout << "Array size is: 0" << endl
             << "Mean is: None" << endl
             << "StdDev is: None" << endl
             << "Array values forward are: None" << endl
             << "Array values reverse are: None" << endl
             << "The largest array value is: None" << endl
             << "The smallest array value is: None";


}
