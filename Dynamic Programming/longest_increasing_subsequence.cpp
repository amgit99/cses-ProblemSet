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
	vector<int> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];
	set<int> lis;

	for(int i=0; i<n; ++i){
		auto pos = lis.lower_bound(nums[i]);
		if(pos!=lis.end()) lis.erase(*pos);
		lis.insert(nums[i]);
	}
	cout << lis.size();
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