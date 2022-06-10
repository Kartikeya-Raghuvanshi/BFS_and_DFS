#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int i,j;
    vector<long long>a(n);
    vector<long long>fen(n+1);
    for(i=0;i<n;i++){
        cin>>a[i];
        fen[i+1]=a[i];
    }
    int p=2;
    while(p<=n){
        for(i=p;i<n+1;i+=p){
            fen[i]=fen[(i)-p/2]+fen[i];
        }
        
        p*=2;
    }
    // for(i=0;i<n;i++){
    //     cout<<fen[i+1]<<" ";
    // }
    // cout<<endl;
    int m;
    for(i=0;i<q;i++){
        long long s,k,b,u;
        cin >>s>>k;
        if (s==2){
            long long sum=0;
            m=log2(k)+1;
            j=0;
            while(j<=m){
                if (k&(1<<j)){

                    sum+=fen[k];
                    k=k&(k-1);
                    
                }
                j++;
            }
            // cout<<sum<<endl;
        }
        else{
            cin>>b>>u;
            // k--;
            
            // m=log2(k)+1;
            // j=0;
            // while(j<=m){
            //     if (k&(1<<j)){

            //         fen[k]-=u*(1<<j);
            //         k=k&(k-1);
                    
            //     }
            //     j++;
            // }
            // p=k;
            // while(p<=n){
            //     fen[p]=fen[p]-u*(((p-1)&p)^p);
            //     p=(((p-1)&p)^p)+p;
            //     // cout<<p<<" ";
            // }
            // m=log2(b)+1;
            // j=0;
            // while(j<=m){
            //     if (b&(1<<j)){
            //         // cout<<b<<endl;
            //         fen[b]+=u*(1<<j);
            //         b=b&(b-1);
                    
            //     }
            //     j++;
            // }
            // p=k+1;
            // while(p<=n){
            //     // if((((p-1)&p)^p)>b-k)fen[p]=fen[p]+u*(b-k);
            //     fen[p]=fen[p]+u*(((p-1)&p)^p);
            //     p=(((p-1)&p)^p)+p;
            //     // cout<<p<<" ";
            // }
            // p=b+1;
            // while(p<=n){
            //     // if((((p-1)&p)^p)>b-k)fen[p]=fen[p]+u*(b-k);
            //     fen[p]=fen[p]+u*(((p-1)&p)^p);
            //     p=(((p-1)&p)^p)+p;
            //     // cout<<p<<" ";
            // }
            m=log2(k)+1;
            j=0;
            while(j<=m){
                if (k&(1<<j)){

                    fen[k]=fen[k]+u;
                    k=k&(k-1);
                    
                }
                j++;
            }
            m=log2(b)+1;
            j=0;
            while(j<=m){
                if (b&(1<<j)){

                    fen[b]=fen[b]+u;
                    b=b&(b-1);
                    
                }
                j++;
            }

        }
    }
    for(i=0;i<n;i++){
        cout<<fen[i+1]<<" ";
    }
    cout<<endl;
}