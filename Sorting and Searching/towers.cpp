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
	int n, num; cin >> n;
	map<int, int> m;
	while(n--){
		cin >> num;
		auto itr = m.upper_bound(num);
		if(itr != m.end()) {
			--m[itr->first];
			if(m[itr->first]==0) m.erase(itr->first);
		}
		++m[num];
	}
	int ans = 0;
	for(auto itr: m) ans += itr.second;
	cout << ans;
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