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
	int n, q, a, b; cin >> n >> q;
	vector<ll> nums(n+1, 0);
	for(int i=1; i<=n; ++i) { cin >> nums[i]; nums[i] += nums[i-1]; }
	while(q--) { cin >> a >> b; cout << nums[b]-nums[a-1] << endl; }
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