//Language: GNU C++


#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <functional>
#include <numeric>
#include <sstream> 
#include <iostream> 
#include <iomanip>
#include <set>
using namespace std;
long long a,b,s,N,M,A,B,r[123450];
#define MOD     1000000009
int find(int node){
        if(r[node])return r[node]=find(r[node]);
        return node;
}
int main(){
        int N=0;
        cin>>N>>M;
        s=1;
        for(int i=1;i<=M;++i){
                cin>>a>>b;
                A=find(a);
                B=find(b);
                if(A==B){
                        s=s*2%MOD;
                }
                else{
                        r[B]=A;
                }
                if(s>0)cout<<s-1<<endl;
                else cout<<MOD-1<<endl;
        }
        return 0;
}