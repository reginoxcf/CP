//Implicit(dynamic) Li Chao Tree
const ll maxn = 1e6+3, inf = 1e12; //change this to preference/problem constraints
struct func {
    ll m, b;
    ll operator()(ll x) { return m * x + b; }
} L[maxn * 4];

func create(ll a, ll b){
    func x; x.m = a, x.b = b;
    return x;
}

struct ImplicitLiChaoTree{
    ll left[maxn*4], right[maxn*4], cnt = 0;
    void insert(ll l, ll r, func seg, ll id=0) {
        if(l + 1 == r) {
            if(seg(l) > L[id](l)) L[id] = seg;
            return;
        }
        ll mid = (l + r) >> 1;
        if(L[id].m > seg.m) swap(L[id], seg);
        if(L[id](mid) < seg(mid)){
            if(left[id] == 0) left[id] = ++cnt;
            swap(L[id], seg);
            insert(l, mid, seg, left[id]);
        }
        else{
            if(right[id] == 0) right[id] = ++cnt;
            insert(mid, r, seg, right[id]);
        }
    }
    ll query(ll l, ll r, ll x, ll id=0) {
        if(l + 1 == r) return L[id](x);
        ll mid = (l + r) >> 1;
        if(x < mid){
            if(left[id] == 0) left[id] = ++cnt;
            return max(L[id](x), query(l, mid, x, left[id]));
        }
        else{
            if(right[id] == 0) right[id] = ++cnt;
            return max(L[id](x), query(mid, r, x, right[id]));
        }
    }
} ;
/*
struct "func" has 2 numbers: 
- m is the slope
- b is the y-intercept
if "var" is a "func" then var(x) will return mx+b

Usage:
- create(a, b): create function f(x) = ax+b and returns it (struct func)

- insert(l, r, func, id): insert function "func" into LCT
l, r is range of LCT
id is index of LCT root

e.g.: insert(-inf, inf, func)

- query(l, r, x, id): return the MAXIMUM value of ALL func(x)
l, r is range of LCT
id is index of LCT root

e.g.: query(-inf, inf, 2)

For the most accurate results, l, r, and id should be the same across all function calls
It is recommended for l = -inf, r = inf and id = 0/1
 */
//Credits: https://robert1003.github.io/2020/02/06/li-chao-segment-tree.html
