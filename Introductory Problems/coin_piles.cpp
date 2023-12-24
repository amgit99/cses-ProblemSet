#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(long long a, long long b){
	if(a > 2*b){
		cout << "NO" << endl;
		return;
	}
	if((a+b)%3==0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	long long t, a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a>b)solve(a, b);
		else solve(b, a);
	}
	return 0;
}