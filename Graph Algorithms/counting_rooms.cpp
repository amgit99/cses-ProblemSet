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

vector<vector<char>> floor_plan;
int ans = 0;

void bfs(int x, int y){
	++ans;
	queue<pi> q;
	q.push({x, y});
	while(!q.empty()){
		int i = q.front().first, j = q.front().second;
		q.pop();
		if(i>0 && floor_plan[i-1][j]=='.') 
			{ q.push({i-1, j}); floor_plan[i-1][j] = 'f'; }
		if(i<floor_plan.size()-1 && floor_plan[i+1][j]=='.') 
			{ q.push({i+1, j}); floor_plan[i+1][j] = 'f'; }
		if(j>0 && floor_plan[i][j-1]=='.') 
			{ q.push({i, j-1}); floor_plan[i][j-1] = 'f'; }
		if(j<floor_plan[0].size()-1 && floor_plan[i][j+1]=='.') 
			{ q.push({i, j+1}); floor_plan[i][j+1] = 'f'; }
	}
}

void solve(){
	int n, m; cin >> n >> m;
	floor_plan.resize(n, vector<char> (m));
	for(int i=0; i<n; ++i) 
		for(int j=0; j<m; ++j) 
			cin >> floor_plan[i][j];

	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(floor_plan[i][j] == '.')
				{ bfs(i, j); floor_plan[i][j] = 'f'; }

	cout << ans;
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