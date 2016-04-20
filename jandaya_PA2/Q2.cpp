#include <iostream>

using namespace std;

//void PrintLine(int);
//void PrintLine(int, int);
void PrintRhombus(int);

int main()
{
    int input;
    cout << "Enter a number [1-9]: ";

    while (!(cin >> input) || input > 9 || input < 1)
    {
        cout << "Wrong input, please enter a single digit number between 1 and 9." << endl << endl
             << "Enter a number [1-9]:";
        cin.clear();
        cin.ignore(999, '\n');
    }

    PrintRhombus(input);
}

void PrintRhombus(int input)
{
    static int midpoint = 1;

    if ( input == 1 )                           //Base Case
    {
        // Prints out middle line
        for (int i = 1; i < midpoint; i++)      // 1 to user input
            cout << i << " ";

        for (int i = midpoint; i > 0; i--)      // User input - 1 to 1
            cout << i << " ";

        if (midpoint != 1)
            cout << endl;
    }

    if ( input > 1 )
    {
        //Prints out lines above middle line
        for (int i = 0; i < input - 1; i++)     // Print Spaces before 1
            cout << "  ";

        for (int i = 1; i <= midpoint; i++)     // Print 1 to midpoint
            cout << i << " ";

        for (int i = midpoint - 1; i > 0; i--)  // Print midpoint - 1 to 1
            cout << i << " ";

        cout << endl;

        midpoint ++;
        PrintRhombus(input - 1);            // Calls recursively until base case (the middle line).
        midpoint --;

        //Prints out lines below middle line
        for (int i = 0; i < input - 1; i++)     // Print Spaces before 1
            cout << "  ";

        for (int i = 1; i <= midpoint; i++)     // Print 1 to midpoint
            cout << i << " ";

        for (int i = midpoint - 1; i > 0; i--)  // Print midpoint - 1 to 1
            cout << i << " ";

        cout << endl;
    }

    return;
}

/*

//These functions would make the PrintRhombus function look so much cleaner, but they're not allowed :(
//The printing of lines is exactly the same, so you can replace them with a function
//Only the middle line is different

void PrintRhombus(int input)
{
    static int midpoint = 1;

    if ( input == 1 )                       // Prints out middle line
        PrintLine(midpoint);                // Prints middle line

    if ( input > 1 )
    {
        PrintLine(input, midpoint);         // Prints lines above middle line
        cout << endl;

        midpoint ++;
        PrintRhombus(input - 1);            // Calls recursively until base case (the middle line).
        midpoint --;

        PrintLine(input, midpoint);         // Prints lines below middle line
        if (midpoint > 1)
        cout << endl;                       // Newline if not the last line
    }

    return;
}

void PrintLine(int midpoint)                // Function to print middle line
{
    for (int i = 1; i < midpoint; i++)     // 1 to user input
        cout << i << " ";

    for (int i = midpoint; i > 0; i--)      // User input - 1 to 1
        cout << i << " ";

    if (midpoint != 1)
        cout << endl;
}

void PrintLine(int input, int midpoint)     // Overloaded function to print every line
{
    for (int i = 0; i < input - 1; i++)     // Print Spaces before 1
        cout << "  ";

    for (int i = 1; i <= midpoint; i++)     // Print 1 to midpoint
        cout << i << " ";

    for (int i = midpoint - 1; i > 0; i--)  // Print midpoint - 1 to 1
        cout << i << " ";
}
*/
