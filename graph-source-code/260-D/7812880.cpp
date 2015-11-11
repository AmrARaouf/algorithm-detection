//Language: GNU C++


#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define MAXN 100001

#define PI 3.14159265358979323846264338328

using namespace std;

vector<int>V[100001];
int col[MAXN], s[MAXN];

bool vis[MAXN];


int zero, one;
void DFS(int src)
{
    if(vis[src]) return;

    if(zero == -1 && col[src] == 0)
    {
        zero = src;
    }

    if(one == -1 && col[src] == 1)
    {
        one = src;
    }

    vis[src] = true;
    for(int i = 0; i < V[src].size(); i++)
    {
        if(!vis[V[src][i]])
            DFS(V[src][i]);
    }
    return;
}



int main()
{

    int i, j, k;
    LL x, y;
    int n;
    cin>>n;
    priority_queue< pair<int, int> >B, W;

    for(i = 1; i <= n; i++)
    {
        cin>>col[i]>>s[i];
        if(col[i])
            B.push(make_pair(s[i], i));
        else
            W.push(make_pair(s[i], i));
    }
    pair <int, int> p, q;
    while(!B.empty() && !W.empty())
    {
        p = B.top();
        q = W.top();
        B.pop();
        W.pop();

        int mn = min(p.first, q.first);
        cout<<p.second<<" "<<q.second<<" "<<mn<<endl;
        if(p.first < q.first || (p.first == q.first && B.size() >= W.size()))
        {
            q.first -= p.first;
            W.push(q);
        }
        else
        {
            p.first -= q.first;
            B.push(p);
        }
    }
//    if(!B.empty())
//    {
//        for(j = 1; j <= n; j++)
//        {
//            if(col[j] == 0)
//            {
//                while(!B.empty())
//                {
//                    p = B.top();
//                    B.pop();
//                    cout<<j <<" "<<p.second<<" "<<p.first<<endl;
//                }
//                break;
//            }
//        }
//    }
//
//
//
//    if(!W.empty())
//    {
//        for(j = 1; j <= n; j++)
//        {
//            if(col[j] == 1)
//            {
//                while(!W.empty())
//                {
//                    p = W.top();
//                    W.pop();
//                    cout<<j <<" "<<p.second<<" "<<p.first<<endl;
//                }
//                break;
//            }
//        }
//    }
//    zero = -1, one = -1;
//    for(i = 1; i <= n; i++)
//    {
//        if(!vis[i])
//        {
//            if(col[i] == 0 && one != -1)
//                cout<<i<<" "<<one<<" "<<0<<endl;
//            if(col[i] == 1 && zero != -1)
//                cout<<i<<" "<<zero<<" "<<0<<endl;
//            DFS(i);
//        }
//    }



    return 0;
}

/*





*/

		 	   	     	    	  	  			