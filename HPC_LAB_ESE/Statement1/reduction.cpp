#include<iostream>
#include<omp.h>

using namespace std;

int main() {
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int array[n];
    cout<<"Enter the numbers\n";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    int sum = 0;

    #pragma omp parallel for reduction(+: sum)
    for(int i=0; i<n; i++)
    {
        cout<<"Thread "<<omp_get_thread_num()<<"Executing\n";
        sum+=array[i];
    }

    cout<<"Sum of array elements using reduction clause is "<<sum<<"\n"; 
    return 0;
}