#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	long long n, count = 0;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0; i<n; ++i)cin>>arr[i];	
	for(int i=1; i<n; ++i){
		if(arr[i]<arr[i-1]){
			count += arr[i-1]-arr[i];
			arr[i] += arr[i-1]-arr[i];
		}
	}
	cout<<count;
	return 0;
}