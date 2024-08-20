#include<iostream>
using namespace std;
#define max 100
struct DienThoai{
	string NhanHieu;
	int KichThuoc;
	long GiaBan;
};
struct List{
	DienThoai dt[max];
	int count=0;
};
void Nhap(List &d, DienThoai x, string nh, int kt, long gia){
	x.NhanHieu=nh;
	x.KichThuoc=kt;
	x.GiaBan=gia;
	if(d.count>max){
		cout<<"Danh sach day!!";
	}
	else{
		d.count++;
		d.dt[d.count]=x;
	}
}
void Xuat(List &d, int n){
	for(int i=1;i<=n;i++){
		cout<<d.dt[i].NhanHieu<<" | ";
		cout<<d.dt[i].KichThuoc<<" | ";
		cout<<d.dt[i].GiaBan<<" | "<<endl;
	}
}
void Xuat1(List d,int i){
	cout<<d.dt[i].NhanHieu<<" | ";
	cout<<d.dt[i].KichThuoc<<" | ";
	cout<<d.dt[i].GiaBan<<" | "<<endl;
}
void QuyHoachDong(List d, int n, int s, int x, List &a){
	int S[max][max];
	int tam=0;
	for(int j=0;j<=s;j++){
		S[0][j]=0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			S[i][j]=S[i-1][j];
			if(d.dt[i].KichThuoc<=j){
				tam=d.dt[i].GiaBan+S[i-1][j-d.dt[i].KichThuoc];

			if(S[i][j]<tam){
				S[i][j]=tam;
			}
		}
	}}
	x=S[n][s];
	cout<<"Gia Tri Max: "<<x<<endl;
	int c=n,j=s;
	cout<<"Danh sach dien thoai: "<<endl;
	while(c!=0){
		if(S[c][j]!=S[c-1][j]){
			Xuat1(d,c);
			j=j-d.dt[c].KichThuoc;
		}
		c--;
	}
}
int main(){
	List d,a;
	DienThoai k;
	int n=5,x;
	Nhap(d,k,"Samsung",2,300);
	Nhap(d,k,"Xiaomi",5,600);
	Nhap(d,k,"Sony",1,900);
	Nhap(d,k,"Nokia",3,250);
	Nhap(d,k,"Oppo",3,300);
	Xuat(d,n);
	QuyHoachDong(d,5,7,x,a);
}
