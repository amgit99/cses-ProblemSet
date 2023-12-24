#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define brrr cin.tie(0) -> sync_with_stdio(0);
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
int visited[2*100000 + 2];
vector<vector<pi>> subtree_lengths;
vector<int> ans; 

int dfs1(int node){
	visited[node] = 1;
	int max_len = 0;
	for(auto itr: adj[node]){
		if(visited[itr]) continue;
		subtree_lengths[node].push_back({dfs1(itr), itr});
		max_len = max(max_len, subtree_lengths[node].back().ff);
	}
	return max_len+1;
}

void dfs2(int node, int drip){
	visited[node] = 1;
	subtree_lengths[node].pb({drip, -1});
	sort(subtree_lengths[node].begin(), subtree_lengths[node].end());

	ans[node] = subtree_lengths[node].back().ff;

	for(auto itr: adj[node]){
		if(visited[itr]) continue;
		int sub_drip = -1;
		int l = subtree_lengths[node].size();
		while(1){
			if(subtree_lengths[node][--l].ss != itr){
				sub_drip = subtree_lengths[node][l].ff;
				break;
			}
		}
		dfs2(itr, sub_drip+1);
	}
}

void solve(){
	int n; cin >> n;
	adj.resize(n+1);
	memset(visited, 0, sizeof(visited));
	subtree_lengths.resize(n+1);
	ans.resize(n+1, 0);

	for(int i=0; i<n-1; ++i){
		int si, fi; cin >> si >> fi;
		adj[si].pb(fi);
		adj[fi].pb(si);
	}

	dfs1(1);
	memset(visited, 0, sizeof(visited));
	dfs2(1, 0);

	for(int i=1; i<=n; ++i) cout << ans[i] << " ";
}

int main(){
	brrr

	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

	// tc
	solve();

	return 0;
}