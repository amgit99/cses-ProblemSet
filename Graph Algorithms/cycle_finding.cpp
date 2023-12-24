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

void solve(){
	int n,m,a,b,c;
	vector<vector<int>> edges;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) edges.pb({0,i,0}); 
	for(int i=0; i<m; ++i) { cin >> a >> b >> c; edges.pb({a, b, c}); }

	vector<ll> prev(n+1, 1e17), next(n+1, 1e17); 
	prev[0] = next[0] = 0;
	vector<int> parent(n+1);
	parent[0] = -1;
	bool converged;
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m+n; ++j){
			if(next[edges[j][1]] > next[edges[j][0]]+edges[j][2]){
				parent[edges[j][1]] = edges[j][0];
				next[edges[j][1]] = next[edges[j][0]]+edges[j][2];
			}
		}
		converged = 1;
		for(int i=0; i<=n; ++i) if(prev[i]!=next[i]) converged = 0;
		if(converged || i==n-1) break;
		for(int i=0; i<=n; ++i) prev[i]=next[i];
	}
	
	if(converged) { cout << "NO"; return; }

	int cycle_pointer;
	for(int i=1; i<=n; ++i) {
		if(prev[i]!=next[i]) { cycle_pointer = i; break; }
	}
	for(int i=0; i<n; ++i) cycle_pointer = parent[cycle_pointer];

	cout << "YES" << endl;
	vector<int> cycle = {cycle_pointer};
	while(cycle.size() == 1 || cycle[cycle.size()-1]!=cycle[0]) cycle.pb(parent[cycle[cycle.size()-1]]);
	for(int i=cycle.size()-1; i>=0; --i) cout << cycle[i] << " ";
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