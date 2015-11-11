//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MXN=100000;
const int MXM=300000;

struct node{
    LL y,s;
};

LL last[MXN+10],e[MXM*2+10],len[MXM*2+10],pre[MXM*2+10],tot;
LL dis[MXN+10];
node rail[MXN+10];
bool used[MXN+10];
int q[MXN],n,m,k,head,tail;

void add(int u,int v,int x){
    tot++;
    pre[tot]=last[u];
    e[tot]=v;
    len[tot]=x;
    last[u]=tot;

}

int cmp(const node &a,const node &b){
    return a.y<b.y;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    int u,v,x;
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&x);
        add(u,v,x);
        add(v,u,x);
    }
    for (int i=0;i<k;i++){
        scanf("%I64d%I64d",&rail[i].s,&rail[i].y);
    }
    memset(dis,0x7f,sizeof(dis));
    dis[1]=0;
    used[1]=1;
    head=0;tail=1;
    q[0]=1;
    while (head!=tail){
        int nowx=q[head];
        head++;
        if (head<0 || head>=MXN){
            head=(head%MXN+MXN)%MXN;
        }
        int pos=last[nowx];
        while (pos){
            if (dis[e[pos]]>dis[nowx]+len[pos]){
                dis[e[pos]]=dis[nowx]+len[pos];
                if (!used[e[pos]]){
                    if (dis[e[pos]]<dis[q[head]]){
                        head--;
                        if (head<0 || head>=MXN){
                            head=(head%MXN+MXN)%MXN;
                        }
                        q[head]=e[pos];
                        used[e[pos]]=1;
                    }else{
                        q[tail]=e[pos];
                        used[e[pos]]=1;
                        tail++;
                        if (tail<0 || tail>=MXN){
                            tail=tail%MXN;
                        }
                    }
                }
            }
            pos=pre[pos];
        }
        used[nowx]=0;
    }
//    cout<<dis[4];
    sort(rail,rail+k,cmp);
    int ans=k;
    for (int i=0;i<k;i++){
        if (rail[i].y<dis[rail[i].s]){
            ans--;
//            cout<<rail[i].y<<' '<<rail[i].s<<' '<<dis[rail[i].s]<<endl;
            dis[rail[i].s]=rail[i].y;
            used[rail[i].s]=1;
            q[tail]=rail[i].s;
            tail++;
            if (tail<0 || tail>=MXN){
                tail=tail%MXN;
            }
            while (head!=tail){
                int nowx=q[head];
                head++;
                if (head<0 || head>=MXN){
                    head=(head%MXN+MXN)%MXN;
                }
                int pos=last[nowx];
                while (pos){
                    if (dis[e[pos]]>dis[nowx]+len[pos]){
                        dis[e[pos]]=dis[nowx]+len[pos];
                        if (!used[e[pos]]){
                            if (dis[e[pos]]<dis[q[head]]){
                                head--;
                                if (head<0 || head>=MXN){
                                    head=(head%MXN+MXN)%MXN;
                                }
                                q[head]=e[pos];
                                used[e[pos]]=1;
                            }else{
                                q[tail]=e[pos];
                                used[e[pos]]=1;
                                tail++;
                                if (tail<0 || tail>=MXN){
                                    tail=tail%MXN;
                                }
                            }
                        }
                    }
                    pos=pre[pos];
                }
                used[nowx]=0;
            }
        }
    }
    printf("%d",ans);
}
