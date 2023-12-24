#include<bits/stdc++.h>

#define brr cin.tie(0) -> sync_with_stdio(0);
#define tc int t; cin >> t; while(t--)
#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

void solve(){
	int a,b; cin >> a >> b;
	vector<vector<int>> dp(max(a,b)+1, vector<int> (max(a,b)+1, 0));

	for(int i=1; i<=max(a,b); ++i) dp[0][i] = dp[i][0] = 1 + dp[0][i-1];

	for(int i=1; i<=max(a,b); ++i){
		for(int j=1; j<=i; ++j){
			if(i==j) continue;
			int ans = 1e9;
			for(int l=1; l<i; ++l) ans = min(ans, 1+dp[l][j]+dp[i-l][j]);
			for(int l=1; l<j; ++l) ans = min(ans, 1+dp[i][l]+dp[i][j-l]);
			dp[i][j] = dp[j][i] = ans;
		}
	}
	cout << dp[a][b];
}

int main(){
	brr

	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

	tc
	solve();

	return 0;
}