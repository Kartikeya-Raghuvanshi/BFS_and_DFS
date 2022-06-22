#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    long long cost;
};


const int INF = 1000000001;

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<Edge> edges(m);
    int i,j;
    for(i=0;i<m;i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].cost;
    }
    vector<long long> d(n+1,INF);
    vector<int> p(n+1, -1);
    vector<bool>vist(n+1,false);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        if (i==0){
            vist[1]=true;
            d[1]=0;
        }
        for (j=0;j<m;j++) {
            Edge e=edges[j];
            if (d[e.a] + (long long)e.cost < (long long)d[e.b]) {
                d[e.b] = d[e.a] +(long long) e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (j=0;j<cycle.size();j++)
            cout << cycle[j] << " ";
        cout << endl;
    }
}

int main(){

    solve();

}