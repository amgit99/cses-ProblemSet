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

	map<int,vector<int>> m; 
	for(int i=0; i<n; ++i) m[nums[i]].pb(i);

	for(int i=0; i<n; ++i){
		int num = t - nums[i];

		for(int j=i+1; j<n; ++j){
			if(m.count(num - nums[j])){
				for(auto itr: m[num - nums[j]]){
					if(itr != j && itr != i){
						cout << i+1 __ j+1 __ itr+1 << endl;
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