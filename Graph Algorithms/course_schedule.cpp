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
vector<int> start, fin;
int waqt = 0;
bool cycle = 0;

void dfs(int node){
	start[node] = waqt++;
	for(auto itr: adj[node])
		if(start[itr]==-1) dfs(itr);
		else if (start[itr]<start[node] && fin[itr]==-1) cycle = 1;
	fin[node] = waqt++;
}

void solve(){
	int n, m, a, b; cin >> n >> m;
	adj.resize(n); start.resize(n,-1); fin.resize(n,-1);
	for(int i=0; i<m; ++i) { cin >> a >> b; adj[a-1].pb(b-1); }

	for(int i=0; i<n; ++i) if(start[i]==-1) dfs(i);

	if(cycle) { cout << "IMPOSSIBLE"; return; }
	
	vector<pi> topo(n);
	for(int i=0; i<n; ++i) topo[i] = {fin[i], i};
	sort(topo.begin(), topo.end());
	for(int i=n-1; i>=0; --i) cout << topo[i].second + 1 << " ";
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