#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
//#include<stack>
//#include<chrono>
#include<map>

#define __ << "  " <<

using namespace std;
//using namespace std::chrono;

void solve(){
	int n,m,num;
	cin >> n >> m;
	map<int, int> tickets;
	for(int i=0; i<n; ++i) {
		cin >> num;
		++tickets[num];
	}

	while(m--){
		cin >> num;
		auto best_ticket = tickets.lower_bound(num);

		if(tickets.size()==0 || (best_ticket == tickets.begin() && best_ticket->first > num)) {
			cout << -1 << "\n";
			continue;
		}
		else if(best_ticket->first > num || best_ticket == tickets.end())--best_ticket;

		cout << best_ticket->first << "\n";
		--tickets[best_ticket->first];
		if(best_ticket->second==0) tickets.erase(best_ticket->first);

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("output.txt","w",stdout);

	//auto start = chrono::high_resolution_clock::now();
	solve();
	//auto stop = chrono::high_resolution_clock::now();

	//cout << "\nEXECUTION TIME (MICROSECONDS) :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count();

	return 0;
}