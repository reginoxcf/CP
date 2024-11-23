//Least Common Ancestor of 2 nodes (u, v)
#include<bits/stdc++.h>
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sp << " "
#define task ""
using namespace std;
ll n, q, l, r;
const ll LOG = 22, N = 1e6+3;
ll depth[N], p[N][LOG+2];
vector<ll> children[N];
void dfs(ll u, ll pa){
	depth[u]=depth[pa]+1;
	p[u][0]=pa;
	for(ll i = 1; i <= LOG; i++) p[u][i]=p[p[u][i-1]][i-1];
	for(ll i = 0; i < (ll)children[u].size(); i++){
		dfs(children[u][i],u);
	}
	return ;
}

ll lca(ll u, ll v){
	if(depth[u]<depth[v]) swap(u,v);
	ll k = depth[u]-depth[v];
	for(ll i = LOG; i >= 0; i--){
		if(k&(1<<i)){
			u = p[u][i];
		}
	}
	if(u==v) return u;
	for(ll i = LOG; i >= 0; i--){
		if(p[u][i]!=p[v][i]){
			u=p[u][i];
			v=p[v][i];
		}
	}
	return p[u][0];
}
int main(){
	faster;
	cin >> n;
	for(ll i = 1; i < n; i++){
		cin >> l >> r;
		children[l].push_back(r);
	}
	dfs(1,0);
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << lca(l,r) << "\n";
	}
	return 0;
}