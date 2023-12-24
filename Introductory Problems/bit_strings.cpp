#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long ans=1;
	while(n--) ans = (ans<<1)%1000000007;
	cout<<ans<<endl;
	return 0;
}