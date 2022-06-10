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
    int m;
    // for(i=0;i<n;i++){
    //     cout<<fen[i+1]<<" ";
    // }
    // cout<<endl;
    for(i=0;i<q;i++){
        long long s,k,b;
        cin >>s>>k>>b;
        if (s==1){
            p=k;
            while(p<=n){
                fen[p]=fen[p]-a[k-1]+b;
                p=(((p-1)&p)^p)+p;
                // cout<<p<<" ";
            }
            a[k-1]=b;
            // cout<<endl;
            // for(i=0;i<n;i++){
            //     cout<<fen[i+1]<<" ";
            // }
            // cout<<endl;
        }
        else{
            k--;
            long long sum=0;
            m=log2(k)+1;
            j=0;
            while(j<=m){
                if (k&(1<<j)){

                    sum-=fen[k];
                    k=k&(k-1);
                    
                }
                j++;
            }
            m=log2(b)+1;
            j=0;
            while(j<=m){
                if (b&(1<<j)){
                    // cout<<b<<endl;
                    sum+=fen[b];
                    b=b&(b-1);
                    
                }
                j++;
            }
            cout<<sum<<endl;

        }
    }
    // for(i=0;i<n;i++){
    //     cout<<fen[i+1]<<" ";
    // }
    // cout<<endl;

}