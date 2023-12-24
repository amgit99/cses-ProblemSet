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

int divisors[1000001];

void solve(){
	int n; cin >> n;

	for (int i = 1; i <= 1000001; ++i)
		for (int j = i; j <= 1000001; j += i)
			++divisors[j];

	while(n--){
		int val; cin >> val;
		cout << divisors[val] << endl;
	}
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