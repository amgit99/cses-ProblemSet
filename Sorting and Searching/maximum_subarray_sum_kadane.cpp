#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<map>
#include<chrono>
#include <climits>
#include<queue>

#define __ << "  " <<

using namespace std;

void solve(){
	long long n, num, max_ever = 0, max_sofar = 0, maxest = -2147483648;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> num;
		max_sofar += num;
		if(max_sofar < 0) max_sofar = 0;
		else max_ever = max(max_ever, max_sofar);
		maxest = max(maxest, num);
	}
	if(max_ever == 0) cout << maxest;
	else cout << max_ever;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("output.txt","w",stdout);

	//auto start = chrono::high_resolution_clock::now();
	solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}