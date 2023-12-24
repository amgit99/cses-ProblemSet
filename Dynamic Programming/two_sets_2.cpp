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

int inv(int i) {
  return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

void solve(){
	int n, sum; cin >> n;
 
	sum = (n*(n+1))/2;
	if(sum%2) { cout << 0; return; }
 
	vector<vector<ll>> dp(n+1, vector<ll> (sum/2+1, 0));
 
	for(int i=0; i<=n; ++i) dp[i][0] = 1;
	for(int i=1; i<=sum/2; ++i) dp[0][i] = 0;
 
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=sum/2; ++j){
			if(i<=j) dp[i][j] = (dp[i-1][j-i] + dp[i-1][j])%mod;
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << (dp[n][sum/2]*inv(2))%mod;
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
