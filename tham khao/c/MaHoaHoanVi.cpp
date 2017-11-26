#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
string taoChuoiHoanVi(string key)
{
	string key_hoan_vi="";
	int length=key.length();
	for (int gioihan = length; gioihan >=1 ; gioihan--)
	{
		int vitri=rand()%gioihan;
		key_hoan_vi=key_hoan_vi+key[vitri];
		swap(key[gioihan-1],key[vitri]);
	}
	return key_hoan_vi;
}
void khoiTaoMaTranP(string ban_goc,int &m,int n,char P[][50])
{
	int length=ban_goc.length();
	m = length/n;
	if((length%n)!=0)
	{
		m+=1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i*n+j>=length)
			{
				P[i][j]='a';
			}
			else {
				P[i][j]=ban_goc[i*n+j];
			}
		}
	}
}
int tim_vi_tri_cu(char c,string key){
	int length=key.length();

	for (int i = 0; i < length; i++)
	{
		if(c==key[i])
		{
			return i;
		}
	}
}
void khoiTaoMaTranP1(int m,int n,string key, string key_hoan_vi, char P[][50],char P1[][50])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int vitri=tim_vi_tri_cu(key_hoan_vi[j],key);
			P1[i][j]=P[i][vitri];
		}
	}
}
string tao_ban_ma(int m,int n, char P1[][50])
{
	string ban_ma="";
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<m;j++){
				ban_ma=ban_ma+P1[j][i];
		}
	}
	return ban_ma;
}

void xuatMaTran(int m,int n,char A[][50])
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

int main(){
	srand(time(NULL));
	int m,n,so_lan_hv;
	string key;
    string key_hoan_vi;
	string ban_ma;
	char P[50][50];
	char P1[50][50];
	cout<<"nhap key :";
	cin>>key;

	string ban_goc;
	cout<<"nhap ban goc :";
	cin >> ban_goc;

	cout<<"nhap so lan hoan vi ";
    cin>>so_lan_hv;
	n=key.length();
    for(int i=1;i<=so_lan_hv;i++)
    {
    cout<<"\nlan hoan vi thu "<<i<<endl;
	key_hoan_vi="";
	key_hoan_vi=taoChuoiHoanVi(key);
	cout<<"key khi hoan vi :"<<key_hoan_vi<<endl;
	khoiTaoMaTranP(ban_goc,m,n,P);
	cout<<"ma tran P :"<<endl;
	xuatMaTran(m,n,P);
	khoiTaoMaTranP1(m,n,key,key_hoan_vi,P,P1);
	cout<<"ma tran P1 do hoan vi cua P :"<<endl;
	xuatMaTran(m,n,P1);

	ban_ma=tao_ban_ma(m,n,P1);
	cout<<"ban ma thu duoc la: "<<ban_ma<<endl;
	ban_goc=ban_ma;
	}
	return 0;
}
