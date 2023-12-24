#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pi pair<ll, ll>
#define mod 1000000007

using namespace std;

void solve(){
	int n, m, a, b, c; cin >> n >> m;
	vector<vector<pi>> adj(n+1);
	vector<ll> dist(n+1, 1e15);
	dist[1] = 0;

	for(int i=0; i<m; ++i) { cin >> a >> b >> c; adj[a].pb({b,c}); }
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({0, 1});

	while(!q.empty()){
		ll d = q.top().first, node = q.top().second;
		q.pop();
		if(d>dist[node]) continue;
		for(auto itr: adj[node]){
			if(dist[itr.first] > dist[node]+itr.second){
				dist[itr.first] = dist[node]+itr.second;
				q.push({dist[itr.first], itr.first});
			}
		}
	}
	for(int i=1; i<=n; ++i) cout << dist[i] << " "; 
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