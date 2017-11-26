#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

string bangchuthuong = "abcdefghijklmnopqrstuvwxyz";
string bangchuhoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string getkey(){
	string key = bangchuhoa;
	srand(time(0));
	random_shuffle(key.begin(),key.end());
	return key;
}

int getnumber(string banma, char c){
	for(int i = 0; i < banma.length(); i++){
		if(banma[i] == c) return i;
	}
}

string encode(string banro, string key ){
	string banma;
	char c[26];
    for(int i = 0; i < banro.length() ; i++ ){
		int number = getnumber(bangchuthuong,banro[i]);
		c[i] = key[number]; 
    }
    banma = c;
    return banma;
}
int main(){
	string key = getkey();
	string banro;
	cout << "Chu ban dau : \t\t\t" << bangchuthuong << endl ;
	cout << "Chu thay the ( Ngau nhien ) : \t" << key <<endl;
	cout << "Nhap vao ban ro : ";
	cin >> banro;
	cout << "Khoa duoc tao ra la : " << encode(banro,key);
	return 0;
}
