//Language: GNU C++


//Caution to the wind,complete freedom
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define sd(n) scanf("%d",&n);
#define pd(n) printf("%d\n",n);
#define sl(n) scanf("%lld",&n);
#define pl(n) printf("%lld\n",n);
ll mpow(ll a, ll n,ll mod)
{ll ret=1;ll b=a;while(n) {if(n&1)
    ret=(ret*b)%mod;b=(b*b)%mod;n>>=1;}
return (ll)ret;
}
using namespace std;
#define pi acos(-1.0)
#define MAX 1000001
#define  pii pair<int,int>
#define vi vector<int>
int get(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else {
        if (c >= 'A' && c <= 'Z') {
            return 26 + c - 'A';
        } else {
            return 52 + c - '0';
        }
    }
}
char put(int v) {
    if (v < 26) {
        return v + 'a';
    } else {
        v -= 26;
        if (v < 26) {
            return v + 'A';
        } else {
            v -= 26;
            return v + '0';
        }
    }
}

string A(int v) {
    int x = v / 62;
    int y = v % 62;
    string res(2, '0');
    res[0] = put(x);
    res[1] = put(y);
    return res;
}
int main()
{
    int n,m,i,j;
    sd(n);
    m=62*62;
    vector<int> g[m];
    int indeg[m],outdeg[m];
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    int p=n;
    while(p--)
    {
        string s;
        cin>>s;
        int u=get(s[0])*62+get(s[1]);
        int v=get(s[1])*62+get(s[2]);
        g[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
    int c1=0,c2=0,start=-1;
    for(i=0;i<m;i++)
    {
        if(indeg[i]==outdeg[i])
            continue;
        if(indeg[i]>outdeg[i]+1)
        {
            cout<<"NO";
            return 0;
        }
        if(indeg[i]==outdeg[i]+1)
            c1++;
        if(outdeg[i]==indeg[i]+1)
            {
                c2++;
                start=i;
            }
    }
    if(c1>1||c2>1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(c1!=c2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(start==-1)
    {
         for (int i=0;i<m; ++i) {
            if (outdeg[i] > 0) {
                start = i;
                break;
            }
        }

    }
    vector<int> res;
    vector<int> stck;
    stck.push_back(start);
    while(!stck.empty())
    {
        int v=stck.back();
        if(g[v].empty())
        {
            res.push_back(v);
            stck.pop_back();
        }
        else
        {
            stck.push_back(g[v].back());
            g[v].pop_back();
        }

    }
    if(res.size()!=n+1)
    {
        cout<<"NO";
        return 0;
    }
    reverse(res.begin(),res.end());
    cout<<"YES"<<endl;
    cout<<A(res[0]);
    for(i=1;i<res.size();i++)
    {
        cout<<put(res[i]%62);

    }
    return 0;
}
