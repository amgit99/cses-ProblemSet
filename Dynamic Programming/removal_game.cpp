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
	int n; cin >> n;
	vector<ll> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];

	vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n));
	for(int i=n; i>0; --i) { 
		dp[0][n-i].resize(i, 0);
		dp[1][n-i].resize(i, 0);
	}

	for(int i=0; i<n; ++i) dp[0][i][0] = nums[i];

	for(int j=1; j<n; ++j){
		for(int i=0; i<n-j; ++i){
			dp[0][i][j] = max(nums[i]+dp[1][i+1][j-1], nums[j+i]+dp[1][i][j-1]);
			dp[1][i][j] = min(dp[0][i+1][j-1], dp[0][i][j-1]);
		}
	}

	cout << dp[0][0][n-1];
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