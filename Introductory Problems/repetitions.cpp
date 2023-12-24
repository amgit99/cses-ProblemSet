#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	string dna;
	cin>>dna;
	int maxx=1, streak=1;
	if(dna.size()==1) cout<<1<<endl;
	else{
		for(int i=1; i<dna.size(); ++i){
			if(dna[i-1]==dna[i])streak++;
			else streak=1;
			if(streak>maxx)maxx = streak;
		}
		cout<<maxx<<endl;
	}
	return 0;
}