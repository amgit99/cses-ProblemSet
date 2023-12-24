#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pi = pair<int, int>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> dp(n+1, 1e9);
	for(int i=0; i<=min(9,n); ++i) dp[i] = 1;
	for(int i=10; i<=n; ++i){
		set<int> digits;
		int temp = i;
		while(temp>0) {digits.insert(temp%10); temp/=10;}
		for(auto d: digits)
			if(d!=0 && i-d>=0) dp[i] = min(dp[i], 1+dp[i-d]);
	}
	cout << dp[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	//auto start = chrono::high_resolution_clock::now();
	solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}