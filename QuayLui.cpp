#include<iostream>
using namespace std;
int x[100];
void show(int a[],int n){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
}
void Try(int k){
	for(int i=0;i<=1;i++){
		x[k]=i;
		if(k==4){
			show(x,4);
			cout<<endl;
		}
		else{
			Try(k+1);
		}
	}
}
int main(){
	Try(1);
}
