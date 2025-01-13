struct Fenwick{
	// range add range query (sum)
	vector<vector<ll>> t;
	int n;
	Fenwick(int n): n(n){
		t.assign(n+1, vector<ll>(2, 0));
	}
	void resize(int n){
		this->n = n;
		t.assign(n+1, vector<ll>(2, 0));
	}
	void upd(int tp, int id, ll x){
		for(int i = id; i <= n; i+=i&(-i)) t[i][tp]+=x;
	}
	void add(int l, int r, ll x){
		upd(0, l, x); upd(0, r+1, -x);
		upd(1, l, x*(ll)(l-1)); upd(1, r+1, -x*(ll)r);	
	}
	ll sum(int tp, int id){
		ll res = 0;
		for(ll i = id; i > 0; i-=i&(-i)) res+=t[i][tp];
		return res;
	}

	ll get(int x) {return sum(0, x)*(ll)x  - sum(1, x);}

	ll query(int l, int r) {return get(r) - get(l-1);}
};
//Usage:
// - add(l, r, x): increase a[l], a[l+1], ..., a[r] by x
// - query(l, r): find a[l] + a[l+1] + ... + a[r]
