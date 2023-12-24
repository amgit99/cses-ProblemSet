#include<bits/stdc++.h>
#include<bitset>

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
	vector<int> apples(n);

	ll sum = 0, ans = 1e17;
	for(int i=0; i<n; ++i) { cin >> apples[i]; sum+=apples[i]; }

	for(int i=0; i<(1<<n); ++i){
		ll subset = 0;
		bitset<20> bs(i);
		for(int i=0; i<n; ++i) if(bs[i]) subset += apples[i];
		subset<<=1;
		ans = min(ans, abs(sum-subset));
	}
	cout << ans; 
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