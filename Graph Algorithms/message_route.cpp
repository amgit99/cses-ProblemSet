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
	int n, m, a, b; cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for(int i=0; i<m; ++i) { cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }

	vector<int> predecessor(n+1, -1);
	queue<int> q({1});
	predecessor[1] = 1;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto itr: adj[f]){
			if(predecessor[itr]==-1) {
				q.push(itr); 
				predecessor[itr] = f;
			}
		}
	}

	if(predecessor[n]==-1) cout << "IMPOSSIBLE";
	else{
		vector<int> path;
		int back = n;
		while(back!=1) { path.pb(back); back = predecessor[back]; }
		path.pb(1);
		cout << path.size() << endl;
		for(int i=path.size()-1; i>=0; --i) cout << path[i] << " ";
	}
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