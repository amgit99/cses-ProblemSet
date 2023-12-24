#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

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
	vector<int> nums(n), ans(n, 0);
	for(int i=0; i<n; ++i) cin >> nums[i];

	stack<pi> s;
	for(int i=n-1; i>=0; --i){
		while(!s.empty() && s.top().ff > nums[i]){
			ans[s.top().ss] = i+1;
			s.pop();
		}
		s.push({nums[i], i});
	}

	for(auto itr: ans) cout << itr << " ";
}

int main(){
	brr

	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

	// tc
	solve();

	return 0;
}