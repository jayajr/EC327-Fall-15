#include <cmath>
#include "statistics.h"

float getMean(int myArray[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += myArray[i];

    return ((float)sum / (float)size);
}

float getStdDev(int myArray[], int size)
{
    float mean = getMean(myArray, size);

    float variance = 0.0f;

    for (int i = 0; i < size; i++)
        variance += (myArray[i] - mean) * (myArray[i] - mean);

    variance /= (float)size;

    return sqrt(variance);
}
