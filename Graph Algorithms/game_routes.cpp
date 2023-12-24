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

vector<int> start, fin;
vector<vector<int>> adj, adjR;
int waqt = 0;

void dfs(int node){
	start[node] = waqt++;
	for(auto itr: adj[node]) if(start[itr]==-1) dfs(itr);
	fin[node] = waqt++;
}

void solve(){
	int n, m, a, b; cin >> n >> m;
	adj.resize(n); adjR.resize(n); start.resize(n,-1); fin.resize(n,-1);
	while(m--){ cin >> a >> b; adj[a-1].pb(b-1); adjR[b-1].pb(a-1); }

	dfs(0);

	priority_queue<pi> pq;
	vector<ll> dp(n, 0);
	dp[0] = 1;

	for(int i=0; i<n; ++i) if(fin[i]!=-1) pq.push({fin[i], i});
	while(!pq.empty()){
		int node = pq.top().S;
		pq.pop();
		for(auto itr: adjR[node])
			dp[node] = (dp[node] + dp[itr])%mod;
	}

	cout << dp[n-1];
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