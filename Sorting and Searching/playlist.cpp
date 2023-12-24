#include<bits/stdc++.h>
using namespace std;

#define __ << "  " <<
#define ll long long
#define endl '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define F first
#define S second
#define pi = pair<int, int>;
#define pl = pair<ll, ll>;

template<typename U>
void print(U arr) {
	for(auto element: arr)
		cout << element << " ";
	cout << endl;
}


void solve(){
	int n,    ans=1;
	cin >> n;
	int nums[n];
	set<int> s;
	for(int i=0; i<n; ++i) cin >> nums[i];
	int i=0, j=1;
	s.insert(nums[i]);
	while(j<n){
		if(s.find(nums[j])!=s.end()){
			ans = max(ans, (int)s.size());
			while(nums[i]!=nums[j]) s.erase(nums[i++]);
			++i;
		}
		s.insert(nums[j++]);
	}
	cout << max(ans, (int)s.size());
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