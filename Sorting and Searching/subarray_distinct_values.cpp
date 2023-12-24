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
	vector<int> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];

	int i = 0, j = 0;
	ll ans = 0;
	unordered_map<int, int> m;
	++m[nums[0]];
	while(1){ // check if size <= k , end not reached, and next element is now new
		while(m.size() <= k && j < n-1){
			if(m.size() == k && m.count(nums[j+1])==0) break;
			++m[nums[++j]];
		}
		ll diff = j - i + 1;
		ans += (diff*(diff-1))/2;
		while(m.size() >= k){
			--m[nums[i]];
			if(m[nums[i]]==0) m.erase(nums[i]);
			++i;
		}
		if(j >= n-1) break;
		diff = j - i + 1;
		ans -= (diff*(diff-1))/2;
	}
	cout << ans+n;
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