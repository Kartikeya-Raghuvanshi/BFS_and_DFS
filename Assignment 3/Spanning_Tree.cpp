#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>size;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    size.resize(n+1);
    vector<Edge>edg(m);
    long long cost=0;

    int i,j;
    int a,b,w;
    for(i=1;i<=n;i++){
        make_set(i);
    }
    for(i=0;i<m;i++){
        cin>>a>>b>>w;
        edg[i].u=a;
        edg[i].v=b;
        edg[i].weight=w;
    }
    sort(edg.begin(),edg.end());

    for(i=0;i<m;i++){
        Edge e;
        e=edg[i];
        if (find_set(e.u)!=find_set(e.v)){
            b=find_set(e.v);
            a=find_set(e.u);
            cost+=e.weight;
            union_sets(a,b);
        }
    }

    cout<<cost;
}