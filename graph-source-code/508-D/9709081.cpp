//Language: GNU C++


#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int seed = 63;
int base[2] = {1, 63};

int path[200010];
int father[5010];
char s[200010][5];
int scr, des, n, top;
int I[5010],O[5010],vis[200010],c[5010];

int Get(char c){
	if(c >= 'a' && c <= 'z') return c - 'a' + 1;
	if(c >= 'A' && c <= 'Z') return c - 'A' + 27;
	return c - '0' + 53;
}

void Init(){
    for(int i=0; i<5010; i++)
        father[i] = i;
}

int Find(int x){
    if(x != father[x])
        father[x] = Find(father[x]);
    return father[x];
}

vector <pair <int, int> > vt[5010];
vector <int> ans;
void DFS(int u){
    for(int i=c[u]; i<vt[u].size(); i=c[u]){
    	c[u]++;
        if(!vis[vt[u][i].second]){
            vis[vt[u][i].second] = 1;
            DFS(vt[u][i].first);
            path[top++] = vt[u][i].second;
        }
    }
}

int main(){
    Init();
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",s[i]);
        int v = (Get(s[i][1]))*base[1] + (Get(s[i][2]))*base[0];
        int u = (Get(s[i][0]))*base[1] + (Get(s[i][1]))*base[0];
        I[v]++;
        O[u]++;
        vt[u].push_back(make_pair(v, i));
        father[Find(v)] = Find(u);
    }
    int cnt = 0;
    for(int i=0; i<5000; i++)
        if(I[i] + O[i] && father[i] == i) cnt++;
    if(cnt > 1){
        puts("NO");
        return 0;
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i=0; i<5000; i++){
        if(I[i] == O[i]) continue;
        if(I[i] - O[i] == 1) cnt1++, des = i;
        else if(O[i] - I[i] == 1) cnt2++, scr = i;
        else cnt3++;
    }
    if(cnt3){
        puts("NO");
        return 0;
    }
    if(cnt1 == 1 && cnt2 == 1) DFS(scr);
    else if(cnt1 == 0 && cnt2 == 0) DFS((Get(s[0][1]))*63 + (Get(s[0][2])));
    else{
        puts("NO");
        return 0;
    }
    puts("YES");
    printf("%s",s[path[top-1]]);
    for(int i=top-2; i>=0; i--)
        printf("%c",s[path[i]][2]);
    printf("\n");
    return 0;
}
