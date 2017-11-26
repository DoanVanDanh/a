#include<iostream>
using namespace std;
int c[3][3];//ban ma dang so
int key[3][3];
int p[3][3];//ban ro dang so

//khoi tao mang ban ro va khoa+ ban ma, do ban ro co the khuyet==> minh dien cho chac
void khoiTao()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			c[i][j]=0;
			key[i][j]=0;
			p[i][j]=0;
		}
	}
}

//Hill Trai
//chuyen doi ban ro voi : chu cai -->so 
void chuyenDoiP1(string st)
{
	cout<<" \n chuyen doi ban ro vua nhap \n";
	for(int i=0;i<st.size();i++)
	{
		int a=i/3;
		int b= i-a*3;
		if(st[i]>='a' && st[i]<='z')
		{
			p[a][b]=st[i]%97;	
		}
		if(st[i]>='A' && st[i]<='Z')
		{
			p[a][b]=st[i]%65;	
		}
		cout<<p[a][b]<<endl;
	}
}

void encrypt1()
{
	cout<<"\n mã hóa hill trái:\n ";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				c[i][j]+=p[i][k]*key[k][j];
			}
			c[i][j]=c[i][j]%26;
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
		
	}
}
//so-->chu
void showC1()
{
	cout<<"\n ket qua ";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<(char)(c[i][j]+'A');
		}
	}
}

///////////////////////////
//hil phai
void chuyenDoiP2(string st)
{
	cout<<" \n chuyen doi ban ro vua nhap \n";
	for(int i=0;i<st.size();i++)
	{
		int a=i/3;
		int b= i-a*3;
		if(st[i]>='a' && st[i]<='z')
		{
			p[b][a]=st[i]%97;	
		}
		if(st[i]>='A' && st[i]<='Z')
		{
			p[b][a]=st[i]%65;	
		}
		cout<<p[b][a]<<endl;
	}
}
void encrypt2()
{
	cout<<"\n mã hóa hill trái:\n ";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				c[i][j]+=key[i][k]*p[k][j];
			}
			c[i][j]=c[i][j]%26;
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
		
	}
}




void showC2()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<(char)(c[j][i]+'A');
		}
	}
}
main()
{
	//hill trai
	//khoi tao ban ro + khoa
	cout<<"hill trái \n";
	khoiTao();
	
	//nhap ban ro dang chu --> chuyen doi sang dang so
	cout<<"nhap ban ro, vi du: paymoremo \n";
	string st;
	getline(cin,st);
	chuyenDoiP1(st);
	
	//nhap khoa k
	cout<<"\n nhap khoa k (ma tran ) 3x3 \n";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>key[i][j];
	
	cout<<endl;
	encrypt1();
	showC1();
	
	/////////////////////////////////////////////
	
	//hill phai: khoi tao lai lan nua	
	cout<<"\n \n hill phai";
	khoiTao();
		cout<<"nhap ban ro, vi du: paymoremo \n";
	fflush(stdin);
	string st2;
	getline(cin,st2);
	chuyenDoiP2(st2);
	
	//nhap khoa k
	cout<<"\n nhap khoa k (ma tran ) 3x3 \n";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>key[i][j];
	encrypt2();
	showC2();
}
