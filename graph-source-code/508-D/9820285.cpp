//Language: GNU C++0x


#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
int getind(char c){
    if(isdigit(c))return c-'0';
    else if(islower(c)) return 10+c-'a';
    else  return 36+c-'A';
}char getchar(int d){
    if(d<10)return d+'0';
    else if(d<36) return d+'a'-10;
    else  return d+'A'-36;
}
string getstring(int ind){
    int a,b;
    string s;
    a=ind/(67*67);
    ind%=(67*67);
    b=ind/67;
    s+=getchar(b);
    s+=getchar(a);
    return s;
}
list<int> g[300000];
int cnt[300000];
int vis=0,beg=0;
void dfs1(int v,list<int>&l ){
    l.push_back(v);
    cnt[v]++;
    if(cnt[v]==0){
        return;
    }
    if(!g[v].empty()){
    cnt[v]--;
    int u=g[v].back();
    g[v].pop_back();
    dfs1(u,l);}
}void dfs(int v,list<int>&l ){
    l.push_back(v);
    if(v==beg)vis++;
    if(vis==2)return;
    if(!g[v].empty()){
    int u=g[v].back();
    g[v].pop_back();
    dfs(u,l);}
}
int main(){
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int v=getind(s[0])*67+getind(s[1])*67*67,u=getind(s[1])*67+getind(s[2])*67*67;
        g[v].push_back(u);
        cnt[v]++;
        cnt[u]--;
//        cout<<s[0]<<s[1]<<" -> "<<s[1]<<s[2]<<endl;
    }
    for(int i=0;i<300000;i++) if((cnt[i]!=0&&vis==2)||abs(cnt[i])>1){cout<<"NO";return 0;}else if(cnt[i]!=0){vis++;if(cnt[i]>0)beg=i;}
    list<int>ans;
    if(vis==2){
        dfs1(beg,ans);
    }
    else if(vis==0){
    for(int i=0;i<300000;i++){
        if(!g[i].empty()){
            beg=i;
            dfs(i,ans);
            break;
        }
    }}
    else{cout<<"NO";return 0;}
    while(true){
        bool flag=true;
        list<int>tmp;
//        for(list<int>::iterator itr=ans.begin();itr!=ans.end();itr++){cout<<getstring(*itr)<<" ";}
//        cout<<endl;
        for(list<int>::iterator itr=ans.begin();itr!=ans.end();itr++){
            if(!g[(*itr)].empty()){
//                cout<<getstring(*itr)<<" "<<g[(*itr)].size()<<endl;
                vis=0;
                beg=(*itr);
                dfs((*itr),tmp);
                ans.insert(itr,tmp.begin(),tmp.end());
                ans.erase(itr);
                flag=false;
                break;
            }
        }
        if(flag)break;
    }
    if(ans.size()!=n+1){cout<<"NO";return 0;}
    cout<<"YES\n";
    for(list<int>::iterator itr=ans.begin();itr!=ans.end();itr++){s=getstring(*itr);cout<<s[0];}
    cout<<s[1];
}
