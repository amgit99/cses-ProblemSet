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

int seggs[MAX_N], from[MAX_N], to[MAX_N];

int query(int index, int L, int R) {
	if(R < from[index] || L > to[index]) return 1e9;
	else if(L==from[index] && R==to[index]) return seggs[index];
	else return min(query(index*2+1, max(L, (to[index]+from[index])/2+1), R), query(index*2, L, min(R, (to[index]+from[index])/2)));
}

void update(int index, int update_point, int value) {
	if(update_point == from[index] && update_point == to[index]) 
		{ seggs[index] = value; return; }
	else if(update_point >= from[index] && update_point <= (to[index]+from[index])/2)
		update(index*2, update_point, value);
	else
		update(index*2+1, update_point, value);

	seggs[index] = min(seggs[index*2], seggs[index*2+1]);
}

void solve(){
	ll n, q, op, a ,b; 
	cin >> n >> q;
	for(int i=0; i<MAX_N; ++i) seggs[i] = 1e9;
	for(int i = MAX_N/2-1; i>=MAX_N/2-n; --i) cin >> seggs[i];
	for(int i = MAX_N/2-1; i>=0; --i) from[i] = to[i] = MAX_N/2-i-1;

	ll f = MAX_N/2, p = 0;
	while(f < MAX_N-1) { 
		seggs[f] = min(seggs[p], seggs[p+1]);
		to[f] = to[p];
		from[f] = from[p+1];
		++f;
		p+=2;
	}
	reverse(seggs, seggs+MAX_N);
	reverse(from, from+MAX_N);
	reverse(to, to+MAX_N);

	while(q--){
		cin >> op >> a >> b;
		if(op==1) update(1, a-1, b);
		else cout << query(1, a-1, b-1) << endl;
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