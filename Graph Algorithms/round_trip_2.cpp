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
bool cycle_found = 0;
vector<int> cycle, start, fin;
int waqt = 0, cycle_start;

void dfs(int node){
	cycle.pb(node);
	start[node] = waqt++;

	for(auto itr: adj[node]){
		if(start[itr]==-1) dfs(itr);
		else if(start[itr]<start[node] && fin[itr]==-1 && cycle.size()>1){
			cycle_found = 1;
			cycle.pb(itr);
			cycle_start = itr;
		}
		if(cycle_found) return;
	}

	fin[node] = waqt++;
	cycle.pop_back();
}

void solve(){
	int n, m, a, b, ptr; cin >> n >> m;
	adj.resize(n); start.resize(n, -1); fin.resize(n, -1);
	for(int i=0; i<m; ++i) { cin >> a >> b; adj[a-1].pb(b-1); }


	for(int i=0; i<n; ++i) if(start[i]==-1 && !cycle_found) dfs(i);
	
	if(!cycle_found) { cout << "IMPOSSIBLE" << endl; return; }
	for(int i=0; i<cycle.size(); ++i) if(cycle[i]==cycle_start) {ptr = i; break;}
	cout << cycle.size()-ptr << endl;
	for(int i=ptr; i<cycle.size(); ++i) cout << cycle[i]+1 << " "; 
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