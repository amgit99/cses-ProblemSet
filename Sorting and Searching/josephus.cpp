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
	int n, val; cin >> n;
	set<int> s;
	for(int i=1; i<=n; ++i) s.insert(i);
	auto itr = s.begin();
	++itr;
	while(s.size()>1){
		val = *itr;
		cout << val << ' ';
		++itr;
		s.erase(val);
		if(itr==s.end()) itr = s.begin();
		++itr;
		if(itr==s.end()) itr = s.begin();
	}
	cout << *s.begin();
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