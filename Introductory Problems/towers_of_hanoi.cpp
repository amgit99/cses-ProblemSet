#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>

#define __ << "  " <<

using namespace std;

void hannoy(int n, int from, int to, int via){
	if(n>0){
		hannoy(n-1, from, via, to);
		cout << from << " " << to << endl;
		hannoy(n-1, via, to, from);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << (1<<n)-1 << endl;
	hannoy(n,1,3,2);
	return 0;
}
