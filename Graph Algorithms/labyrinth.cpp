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
string path = "";

void backtrack(int i, int j){
	while(floor_plan[i][j]!='A'){
		path += floor_plan[i][j];
		if(floor_plan[i][j]=='U') ++i;
		else if(floor_plan[i][j]=='D') --i;
		else if(floor_plan[i][j]=='L') ++j;
		else if(floor_plan[i][j]=='R') --j;
	}
	reverse(path.begin(), path.end());
	cout << "YES\n" << path.size() << endl << path;
}

void bfs(int i, int j){
	queue<pi> q;
	q.push({i, j});

	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		if(x>0 && floor_plan[x-1][y]=='.') 
			{ floor_plan[x-1][y]='U'; q.push({x-1, y}); }

		if(x<floor_plan.size()-1 && floor_plan[x+1][y]=='.') 
			{ floor_plan[x+1][y]='D'; q.push({x+1, y}); }

		if(y>0 && floor_plan[x][y-1]=='.') 
			{ floor_plan[x][y-1]='L'; q.push({x, y-1}); }

		if(y<floor_plan[0].size()-1 && floor_plan[x][y+1]=='.') 
			{ floor_plan[x][y+1]='R'; q.push({x, y+1}); }
	}
}

void solve(){
	int n, m, si, sj, ei, ej; cin >> n >> m;
	floor_plan.resize(n, vector<char> (m));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> floor_plan[i][j];
			if(floor_plan[i][j] == 'A') { si = i; sj = j; }
			if(floor_plan[i][j] == 'B') { ei = i; ej = j; }
		}
	}

	floor_plan[ei][ej] = '.';
	bfs(si, sj);
	if(floor_plan[ei][ej]=='.') cout << "NO";
	else backtrack(ei, ej);
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