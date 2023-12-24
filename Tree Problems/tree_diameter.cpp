#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

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
vector<bool> visited;
int ans = -1;

int find(int node){
	visited[node] = 1;
	vector<int> chains;
	for(auto itr: adj[node]){
		if(visited[itr]) continue;
		chains.push_back(find(itr));
	}
	sort(chains.begin(), chains.end());
	int n = chains.size();
	if(n == 0) return 1;
	if(n > 1) ans = max(ans, chains[n-1]+chains[n-2]);  
	return chains.back()+1;
}

void solve(){
	int n; cin >> n;
	if(n==1) {cout << 0; return;}
	adj.resize(n+1), visited.resize(n+1, 0);
	for(int i=0; i<n-1; ++i){
		int fr, to; 
		cin >> fr >> to;
		adj[fr].pb(to);
		adj[to].pb(fr);
	}
	cout << max(find(1)-1, ans);
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