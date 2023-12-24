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

i64 n;
vector<vector<int>> adj;
bool visited[200000+2];
i64 ans[200000+2];
i64 subtree_counts[200000+2];

void dfs1(int node){
	visited[node] = 1;
	for(auto itr: adj[node]){
		if(visited[itr]) continue;
		dfs1(itr);
		ans[node] += ans[itr] + subtree_counts[itr];
		subtree_counts[node] += subtree_counts[itr];
	}
	++subtree_counts[node];
}

void dfs2(int node, i64 drip){
	visited[node] = 1;
	ans[node] += drip;
	for(auto itr: adj[node]){
		if(visited[itr]) continue;
		dfs2(itr, ans[node] - ans[itr] - 2*subtree_counts[itr] + n);
	}
}

void solve(){
	cin >> n;
	adj.resize(n+1);
	memset(visited, 0, sizeof(visited));
	memset(subtree_counts, 0, sizeof(subtree_counts));
	memset(ans, 0, sizeof(ans));

	for(int i=0; i<n-1; ++i){
		int si, fi; cin >> si >> fi;
		adj[si].pb(fi);
		adj[fi].pb(si);
	}

	dfs1(1);
	memset(visited, 0, sizeof(visited));
	dfs2(1,0);

	for(int i=1; i<=n; ++i) cout << ans[i] << " ";
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