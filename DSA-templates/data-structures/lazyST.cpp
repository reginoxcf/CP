const ll N = 1e6+3;
struct LazySegTree{
	//Segment tree lazy propagation subarray sum
	ll tree[N*4+1], lazy[N*4+1];
	void reset(){
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
	}
	void down(ll id){
		ll t = lazy[id];
		tree[id*2+1]+=t;
		tree[id*2]+=t;
		lazy[id*2+1]+=t;
		lazy[id*2]+=t;
		lazy[id]=0;
	}
	void upd(ll id, ll l, ll r, ll u, ll v, ll val){
		if(l>r||u>v) return ;
		if(v<l||r<u) return ;
		if(u<=l&&r<=v){
			tree[id]+=val;
			lazy[id]+=val;
			return ;
		}
		down(id);
		upd(id*2,l,(l+r)/2,u,v,val);
		upd(id*2+1,(l+r+2)/2,r,u,v,val);
		tree[id]=tree[id*2]+tree[id*2+1];
	}
	ll get(ll id, ll l, ll r, ll u, ll v){
		if(u>v||l>r) return 0;
		if(v<l||r<u) return 0;
		if(u<=l&&r<=v) return tree[id];
		down(id);
		return get(id*2, l, (l+r)/2, u, v)+get(id*2+1, (l+r+2)/2, r, u, v);
	}
} tree;

/*
UNTESTED CODE
struct LazyST{
	//Segment tree lazy propagation subarray sum
	vector<pair<ll,ll>> t;
	void resize(int n){
		this->n = n;
		t.resize(n*4+3);
	}
	LazySegTree(int n){
		this->n = n;
		resize(n);
	}
	void push(int id){
		ll &x = t[id].second;
		t[id*2].first += x;
		t[id*2+1].first += x;
		t[id*2].second += x;
		t[id*2+1].second += x;
		x = 0;
	}
	void update(int L, int R, ll v, int id = 1, int l = 1, int r = n){
		if(L > r || R < l) return;
		if(L <= l && r <= R){
			t[id].first += v;
			t[id].second += v;
			return;
		}
		push(id);
		update(L, R, v, id*2, l, (l+r)/2);
		update(L, R, v, id*2+1, (l+r+2)/2, r);
		t[id].first = t[id*2].first + t[id*2+1].first;
	}
	ll get(int L, int R, int id = 1, int l = 1, int r = n){
		if(L > r || R < l) return 0;
		if(L <= l && r <= R) return t[id].first;
		push(id);
		return get(L, R, id*2, l, (l+r)/2) + get(L, R, id*2+1, (l+r+2)/2, r);
	}
	int walk(int id, ll v, int l = 1, int r = n){
		if(t[id].first < v) return n+1; 
		if(l == r) return l;
		push(id);
		if(t[id*2].first >= v) return walk(v, l, id*2, (l+r)/2);
		return walk(v-t[id*2].first, id*2+1, (l+r+2)/2, r);
	}
};
*/
