//Language: GNU C++


/*************************************************************************
    > File Name: d.cpp
    > Author: implus
    > Mail: 674592809@qq.com
    > Created Time: 一 12/16 13:04:59 2013
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson l,m,ls
#define rson m+1,r,rs

struct node{
    int a,b,v;
    node(){}
    node(int a,int b,int v):a(a),b(b),v(v){}
};
int main(){
    int n;
    while(cin>>n){
        vector<pii> a[2];
        int type,val;
        for(int i = 0; i <n; i++){
            cin>>type>>val;
            a[type].push_back(pii(val,i+1));
        }
        for(int i = 0; i < 2; i++)
            sort(a[i].begin(),a[i].end());
        int p0 = 0,p1 = 0;
        vector<node> v;
        while(1){
            if(p0 == a[0].size() || p1 == a[1].size())break;
            pii& t0 = a[0][p0];
            pii& t1 = a[1][p1];
            if(t0.first < t1.first){
                v.push_back(node(t0.second,t1.second,t0.first));
                t1.first -= t0.first;
                p0++;
            }else if(t0.first > t1.first){
                v.push_back(node(t0.second,t1.second,t1.first));
                t0.first -= t1.first;
                p1++;
            }else {
                v.push_back(node(t0.second,t1.second,t1.first));
                if(a[0].size() - p0 > a[1].size() - p1){
                    t1.first -= t0.first;
                    p0++;
                }else{
                    t0.first -= t1.first;
                    p1++;
                }
            }
        }
        for(int i = 0; i < v.size(); i++){
            cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].v<<endl;
        }
    }
    return 0;
}
