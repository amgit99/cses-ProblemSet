#include<bits/stdc++.h>
#pragma GCC target("popcnt")

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
	vector<bitset<3000>> grid;
	for(int i=0; i<n; ++i){
		string s; cin >> s;
		grid.push_back(bitset<3000> (s));
	}

	long long ans = 0;
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			int cc = (grid[i]&grid[j]).count();
			ans += (cc*(cc-1))/2;
		}
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