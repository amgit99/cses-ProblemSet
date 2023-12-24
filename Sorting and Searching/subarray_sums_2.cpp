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
	ll n, t; cin >> n >> t;
	vector<ll> nums(n+1);
	for(int i=0; i<n; ++i) cin >> nums[i];

	unordered_map<ll, int> m;
	m[0] = 1;
	ll sum = 0, ans = 0;
	for(int i=0; i<n; ++i){
		sum += nums[i];
		if(m.count(sum - t)) ans += m[sum - t];
		++m[sum];
	}
	cout << ans;
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