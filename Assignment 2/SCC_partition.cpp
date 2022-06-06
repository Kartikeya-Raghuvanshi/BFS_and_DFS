#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;// graph represented as an adjacency list (here directed graph)
vector<vector<int> > adjr;// same graph with reversed connections

vector<int>df;

vector<int>order;
vector<int>loc;



void dfs(int v,int val){// here v is the vertex which we search and val gives ith the initial id
    int u;
    int con=adj[v].size();

    for ( u=0 ; u<con;u++){
        int nod =adj[v][u];
        if (df[nod]==-1){
            df[nod]=val;
            dfs(nod,val);
        }
    }
    order.push_back(v);
}

void systems(int v,int set){


    int u;
    int con=adjr[v].size();

    for ( u=0 ; u<con;u++){
        int nod =adjr[v][u];

        if (df[nod]==df[v]&&loc[nod]==-1){
            loc[nod]=set;
            systems(nod,set);
        }
    }

}

void gr_connect(int u, int v){//creating an ordered connection u->v u is req for b
    adj[u].push_back(v);
    adjr[v].push_back(u);
}

int main(){
    int n,m;
    cin>>n>>m;

    loc.resize(n+1,-1);
    df.resize(n+1,-1);

    int i,j;
    for(i=0;i<=n;i++){
        vector<int>temp;
        adj.push_back(temp);
        adjr.push_back(temp);
    }

    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr_connect(a,b);
    }
    int val;
    for(i=1,val=1;i<=n;i++){
        if (df[i]==-1){
            df[i]=val;

            dfs(i,val);
            val++;
        }
    }
    
    for(i=0,val=1;i<n;i++){
        if (loc[order[n-1-i]]==-1){
            loc[order[n-1-i]]=val;
            systems(order[n-1-i],val);
            val++;
        }
    }
    cout<<endl;
    cout<<val-1<<endl;

    for(i=1;i<=n;i++){
        cout<<loc[i]<<" ";
    }


