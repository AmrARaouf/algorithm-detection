//Language: GNU C++


#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int>a[2];
int b[111111];

int main(){
    scanf("%d",&n);
    int x;
    for (int i=1;i<=n;i++){
        scanf("%d%d",&x,&b[i]);
        a[x].push_back(i);
    }
    int i , j;
    for (i=0,j=0;i<a[0].size()&&j<a[1].size();){
        if (b[a[0][i]] < b[a[1][j]]){
            printf("%d %d %d\n",a[0][i],a[1][j],b[a[0][i]]);
            b[a[1][j]] -= b[a[0][i]];
            i++;
        } else {
            printf("%d %d %d\n",a[0][i],a[1][j],b[a[1][j]]);
            b[a[0][i]] -= b[a[1][j]];
            j++;
        }
    }
    for (;i+j<n-1;){
        if (i < a[0].size())
            printf("%d %d 0\n",a[0][++i],a[1][0]);
        else 
            printf("%d %d 0\n",a[1][++j],a[0][0]);
    }
}