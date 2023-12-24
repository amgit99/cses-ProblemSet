#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pi = pair<int, int>;

using namespace std;

void solve(){
	int n, p, take, no_take; cin >> n >> p;
	vector<int> prices(n), pages(n);
	for(int i=0; i<n; ++i) cin >> prices[i];
	for(int i=0; i<n; ++i) cin >> pages[i];

	vector<vector<int>> dp(n+1, vector<int> (p+1, 0));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=p; ++j){
			if(prices[i-1] <= j)take = pages[i-1] + dp[i-1][j-prices[i-1]];
			else take = 0;
			no_take = dp[i-1][j];
			dp[i][j] = max(take, no_take);
		}
	}
	cout << dp[n][p];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	auto start = chrono::high_resolution_clock::now();
	solve();
	auto stop = chrono::high_resolution_clock::now();
	cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}