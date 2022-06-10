#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>size;
// vector<int>rank;

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
// void make_set(int v) {
//     parent[v] = v;
//     rank[v] = 0;
// }

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
// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (rank[a] < rank[b])
//             swap(a, b);
//         parent[b] = a;
//         if (rank[a] == rank[b])
//             rank[a]++;
//     }
// }

int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    size.resize(n+1);
    // rank.resize(n+1);
    int i,j;
    int a,b;
    for(i=1;i<=n;i++){
        make_set(i);
    }
    for(i=0;i<m;i++){
        char c;
        cin>>c;
        //cout<<c<<endl;
        if (c=='u'){
            j=4;
            while(j--)cin>>c;
            cin>>a>>b;
            //cout<<a<<" "<<b<<endl;
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