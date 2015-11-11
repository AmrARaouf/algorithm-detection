//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define fr first
#define se second
//typedef long long int long long;
const int mod = 1000000007;
#define maxn 100005
long long inf = 1000000000;
typedef pair<long long,int> ii;
typedef pair<int,int> ii1;

long long length;
int n,m,p,q;
long long sum[maxn],visited[maxn];
vector<int> graph[maxn];
vector<pair<long long,int> > comp;
vector<int> elem[maxn];
void dfs(int root,int j)
{
    visited[root]=1;
    elem[j].push_back(root);
    length += sum[root];
    for(int i=0;i<graph[root].size();i++)
    {
        int child = graph[root][i];
        if(visited[child]==0)
        dfs(child,j);
    }
}

int main()
{
    cin>>n>>m>>p>>q;
    int a,b;
    long long c;
    for(int i=0;i<n;i++)
    sum[i]=0;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        sum[a-1] += c;
        sum[b-1] += c;
    }
    int component=0,it=0,opstart=-1,opend=-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
                length=0;
            dfs(i,it);
                comp.push_back(ii(length/2,i));
                component++;
                if(elem[it].size()>=2)
                {opstart=elem[it][0]+1;
                opend =elem[it][1]+1;}
                it++;
        }
    }
    if(component < q)
    cout<<"NO"<<endl;
    else if(component-p>q)
    cout<<"NO"<<endl;
    else
    {
        int flag=0;
        priority_queue<ii,vector<ii>,greater<ii> > q1;
        for(int i=0;i<comp.size();i++)
        {
            long long ut = comp[i].fr;
            long long ut1 = comp[i].se;
            q1.push(ii(ut,ut1));
        }
        vector<pair<int,int> > edges;
        while(component>q)
        {
            ii top1 = q1.top();
            q1.pop();
            if(!q1.empty())
            {
                ii top2 = q1.top();
                q1.pop();
                long long cost = min(top1.fr+top2.fr+1,inf)+top1.fr+top2.fr;
                q1.push(ii(cost,top1.se));
                component--;
                edges.push_back(ii1(top1.se,top2.se));
                p--;
                if(opstart==-1 &&opend==-1)
                {   
                    opstart = top1.se+1;
                    opend = top2.se+1;
                }
                if(p==0)
                break;
            }
            else if(q1.empty()) {flag=1;break;}
            else if(p==0 && component!=q){flag=1;break;}
            
        }
        if(flag==1)
        cout<<"NO"<<endl;
        else if(component==q)
        {
            if((p!=0 && opstart!=-1) || (p==0))
            {
                cout<<"YES"<<endl;
                for(int i=0;i<edges.size();i++)
                cout<<edges[i].fr+1<<" "<<edges[i].se+1<<endl;
                if(p!=0)
                {
                
                    for(int j=0;j<p;j++)
                    cout<<opstart<<" "<<opend<<endl;
                }
            }
            else if(p!=0 && opstart==-1)
            cout<<"NO"<<endl;
        }
        


    
    }
    return 0;
}