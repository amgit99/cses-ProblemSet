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
bool visited[2*100000+2];
int include[2*100000+2];
int not_include[2*100000+2];
int ans = 0;

// returns <included sum, excluded_max>
void find(int node){
	visited[node] = 1;
	int parent;
	for(auto itr: adj[node]){
		if(visited[itr]) {parent = itr; continue;}
		find(itr);
		not_include[node] += include[itr];
	}
	for(auto itr: adj[node]){
		if(itr==parent) continue;
		include[node] = max(include[node], 
							not_include[itr] + not_include[node] - include[itr] + 1);
	}
}

void solve(){
	int n; cin >> n;
	adj.resize(n+1);
	memset(visited, 0, sizeof(visited));
	memset(include, 0, sizeof(include));
	memset(not_include, 0, sizeof(not_include));

	for(int i=0; i<n-1; ++i){
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	find(1);
	cout << max(include[1], not_include[1]);
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