#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string s;

ll rd(ll l, ll r){
	return rng() % (r-l+1) + l; 
}

void gen(){
	ofstream file(".inp");
	//something
	file.close();
}


int main(){
	for(int T = 1; T <= 1e3; T++){//should be enough
		cout << "Test " << T << "\n";
		gen();
		auto start = chrono::steady_clock::now();
		system("A.exe");
		auto fin = chrono::steady_clock::now();
		auto diff = fin-start;
		auto time = chrono::duration <double,milli> (diff).count();
		system("B.exe");
		if(system("fc .out .ans")!=0){
			cout << "WA\n";
			return 0;
		}
		cout << time << "ms\n";
	}

}
