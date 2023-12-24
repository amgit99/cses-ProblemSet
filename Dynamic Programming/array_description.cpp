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
	int n, m; cin >> n >> m;
	vector<int> nums(n);
	vector<vector<ll>> dp(n, vector<ll> (m+2, 0));
	for(int i=0; i<n; ++i) { cin >> nums[i];}

	if(nums[0]==0) for(int i=1; i<=m; ++i) dp[0][i] = 1;
	else dp[0][nums[0]] = 1;

	for(int i=1; i<n; ++i){
		if(nums[i]!=0) 
			dp[i][nums[i]] = (dp[i-1][nums[i]]+dp[i-1][nums[i]+1]+dp[i-1][nums[i]-1])%mod;
		else
			for(int j=1; j<=m; ++j)
				dp[i][j] = (dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j-1])%mod;
	}
	
	ll ans=0;
	if(nums[n-1]==0) for(int i=0; i<=m; ++i) ans = (ans + dp[n-1][i])%mod;
	else ans = dp[n-1][nums[n-1]];
	cout << ans;
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