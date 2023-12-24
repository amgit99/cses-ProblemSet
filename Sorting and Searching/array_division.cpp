#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
 
#define brr cin.tie(0) -> sync_with_stdio(0);
#define tc int t; cin >> t; while(t--)
#define __ << "  " <<
#define i64 long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007
 
using namespace std;
 
bool check(vector<i64>& nums, i64 part, int k){
	i64 curr_sum = nums[0];
	int blocks = 0;
	for(int i=1; i<nums.size(); ++i){
		if(curr_sum + nums[i] > part){
			++blocks;
			curr_sum = nums[i];
		} else curr_sum += nums[i];
	}
	return k > blocks;
}
 
void solve(){
	int n, k; cin >> n >> k;
	vector<i64> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];
 
	i64 L = *max_element(nums.begin(), nums.end()), R = 0;
	for(auto itr: nums) R += itr;
	while(L < R){
		i64 mid = L + (R-L)/2;
		if(check(nums, mid, k)) R = mid;
		else L = mid+1;
	}
	cout << L;
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
