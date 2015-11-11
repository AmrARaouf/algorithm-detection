//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
const int N = 3001;
const int M = 1e6;

int a[N];
int b[N];
int kt[N];
int n,m;
vector <int> nho;


int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    
    
    int cyc = 0;
    for(int i=1; i<=n; i++) kt[i] = 1;
    for(int i=1; i<=n; i++)
        if (kt[i]==1){
            kt[i] = 0;
            //if (a[i]!=i)
            cyc++;
            int j = a[i];
            while (kt[j]){
                kt[j] = 0;
                j = a[j];
            }
        }
    if (n-cyc==m){
        cout<<0<<" ";
        return 0;
    }
    if (n-cyc < m){
        
        m = m+cyc-n;
        cout<<m<<endl;
        for(int i=1; i<=n; i++) kt[i] = 1;
        for(int i=1; i<=n; i++)
            if (kt[i]==1){
            int u = i;
            kt[i] = 0;
            cyc++;
            int j = a[i];
            while (kt[j]){
                u = min(j,u);
                kt[j] = 0;
                j = a[j];
            }
            nho.push_back(u);
        }
        /*for(int i=0; i<m+cyc-n; i++)
            cout<<nho[i]<<" ";*/
        for(int i=1; i<=m; i++){
            
            cout<<1<<" "<<nho[i]<<" ";
        }
        return 0;
    }
    if (n-cyc>m){
    
        for(int i=1; i<=n; i++)
            b[a[i]] = i;
        m = n-cyc-m;
        cout<<m<<endl;
        int j = 1;
        int u, v;
        while (m>0&&j<=n){
            j = 1;
            while (a[j]==j) j++;
            u = a[j];
            v = a[j];
            while (v!=j){
                u = min(u,v);
                v = a[v];
            }
            m--;
            cout<<min(u,v)<<" "<<max(u,v)<<" ";
            swap(a[u],a[v]);
            
        }
    }
}