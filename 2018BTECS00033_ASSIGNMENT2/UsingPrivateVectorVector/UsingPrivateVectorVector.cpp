#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int i;
	int index=0;
	int n;
	cout<<"Enter Vector size";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	printf("Enter First vector:");
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	printf("Enter Second vector:");
	for(i=0;i<n;i++){
		cin>>b[i];
	}
   #pragma omp parallel private(index)
	{
        index=0;
        while(index<n){
        	c[index]=a[index]+b[index];
        	index++;
        }

	}
	cout<<"a[i]"<<"\t"<<"b[i]"<<"\t"<<"c[i]"<<"\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<"\n";
	}
    return 0;
}
