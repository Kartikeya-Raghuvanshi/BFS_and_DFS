#include<bits/stdc++.h>
using namespace std;

/*

INPUT FORMAT ::

the graph contains n vertex and m directed edges and has q update queries where the value of the current weight are changed
first line contain n , m, q respectively
next m lines contains 3 integers as description of edges as source(u) to sink(v) with weight(w) respectively
next q lines contains update queries as 3 integers as mentioned above

OUTPUT PORMAT ::

the program outputs a matris where the cell i,j represents the min directional distance from vertex i to j
if the distance in such a case is infinite it outputs 1000000001

EXAMPLE::
an example input is given at the end of the code


*/


int main(){//update the weights add or remove with bit changes to the code with O(v2)
    int n,m,q;
    cin>>n>>m>>q;
    int i,j,k;
    vector<vector<long long> >d(n+1,vector<long long>(n+1,1e9+1));
    for(i=0;i<m;i++){
        int t;
        pair<int,long long> temp;
        cin>>t>>temp.first>>temp.second;
        d[t][temp.first]=temp.second;
    }
    for(i=1;i<=n;i++){
        d[i][i]=0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    int u,v,w;
    for(k=0;k<q;k++){
        cin>>u>>v>>w;
        if (d[u][v]>w){
            d[u][v]=w;
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if (d[i][u]+d[u][v]+d[v][j]<d[i][j]){
                        d[i][j]=d[i][u]+d[u][v]+d[v][j];
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
8 15 2
1 2 3
1 4 5
2 7 6
2 8 1
2 4 3
3 5 6
3 8 7
7 1 5
7 8 1
8 5 14
3 2 2
5 6 4
4 6 2
5 4 8
8 6 4
4 6 1
2 4 1
*/