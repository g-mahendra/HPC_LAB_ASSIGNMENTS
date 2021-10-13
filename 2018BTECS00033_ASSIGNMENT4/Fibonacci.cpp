#include <stdio.h>
#include <omp.h>

int fib(int n)
{
    int f[n + 2];
    int i;
    f[0] = 0;
    f[1] = 1;
#pragma omp ordered
    for (i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main()
{
    int n = 0;
    printf("Enter a number ( 0 based indexing ) : ");
    scanf("%d", &n);
    printf("%dth Fibonacci number is : %d\n", n, fib(n));
    return 0;
}
