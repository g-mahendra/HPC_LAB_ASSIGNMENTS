#include<iostream>
#include<omp.h>

using namespace std;

int main() {
    int count =0;
    int n;
    cout<<"Enter number limit\n";
    cin>>n;
    int array[n];

    cout<<"Enter numbers\n";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    cout<<"Counting even numbers\n";
    int i=0;
    #pragma omp parallel for
    for(i=0; i<n; i++)
    {
        if(i%2==0){
            #pragma omp critical
            {count++;}
        }
    }

    cout<<"Number of even numbers is "<<count<<"\n";
    return 0;
}