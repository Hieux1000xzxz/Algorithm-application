#include<iostream>
using namespace std;
void show(int a[],int n){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
}
void Try(int k, int x[],int n,int dd[]){
	for(int i=1;i<=n;i++){
		if(dd[i]==0){
			x[k]=i;
			dd[i]=1;
			if(k==n){
				show(x,n);
				cout<<endl;
			}
			else{
				Try(k+1,x,n,dd);
			}
			dd[i]=0;
		}
	}
}
int main(){
	int x[100],n=5;
	int dd[100];
	for(int i=0;i<=n;i++){
		dd[i]=0;
	}
	Try(1,x,n,dd);
}
