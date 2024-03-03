const ll maxn = 1e6+3;
struct SegTree{
	//Segment tree lazy propagation subarray sum
	ll tree[maxn*4+1], lazy[maxn*4+1];
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
