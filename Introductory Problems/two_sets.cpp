#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	long long n;
	cin>>n;
	if(((n*(n+1))/2)%2)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		if(n%2){
			cout<<n/2+1<<endl;
			for(int i=1; i<n/2+1; i+=2)cout<<i<<" "<<n-i<<" ";
			cout<<"\n"<<n/2<<endl;
			for(int i=2; i<n/2; i+=2)cout<<i<<" "<<n-i<<" ";
			cout<<n;
		}
		else{
			cout<<n/2<<endl;
			for(int i=1; i<n/2; i+=2)cout<<i<<" "<<n+1-i<<" ";
			cout<<"\n"<<n/2<<endl;
			for(int i=2; i<=n/2; i+=2)cout<<i<<" "<<n+1-i<<" ";
		}
	}
	return 0;
}