#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

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

void solve(){
	int n; cin >> n;
	vector<array<int,3>> points;
	int si, fi;
	for(int i=0; i<n; ++i){
		cin >> si >> fi;
		points.push_back({si,0,i});
		points.push_back({fi,1,i});
	}
	sort(points.begin(), points.end());

	vector<int> ans(n);
	set<int> free_rooms = {1};
	int max_rooms = 1;
	int staying = 0;
	for(auto itr: points){
		if(itr[1]==0){
			++staying;
			if(free_rooms.empty())
				ans[itr[2]] = ++max_rooms;
			else {
				ans[itr[2]] = *free_rooms.begin();
				free_rooms.erase(ans[itr[2]]);
			}
		} else {
			--staying;
			free_rooms.insert(ans[itr[2]]);
		}
		max_rooms = max(max_rooms, staying);
	}
	cout << max_rooms << endl;
	for(auto& itr: ans) cout << itr << " ";
}

int main(){
	brr

	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

	// tc
	solve();

	return 0;
}