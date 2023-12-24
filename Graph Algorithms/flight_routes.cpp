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
	int n, m, k, a, b, c; cin >> n >> m >> k;
	vector<vector<pi>> adj(n);
	for(int i=0; i<m; ++i) { cin >> a >> b >> c; adj[a-1].pb({b-1, c}); }

	vector<vector<ll>> dist(n, vector<ll> (k, 1e17));
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	dist[0][0] = 0;
	pq.push({0, 0});

	while(!pq.empty()){
		ll d = pq.top().F, node = pq.top().S;
		pq.pop();
		if(d > dist[node][k-1]) continue;
		for(auto itr: adj[node]){
			if(dist[itr.F][k-1] > d + itr.S){
				dist[itr.F][k-1] = d + itr.S;
				sort(dist[itr.F].begin(), dist[itr.F].end());
				pq.push({d + itr.S, itr.F});
			}
		}
	}
	for(auto itr: dist[n-1]) cout << itr << " ";
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
	while(t--) solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}