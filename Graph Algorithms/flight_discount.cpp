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

	ll n, m, a, b, c, dest, cost; 
	cin >> n >> m;
	vector<vector<pi>> adj(n);
	for(int i=0; i<m; ++i) { cin >> a >> b >> c; adj[a-1].pb({b-1, c}); }

	vector<ll> used(n, 1e18), unused(n, 1e18);
	used[0] = unused[0] = 0;

	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
	pq.push({0, 0, 1});

	while(!pq.empty()){
		a = pq.top()[0]; b = pq.top()[1]; c = pq.top()[2];
		pq.pop();
		if(c==1){
			if(a > unused[b]) continue;
			for(auto itr: adj[b]){
				dest = itr.first; cost = itr.second;
				if(used[dest] > unused[b] + cost/2) {
					used[dest] = unused[b] + cost/2;
					pq.push({used[dest], dest, 0});
				}
				if(unused[dest] > unused[b] + cost) {
					unused[dest] = unused[b] + cost;
					pq.push({unused[dest], dest, 1});
				}
			}
		}
		else{
			if(a > used[b]) continue;
			for(auto itr: adj[b]){
				dest = itr.first; cost = itr.second;
				if(used[dest] > used[b] + cost) {
					used[dest] = used[b] + cost;
					pq.push({used[dest], dest, 0});
				}
			}
		}
	}

	cout << used[n-1];
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