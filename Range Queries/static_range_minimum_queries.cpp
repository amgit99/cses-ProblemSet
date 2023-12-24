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

int st[18][200001];
int logs[200001];

void solve(){
	int n, q, a, b, depth; cin >> n >> q;
	for(int i=0; i<n; ++i) cin >> st[0][i];

	logs[1] = 0;
	for(int i = 2; i < 200001; i++) logs[i] = logs[i/2]+1;

	for(int i=1; i<18; ++i)
		for(int j=0; j<=n-(1<<i); ++j)
			st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);

	while(q--){
		cin >> a >> b;
		depth = logs[b-a+1];
		cout << min(st[depth][a-1], st[depth][b - (1<<depth)]) << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

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