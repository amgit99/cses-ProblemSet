#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<stack>
#include<map>
#include<chrono>
#include<queue>

#define __ << "  " <<

using namespace std;

void solve(){
	long long n, L = 1000000000, R = 0, M, curr, currR, currL;
	cin >> n;
	vector<long long> nums(n);
	for(int i=0; i<n; ++i){
		cin >> nums[i];
		L = min(L, nums[i]);
		R = max(R, nums[i]);
	}
	while(L <= R){
		M = L + (R-L)/2;
		curr = 0, currR = 0, currL = 0;
		for(auto itr: nums){
			currR += abs(itr - (M+1));
			currL += abs(itr - (M-1));
			curr += abs(itr - M);
		}
		if(currL <= curr) R = M - 1;
		else if(currR <= curr) L = M + 1;
		else break;
	}
	cout << curr;
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