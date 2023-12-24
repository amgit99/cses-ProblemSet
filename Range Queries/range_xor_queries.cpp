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

const int MAX_N = 1<<19; 
int seg[MAX_N] = {0}, from[MAX_N], to[MAX_N];

int query(int index, int L, int R) {
	if(R < from[index] || L > to[index]) return 0;
	else if(L==from[index] && R==to[index]) return seg[index];
	else return query(index*2+1, max(L, (to[index]+from[index])/2+1), R)^query(index*2, L, min(R, (to[index]+from[index])/2));
}

void solve() {
	int n, q, a, b; cin >> n >> q;
	for(int i=MAX_N/2-1; i>=MAX_N/2-n; --i) cin >> seg[i] ;
	for(int i = MAX_N/2-1; i>=0; --i) from[i] = to[i] = MAX_N/2-i-1;

	int f = MAX_N/2, p = 0;
	while(f < MAX_N-1) { 
		seg[f] = seg[p]^seg[p+1];
		to[f] = to[p];
		from[f] = from[p+1];
		++f;
		p+=2;
	}
	reverse(seg, seg+MAX_N);
	reverse(from, from+MAX_N);
	reverse(to, to+MAX_N);

	while(q--){
		cin >> a >> b;
		cout << query(1, a-1, b-1) << endl;
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