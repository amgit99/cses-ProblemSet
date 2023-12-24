#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<unordered_map>

#define __ << "  " <<

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, og;
	cin >> s;
	sort(s.begin(), s.end());
	og = s;
	unordered_map<char,int> u; 
	int ans = (int)tgamma(og.size()+1);
	for(int i=0; i<(int)og.size(); ++i)
		++u[og[i]];
	for(auto itr: u)
		ans=ans/(int)tgamma(itr.second+1);
	cout << ans << endl;
	while(true){
		cout << s << endl;
		next_permutation(s.begin(), s.end());
		if(s==og) break;
	}
	return 0;
}