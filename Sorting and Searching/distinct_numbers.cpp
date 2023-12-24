#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<stack>
#include<queue>

#define __ << "  " <<

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("output.txt","w",stdout);

	int n, num;
	cin >> n;
	set<int> s;

	while(n--){
		cin >> num;
		s.insert(num);
	}
	cout << s.size();

	return 0;
}