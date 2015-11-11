//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define eps 1e-7
using namespace std;
typedef __int64 LL;

#define maxn 200100
#define maxe 701000

struct Node{
    LL val;
    int a,b;
    bool operator < (const Node tmp)const{
        return this->val>tmp.val;
    }
}node[maxn],t1,t2;

priority_queue<Node>que;

struct Edge{
    LL from,to,dis,next;
}edge[maxe];
LL head[maxn];
LL n,m,cnt;
void add(LL q,LL h,LL len) {
    edge[cnt].from=q;
    edge[cnt].to=h;
    edge[cnt].dis=len;
    edge[cnt].next=head[q];
    head[q]=cnt;
    cnt++;
}
void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

LL to[maxn];
LL ot[maxn];
vector <LL> ve[maxn];

void bfs(LL pos ,LL id){
    queue<LL>q;
    q.push(pos);
    to[pos] = id;
    while(!q.empty()){
        LL u=q.front();
        q.pop();
        for(LL i=head[u];i!=-1;i=edge[i].next){
            LL v = edge[i].to;
            if(to[v]!=-1)continue;
            q.push(v);
            to[v]=to[u];
        }
    }
}

int main(){
    LL i,j,k;
    LL n,m,p,q,u,v,len;
    LL cnt_node;
    while(cin>>n>>m>>p>>q){
        init();
        for(i=0;i<m;i++){
            scanf("%I64d%I64d%I64d",&u,&v,&len);
            add(u,v,len);
            add(v,u,len);
        }
        LL num = 1;
        memset(to,-1,sizeof(to));

        for(i=1;i<=n;i++){
            if(to[i]!=-1)continue;
            bfs(i,num);
            num++;
        }
        for(i=1;i<num;i++)ve[i].clear();
        for(i=1;i<=n;i++){
            ve[to[i]].push_back(i);
        }
        cnt_node=0;
        memset(ot,-1,sizeof(ot));
        for(i=1;i<num;i++){
            if(ve[i].size()==1){
                node[cnt_node].a = node[cnt_node].b = (int)ve[i][0];
            }
            node[cnt_node].a = (int)ve[i][0];
            node[cnt_node].b = (int)ve[i][1];
            ot[i]=cnt_node;
            cnt_node++;
        }
        for(i=0;i<cnt;i+=2){
            LL go = to[edge[i].from];
            if(ot[go]==-1)continue;
            node[ot[go]].val+=edge[i].dis;
        }
        for(i=0;i<cnt_node;i++){
            que.push(node[i]);
        }
        if(cnt_node<q){
            puts("NO");
            continue;
        }
        if(cnt_node==q){
            if(p==0){
                puts("YES");
                continue;
            }
            while(!que.empty()){
                if(que.top().val!=0)break;
                que.pop();
            }
            if(que.empty()){
                puts("NO");
            }else{
                puts("YES");
                for(i=0;i<p;i++){
                    printf("%d %d\n",que.top().a,que.top().b);
                }
            }
            continue;
        }else{
            if(p<cnt_node-q){
                puts("NO");
                continue;
            }
            puts("YES");
            while(que.size()>=2){
                t1=que.top();
                que.pop();
                t2=que.top();
                que.pop();
                --p;
                cnt_node--;
                printf("%d %d\n",t1.a,t2.a);
                t1.val=min((t1.val+t2.val+min((LL)1e9,t1.val+t2.val+1)),(LL)1e9);
                t1.b=t2.a;
                que.push(t1);
                if(p==0)break;
                if(cnt_node==q)break;
            }
            if(p==0)continue;
            else{
                while(p--){
                    printf("%d %d\n",t1.a,t2.a);
                }
            }
        }
    }
    return 0;
}
//   2 0 0 1
