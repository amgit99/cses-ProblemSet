#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<chrono>
#include<queue>

#define __ << " " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pli pair<long long, int>
#define mod 1000000007

using namespace std;

void solve(){
	int n, m, a, b, c; cin >> n >> m; 
	vector<vector<pair<int, int>>> adj(n);
	while(m--){ cin >> a >> b >> c; adj[a-1].pb({b-1, c}); }

	vector<ll> dist(n, 1e17), ways(n,0), min_stops(n,1e17), max_stops(n,-1e17);
	dist[0] = 0; ways[0] = 1; min_stops[0] = 0; max_stops[0] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0,0});

	while(!pq.empty()){
		ll d = pq.top().F, node = pq.top().S;
		pq.pop();
		for(auto itr: adj[node]){
			if(dist[itr.F] > d+itr.S){
				dist[itr.F] = d+itr.S;
				ways[itr.F] = ways[node];
				min_stops[itr.F] = min_stops[node]+1;
				max_stops[itr.F] = max_stops[node]+1;
				pq.push({dist[itr.F], itr.F});
			}
			else if(dist[itr.F] == d+itr.S){
				ways[itr.F] = (ways[itr.F]+ways[node])%mod;
				min_stops[itr.F] = min(min_stops[itr.F], min_stops[node]+1);
				max_stops[itr.F] = max(max_stops[itr.F], max_stops[node]+1);
			}
		}
	}

	cout << dist[n-1] __ ways[n-1] __ min_stops[n-1] __ max_stops[n-1];
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