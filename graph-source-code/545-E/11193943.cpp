//Language: GNU C++


#include<iostream>
#include <bits/stdc++.h>
typedef long long int ll;
#define INF 1000000000000000
#define MAX 300005
using namespace std;

struct Node{
    ll vert,weight,edgenum;
    struct Node* next;
};
typedef pair<ll,ll> mypair;
struct Node* edges[MAX];

ll dist[MAX]; 
ll parentweight[MAX]; 
ll parentedge[MAX]; 

void dijk(ll src)
{
    ll pp;
    for(pp=0;pp<MAX;pp++)
        dist[pp]=INF;
    set< mypair > qu; 
    dist[src]=0;
    qu.insert(make_pair(0,src));
    while(!qu.empty())
    {
        mypair temp=*qu.begin();
        qu.erase(qu.begin());
        ll vertex=temp.second;
        struct Node* temp2=edges[vertex];
        while(temp2!=NULL)
        {
            if(dist[temp2->vert]>dist[vertex]+temp2->weight) 
            {
                if(dist[temp2->vert]!=INF) 
                    qu.erase(qu.find(make_pair(dist[temp2->vert],temp2->vert)));
                parentweight[temp2->vert]=temp2->weight;
                parentedge[temp2->vert]=temp2->edgenum;
                dist[temp2->vert]=dist[vertex]+temp2->weight;
                qu.insert(make_pair(dist[temp2->vert],temp2->vert));
            }
            if(dist[temp2->vert]==dist[vertex]+temp2->weight) 
            {
                if(parentweight[temp2->vert]>temp2->weight)
                {
                    parentweight[temp2->vert]=temp2->weight;
                    parentedge[temp2->vert]=temp2->edgenum;
                }
            }
            temp2=temp2->next;
        }
    }
}

int main()
{
	ll weighttotal=0,top,mains,aa,nn,bb,i,j,k,c,n,m,a,b;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> a >> b >> c;
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->vert=b;
        temp->weight=c;
        temp->edgenum=i;
        struct Node* temp2=(struct Node*)malloc(sizeof(struct Node));
        temp2->vert=a;
        temp2->weight=c;
        temp2->edgenum=i;
        temp->next=edges[a];
        temp2->next=edges[b];
        edges[a]=temp;
        edges[b]=temp2;
    }
    cin >> aa;
    dijk(aa);
    for(i=1;i<=n;i++)
        if(i!=aa)
            weighttotal+=parentweight[i];
    cout << weighttotal << endl;
    for(i=1;i<=n;i++)
        if(i!=aa)
            cout << parentedge[i] << " ";
    cout << endl;
	return 0;
}
