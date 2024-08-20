#include<iostream>
using namespace std;
#define max 100
struct Quat{
	string HangSX;
	string Mau;
	long GiaBan;
};
struct List{
	Quat Q[max];
	int count=-1;
};
void Nhap(List &d, Quat &q, string hsx, string mau, long gia)
{
	q.HangSX=hsx;
	q.Mau=mau;
	q.GiaBan=gia;
	if(d.count==max){
		cout<<"Danh sach day!"<<endl;
	}
	else{
		d.count++;
		d.Q[d.count]=q;
	}
}
void Xuat(List &d, int n){
	for(int i=0;i<n;i++){
		cout<<d.Q[i].HangSX<<" | ";
		cout<<d.Q[i].Mau<<" | ";
		cout<<d.Q[i].GiaBan<<" | "<<endl;
	}
}
void SapXep(List &d, int n){
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(d.Q[j-1].GiaBan<d.Q[j].GiaBan){
				Quat tam=d.Q[j-1];
				d.Q[j-1]=d.Q[j];
				d.Q[j]=tam;
			}
		}
	}
}
void ThamLam(List &d, int n, long p, int u, List &v){
	long k=p;
	int i=0,tong=0,z=0;
	while(tong<=k && i<n){
		tong=tong+d.Q[i].GiaBan;
		u++;
		v.Q[z]=d.Q[z];
		z++;
		i++;
	}

	if(u>0){
		cout<<"So luong quat: "<<u<<endl;
		cout<<"Danh sach quat: \n";
		Xuat(v,u);
	}
	else cout<<"Khong tim duoc!";
	
}
int main(){
	List d,v;
	Quat q;
	int n=5;
	Nhap(d,q,"TOSI","Vang",700000);
	Nhap(d,q,"HISI","Cam",100000);
	Nhap(d,q,"OSIT","Den",300000);
	Nhap(d,q,"COII","Den",800000);
	Nhap(d,q,"BISU","Do",500000);
	Xuat(d,n);
	SapXep(d,n);
	cout<<"Danh sach sau sap xep:\n";
	Xuat(d,n);
	ThamLam(d,n,1400000,0,v);
}
