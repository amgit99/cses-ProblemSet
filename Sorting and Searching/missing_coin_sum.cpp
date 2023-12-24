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

	int n;
	cin >> n;
	int nums[n];
	for(int i=0; i<n; ++i) cin >> nums[i];
	sort(nums, nums+n);

	long long R = 1;
	for(int i=0; i<n; ++i)
		if(R >= nums[i]) R += nums[i];
		else break;
	cout << R;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	freopen("output.txt","w",stdout);

	auto start = chrono::high_resolution_clock::now();
	solve();
	auto stop = chrono::high_resolution_clock::now();
	cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}