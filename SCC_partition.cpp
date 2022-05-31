#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;// graph represented as an adjacency list (here directed graph)
vector<vector<int> > adjr;// same graph with reversed connections

int sys=0;
vector<int>df;

vector<int>order;
vector<int>loc;



void dfs(int v,int val){// here v is the vertex which we search 
    //if (df[v]!=-1)return;
    
   // cout<<v<<" ";
    int u;
    int con=adj[v].size();

    for ( u=0 ; u<con;u++){
        int nod =adj[v][u];
        //cout<<nod<<endl;
        if (df[nod]==-1){
            df[nod]=val;
            dfs(nod,val);
        }
    }
    order.push_back(v);
}


// void bfs(int n){//here s is the source vertex and total number of vertices
//     queue<int> q;
//     vector<bool> used(n+1, false);// to check whether the position is used or not

//     int i;
    
//     for(i=1;i<=n;i++){
//         if (!used[i]){
//             used[i]=true;
//             order.push_back(i);
//             q.push(i);

//             while(!q.empty()){
//                 int v=q.front();
//                 q.pop();
//                 int con=adj[v].size();
//                 int j;
//                 for(j=0;j<con;j++){
//                     int u=adj[v][j];
//                     if (used[u]==false){
//                         used[u]=true;
//                         order.push_back(u);
//                         q.push(u);

//                     }
//                 }
//             }
//         }
//     }
// }
void systems( /*int n*/int v,int set){//here s is the source vertex and total number of vertices

    //cout<<v<<" ";

    int u;
    int con=adjr[v].size();

    for ( u=0 ; u<con;u++){
        int nod =adjr[v][u];
        //cout<<nod<<endl;

        if (df[nod]==df[v]&&loc[nod]==-1){
            loc[nod]=set;
            systems(nod,set);
        }
    }
    //order.push_back(v);

    // queue<int> q;
    // int i;


    // vector<bool> used(n+1, false);// to check whether the position is used or not

    // for(i=0;i<n;i++){
    //     if (!used[order[i]]){
    //         sys++;
    //         used[order[i]]=true;
    //         loc[order[i]]=sys;
    //         q.push(order[i]);

    //         while(!q.empty()){
    //             int v=q.front();
    //             q.pop();
    //             int con=adjr[v].size();
    //             int j;
    //             for(j=0;j<con;j++){
    //                 int u=adjr[v][j];
    //                 if (used[u]==false){
    //                     used[u]=true;
    //                     loc[u]=sys;
    //                     q.push(u);

    //                 }
    //             }
    //         }

    //     }
    // }

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
    //bfs(1,n);
    int val;
    for(i=1,val=1;i<=n;i++){
        if (df[i]==-1){
            df[i]=val;

            dfs(i,val);
            val++;
        }
    }
    
    for(i=1,val=1;i<=n;i++){
        if (loc[i]==-1){
            loc[i]=val;
            systems(i,val);
            val++;
        }
    }

    // cout<<endl;
    // for(i=0;i<n;i++){
    //     cout<<order[i]<<" ";
    // }
    //cout<<endl;

    cout<<val-1<<endl;

    for(i=1;i<=n;i++){
        cout<<loc[i]<<" ";
    }


}