#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;// graph represented as an adjacency list (here directed graph)

vector<int> order;//final possible topologicalsort
map<int,int>deg;//degree of connections required to come here
void tl_sort(){
    int n=adj.size()-1;
    int i;
    queue<int> q;
    vector<bool> b(n,false);

    for(i=1;i<=n;i++){
        if (deg[i]==0){
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
            deg[v]--;
            if (deg[v]==0){

                b[v]=true;
                q.push(v);
                order.push_back(v);
                continue;
            }
            
            
        }

    }
    

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

    tl_sort();
    //check for the size of sort;

    if(order.size()<n){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(i=0;i<n;i++){
            cout<<order[i]<<" ";
        }
    }


}