//Language: GNU C++


//Author: Siddharth Saluja
//Quote: "DIE FOR YOUR AIM"
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;


#define mod 1000000007
//#define DEBUG
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define fs(a) fscanf(fp,"%d",&a)
#define flls(a) fscanf(fp,"%lld",&a)
#define fss(a) fscanf(fp,"%s",a)
#define fp(a) fprintf(fo,"%d",a)
#define fllp(a) fprintf(fo,"%lld",a)
#define fsp(a) fprintf(fo,"%s",a)
#define fcp(a) fprintf(fo,"%c",a)
#define fnline fprintf(fo,"\n")
#define fspace fprintf(fo," ")
#define ll long long


int main()
{
#ifdef DEBUG
    cout<<"Debugging\n";
#endif
FILE *fp,*fo;
fp=fopen("input.txt","r");
fo=fopen("output.txt","w");
ios::sync_with_stdio(false);

ll n,k,i,temp;
vector<ll> v[100002];
cin>>n>>k;

ll int a[100003]={0},flag=0;

for(i=1;i<=n;i++)
{
    cin>>temp;
    a[temp]++;
    v[temp].push_back(i);
}

if(a[0]==0 || a[0]>1 || v[1].size()>k){cout<<"-1\n";return 0;}
ll r,s,j;
vector<pair<ll,ll> > ans;



for(i=0;i<v[1].size() && i<k;i++)
ans.push_back(make_pair(v[0][0],v[1][i]));



j=1;
for(i=2;i<n;i++,j++)
{
    r=0;
        for(s=0;s<v[j].size();s++)
        {
            temp=0;
                while(r<v[i].size() && temp<k-1)
                {
                    ans.push_back(make_pair(v[j][s],v[i][r]));
                    r++;
                    temp++;
                }
                if(r==v[i].size())
                    break;
        }
        if(r!=v[i].size())
        {
            cout<<"-1\n";return 0;
        }
}

cout<<ans.size()<<endl;

for(i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;

return 0;
}