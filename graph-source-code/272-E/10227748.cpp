//Language: GNU C++


#include <cstdio>
#include <vector>
using namespace std;
const int maxn=3e5+5;
bool other[maxn];
vector<int> e[maxn];
int n,m;
void print(){
        for(int i=1;i<=n;i++){
                if(other[i])printf("1");
                else printf("0");
        }
        puts("");
}
void judge(int s){
        int o=0;
        for(int i=0;i<(int)e[s].size();i++){
                int t=e[s][i];
                if(other[t]==other[s])o++;
        }
        if(o>1){
                other[s]=!other[s];
                for(int i=0;i<(int)e[s].size();i++){
                        int t=e[s][i];
                        if(other[t]==other[s])judge(t);
                }
        }
}

int main(){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
                int f,t;
                scanf("%d%d",&f,&t);
                e[f].push_back(t);
                e[t].push_back(f);
        }
        for(int i=1;i<=n;i++){
                judge(i);
        }
        print();

        return 0;
}