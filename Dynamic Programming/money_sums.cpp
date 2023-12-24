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
	int n, sum=0, count=0; cin >> n;
	vector<int> coins(n);
	for(int i=0; i<n; ++i) { cin >> coins[i]; sum+=coins[i]; }
	vector<bool> dp(sum+1, 0);
	dp[0] = 1;
	sort(coins.begin(), coins.end());
	for(auto coin: coins){
		for(int i=sum; i>=coin; --i){
			if(!dp[i] && dp[i-coin]) { dp[i] = 1; ++count; }
		}
	}
	cout << count << endl;
	for(int i=1; i<=sum; ++i) if(dp[i]) cout << i << " ";
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