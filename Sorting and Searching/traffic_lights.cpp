#include<bits/stdc++.h>

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define pi = pair<int, int>;

using namespace std;

void solve(){
	int n, l, num; cin >> n >> l;
	set<int> lamps;
	map<int, int> lengths;
	lamps.insert(0);
	lamps.insert(n);
	lengths[n] = 1;
	int prev, next;

	for(int i=0; i<l; ++i){
		cin >> num;
		auto itr = lamps.lower_bound(num);

		next = *itr;
		prev = *--itr;

		--lengths[next-prev];
		if(lengths[next-prev]==0) lengths.erase(next-prev);

		lamps.insert(num);
		++lengths[num-prev];
		++lengths[next-num];

		cout << lengths.rbegin()->first << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	//auto start = chrono::high_resolution_clock::now();
	solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}