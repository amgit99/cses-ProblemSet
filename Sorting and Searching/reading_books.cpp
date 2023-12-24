#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define brr cin.tie(0) -> sync_with_stdio(0);
#define tc int t; cin >> t; while(t--)
#define __ << "  " <<
#define i64 long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

void solve(){
	i64 n; cin >> n;

	i64 sum = 0, _max = -1, book;
	for(int i=0; i<n; ++i) {
		cin >> book;
		sum += book;
		_max = max(_max, book);
	}

	if(_max <= sum/2) cout << sum;
	else cout << (_max<<1); 

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