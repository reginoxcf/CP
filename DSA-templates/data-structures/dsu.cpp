//DSU data structure
#include <bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;
const ll N = 1e6+3;
ll t, n, u, v, x;
ll par[N], sz[N];
void make_set(ll u){
	par[u]=u;
	sz[u]=1;
}
ll find_set(ll u){
	if(u==par[u]) return u;
	return par[u]=find_set(par[u]);
}
void union_set(ll u, ll v){
	u = find_set(u), v = find_set(v);
	if(u!=v){
		if(sz[u]<sz[v]) swap(u, v);
		par[v] = u;
		sz[u]+=sz[v];
	}
}
int main(){
	if(fopen(task".inp","r")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0);
	// auto st = chrono::steady_clock::now();
	cin >> n >> t;
	for(ll i = 1; i <= n; i++) make_set(i);
	while(t--){
		cin >> x;
		if(x==0){cin >> u >> v; union_set(u, v);}
		else{cin >> u >> v; cout << ((find_set(u) == find_set(v))? "1\n":"0\n");}
	}
	// auto fi = chrono::steady_clock::now();
	// cout << (chrono::duration <double,milli> (fi-st).count())*1000 << "ms";
}