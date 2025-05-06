const int N = 1e5+3;
int sz[N], depth[N];
bool hv[N];
int hsz, hmax[N], anc[N];
pair<int, int> hid[N];
int sp[N][L+1];

void find_sz(int u, int p){
    depth[u] = depth[p] + 1;
    sz[u] = 1;
    for(int i = 1; i <= L; i++) sp[u][i] = sp[sp[u][i-1]][i-1];
    int mx = -1;
    for(auto v:g[u]){ 
        if(v == p) continue;
        sp[v][0] = u;
        find_sz(v, u);
        sz[u] += sz[v];
        if(mx == -1 || sz[mx] < sz[v]) mx = v;
    }
    if(mx != -1){
        hv[mx] = 1;
    }
}

void find_hld(int u, int p){
    if(hid[u].first == -1){
        hid[u].first = ++hsz;
        hid[u].second = 1;
        anc[u] = u;
    }
    for(auto v:g[u]){
        if(v == p) continue;
        if(hv[v] == 1){
            hid[v].first = hid[u].first;
            hid[v].second = hid[u].second + 1;
            anc[v] = anc[u];
            find_hld(v, u); 
        }
    }
    for(auto v:g[u]){
        if(v == p) continue;
        if(hv[v] == 0) find_hld(v, u);
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for(int l = L; l >= 0; l--){
        if((diff >> l) & 1){
            v = sp[v][l];
        }
    }
    if(u == v) return u;
    for(int l = L; l >= 0; l--){
        if(sp[u][l] != sp[v][l]){
            u = sp[u][l];
            v = sp[v][l];
        }
    }
    return sp[u][0];
}
