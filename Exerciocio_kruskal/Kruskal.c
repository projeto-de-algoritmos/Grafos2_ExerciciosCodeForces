#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001

struct r{
    ll u, v, w, id;
} a[N];

ll n,m,mst, fa[N], f[N], sz[N], l[N]; // mst minimal spanning tree

bool compare(r x, r y){
    return x.w<y.w;

}

ll add(ll u, ll v, ll w){
    ll maxi=0;
    while((fa[u] != u || fa[v] != v ) && u != v){
        if( fa[u] == u || (fa[v]!= v && sz[v]<= sz[u] )){
            maxi=max(maxi , l[v] );
            v = fa[v];
        }else{
            maxi=max(maxi, l[u]);
            u = fa[u];
        }
    }
    if(u == v){
        return w - maxi;
    }    
    if( sz[u] < sz[v]){
        swap(u,v);
    }
    sz[u] += sz[v];
    fa[v] = u;
    l[v] = w;
    return mst +=w , 0;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a[i] .u>>a[i] .v>>a[i].w;
        sz[i] = 1;
        fa[i] = a[i].id=i;
    }         
    sort(a+1,a+m+1, compare);
    for(int i = 1; i <=m; i++){
        f[a[i].id] = add(a[i].u , a[i].v, a[i].w);
    }
    for(int i = 1; i<=m ; i++){
        cout<<mst+f[i]<<endl;
    }
}

/*
5 7
1 2 3
1 3 1
1 4 5
2 3 2
2 5 3
3 4 2
4 5 4
*/