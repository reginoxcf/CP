#include<bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;
const ll maxn = 1e6+3;
ll n, x, y, q;
struct Fenwick{
	// range add range query (sum)
	ll t[maxn][2];
	void upd(ll tp, ll id, ll x){
		for(ll i = id; i <= n; i+=i&(-i)) t[i][tp]+=x;
	}
	void add(ll l, ll r, ll x){
		upd(0, l, x); upd(0, r+1, -x);
		upd(1, l, x*(l-1)); upd(1, r+1, -x*r);	
	}
	ll sum(ll tp, ll id){
		ll res = 0;
		for(ll i = id; i > 0; i-=i&(-i)) res+=t[i][tp];
		return res;
	}
	ll get(ll x){
		return sum(0, x)*x  - sum(1, x);
	}
	ll query(ll a, ll b){
		return get(b) - get(a-1);
	}
} tree;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(task".inp","r")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> x;
		tree.add(i, i, x);
	}
	cin >> q;
	while(q--){
		ll t, l, r, v;
		cin >> t >> l >> r;
		if(t==1){cin >> v; tree.add(l, r, v);}
		else{cout << tree.query(l, r) << "\n";}
	}
	return 0;
}