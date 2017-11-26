#include<iostream>
using namespace std;
void encrypt(string st, int key)
{
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='a' && st[i]<='z')//dufng ham kiem tra
		{
			//  (st[i] + key - 'a' ) --> (int): de phep chia cho %26 chinh xac nhat
			//  + 'A' ==> khoi phuc va chuyen thanh chu in hoa
			cout<<(char)((st[i] + key - 'a' ) % 26 + 'A');
		}
	}
}
void decypt(string st)
{
	for(int i=1;i<=25;i++)
	{
		for(int j=0;j<st.size();j++)
			if(st[j]>='A'&&st[j]<='Z')
			{
				// key == i , +i( not -i) : vi dang duyet tat ca cac truong hop
				cout<<(char)((st[j] - 'A' +i )%26 +'a');
			}
			
		cout<<"\n";
	}
}
main()
{
	string st;
//	cout<<"ma hoa - nhap xau(chu thuong), vi du: abcd \n";
//	getline(cin,st);
//	
//	int key;
//	cout<<"nhap key: vi du: 2 hay 27,... ";
//	cin>>key;
//	
//	encrypt(st,key);
	
	
	
	cout<<" \n \n \n giai ma - nhap xau (chu in hoa), vi du: ABCD \n ";
	fflush(stdin);
	getline(cin,st);
	
	decypt(st);
	
}
