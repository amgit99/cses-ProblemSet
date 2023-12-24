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
vector<int> parity;
bool isBP = true;

void bfs(int node){
	queue<int> q({node});
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto itr: adj[f]){
			if(parity[itr]==-1) {parity[itr] = (parity[f]+1)%2; q.push(itr); }
			else if(parity[itr]==parity[f]) isBP = false;
		}
	}
}

void solve(){
	int n, m, a, b; cin >> n >> m;
	adj.resize(n+1);
	for(int i=0; i<m; ++i) { cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }

	parity.resize(n+1, -1);
	for(int i=1; i<=n; ++i) if(parity[i]==-1) { parity[i] = 0; bfs(i); }
	if(!isBP) cout << "IMPOSSIBLE";
	else for(int i=1; i<=n; ++i) cout << parity[i]+1 << " ";
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