#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<map>
#include<chrono>
#include<queue>

#define __ << "  " <<

using namespace std;

void solve(){
	int n, s, f, ans=0, current=0;
	cin >> n;
	vector<pair<int, bool>> vals;
	for(int i=0; i<n; ++i){
		cin >> s >> f;
		vals.push_back({s,1});
		vals.push_back({f,0});
	}
	sort(vals.begin(), vals.end());
	for(auto itr: vals) {
		if(itr.second) ++current;
		else --current;
		ans = max(ans, current);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("output.txt","w",stdout);

	auto start = chrono::high_resolution_clock::now();
	solve();
	auto stop = chrono::high_resolution_clock::now();
	cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}