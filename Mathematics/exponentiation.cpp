#include<bits/stdc++.h>

#define brr cin.tie(0) -> sync_with_stdio(0);
#define tc int t; cin >> t; while(t--)
#define __ << "  " <<
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007

using namespace std;

ll expo(ll a, ll b){
	if(b==0) return 1;
	if(a==0) return 0; 
	if(b==1) return a;
	if(b%2) return (a*(expo(a, b-1)%mod))%mod;
	return (expo(a, b/2)*expo(a, b/2))%mod;
}

void solve(){
	ll a, b; cin >> a >> b;
	cout << expo(a, b) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

	//auto start = chrono::high_resolution_clock::now();
	int t = 1;
	cin >> t;
	while(t--)solve();
	//auto stop = chrono::high_resolution_clock::now();
	//cout << "\nEXECUTION TIME :: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " µs";

	return 0;
}