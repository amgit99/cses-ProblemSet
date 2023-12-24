#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	long long t, x, y, shell, start;
	cin>>t;
	while(t--){
		cin>>x>>y;
		shell = max(x,y);
		start = shell*shell;
		if(shell%2){
			if(y<x)cout<<start-(shell-1)-(shell-y)<<endl;
			else cout<<start-(x-1)<<endl;
		}
		else{
			if(y>x)cout<<start-(shell-1)-(shell-x)<<endl;
			else cout<<start-(y-1)<<endl;
		}
	}
	return 0;
}