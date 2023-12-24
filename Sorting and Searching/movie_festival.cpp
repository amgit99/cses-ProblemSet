#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<map>
#include<chrono>
#include<queue>

#define pi pair<int, int>
#define __ << "  " <<

using namespace std;

void solve(){
	int m, prev_fin = -1, ans = 0;
	cin >> m;
	vector<pi> movies(m);
	for(int i=0; i<m; ++i) cin >> movies[i].second >> movies[i].first;
	priority_queue<pi, vector<pi>, greater<pi>> pq(movies.begin(), movies.end());
	while(!pq.empty()){
		if(pq.top().second >= prev_fin) {
			++ans;
			prev_fin = pq.top().first;
		}
		pq.pop();
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("output.txt","w",stdout);

	auto start = chrono::high_resolution_clock::now();
	solve();
	auto stop = chrono::high_resolution_clock::now();
	cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}