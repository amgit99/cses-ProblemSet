#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n, i=1;
	cin>>n;
	if(n==1)cout<<1;
	else if(n<=3)cout<<"NO SOLUTION";
	else if(n==4)cout<<2<<" "<<4<<" "<<1<<" "<<3;
	else{
		while(i<=n){
			cout<<i<<" ";
			i+=2;
		}
		i=2;
		while(i<=n){
			cout<<i<<" ";
			i+=2;
		}
	}
	return 0;
}