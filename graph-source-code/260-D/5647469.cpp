//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);





int bucket[2][200000];
int id[2][200000];
int vis[2][200000];

int p[2];
int n[2];
vector< pair<int,int> > adj[2][200000];



vector<int> a1,a2,a3;



void dfs(int u1,int u2,int mrk)
{
    int i,v;
    vis[u1][u2]=mrk;
    for(i=0;i<adj[u1][u2].size();i++)
    {
        v=adj[u1][u2][i].first;
        if(vis[u1^1][v]) continue;
        dfs(u1^1,v,mrk);

        a1.push_back(id[u1][u2]);
        a2.push_back(id[u1^1][v]);
        a3.push_back(adj[u1][u2][i].second);
    }
}



int now_mark[400000];



int main()
{
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    int i,c,val,N;




    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        scanf("%d %d",&c,&val);

        id[ c ][ n[c] ]=i;
        bucket[ c ][ n[c] ]=val;
        n[c]++;
    }


    while(p[0]<n[0] && p[1]<n[1])
    {

        if(bucket[0][p[0]]<bucket[1][p[1]])
        {
            adj[0][p[0]].push_back(make_pair(p[1],bucket[0][p[0]]));
            adj[1][p[1]].push_back(make_pair(p[0],bucket[0][p[0]]));


			//cout<<bucket[0][p[0]]<<endl;


            bucket[1][p[1]]-=bucket[0][p[0]];
            bucket[0][p[0]]=0;

            p[0]++;
        }
        else if(bucket[0][p[0]]>bucket[1][p[1]])
        {
            adj[0][p[0]].push_back(make_pair(p[1],bucket[1][p[1]]));
            adj[1][p[1]].push_back(make_pair(p[0],bucket[1][p[1]]));


			//cout<<bucket[1][p[1]]<<endl;



            bucket[0][p[0]]-=bucket[1][p[1]];
            bucket[1][p[1]]=0;

            p[1]++;
        }
        else
        {
            adj[0][p[0]].push_back(make_pair(p[1],bucket[1][p[1]]));
            adj[1][p[1]].push_back(make_pair(p[0],bucket[1][p[1]]));

			//cout<<bucket[1][p[1]]<<endl;


            bucket[0][p[0]]-=bucket[1][p[1]];
            bucket[1][p[1]]=0;

            p[1]++;
            p[0]++;
        }


        //cout<<p[0]<<p[1];
        //asdf
    }


	//asdf



    int now=1;
    for(i=0;i<n[0];i++)
    {
        if(vis[0][i]==0) dfs(0,i,now++);
    }



    for(i=0;i<n[1];i++)
    {
        if(vis[1][i]==0) dfs(1,i,now++);
    }


    now_mark[1]=1;

    for(i=0;i<n[0];i++)
    {
        if( now_mark  [ vis[ 0 ][ i ] ] ==0)
        {
            now_mark  [ vis[ 0 ][ i ] ]=1;
            a1.push_back(id[0][i]);
            a2.push_back(id[1][0]);
            a3.push_back(0);
        }
    }

    for(i=0;i<n[1];i++)
    {
        if( now_mark  [ vis[ 1 ][ i ] ] ==0)
        {
            now_mark  [ vis[ 1 ][ i ] ]=1;
            a1.push_back(id[1][i]);
            a2.push_back(id[0][0]);
            a3.push_back(0);
        }
    }



    for(i=0;i<a1.size();i++)
    {
        printf("%d %d %d\n",a1[i]+1,a2[i]+1,a3[i]);
    }

    return 0;
}
