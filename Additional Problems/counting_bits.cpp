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
	++n;
	ll ans = 0;
	for(int i=0; i<51; ++i){
		ll block = ((ll)1)<<(i+1);
		ans += ((n/block)*block)/2;
		ans += max((ll)0, n%block - block/2);
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