#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define brr cin.tie(0) -> sync_with_stdio(0);
#define tc int t; cin >> t; while(t--)
#define __ << " " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

void solve(){
	int n, t; cin >> n >> t;
	vector<int> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];

	map<int, vector<array<int,2>>> m;
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			m[nums[i] + nums[j]].pb({i+1, j+1});

	for(auto sum: m){
		int num = sum.first;
		for(auto points: sum.second){
			int i = points[0], j = points[1];
			if(m.count(t-num)){
				for(auto points2: m[t-num]){
					int k = points2[0], l = points2[1];
					if(i!=k && i!=l && j!=k && j!=l){
						cout << i __ j __ k __ l << endl;
						return;
					}
				}
			}
		}
	}

	cout << "IMPOSSIBLE";
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