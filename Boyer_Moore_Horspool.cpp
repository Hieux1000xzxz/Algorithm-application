#include<bits/stdc++.h>
using namespace std;
#define max 100
struct MayTinh{
	string TenHSX;
	char *CauHinh;
	long GiaBan;
};
struct List{
	int count=-1;
	MayTinh M[max];
};
void ThemMay(List &L, string hsx, char* ch, long gia){
	MayTinh m;
	m.TenHSX=hsx;
	m.CauHinh=ch;
	m.GiaBan=gia;
	if(L.count==max){
		cout<<"Danh sach day!"<<endl;
	}
	else{
		L.count++;
		L.M[L.count]=m;
	}
}
void HienThiDS(List &L, int n){
	for(int i=0;i<n;i++){
		cout<<L.M[i].TenHSX<<" | ";
		cout<<L.M[i].CauHinh<<" | ";
		cout<<L.M[i].GiaBan<<" | "<<endl;
	}
}
int Find(char *P, char t){
	for(int i=strlen(P)-1;i>=0;i--){
		if(P[i]==t){
			return i;
		}
	}
	return -1;
}
bool Booyer_Moore_Horspool(char *T, char *P){
	int v=strlen(P);
	int i=v-1;
	while(i<strlen(T)){
		int k=v-1;
		while(k>-1 && P[k]==T[i]){
			k--;
			i--;
		}
		if(k<0){
			return P;
		}
		else{
			int x=Find(P,T[i]);
			if(x<0){
				i=i+v;
			}
			else i=i+v-x-1;
		}
	}
	return false;
}
void Check(List L,int n, char *t,int s,List &B){
	for(int i=0;i<n;i++){
		if(Booyer_Moore_Horspool(L.M[i].CauHinh,t)==true){
			B.M[s]=L.M[i];
			s++;
		}
	}
	if(s>0){
		cout<<"So may tinh co SSD 256GB la: "<<s<<endl;
		cout<<"Danh sach may tinh co SSD 256GB: "<<endl;
		HienThiDS(B,s);
	}
	else{
		cout<<"Khong ton tai";
	}
}
int main(){
	List L,t;
	int n=5,s=0;
	ThemMay(L,"DELL","CPU 2.8GHz upto 4GHz - RAM 16GB - SSD 1TB",18000000);
	ThemMay(L,"Acer","CPU 2.8GHz upto 3.5GHz - RAM 16GB - SSD 256GB",13000000);
	ThemMay(L,"Mixi","CPU 2GHz upto 3GHz - RAM 8GB - SSD 256GB",12000000);
	ThemMay(L,"HP","CPU 2.8GHz upto 3.5GHz - RAM 16GB - SSD 512GB",15000000);
	ThemMay(L,"Toeri","CPU 2.2GHz upto 2.8GHz - RAM 8GB - SSD 512GB",10000000);
	HienThiDS(L,n);
	Check(L,n,"SSD 256GB",s,t);
	
}
