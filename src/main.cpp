#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "medianfilter.h"

using namespace std;

//#define dim_1D

int main()
{
#ifdef dim_1D

    element signal_1D[15] = {16, 23, 13, 14, 28, 20, 12, 22, 25, 11, 6, 17, 1, 10, 18};
    element *result;
    int N = sizeof(signal_1D) / sizeof(*signal_1D);
    result = (element *)malloc(N * sizeof(element));

    cout << "signal_1D elements:" << "\n";
    for (int i = 0; i < N; i++)
        std::cout << setw(3) << signal_1D[i] << ",";
    cout << endl;

    medianfilter(signal_1D, result, N);

    cout << "result elements:" << "\n";
    for (int i = 0; i < N; i++)
        std::cout << setw(3) << *(result + i) << ",";
    cout << endl;

#else

    element signal_2D[64] = {64, 2, 3, 61, 60, 6, 7, 57, 9, 55, 54, 12, 13, 51, 50, 16, 17, 47, 46, 20, 21, 43, 42, 24, 40, 26, 27, 37, 36, 30, 31, 33, 32, 34, 35, 29, 28, 38, 39, 25, 41, 23, 22, 44, 45, 19, 18, 48, 49, 15, 14, 52, 53, 11, 10, 56, 8, 58, 59, 5, 4, 62, 63, 1};
    element *result;
    int M = 8;
    int N = 8;
    result = (element *)malloc(M * N * sizeof(element));

    cout << "signal_2D elements:" << endl << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << setw(5) << *(signal_2D + (i * N + j)) << ",";
        cout << endl << endl;
    }

    medianfilter(signal_2D, result, N, M);

    cout << "result elements:" << endl << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << setw(5) << *(result + (i * N + j)) << ",";
        cout << endl << endl;
    }

#endif

    return 0;
}