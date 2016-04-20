#include <iostream>

using namespace std;

int* ReverseMultiply(int*, int);

int main()
{
    int length;

    cout << "Enter the number of entries: ";
    cin >> length;

    if (length <= 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Invalid size entered.";
    }

    else
    {
        int myArray[length];

        for (int i = 0; i < length; i++)
        {
            cout << "Entry " << i << " is: ";
            cin >> myArray[i];
        }

        cout << "*****" <<endl
             << "Original array is: ";

        for (int i = 0; i < length; i++)
        {
            cout << myArray[i] << " ";
        }

        cout << "and the address of the zero element is "
             << &myArray <<endl;


        int* output = ReverseMultiply(myArray, length);

        cout << "Final array is ";

        for (int i = 0; i < (length * 2 + 1); i++)
        {
            cout << *(output + i) << " ";
        }

        cout << " and the address of the zero element is: "
             << &output;
    }
}

int* ReverseMultiply(int* myArray, int length)
{
    int product = 1;
    int* resultArray = new int[length * 2 + 1];

    for (int i = 0, j = (length - 1); i < length; i++, j--)
    {
        *(resultArray + i) = myArray[i];
        resultArray[length + i] = myArray[j];
    }

    for (int i = 0; i < (length * 2); i++)
    {
        product *= resultArray[i];
    }

    resultArray[length * 2] = product;
    return resultArray;
}

