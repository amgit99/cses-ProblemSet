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
	int n, m; cin >> n >> m;

	vector<vector<char>> grid(n, vector<char> (m));
	vector<char> entity = {'A','M'};
	queue<vector<int>> q;
	int si, sj, ei = -1, ej = -1; 

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> grid[i][j];
			if(grid[i][j]=='A') { si=i; sj=j; }
			if(grid[i][j]=='M') q.push({i, j, 1});
		}
	}

	q.push({si, sj, 0});
	while(!q.empty()){
		int x = q.front()[0], y = q.front()[1], e = q.front()[2];
		q.pop();
		if(x>0   && grid[x-1][y]=='.') { 
			if(e) grid[x-1][y] = 'M'; 
			else grid[x-1][y] = 'U'; 
			q.push({x-1, y, e}); }
		if(x<n-1 && grid[x+1][y]=='.') { 
			if(e) grid[x+1][y] = 'M';
			else grid[x+1][y] = 'D'; 
			q.push({x+1, y, e}); }
		if(y>0   && grid[x][y-1]=='.') { 
			if(e) grid[x][y-1] = 'M';
			else grid[x][y-1] = 'L';
			q.push({x, y-1, e}); }
		if(y<m-1 && grid[x][y+1]=='.') { 
			if(e) grid[x][y+1] = 'M';
			else grid[x][y+1] = 'R';
			q.push({x, y+1, e}); }

		if((x==0 || y==0 || x==n-1 || y==m-1) && e==0) { ei = x; ej = y; }
	}

	if(ei == -1) { cout << "NO"; return; }
	string path = "";
	while(grid[ei][ej]!='A'){
		path+=grid[ei][ej];
		if(grid[ei][ej]=='U') ++ei;
		else if(grid[ei][ej]=='D') --ei;
		else if(grid[ei][ej]=='L') ++ej;
		else --ej;
	}
	reverse(path.begin(), path.end());
	cout << "YES\n" << path.size() << endl << path;
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