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
	int n, k; cin >> n >> k;
	vector<ll> nums(n);
	for(int i=0; i<n; ++i) {
		string str; cin >> str;
		ll num = 0;
		for(int i=0; i<k; ++i)
			if(str[i] == '1') num += 1<<(k-i-1);
		nums[i] = num;
	}
	int ans = k;
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			ans = min(ans, __builtin_popcount(nums[i]^nums[j]));
		
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