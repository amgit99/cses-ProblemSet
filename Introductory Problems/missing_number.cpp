#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n, value;
	cin>>n;
	unordered_set<int> us;
	for(int i=1; i<n; ++i){
		cin>>value;
		us.insert(value);
	}
	for(int i=1; i<=n; ++i)if(us.find(i)==us.end())cout<<i;
	return 0;
}