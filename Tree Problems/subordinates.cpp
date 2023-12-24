#include<bits/stdc++.h>

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

vector<vector<int>> adj;
vector<int> subs;

void dfs(int node){
	for(auto itr: adj[node]){ dfs(itr); subs[node]+=subs[itr]+1; }
}

void solve(){
	int n, num; cin >> n;
	adj.resize(n+1); subs.resize(n+1, 0);
	for(int i=2; i<=n; ++i) { cin >> num; adj[num].pb(i); }

	dfs(1);

	for(int i=1; i<subs.size(); ++i) cout << subs[i] << " ";
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