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
	string s1, s2; cin >> s1 >> s2;
	vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, 0));

	for(int i=1; i<=s1.size(); ++i) dp[i][0] = dp[i-1][0]+1;
	for(int i=1; i<=s2.size(); ++i) dp[0][i] = dp[0][i-1]+1;

	for(int i=1; i<=s1.size(); ++i)
		for(int j=1; j<=s2.size(); ++j)
			if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));

	cout << dp[s1.size()][s2.size()];
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