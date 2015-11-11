//Language: GNU C++


#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int maxn=510;
int used[maxn][maxn];
string mp[maxn];
struct move{
	int x,y,type;
	// 0 = B
	// 1 = R
	// 2 = D
};
vector<move> moves;
int n,m;
void dfs(int x,int y,bool first){
	if(x<0 || y<0 || x>=n || y>=m)
		return;
	if(used[x][y])
		return;	
	if(mp[x][y] == '#')
		return;
	used[x][y] = 1;
	move mv; 	mv.x = x;	mv.y = y;	mv.type = 0;
	moves.push_back(mv);
	dfs(x-1,y,false);
	dfs(x,y-1,false);
	dfs(x+1,y,false);
	dfs(x,y+1,false);
	if(!first){
		move mv2; mv2.x = x;	mv2.y = y;	mv2.type = 2;
		moves.push_back(mv2);
		move mv3; mv3.x = x;	mv3.y = y;	mv3.type = 1;
		moves.push_back(mv3);
	}
}



int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> mp[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!used[i][j] && mp[i][j]!='#')
				dfs(i,j,true);					
	cout << moves.size() << endl;
	for(int i=0;i<moves.size();i++){
		switch(moves[i].type){
			case 0: cout << "B "; break;
			case 1: cout << "R "; break;
			case 2: cout << "D "; break;
		}
		cout << moves[i].x +1<< " " << moves[i].y+1 << endl;
	}		
}

