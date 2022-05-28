#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;// graph represented as an adjacency list (here directed graph)

vector<int> order;//final possible topologicalsort
map<int,int>deg;//degree of connections required to come here
int tl_sort(){
    int n=adj.size()-1;
    int i;
    queue<int> q;
    vector<bool> b(n,false);
    vector<int>p(n+1,-1),d(n+1,-1);//parent and distance for the coressponding nodes
    map<int,int>deg0=deg;//to copy the degree into a new map

    //first checking for cycles
    for(i=1;i<=n;i++){
        if (deg0[i]==0){
            q.push(i);
            b[i]=true;
            order.push_back(i);
        }
    }
    while(!q.empty()){
        
        int u=q.front();
        q.pop();
        int m=adj[u].size();
        for(i=0;i<m;i++){
            
            int v=adj[u][i];
            if(b[v])break;//checking if there is a cycle present
            deg0[v]--;
            if (deg0[v]==0){

                b[v]=true;
                q.push(v);
                order.push_back(v);
                continue;
            } 
        }
    }
    if (order.size()<n)return 0;//the starting city is 1 and end is n

    order.clear();
    deg0=deg;
    
    d[1]=0;
    p[1]=0;
    q.push(1);
    for(i=1;i<=n;i++){
        if (deg0[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u=q.front();
        
        q.pop();
        int m=adj[u].size();
        //cout<<u<<m<<endl;
        for(i=0;i<m;i++){
            int v=adj[u][i];
            
            if((d[v]==-1||d[v]<d[u]+1)&&d[u]!=-1){
                p[v]=u;
                d[v]=d[u]+1;
            }
            deg0[v]--;

            if (deg0[v]==0){
                q.push(v);
            }

        }

    }

    order.push_back(n);
    i=n;
    while(p[i]!=0){
        if(p[i]==-1){
            return 0;
        }
        order.push_back(p[i]);
        i=p[i];
    }
    return 1;
}


void gr_connect(int u, int v){//creating an ordered connection u->v u is req for b
    adj[u].push_back(v);
}

int main(){
    int n,m;
    cin>>n>>m;

    int i,j;
    for(i=0;i<=n;i++){
        vector<int>temp;
        adj.push_back(temp);
    }

    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr_connect(a,b);
        deg[b]++;
    }
    if(!tl_sort()){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<order.size()<<endl;
        for(i=order.size()-1;i>=0;i--){
            cout<<order[i]<<" ";
        }
    }


}