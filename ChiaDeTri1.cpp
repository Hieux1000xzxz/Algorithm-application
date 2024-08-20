#include<iostream>
using namespace std;
int ChiaDeTri(int a[],int n,int l, int r, int &tong){
	if(l==r){
		tong=tong+a[l];
	}
	else{
		int m=(l+r)/2;
		ChiaDeTri(a,n,l,m,tong);
		ChiaDeTri(a,n,m+1,r,tong);
	}
}
int main(){
	int n=5;
	int tong=0;
	int a[n]={1, 5, 9, 11, 20};
	ChiaDeTri(a,n,0,4,tong);
	cout<<tong;
}
