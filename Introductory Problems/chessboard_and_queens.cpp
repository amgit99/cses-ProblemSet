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

vector<vector<bool>> board(8, vector<bool>(8, 0));
vector<bool> bwd(15, 0), fwd(15, 0), row(8, 0);
int ans = 0;

void counter(int j){
	if(j==8) { ++ans; return; }

	for(int i=0; i<8; ++i){
		if(board[i][j] && !fwd[i+j] && !bwd[i-j+7] && !row[i]){
			fwd[i+j] = bwd[i-j+7] = row[i] = 1;
			counter(j+1);
			fwd[i+j] = bwd[i-j+7] = row[i] = 0;
		}
	}
}

void solve(){
	for(int i=0; i<8; ++i){
		string row; cin >> row;
		for(int j=0; j<8; ++j){
	 		if(row[j]=='.') board[i][j] = 1;
	 	}
	}
	counter(0);
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