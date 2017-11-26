#include <iostream>
#include <string>
using namespace std;

string banchuthuong = "abcdefghijklmnopqrstuvwxyz";
string banchuhoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
int getnumber(string banma, char c){
	for(int i = 0; i < banma.length(); i++){
		if(banma[i] == c) return i;
	}
}

string mahoa(string banro, int k ){
	string banma = "";
	char c[banro.length() -1];
    for(int i = 0; i < banro.length(); i++ ){
        int number = getnumber(banchuthuong,banro[i]);
        number = (number + k) % 26;
       	c[i] = banchuhoa[number];
    }
    banma = c;
    return banma;
}
string giaima(string banma, int k){
	string banro = "";
	char c[banma.length() -1];
    for(int i = 0; i < banma.length(); i++ ){
        int number = getnumber(banchuhoa,banma[i]);
        number = (number - k) % 26;
       	c[i] = banchuthuong[number];
    }
    banro = c;
    return banro;
}

int main()
{
    string banro = "meetmeafterthetogaparty";
    string banma;
    int k = 3;
    //cout << "Nhap ban ro : ";
    //cin >> banro;
    //cout << "nhap khoa k : ";
    //cin >> k;
    banma = mahoa(banro, k);
    cout << "Ban ma vua ma hoa xong la : " << banma << endl;
    banro = giaima(banma,k);
    cout << "Ban ro vua giai ma lai tu ma " << banma <<" la : " << banro << endl;
    return 0;
}
