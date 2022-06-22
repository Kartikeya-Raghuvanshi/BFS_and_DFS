#include<bits/stdc++.h>
using namespace std;

vector<long long>d;//to maintain the distance od each node 

struct cmp {
    bool operator() (int x, int y) const {
        return d[x] == d[y] ? x < y : d[x] < d[y];
    }
};

const int MOD = 1e9+7;
const long long INF=1e15;

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> minw(n+1,0),maxw(n+1,0),ways(n+1,0);
    vector<vector<pair<int,long long> > >gra(n+1);
    d.resize(n+1,INF);
    
    int i;
    for(i=0;i<m;i++){
        pair<int ,long long> temp;
        int t;
        cin>>t>>temp.first>>temp.second;
        gra[t].push_back(temp);
        
    }
    set<int ,cmp>qu;
    d[1]=0;
    ways[1]=1;
    qu.insert(1);
    while(!qu.empty()){
        int u=*qu.begin();
        long long dis=d[u];
        qu.erase(qu.begin());

        int k=gra[u].size();
        for (i=0;i<k;i++){
            int v=gra[u][i].first;
            
            int w=gra[u][i].second;
            if (dis+w<=d[v]){
                if (d[v]!=INF)qu.erase(v);//to remove redundancy
                if(dis + w == d[v]){
                        ways[v] = (ways[u] + ways[v]) % MOD;
                        minw[v] = min(minw[v], minw[u]+1);
                        maxw[v] = max(maxw[v], maxw[u]+1);
                }
                if(dis + w < d[v]){
                        d[v] = dis+w;
                        ways[v] = ways[u];
                        minw[v] = minw[u]+1;
                        maxw[v] = maxw[u]+1;
                }
                qu.insert(v);

            }
        }

    }
    cout<<d[n]<<" "<<ways[n]<<" "<<minw[n]<<" "<<maxw[n];
}