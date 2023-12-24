#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

void solve(){
	int n, k;
	cin >> n >> k;

	pbds p;
	for(int i=1; i<=n; ++i) p.insert(i);

	int killer_order = 0, victim;
	while(!p.empty()){
		victim = *p.find_by_order((killer_order+k)%p.size());
		killer_order = (killer_order+k)%p.size();
		p.erase(victim);
		cout << victim << " ";
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