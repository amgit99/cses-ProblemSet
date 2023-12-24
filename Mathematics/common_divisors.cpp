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

// int divisors[1000001];

void solve(){
	int n, num; cin >> n;
	unordered_map<int, int> m;
	for(int i=0; i<n; ++i) {
		cin >> num;
		++m[num];
	}

	int ans = 1;
	for(int i=1000000; i>=1; --i){
		int multiples = 0;
		for(int j=i; j<1000001; j+=i){
			// ++divisors[j];
			if(m.count(j)) multiples += m[j];
		}
		if(multiples > 1) {
			cout << i;
			return;
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