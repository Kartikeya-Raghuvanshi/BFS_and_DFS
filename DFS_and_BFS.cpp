#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;// graph represented as an adjacency list (here undirected graph)

vector<int>tin,tout;

int timer=0;

vector<int>df;
vector<int>bf_d, bf_p;//for calculation of distance in bfs & for storing the parent respectively

bool cycles=false;//to check if the graph has cycles using dfs

vector<char> comp;//this is to check for connected componnent classification inthe graph (as 'A','B'...)

vector<pair<int,int> > brid;
//to check for the min time int the neighbours


//point *****
void dfs(int v){// here v is the vertex which we search 
    tin[v] =timer++;
    

    int u;
    int con=adj[v].size();

    for ( u=0 ; u<con;u++){
        int nod =adj[v][u];
        //cout<<nod<<endl;

        if (df[nod]==-1){
            df[nod]=v;

            dfs(nod);
        }
        else{
            if (!cycles){
                cycles=true;
            }
        }
    }
           

    tout[v] =timer++;

}

void bfs(int s,int n){//here s is the source vertex and total number of vertices
    queue<int> q;
    q.push(s);

    bf_p[s]=0;//this indicates that the node is head/source
    bf_d[s]=0;



    vector<bool> used(n, false);// to check whether the position is used or not
    used[s]=true;

    while(!q.empty()){
        int v=q.front();
        q.pop();
        int con=adj[v].size();
        int i;
        for(i=0;i<con;i++){
            int u=adj[v][i];
            if (used[u]==false){
                used[u]=true;
                q.push(u);
                bf_p[u]=v;

            }

        }

    }
}

void dfs_edge_classify(int u, int v){
    if (df[u]==-1||df[v]==-1){
        cout<<"Disjoint\n";
    }
    else if (df[u]==v||df[v]==u){
        cout<<"tree edge\n";
    }
    else cout<<"back edge\n";
    

}

int connections(int n){//this is to give each set of connection a unique id & returns the no. of connections
    int j;
    for (j=1;j<=n;j++){
        bf_p[j]=-1;
    }
    char t='A'-1;//this is the char for ids
    for (j=1;j<=n;j++){
        if (bf_p[j]!=-1)continue;
        queue<int> q;
        q.push(j);
        t++;

        bf_p[j]=0;//this indicates that the node is head/source
        comp[j]=t;



        vector<bool> used(n, false);// to check whether the position is used or not
        used[j]=true;

        while(!q.empty()){
            int v=q.front();
            q.pop();
            int con=adj[v].size();
            int i;
            for(i=0;i<con;i++){
                int u=adj[v][i];
                if (used[u]==false){
                    used[u]=true;
                    
                    comp[u]=t;
                    
                    q.push(u);
                    bf_p[u]=v;

                }

            }

        }
    }
    return t-'A'+1;


}

void gr_edge_insert(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void bridge_find(int l, int n){//where l is the current no. of components of the graph
    int x,y;
    for (x=1;x<=n-1;x++){
        for (y=x+1;y<=n;y++){
            if (find(adj[x].begin(),adj[x].end(),y)==adj[x].end())continue;
            int j;
            for (j=1;j<=n;j++){
                bf_p[j]=-1;
            }
            char t='A'-1;//this is the char for ids
            for (j=1;j<=n;j++){
                if (bf_p[j]!=-1)continue;
                queue<int> q;
                q.push(j);
                t++;

                bf_p[j]=0;//this indicates that the node is head/source
                comp[j]=t;



                vector<bool> used(n, false);// to check whether the position is used or not
                used[j]=true;

                while(!q.empty()){
                    int v=q.front();
                    q.pop();
                    int con=adj[v].size();
                    int i;
                    for(i=0;i<con;i++){
                        int u=adj[v][i];
                        if ((u==x&&v==y)||(u==y&&v==x))continue;
                        if (used[u]==false){
                            used[u]=true;
                            
                            comp[u]=t;
                            
                            q.push(u);
                            bf_p[u]=v;

                        }

                    }

                }
            }
            if (t+1-'A'>l){
                pair <int,int> p;
                p=make_pair(x,y);
                brid.push_back(p);
            }
            
        }
    }
    


}

void gr_edge_remove(int u, int v){
    adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
    adj[v].erase(find(adj[v].begin(),adj[v].end(),u));
}


int main(){
    int n;//n denotes the total number of vertex/nodes
    n=12;

    tin.resize(n+1,-1);
    tout.resize(n+1,-1);

    df.resize(n+1,-1);
    bf_d.resize(n+1,-1);
    bf_p.resize(n+1,-1);

    comp.resize(n+1,'0');

    


    int i;
    for(i=0;i<=n;i++){
        vector<int> vtx;

        adj.push_back(vtx);
    }

    gr_edge_insert(2,4);
    gr_edge_insert(4,8);
    gr_edge_insert(8,3);
    gr_edge_insert(3,7);
    gr_edge_insert(7,5);
    gr_edge_insert(3,1);
    gr_edge_insert(4,9);
    gr_edge_insert(9,10);
    gr_edge_insert(1,10);
    gr_edge_insert(5,10);
    gr_edge_insert(10,6);
    gr_edge_insert(6,4);
    gr_edge_insert(11,12);

    


    df[2]=0;
    dfs(2);

    bfs(2,n);


    //check for dfs algo:
    // for(i=1;i<=n;i++){
    //     cout<<df[i]<<" ";
    // }
    // cout<<endl;
    // for(i=1;i<=n;i++){
    //     cout<<tin[i]<<" ";
    // }
    // cout<<endl;
    // for(i=1;i<=n;i++){
    //     cout<<tout[i]<<" ";
    // }
    //cout<<"\n\n";
    //edge classification:
    // dfs_edge_classify(4,8);
    // dfs_edge_classify(8,7);
    // dfs_edge_classify(8,11);
    // dfs_edge_classify(6,10);




    //check for bfs algo
    // for(i=1;i<=n;i++){
    //     cout<<bf_d[i]<<" ";
    // }
    // cout<<endl;
    // for(i=1;i<=n;i++){
    //     cout<<bf_p[i]<<" ";
    // }

    //classifying the connections in the graphs with unique ids as 'A','B'.....
    // connections(n);
    // for(i=1;i<=n;i++){
    //     cout<<comp[i]<<" ";
    // }
    // cout<<endl;

    //check for cyclic
    //cout <<"Is the graph cyclic: "<<(bool)cycles;

    //check for the bridges 
    // int l=connections(n);
    // bridge_find(l,n);
    // int m=brid.size();
    // for (i=0;i<m;i++){
    //     cout<<"("<<brid[i].first<<","<<brid[i].second<<")"<<" ";

    // }
    // cout<<endl;

    //removing bridges
    // m=brid.size();
    // for (i=0;i<m;i++){
    //     gr_edge_remove(brid[i].first,brid[i].second);
    // }

    //checking for the total number of connections after the bridge removal
    // connections(n);
    // for(i=1;i<=n;i++){
    //     cout<<comp[i]<<" ";
    // }
    // cout<<endl;

        


}
/*
the graph used for this question :


2------4-------8-----3----------7
       |             |          |
      / \            |          |
     /   \           |          |
    6     9----------1          5
    \     /           \       /
     \   /              \    /
       |                   |
       \                  /
         \               /
           \            /
             \         /
               \     /
                  10


        11-------12



*/

