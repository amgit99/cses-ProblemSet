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
	ll n, m, q, a, b, c; cin >> n >> m >> q;

	vector<vector<ll>> dp(n+1, vector<ll> (n+1, 1e15));

	for(int i=1; i<=n; ++i) dp[i][i] = 0;

	for(int i=0; i<m; ++i) { cin >> a >> b >> c; dp[a][b] = dp[b][a] = min(dp[a][b], c); }

	for(int g=1; g<=n; ++g){
		for(int i=1; i<=n; ++i){
			if(i==g) continue;
			for(int j=1; j<=n; ++j){
				if(j==g) continue;
				dp[i][j] = min(dp[i][j], dp[i][g]+dp[g][j]);
			}
		}
	}

	while(q--){
		cin >> a >> b;
		if(dp[a][b] == 1e15) cout << -1 << endl;
		else cout << dp[a][b] << endl;
	}
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