#include<bits/stdc++.h>

#define __ << "    " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

const int MAX_N = 1<<19;

ll seggs[MAX_N] = {0}, from[MAX_N], to[MAX_N];

ll query(ll index, ll L, ll R) {
	if(R < from[index] || L > to[index]) return 0;
	else if(L==from[index] && R==to[index]) return seggs[index];
	else return query(index*2+1, max(L, (to[index]+from[index])/2+1), R) + query(index*2, L, min(R, (to[index]+from[index])/2));
}

ll update(ll index, ll update_point, ll value) {
	ll diff;
	if(update_point == from[index] && update_point == to[index]) {
		diff = value - seggs[index];
		seggs[index] = value;
	}
	else if(update_point >= from[index] && update_point <= (to[index]+from[index])/2) {
		diff = update(index*2, update_point, value);
		seggs[index] += diff;
	}
	else {
		diff = update(index*2+1, update_point, value);
		seggs[index] += diff;
	}
	return diff;
}

void solve(){
	ll n, q, op, a ,b; 
	cin >> n >> q;
	for(int i = MAX_N/2-1; i>=MAX_N/2-n; --i) cin >> seggs[i];
	for(int i = MAX_N/2-1; i>=0; --i) from[i] = to[i] = MAX_N/2-i-1;

	ll f = MAX_N/2, p = 0;
	while(f < MAX_N-1) { 
		seggs[f] = seggs[p]+seggs[p+1];
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	auto start = chrono::high_resolution_clock::now();
	int t = 1;
	// cin >> t;
	while(t--) solve();
	auto stop = chrono::high_resolution_clock::now();
	cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}