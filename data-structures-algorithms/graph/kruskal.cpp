#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6+3;
#define pll pair<ll,ll>
#define ppll pair<ll,pair<ll,ll>>
#define fi first
#define se second
struct DSU{
	ll par[maxn], sz[maxn];
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
} dsu;
ll n, m, x, y, w;
vector<pll> adj[maxn];
vector<ppll> v;

ll kruskal(){
	for(ll i = 0; i <= n; i++) dsu.make_set(i);
	sort(v.begin(), v.end());
	ll cost = 0, cnt = 0;
	for(ll i = 0; i < (ll)v.size(); i++){
		ppll q = v[i];
		if(dsu.find_set(q.se.fi) == dsu.find_set(q.se.se)) continue;
		cost += q.fi;
		dsu.union_set(q.se.fi, q.se.se);
		cnt++;
		if(cnt == n-1) break;
	}
	return cost;
}

int main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= m; i++){
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		v.push_back({w, {x, y}});
	}
	auto st = chrono::steady_clock::now();
	cout << kruskal();
	auto e = chrono::steady_clock::now();
	cerr << chrono::duration <double,milli> (e-st).count()*1000 << " ms\n";
	return 0;
}