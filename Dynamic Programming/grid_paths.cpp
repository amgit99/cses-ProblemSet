#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pi = pair<int, int>;
#define mod 1000000007

using namespace std;

void solve(){
	int n, U, L; cin >> n;
	vector<string> grid;
	string val;
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	for(int i=0; i<n; ++i){ cin >> val; grid.pb(val); }

	for(int i=0; i<n; ++i)
		if(grid[0][i]=='*') break;
		else dp[0][i] = 1;

	for(int i=0; i<n; ++i)
		if(grid[i][0]=='*') break;
		else dp[i][0] = 1;

	for(int i=1; i<n; ++i){
		for(int j=1; j<n; ++j){
			if(grid[i][j] == '*') dp[i][j] = 0;
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
		}
	}

	cout << dp[n-1][n-1];
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