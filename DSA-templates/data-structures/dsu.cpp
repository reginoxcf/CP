//https://judge.yosupo.jp/problem/unionfind
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) begin(v), end(v)
#define pi pair<int, int>
#define vi vector<int>
using namespace std;

struct DSU{
	int n;
	vector<int> lab;
	DSU(int n){
		this->n = n;
		lab.resize(n+1, -1);
	}
	void resize(int n){
		this->n = n;
		lab.resize(n+1, -1);
	}
	int find(int u){
		if(lab[u] < 0) return u;
		return lab[u] = find(lab[u]);
	}
	void join(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(lab[u] > lab[v]) swap(u, v);
		lab[u] += lab[v];
		lab[v] = u;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t; cin >> n >> t;
	DSU dsu(n);
	while(t--){
		int x, u, v; cin >> x;
		if(x==0){
			cin >> u >> v;
			dsu.join(u+1, v+1);
		}
		else{
			cin >> u >> v;
			cout << (dsu.find(u+1) == dsu.find(v+1)? "1\n":"0\n");
		}
	}
	return 0;
}
