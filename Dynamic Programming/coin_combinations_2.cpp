#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F firstt
#define S second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

void solve(){
	int n, t, c; cin >> n >> t;
	vector<int> dp(t+1, 0);
	set<int> coins;
	for(int i=0; i<n; ++i) {cin >> c; coins.insert(c);}
	dp[0] = 1;
	for(auto coin: coins)
		for(int i=0; i<=t; ++i)
			if(i-coin >= 0)
				dp[i] = (dp[i] + dp[i-coin])%mod;
	cout << dp[t];
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