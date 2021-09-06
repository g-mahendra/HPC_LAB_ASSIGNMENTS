#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	int n;
	int i;
	cout<<"Enter Vector Size:"<<"\n";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	cout<<"Enter First vector"<<"\n";

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Enter Second Vector"<<"\n";
	for(i=0;i<n;i++){
		cin>>b[i];
	}
   #pragma omp parallel
	{
		#pragma omp for
 		for(i=0; i<n; i++) 
 		{c[i]=b[i]+a[i];} 		
	}
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for(i=0;i<n;i++){
    	printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
	}
	return 0;


}
