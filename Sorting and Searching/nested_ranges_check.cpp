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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve(){
	int n; cin >> n;
	vector<int> start(n), fin(n);
	vector<array<int,3>> points(n);
	for(int i=0; i<n; ++i) {
		cin >> points[i][0] >> points[i][1];
		points[i][2] = i;
	}

	sort(points.begin(), points.end(), [] (array<int,3>& a, array<int,3>& b) -> bool{   
	   if(a[0] != b[0]) return a[0] < b[0];
	   return a[1] > b[1];
	});

	vector<int> a(n), b(n);
	pbds<pair<int,int>> pb1, pb2;

	for(int i=n-1; i>=0; --i){
		a[points[i][2]] = pb1.order_of_key({points[i][1]+1,-1});
		pb1.insert({points[i][1], points[i][2]});
	}

	for(int i=0; i<n; ++i){
		b[points[i][2]] = i - pb2.order_of_key({points[i][1],-1});
		pb2.insert({points[i][1], points[i][2]});
	}

	for(int i=0; i<n; ++i) if(a[i]>0) a[i] = 1;
	for(int i=0; i<n; ++i) if(b[i]>0) b[i] = 1;

	for(int i=0; i<n; ++i) cout << a[i] << " "; cout << endl;
	for(int i=0; i<n; ++i) cout << b[i] << " "; cout << endl;
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