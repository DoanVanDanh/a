#include<iostream>
using namespace std;
int main()
{
    int i=2;
    long long n;
    do{
		cout<<"nhap n= ";
   	 	cin>>n;
    }

    while(n<2);
    cout<<n<<"=";

    while(n!=1)
    {
    	if(n==i)
    	{
    		cout<<i;
    		n=n/i;
    	}
    	else if(n%i==0)
    	{
    		cout<<i<<"*";
    		
    		n=n/i;
    	}
    	else {
    		
    		i++;
    	}

    }

    return 0;
}
