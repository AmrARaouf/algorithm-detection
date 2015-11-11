//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

// Template By @li_@kber
typedef long long int ll;
typedef unsigned long long int ull;
const double pi=acos(-1.0);
int inf=1000000007;
//int row[]={1,0,-1,0};int col[]={0,1,0,-1}; //4 Direction
//int row[]={1,1,0,-1,-1,-1,0,1};int col[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int row[]={2,1,-1,-2,-2,-1,1,2};int col[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int row[]={-1,-1,+0,+1,+1,+0};int col[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

#define ri(N) scanf("%d",&N)
#define rll(N) cin>>N
#define rs(N) scanf("%s",N)
#define eps 1e-9
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define tonum(c) (c>='A'&&c<='Z'?c-'A' : c-'a'+26)
#define all(X)  X.begin(),X.end()
#define UNIQUE(X)  X.resize(unique(all(X))-X.begin())
#define tr(container,it)  for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
//////////////////////////////////////////////////////////////////////
// Numberic Functions
int day(int d,int m,int y)
  {if(m<3){--y;m+=12;}return 365*y+y/4 - y/100+y/400+(153*m - 457)/5+d - 306;}
int leap(int x)
  {if((x%4==0&&x%100!=0)||x%400==0)return 1;return 0;}
ll josephus(ll x) // If the 2nd person is killed always then the last man
  {return 2*(x-pow(2,(ll)log2(x)))+1;}
ll josephus(ll n,ll x) // If the 2nd person is killed always then the x'th man
  {if(n==1&&x==1)return 1;if(n>1&&x==1)return 2;ll res=josephus(n-1,x-1);if(res==n-1)return 1;if(res<=n-2)return res+2;}
ll survivor(ll n,ll k) // If the k'th person is killed always then the last man
  {ll i,s;for(s=0,i=1;i<=n;i++)s=(s+k)%i;return (s+1);}
template<class T> inline T gcd(T a,T b)
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> T power(T N,T P)  // a^b
  {return (P==0)? 1: N*power(N,P-1);}
template<class T> inline T mod(T N,T M)  // n%mod
  {if(N<0)N+=(ceil(-N*1.00/M)*M);return N%M;}
template<class T> T bigmod(T a,T b,T mod)  //(a^b)%mod
  {if(b==0)return 1;if(b%2==0){T ret=bigmod(a,b/2,mod);return ((ret%mod)*(ret%mod))%mod;}else return ((a%mod)*(bigmod(a,b-1,mod)%mod))%mod;}
int modular_inverse(int a, int b)
  {int b0=b,t,q;int x0=0,x1=1;if(b==1)return 1;while(a>1){q=a/b;t=b,b=a%b,a=t;t=x0,x0=x1-q*x0,x1=t;}if(x1<0)x1+=b0;return x1;}
template<class T> inline double distance_point(pair<T,T>P,pair<T,T>Q)
  {T X1,X2,Y1,Y2;X1=P.first,Y1=P.second;X2=Q.first,Y2=Q.second;return sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));}
// String conversion
template<class T> ll stoi(T Str){stringstream ss(Str);ll N;ss>>N;return N;}
template<class T> string itos(T N){stringstream ss;ss<<N;string Str;Str=ss.str();return Str;}
template<class T> vector<int> vstoi(T Str){stringstream ss(Str);vector<int>A;for(int N;ss>>N;A.push_back(N));return A;}
vector<string> split(string str,string Separator)
  {vector<string>answer;string temp;for(int i=0;i<str.length();i++){bool isSeparator=false;for(int j=0;j<Separator.length();j++)if(str[i]==Separator[j])isSeparator=true;if(!isSeparator){temp+=str[i];continue;}if(temp!="")answer.push_back(temp);temp="";}if(temp!="")answer.push_back(temp);return answer;}
// Working with bit
ll check_bit(ll N,int POS){return (N & (1LL<<POS));}
ll on_bit(ll N,int POS){return N | (1LL<<POS);}
ll off_bit(ll N,int POS){return N & ~(1LL<<POS);}
string from_decimal_to(ll n, int b)  // Upto base 20
  {if(n==0)return "0";string chars="0123456789ABCDEFGHIJ";string result="";while(n>0){result=chars[n%b]+result;n/=b;}return result;}
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
#define ii pair<int,int>
#define pp1 pair<int,pair<int,int> >
#define pp2 pair<pair<int,int>,int >
#define pq(xx) priority_queue<xx,vector<xx>,greater<xx> >
#define MAX 100000
//////////////////////////////////////////////////////////////////////
int k,l,m,n;
vector<int>v[300005];
pair<ii,int> state[300005];
ll dp[300005];
ll len[300005];
int change(int x,ll p,ll q)
{
    if(dp[x]!=-1)
      return 0;
    dp[x]=p;
    len[x]=q;
    for(int i=0;i<v[x].size();i++)
    {
        int j=v[x][i];
        change(j,p,q);
    }
    return 0;
}
int main()
{
    //freopen("E:/in.txt","r",stdin);
    //freopen("E:/out.txt","w",stdout);
    int i,j,t,kase=1;
    ri(n);
    map<string,int>mp;
    vector<int>input;
    string str;
    int ind=1;
    for(i=0;i<n;i++)
    {
        cin>>str;
        int cnt=0;
        for(j=0;str[j];j++)
        {
            str[j]=tolower(str[j]);
            cnt+=str[j]=='r';
        }
        int p;
        if(mp.find(str)==mp.end())
          p=mp[str]=ind++;
        else
          p=mp[str];
        state[p]=MP(MP(cnt,str.size()),p);
        input.push_back(p);
    }
    for(i=0;i<300005;i++)
      v[i].clear();
    ri(m);
    string str1,str2;
    for(i=0;i<m;i++)
    {
        cin>>str1>>str2;
        int cnt1=0,cnt2=0;
        for(j=0;str1[j];j++)
        {
            str1[j]=tolower(str1[j]);
            cnt1+=str1[j]=='r';
        }
        for(j=0;str2[j];j++)
        {
            str2[j]=tolower(str2[j]);
            cnt2+=str2[j]=='r';
        }
        int p,q;
        if(mp.find(str1)!=mp.end())
          p=mp[str1];
        else
          p=mp[str1]=ind++;
        if(mp.find(str2)!=mp.end())
          q=mp[str2];
        else
          q=mp[str2]=ind++;
        v[q].push_back(p);
        state[p]=MP(MP(cnt1,str1.size()),p);
        state[q]=MP(MP(cnt2,str2.size()),q);
    }
    sort(state+1,state+ind);
    memset(dp,-1,sizeof(dp));
    for(i=1;i<ind;i++)
    {
        int x=state[i].ss;
        if(dp[x]==-1)
          change(x,state[i].ff.ff,state[i].ff.ss);
    }
    ll cnt=0,total=0;
    for(i=0;i<n;i++)
    {
        cnt+=dp[input[i]];
        total+=len[input[i]];
    }
    cout<<cnt<<" "<<total<<"\n";
return 0;
}
