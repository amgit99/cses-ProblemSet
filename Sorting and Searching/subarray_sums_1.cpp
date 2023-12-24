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

	ll i = 0, j = 0; // j inclusive
	ll sum = nums[0], ans = 0;

	while(1){
		if(sum==t) ++ans;
		if(sum < t && j < n-1) sum += nums[++j];
		else if(sum >= t && i < n) sum -= nums[i++];
		else break; 
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