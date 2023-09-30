#include<iostream>
using namespace std;
const int MAX = 100;
struct danhSach {
	int ds[MAX];
	int n;
};
void nhap(danhSach& a) {
	cout << "nhap so phan tu : ";
	for (int i = 0; i < a.n; i++)
	{
		cout << "nhap phan tu thu " << i << ":";
		cin >> a.ds[i];
	}
}
void xuatds(danhSach x) {
	for (int i = 0; i < x.n; i++)
		cout << x.ds[i] << "\t";
	cout << endl;
}
int Lds(danhSach x)
{
	return x.n;
}

void themDS(danhSach& x)
{
	int a;
	cout << "Nhap so nguyen a can them vao cuoi ds: ";
	cin >> a;
	x.ds[x.n] = a;
	x.n++;
}
void xoaDs(danhSach& x) {
	int a;
	cout << "Nhap so nguyen a ban can xoa: ";
	cin >> a;
	int i = 0;
	while (i < x.n) {
		if (x.ds[i] == a) {
			for (int j = i; j < x.n - 1; j++)
				x.ds[j] = x.ds[j + 1];
			x.n--;
		}
		else {
			i++;
		}
	}
}
void tachds(danhSach& x ) 
{
	danhSach c,l;
	c.n = 0;
	l.n = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (x.ds[i] % 2 == 0)
		{
			c.ds[i] = x.ds[i];
			c.n++;
		}
		else
		{
			l.ds[i] = x.ds[i];
			l.n++;
		}
	}
	cout << "danh sach chan:" << endl;
	xuatds(c);
	cout << "danh sach le:" << endl;
	xuatds(l);
}
int binarysearch(danhSach x, int target) {
	int trai = 0, phai = x.n - 1;
	int mid;
	while (trai <= phai) {
		 mid = trai + ( phai-trai) / 2;
		if (x.ds[mid] == target)
			return mid;
		else if (x.ds[mid] < target)
			trai = mid - 1;
		else 
			phai = mid + 1;
	}
	return -1;
}
int main() {
	cout<<"doi lol";
	danhSach x;
	nhap(x);
	xuatds(x);
	themDS(x);
	xuatds(x);
	xoaDs(x);
	xuatds(x);
	int tg;
	cout << "nhap so can tim: ";
	cin >> tg;
	int i = binarysearch(x, tg);
	if (i != -1)
		cout << "vi tri cua " << tg << " la: " << i << endl;
	else
		cout << "khong tim thay vi tri cua " << tg;
	//tachds(x);
	return 0;

}
