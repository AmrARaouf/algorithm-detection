//Language: GNU C++


#include <iostream>
#include <cstdio>

using namespace std;

int n, k;

void enter(){
    cin >> n >> k;
    if (n%2==0){
        if (k>=n/2){
            cout << -1;
            return;
        }
    }else{
        if (k>n/2){
            cout << -1;
            return;
        }
    }
    {
        cout << n*k << endl;
        for (int i=1; i<=n; i++){
            int tmp=i+1;
            for (int j=1; j<=k; j++){
                if (tmp>n) tmp=1;
                if (tmp!=i){
                    //cout << i << " " << tmp << endl;
                    printf("%d %d\n", i, tmp);
                }
                tmp++;
            }
            
        }
    }
}

int main(){
    enter();
    return 0;
}