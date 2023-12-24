#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
//#include<string>
//#include<stack>
//#include<set>

#define __ << "  " <<

using namespace std;
using namespace std::chrono;

//int c[200000];

void solve(){

	int n, x, ans=0;
	cin >> n >> x;
	vector<int> c(n);
	for(int i=0; i<n; ++i) cin >> c[i];
	sort(c.begin(), c.end());
	int L = 0, H = n-1;

	while(L<=H){
		if(c[L]+c[H] <= x) ++L;
		--H;
		++ans;
	}
	cout << ans;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	freopen("output.txt","w",stdout);

	auto start = high_resolution_clock::now();
	solve();
	auto stop = high_resolution_clock::now();

	cout << "\nEXECUTION TIME (MICROSECONDS) :: " << duration_cast<microseconds>(stop - start).count();
	return 0;
}