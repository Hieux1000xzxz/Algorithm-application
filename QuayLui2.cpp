#include<iostream>
using namespace std;
int x[100],m=4,n=7;
void show(int a[]){
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}}
void Try(int k){
	for(int i=x[k-1]+1;i<=n-m+k;i++){
		x[k]=i;
		if(k==m){
			show(x);
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
