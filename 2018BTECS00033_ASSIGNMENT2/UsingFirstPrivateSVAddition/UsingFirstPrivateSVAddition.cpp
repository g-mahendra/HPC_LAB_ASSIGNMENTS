#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	int n,scalar;
	cout<<"Enter Vector size"<<"\n";
	cin>>n;
	int a[n+1];
	int i=0;
	int c[n+1];
	cout<<"Enter vector values"<<"\n";

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"enter scalar value "<<"\n";
	cin>>scalar;
	i=0;
    #pragma omp parallel firstprivate(i)
	{
        while(i<n){
        	c[i]=a[i]+scalar;
        	i++;
        }
	}

 	cout<<"Output vector"<<"\n";
 	for(i=0;i<n;i++){
 		cout<<"a[i]+scalar="<<a[i]<<"+"<<scalar<<"="<<c[i]<<" "<<"\n";
 	}
  return 0;	
}
