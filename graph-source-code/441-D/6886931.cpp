//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 1
#define nmax 3111
int n,m1;
int p[nmax];
int k;
int m2;
int check[nmax];
void readInput()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i);
    scanf("%d",&m2);
}
int f(int *tmp_p, int n)
{
    int lt=0;
    FOR(i,1,n) check[i]=0;
    int ans=0;
    FOR(i,1,n) if (check[i]==0)
    {
        int j=i;
        lt++;
        check[j]=lt;
        //BUG(j);
        while (check[tmp_p[j]]==0)
        {
            //cout<<j<<"__"<<tmp_p[j]<<endl;
            j= tmp_p[j];
            check[j]=lt;
            ans++;
        }
    }
    return ans;
}
vector<int> res;
void solve(){
        int dem=0;
    while (m1!=m2)
    {
        FOR(i,1,n-1)
        {
            bool ff=false;
            FOR(j,i+1,n)
            {
                swap(p[i],p[j]);
                int m3= f(p,n);
                if ((m1-m3)*(m2-m3)<0 || (m3==m2))
                {
                    res.push_back(i);
                    res.push_back(j);
                    m1=m3;
                    if (m1==m2)
                    {
                        ff=true;
                        break;
                    }
                }
                else
                    swap(p[i],p[j]);
            }
            if (ff) break;
        }
    }

}
void writeOutput(){
    printf("%d\n",(int)res.size()/2);
    FOR(i,0,(int)res.size()-1)
    {
        printf("%d ",res[i]);
    }
}
bool checkLT[nmax];
void solve1(){
    // Xu ly tang len
    FOR(i,1,n) checkLT[i]=false;
    checkLT[check[p[1]]]=true;
    FOR(i,2,n){
        if (checkLT[check[p[i]]]==false){
            res.push_back(1);
            res.push_back(i);
            checkLT[check[p[i]]]=true;
            m1++;
            if (m1==m2) return;
        }
    }
}

void solve2(){
   while (m1>m2){
        FOR(i,1,n) check[i]=0;
        FOR(i,1,n) if (p[i]!=i){
            int x=i;
            while (check[x]==0){
                check[x]=1;
                x=p[x];
            }
            FOR(j,i+1,n) if (check[j]==1){
                res.push_back(i);
                res.push_back(j);
                m1--;
                swap(p[i],p[j]);
                break;
            }
            break;
        }
   }
}
int main()
{
    if (DEBUG==1)
    {
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    }
    readInput();
    m1= f(p,n);
    //solve();
    if (m1<m2) solve1(); else if (m1>m2) solve2();
    writeOutput();
    return 0;
}
