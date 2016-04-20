#ifndef PA2FUNCTIONS_H_
#define PA2FUNCTIONS_H_

#include <string>

extern int ENTRIES;
extern double first, last, delta;
extern int INT_RESULT;
extern double DOUBLE_RESULT;
extern char COMMAND;
extern char IN_FILENAME[50];
extern char CHAR_FROM_INFILE[1000];
extern double DOUBLE_FROM_INFILE[1000];
extern char OUT_FILENAME[50];;
extern bool OUTFILE_SWITCH;
extern bool INFILE_SWITCH;
extern bool NO_COMPUTATION;

using namespace std;

void initialize();
bool checkCode(char);
void writeDataToFile(const char *);
void readDataFromFile(const char *);
double findNyanCatValue(double);
int factorial(int);
int fibonacci(int);
double findSqrtValue(double);
double naturalLog(double);
int findNextOddValue(int);

#endif // PA2FUNCTIONS_H
