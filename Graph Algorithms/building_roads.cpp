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

vector<int> parents, sizes;
int unions;

void onion_init(int n){
	unions = n;
	parents.resize(n);
	for(int i=0; i<n; ++i) parents[i] = i;
	sizes.resize(n, 1);
}

int find(int a){
	if(parents[a]==a) return a;
	else return parents[a] = find(parents[a]);
}

void onion(int a, int b){
	a = find(a); b = find(b);
	if(a!=b) {
		if(sizes[a] > sizes[b]) { sizes[a]+=sizes[b]; parents[b] = a; }
		else { sizes[b]+=sizes[a]; parents[a] = b; }
		--unions;
	}
}

void solve(){
	int n, m, a, b; cin >> n >> m;
	onion_init(n);
	for(int i=0; i<m; ++i) { cin >> a >> b; onion(a-1, b-1); }

	cout << unions-1 << endl;
	vector<int> leaders;
	for(int i=0; i<n; ++i) if(i==find(i)) leaders.pb(i+1);
	for(int i=1; i<leaders.size(); ++i) cout << leaders[i-1] << " " << leaders[i] << endl;

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