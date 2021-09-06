#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int i=0;
	int n;
	cout<<"Enter size of vector";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	printf("Input First vector:");
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	printf("Input Second vector:");
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	i=0;
   #pragma omp parallel firstprivate(i)
	{
        while(i<n){
			c[i]=a[i]+b[i];
        	i++;
        }
	}
	cout<<"Value of i after parallel block as it was firstprivate is i = "<<i<<"\n";
	cout<<"a[i]"<<"\t"<<"b[i]"<<"\t"<<"c[i]"<<"\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<"\n";
	}
    return 0;
}

