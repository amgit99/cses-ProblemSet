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
	ll n; cin >> n;	
	vector<ll> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];

	unordered_map<ll, ll> m;

	m[0] = 1;
	ll sum = 0, ans = 0;
	for(int i=0; i<n; ++i){
		sum = ((sum+nums[i])%n + n)%n;
		if(m.count(sum)) ans += m[sum];
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