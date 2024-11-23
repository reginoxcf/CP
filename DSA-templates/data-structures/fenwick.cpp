const int N = 1e6+3;
struct Fenwick{
	// range add range query (sum)
	ll t[N][2];
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
};
//Usage:
// - add(l, r, x): increase a[l], a[l+1], ..., a[r] by x
// - query(l, r): find a[l] + a[l+1] + ... + a[r]
