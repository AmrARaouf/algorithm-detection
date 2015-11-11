//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
const int maxn=1000*100+100;
vector <int>b,w;
int v[maxn],u[maxn],we[maxn],par[maxn],c[maxn],s[maxn],cnt=1,n,bf,wf;
int  root(int v){
    return (par[v]==v) ? v : par[v]=root(par[v]);
}
void onion(int a,int b){
    par[root(a)]=par[root(b)];
}
int main()
{
    ios_base::sync_with_stdio (false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>s[i],par[i]=i;
        if(c[i]==1)
            bf=i,b.push_back(i);
        else
            wf=i,w.push_back(i);
    }
    int f=0;
    for(int i=0;i<b.size();i++){
        for(int j=f;j<w.size();j++){
            onion(b[i],w[j]);
            int ans=min(s[b[i]],s[w[j]]);
            v[cnt]=b[i],u[cnt]=w[j],we[cnt]=ans;
            cnt++;
            s[b[i]]-=ans,s[w[j]]-=ans;
            if(s[b[i]]>0)
                f=j+1;
            else
                break;
        }
    }
    for(int i=1;i<=n;i++){
        if(root(i)!=root(bf) && c[bf]!=c[i]){
            v[cnt]=bf,u[cnt]=i,we[cnt]=0,cnt++;
            onion(1,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(root(i)!=root(wf) && c[wf]!=c[i]){
            v[cnt]=wf,u[cnt]=i,we[cnt]=0,cnt++;
            onion(1,i);
        }
    }
    for(int i=1;i<=n-1;i++)
        if(v[i]==u[i])
            cout<<i<<endl;
    for(int i=1;i<=n-1;i++)
        cout<<v[i]<<" "<<u[i]<<" "<<we[i]<<endl;

    return 0;
}
