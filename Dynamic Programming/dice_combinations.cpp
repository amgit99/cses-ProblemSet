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
	vector<ll> dp = {1,2,4,8,16,32};
	if(n<7) { cout << dp[n-1]; return; }
	for(int i=0; i<n-6; ++i){
		ll sum = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]+ dp[5])%mod;
		dp.push_back(sum);
		dp.erase(dp.begin());
	}
	cout << dp[5];
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