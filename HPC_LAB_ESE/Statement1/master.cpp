#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n = 10;
    int i;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = i;
    }
    i = 0;
#pragma omp parallel num_threads(8) shared(n) private(i)
#pragma omp master
    {
        cout << "master Thread " << omp_get_thread_num() << " running\n";
        array[5] *= 5;
    }
#pragma omp for
    for (int i = 0; i < n; i++)
    {
        if (i == 5)
        {
            continue;
        }
        else
            array[i] *= 2;
    }

    cout << "Array elements after modificatin\n";

    for (int i = 0; i < n; i++)
        cout << array[i] << "\t";
    return 0;
}