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
	vector<vector<int>> jobs(n, vector<int> (3));
	vector<vector<int>> jobsT(3, vector<int> (n));
	for(int i=0; i<n; ++i) cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];

	sort(jobs.begin(), jobs.end());
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<3; ++j)
			jobsT[j][i] = jobs[i][j];

	vector<ll> dp(n+1, 0);
	for(int i=n-1; i>=0; --i){
		int next = upper_bound(jobsT[0].begin(), jobsT[0].end(), jobs[i][1]) - jobsT[0].begin();
		dp[i] = max(dp[i+1], jobs[i][2]+dp[next]);
	}
	cout << dp[0];
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