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
#define MOD 1000000007

using namespace std;

const int TWO_MOD_INV = 500000004;

/** @return The sum of all numbers in [start, end] mod MOD. */
long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) *
	        TWO_MOD_INV % MOD);
}

void solve() {
	long long n;
	cin >> n;

	long long total = 0;
	long long at = 1;
	while (at <= n) {
		long long add_amt = n / at;  // Our divisor to process
		// The largest number that still has the same value of q
		long long last_same = n / add_amt;

		total = (total + add_amt * total_sum(at, last_same)) % MOD;
		at = last_same + 1;
	}

	cout << total << endl;
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