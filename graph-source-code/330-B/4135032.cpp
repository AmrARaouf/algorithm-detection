//Language: GNU C++


#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector< bool > flag(n+1,false);
    for(int i = 0 ; i < m ; i ++ ){
        int a,b;
        cin >> a>>b;
        flag[a]=flag[b]=true;
    }
    int centerPoint = 0;
    for(int i = 1 ; i <= n ; i  ++ ){
        if(!flag[i]){
            centerPoint = i;
            break;
        }
    }
    cout<<n-1<<endl;
    for(int i = 1; i <= n ; i ++ ){
        if(i!=centerPoint) cout<<i<<" "<<centerPoint<<endl;
    }
    return 0;
}