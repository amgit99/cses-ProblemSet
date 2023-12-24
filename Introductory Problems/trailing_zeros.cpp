#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	long long n, fives=0;
	cin>>n;
	while(n>0){
		fives+=n/5;
		n/=5;
	}
	cout<<fives<<endl;
	return 0;
}