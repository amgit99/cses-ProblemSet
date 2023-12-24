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
vector<int> depth, predecessor;
int waqt = 0, cycle_start = -1, cycle_end = -1;

void dfs(int node){
	for(auto itr: adj[node]){
		if(predecessor[itr]==-1){ 
			predecessor[itr] = node; 
			depth[itr] = depth[node]+1; 
			dfs(itr); 
		}
		else if(depth[node]-depth[itr] > 1) { 
			cycle_start = node; 
			cycle_end = itr; 
		}
	}
}

void solve(){
	int n, m, a, b; cin >> n >> m;
	adj.resize(n+1); depth.resize(n+1,-1); predecessor.resize(n+1,-1);
	for(int i=0; i<m; ++i) { cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }

	for(int i=1; i<=n; ++i) if(predecessor[i]==-1) { predecessor[i] = i; dfs(i); }

	if(cycle_start ==-1) cout << "IMPOSSIBLE";
	else{
		int node = cycle_start;
		vector<int> cycle;
		while(node!=cycle_end) { cycle.pb(node); node = predecessor[node]; }
		cout << cycle.size()+2 << endl;
		for(auto itr: cycle) cout << itr << " ";
		cout << cycle_end << " " << cycle_start;
	}

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