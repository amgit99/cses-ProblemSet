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

vector<vector<ll>> dp(1000002, vector<ll> (2, 0));

void calculate(){
	dp[1][0] = dp[1][1] = 1;
	for(int i=2; i<1000002; ++i){
		dp[i][0] += (2*dp[i-1][0] + dp[i-1][1])%mod;
		dp[i][1] += (dp[i-1][0] + 4*dp[i-1][1])%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	//auto start = chrono::high_resolution_clock::now();
	calculate();
	int t, n; cin >> t;
	while(t--){
		cin >> n;
		cout << (dp[n][0]+dp[n][1])%mod << endl;
	}
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}