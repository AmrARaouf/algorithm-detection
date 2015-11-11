//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct rec1{
    int x, y, n, w, c;
    rec1(){};
    rec1(int x1, int y1, int c1, int w1, int n1){
        x=x1;y=y1;w=w1;c=c1;n=n1;
    };
};
rec1 l[100000];
int n, m, p, i, ln=-1, b[3010], d[3010], s[3010], dis[3010], x, flow, ans, num[26];
bool f[3010];
int insert(int x, int y, int c, int w){
    l[++ln] = rec1(x, y, c, w, b[x]);b[x] = ln;
    l[++ln] = rec1(y, x, 0, -w, b[y]);b[y] = ln;
    return 0;
};
bool spfa(){
    int h, t, k;
    for(k=1;k<=n;k++)dis[k] = 10000000;dis[0] = 0;
    memcpy(s, b, sizeof(b));
    d[1] = 0;h = 0;t = 1;f[0] = true;
    while(h!=t){
        h = (h+1)%2000;
        k = b[d[h]];
        while(k!=-1){
            if((dis[d[h]]+l[k].w<dis[l[k].y])&&(l[k].c>0)){
                dis[l[k].y] = dis[d[h]]+l[k].w;
                if(!f[l[k].y]){
                    t = (t+1)%2000;
                    d[t] = l[k].y;
                    f[l[k].y] = true;
                };
            };
            k = l[k].n;
        };
        f[d[h]] = false;
    };
    return dis[n] != 10000000;
};
int dfs(int x, int flow){
    if(x == n)return flow;
    int p=0, k=s[x], t;
    f[x] = true;
    while(k != -1){
        if((dis[x]+l[k].w==dis[l[k].y])&&(l[k].c>0)&&(!f[l[k].y])){
            t = dfs(l[k].y, min(l[k].c, flow));
            p+=t;flow-=t;
            l[k].c-=t;l[k^1].c+=t;
            if(!flow)break;
        };
        k = l[k].n;
    };
    s[x] = k;
    f[x] = false;
    return p;       
};
char str[10001];
int main(){
    memset(b, -1, sizeof(b));
    scanf("%s%d", str, &n);
    int l = strlen(str);
    for(i=0;i<l;i++)num[str[i]-'a']++, flow++;
    for(i=0;i<26;i++)if(num[i])insert(n*26+n+i+1, 3000, num[i], 0);
    for(i=1;i<=n;i++){
        scanf("%s%d", str, &x);
        int j;
        memset(num, 0, sizeof(num));
        l = strlen(str);
        for(j=0;j<l;j++)num[str[j]-'a']++;
        insert(0, i, x, i);
        for(j=0;j<26;j++)if(num[j])insert(n+(n-1)*26+j+1, n*26+n+j+1, num[j], 0), insert(i, n+(n-1)*26+j+1, num[j], 0);
    };
    n = 3000;
    while((flow)&&spfa()){
        int t = dfs(0, 0x7fffffff);
        ans+=t*dis[n];
        flow-=t;
    };
    if(flow)printf("-1\n");else printf("%d\n", ans);
    return 0;
};