#include <iostream>
using namespace std;

#include <algorithm>
#include <ctime>

string bangchuthuong = "abcdefghijklmnopqrstuvwxyz";
string bangchuhoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string key;

//random bang chu hoa
string getKey(){
	string key=bangchuhoa;
	srand(time(0));
	random_shuffle(key.begin(),key.end());
	
	return key;
}

void encypt(string st)
{
	for(int i=0;i<st.size();i++)
	{
		cout<<key[st[i]-97];
	}
}



main()
{
	cout<<bangchuthuong<<endl;
	key=getKey();
	cout<<"key ngau nhien :"<<key;

	cout<<" \n \n nhap ban ro   ";
	string st;
	getline(cin,st);
	
	cout<<"\n ban ma la:  ";
	encypt(st);
}
