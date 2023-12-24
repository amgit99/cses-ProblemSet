#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>

#define _ << "  " <<

using namespace std;

void subset_sums(int start, int end, vector<long long> &nums, vector<long long> &sub){
	for(int i=start; i<=end; ++i){
		for(int j=0; j<(1<<(i-start)); ++j)
			sub.push_back(sub[j]+nums[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, target, ans=0;
	cin >> n >> target;
	vector<long long> nums(n, 0);

	for(int i=0; i<n; ++i) cin >> nums[i];

	vector<long long> sub1(1,0), sub2(1,0);
	subset_sums(0, n/2-1, nums, sub1);
	subset_sums(n/2, n-1, nums, sub2);

	sort(sub1.begin(), sub1.end());
	sort(sub2.begin(), sub2.end());

	for(auto itr: sub1)
		ans += upper_bound(sub2.begin(), sub2.end(), target-itr) - lower_bound(sub2.begin(), sub2.end(), target-itr);
	
	cout << ans << endl;
	return 0;
}