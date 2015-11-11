//Language: GNU C++


//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

const int N=2100;
int mat[N][N];
int n;

int dfn[N],low[N],sccno[N],idx,scc_cnt;
stack<int> st;

void dfs(int u)
{
    dfn[u]=low[u]=++idx;
    st.push(u);
    
    for(int v=0;v<n;v++)
    {
        if(!mat[u][v])continue;
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    
    if(low[u]==dfn[u])
    {
        scc_cnt++;
        int x;
        do
        {
            x=st.top();
            st.pop();
            sccno[x]=scc_cnt;
        }while(x!=u);
    }
}

void find_scc()
{
    idx=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(dfn,0,sizeof(dfn));
    for(int i=0;i<n;i++)
    {
        if(!dfn[i])dfs(i);
    }
}

int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)scanf("%d",&mat[i][j]);
    }
    find_scc();
    bool judge=true;
    for(int i=1;i<n;i++)
    {
        if(sccno[i]!=sccno[i-1])
        {
            judge=false;
            break;
        }
    }
    
    if(judge)printf("YES\n");
    else printf("NO\n");
    
    return 0;
}