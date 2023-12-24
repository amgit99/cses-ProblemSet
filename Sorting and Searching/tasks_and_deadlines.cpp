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
	vector<array<i64,2>> tasks(n);
	for(i64 i=0; i<n; ++i) cin >> tasks[i][0] >> tasks[i][1];

	sort(tasks.begin(), tasks.end(), [](array<i64,2>& a, array<i64,2>& b)->bool{
		if(a[0]!=b[0]) return a[0] < b[0];
		else return a[1] > b[1]; 
	});

	i64 ans = 0, time = 0;
	for(auto itr: tasks){
		time += itr[0];
		ans += itr[1] - time;
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