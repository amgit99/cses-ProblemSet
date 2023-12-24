#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<chrono>
#include<queue>
 
#define __ << "  " <<
 
using namespace std;
 
void solve(){
	int n, num;
	cin >> n;
	set<int> s;
	for(int i=0; i<n; ++i){
		cin >> num;
		if(s.find(num-1)!=s.end()) s.erase(num-1);
		s.insert(num);
	}
	cout << s.size();
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("output.txt","w",stdout);
 
	//auto start = chrono::high_resolution_clock::now();
	solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";
 
	return 0;
}