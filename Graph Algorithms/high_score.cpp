#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define INF 1e17
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

vector<vector<ll>> adj, adj2;
vector<bool> visited;
ll n, m, a, b, c;
bool reached = 0;

void dfs(int node){
	visited[node] = 1;
	if(node == n-1) reached = 1;
	for(auto itr: adj2[node]) if(!visited[itr]) dfs(itr);
}

void solve() {
	cin >> n >> m;

	adj2.resize(n); visited.resize(n, 0);
	for(int i=0; i<m; ++i) {cin >> a >> b >> c; adj.pb({a-1, b-1, c}); adj2[a-1].pb(b-1); }

	vector<ll> newScore(n, -INF), prevScore(n, -INF);
	vector<bool> discovered(n, 0);
	newScore[0] = prevScore[0] = 0;
	discovered[0] = 1;
	
	bool converged = 1;
	for(int j=0; j<n; ++j){
		for(int i=0; i<m; ++i){
			if(discovered[adj[i][0]]){
				discovered[adj[i][1]] = 1;
				newScore[adj[i][1]] = max(newScore[adj[i][1]], newScore[adj[i][0]]+adj[i][2]);
			}
		}
		converged = 1;
		for(int i=0; i<n; ++i) if(prevScore[i]!=newScore[i]) converged = 0;
		if(converged) break;
		if(j<n-1) for(int i=0; i<n; ++i) prevScore[i]=newScore[i];
	}
	if(converged) { cout << newScore[n-1]; return; }

	// cout << "not converged" << endl;

	vector<int> cycles;
	for(int i=0; i<n; ++i) {
		if(prevScore[i]!=newScore[i]) {
			// cout << i << endl;
			fill(visited.begin(), visited.end(), 0);
			dfs(i);
		}
	}

	// cout << reached << endl;

	if(reached) cout << -1;
	else cout << newScore[n-1];
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	//auto start = chrono::high_resolution_clock::now();
	int t = 1;
	//cin >> t;
	while(t--)solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";
	return 0;
}