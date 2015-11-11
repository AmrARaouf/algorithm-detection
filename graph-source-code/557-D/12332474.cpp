//Language: GNU C++11


#include<bits/stdc++.h>
#define maxx 100011
#define ll long long
using namespace std;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
vector<int> p[maxx];
ll ans;
int n,m,in[maxx],out[maxx],col[maxx];
int ran[2];
bool isOne(){
    for(int i=1;i<=n;i++) if(in[i]) return 0;
    return 1;
}
bool isTwo(){
    int i,cnt=0;
    for(i=1;i<=n;i++)
        if(in[i]>=2) return 0;
        else if(in[i]==1) cnt++;
    ans=(ll)cnt*(n-2)/2;
    return 1;
}
bool dfs(int x,int f){
    col[x]=f;
    ran[f]++;
    for(int i=0;i<p[x].size();i++){
        int g=p[x][i];
        if(col[g]==-1){
            if(!dfs(g,f^1)) return 0;
        }
        else if(col[g]!=(f^1)) return 0;
    }
    return 1;
}
ll C(int x){
    if(x<=1) return 0;
    return (ll)x*(x-1)/2;
}
ll gao(int x){
    ran[0]=ran[1]=0;
    if(!dfs(x,0)) return -1;
    else return C(ran[0])+C(ran[1]);
}
int main()
{
    int i,x,y;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        read(x);read(y);
        p[x].push_back(y);p[y].push_back(x);in[x]++;in[y]++;
    }
    if(isOne()){
        cout<<"3 "<<(ll)n*(n-1)*(n-2)/6<<endl;
        return 0;
    }
    if(isTwo()){
        cout<<"2 "<<ans<<endl;
        return 0;
    }
    memset(col,-1,sizeof col);
    for(i=1;i<=n;i++){
        if(col[i]==-1){
            ll t=gao(i);
            if(t==-1){
                ans=-1;
                break;
            }
            ans+=t;
        }
    }
    if(ans==-1) cout<<"0 1"<<endl;
    else cout<<"1 "<<ans<<endl;
}
