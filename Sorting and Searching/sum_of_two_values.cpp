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
	int n, num, target;
	cin >> n >> target;
	map<int, int> m;
	for(int i=0; i<n; ++i){
		cin >> num;
		if(m.find(target-num) != m.end()){
			cout << m[target-num] << " " << i+1;
			return;
		}
		m[num] = i+1;
	}
	cout << "IMPOSSIBLE";
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}