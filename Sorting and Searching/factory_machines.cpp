#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define brr cin.tie(0) -> sync_with_stdio(0);
#define tc int t; cin >> t; while(t--)
#define __ << "  " <<
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

void solve(){
	ull n, t; cin >> n >> t;
	vector<ull> times(n);
	for(ull i=0; i<n; ++i) cin >> times[i];

	ull L = 0, R = 1e19;
	while(L < R){
		ull mid = L + (R-L)/2;
		ull tasks = 0, i=0;
		while(tasks < t && i < n)
			tasks += mid/times[i++];
		if(tasks < t) L = mid+1;
		else R = mid;
	}
	cout << L;
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