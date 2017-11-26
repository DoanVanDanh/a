#include<iostream>
using namespace std;
string chuoi_ki_tu="abcdefghijklmnopqrstuvwxyz";

int letterToNum(char c)
{
	for (int vitri = 0; vitri < 25; vitri++)
	{
		if (c==chuoi_ki_tu[vitri])
		{
			return vitri;
		}
	}
}

char numToLetter(int vitri)
{
	return chuoi_ki_tu[vitri];
}
void nhapMaTranK(int n,int K[][50])
{
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					cout<<"nhap K["<<i<<"]["<<j<<"]=";
					cin>>K[i][j];
				}
		}
}
void xuatMaTran(int m,int n,int A[][50])
{
	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				{
					cout<<A[i][j]<<" ";
				}
			cout<<endl;
		}
}
void khoiTaoMaTranP(string ban_goc,int &m,int n,int P[][50])
{
	int lent=ban_goc.length();
	m = lent/n;
	if((lent%n)!=0)
	{
		m+=1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i*n+j>=lent)
			{
				P[i][j]=0;
			}
			else {
				P[i][j]=letterToNum(ban_goc[i*n+j]);
			}
		}
	}
}
void khoiTaoMaTranC(int m,int n,int P[][50],int K[][50],int C[][50])
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++){
			int temp=0;
			for(int k=0;k<n;k++)
			{
			temp+=P[i][k]*K[k][j];
			}
			C[i][j]=temp%26;
		}
	}
}
string taoBanMa(int length,int m,int n,int C[][50])
{
	string ban_ma="";
	for (int i = 0; i < m ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if( i*n+j >= length)
			{
				break;
			}
			else {
				ban_ma=ban_ma+""+numToLetter(C[i][j]);
			}
		}
	}
	return ban_ma;
}
void chuyenvi(int m,int n,int A[][50],int A1[][50])
{
	// duyệt mang A
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;j++)
		{
			A1[i][j]=A[j][i];
		}
	}
}
int main()
{
	int P[50][50];
	int P1[50][50];
	int C[50][50];
	int K[50][50];
	int n;
	int m;
	string ban_goc;
	cout<<"nhap cap n cua ma tran K (Key)= ";
	cin>>n;
	cout<<"nhap vao ban goc: ";
	cin>>ban_goc;

	nhapMaTranK(n,K);
	cout<<"ma tran Khoa K"<<endl;
	xuatMaTran(n,n,K);

	khoiTaoMaTranP(ban_goc,m,n,P);
	cout<<"ma tran P "<<endl;
	xuatMaTran(m,n,P);

	khoiTaoMaTranC(m,n,P,K,C);
	cout<<"ma tran C"<<endl;
    xuatMaTran(m,n,C);

    string ban_ma=taoBanMa(ban_goc.length(),m,n,C);
    cout<<"bang ma tao thanh : "<<ban_ma<<endl;
    chuyenvi(m,n,P,P1);
    cout<<"ma tran chuyen vi cua P , P1 la:"<<endl;
    int cot = m ,hang = n;
    xuatMaTran(hang,cot,P1);
    return 0;
}
