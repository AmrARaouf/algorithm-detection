//Language: GNU C++


#include <iostream>
#include <vector>
using namespace std;

    
    #define max_n 100005
    #define pb push_back
    long long rez,maxim;
    int n,i,V[max_n];
    struct ceva{
        int a,b,c;
    } Mu[max_n];
    vector<int> T[max_n];

void df ( int varf, long long cost ){
    if ( cost > maxim ){
        maxim=cost;
    }
    V[varf]=1;
    for ( int i=0; i<T[varf].size(); i++ ){
        if ( !V[ Mu[T[varf][i]].a + Mu[T[varf][i]].b - varf ] ){
            df (  Mu[T[varf][i]].a + Mu[T[varf][i]].b - varf, cost+Mu[T[varf][i]].c);
        }
    }
}

int main(){
    cin>>n;
    for ( i=1; i<n; i++ ){
        cin>>Mu[i].a>>Mu[i].b>>Mu[i].c;
        T[Mu[i].a].pb(i);
        T[Mu[i].b].pb(i);
        rez+=2*Mu[i].c;
    }
    df(1,0);
    cout<<rez-maxim;
    return 0;
}
