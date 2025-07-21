#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n), sz(n,1) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
        return true;
    }
};

struct Edge{
    int u,v;
    double d2;          // 거리의 제곱
    bool operator<(const Edge& o) const { return d2 < o.d2; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    cout<<fixed<<setprecision(8);
    for(int tc=1; tc<=T; ++tc){
        int N, S; cin>>N>>S;           // S는 무시
        vector<array<double,3>> pos(N);
        for(auto &p: pos){
            double x,y,z,vx,vy,vz;
            cin>>x>>y>>z>>vx>>vy>>vz;  // vx,vy,vz 모두 0
            p = {x,y,z};
        }
        vector<Edge> es;
        es.reserve( (long long)N*(N-1)/2 );
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j){
                double dx=pos[i][0]-pos[j][0];
                double dy=pos[i][1]-pos[j][1];
                double dz=pos[i][2]-pos[j][2];
                es.push_back({i,j, dx*dx+dy*dy+dz*dz});
            }
        sort(es.begin(), es.end());
        DSU dsu(N);
        double ans2 = 0;
        for(const auto& e: es){
            dsu.unite(e.u,e.v);
            if(dsu.find(0)==dsu.find(1)){ ans2 = e.d2; break; }
        }
        cout<<"Case #"<<tc<<": "<<sqrt(ans2)<<"\n";
    }
    return 0;
}