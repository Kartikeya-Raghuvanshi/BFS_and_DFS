#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>size;

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
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
void disjoin_sets(int a,int b){
    if (size[a] < size[b]) swap(a, b);
    parent[b] = b;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    parent.resize(n+1);
    size.resize(n+1);
    int i,j;
    int a,b;
    for(i=1;i<=n;i++){
        make_set(i);
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        union_sets(a,b);
    }
    for(i=0;i<k;i++){
        char c;
        cin>>c;
        if (c=='c'){
            j=2;
            while(j--)cin>>c;
            cin>>a>>b;
            union_sets(a,b);
        }
        else{
            j=2;
            while(j--)cin>>c;
            cin>>a>>b;
            if(find_set(a)==find_set(b))cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}