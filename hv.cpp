#include <iostream>
using namespace std;
#include <algorithm>
#include <ctime>


string st;
string key;

string a[200][200];

void taoBang()
{
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
			a[i][j]="-";
	}
}

int arrayKeyRandom[200];
string getKey(){
	srand(time(0));
	
	
	int randNum = rand()%(key.size()-0 + 1) + 0;
	arrayKeyRandom[i]=randNum;
	
	return key;
}
void doDuLieuVaoBang(string st,string key)
{
//	//kich thuoc bang
//	int m=key.length();
//	int n=st.length()%m;
	
	//do du lieu vao bang
	for(int i=0;i<st.size();i++)
	{
		int aa=i/3;
		int bb= i-aa*3;
		
		a[aa][bb]=st[i];	
	}
	//random key
	string keyMoi= getKey();
	cout<<"\n key sau khi random "<<keyMoi; 	
	//sap lai bang
	
	
	//lay gia tri moi cua bang==> ket qua
}


main()
{

	
	cout<<"nhap ban ro";
	getline(cin,st);
	cout<<st;
	
	cout<<" \n nhap key";	
	fflush(stdin);
	getline(cin,key);
	cout<<key;
	
		taoBang();
	
	doDuLieuVaoBang(st,key);
}

