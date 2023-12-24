#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main(){
	string s;
	cin >> s;
	vector<int> occ(26);
	for(int i=0; i<s.size(); ++i) ++occ[s[i]-'A'];
	int odds=0;
	for(int i=0; i<26; ++i) if(occ[i]%2) ++odds;
	if(odds>1) cout << "NO SOLUTION";
	else {
		string ans="";
		int odd_char=-1;
		for(int i=0; i<26; ++i)
			if(occ[i]%2) odd_char = i;
			else for(int o=0; o<occ[i]/2; ++o) ans+=(char)(i+65);
		if(odd_char!=-1) for(int o=0; o<occ[odd_char]; ++o) ans+=(char)(odd_char+65);
		for(int i=25; i>=0; --i)
			if (occ[i]%2==0) for(int o=0; o<occ[i]/2; ++o) ans+=(char)(i+65);
		cout << ans;
	}
	return 0;
}
