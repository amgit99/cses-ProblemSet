#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<bitset>

#define __ << "  " <<

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i=0; i<(1<<n); ++i){
		int num = i^(i>>1);
		bitset<16> ans(num);
		for(int i=n-1; i>=0; --i) cout << ans[i];
		cout << endl;
	}

	return 0;
}

















































