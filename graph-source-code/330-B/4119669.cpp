//Language: GNU C++


#include <iostream>
using namespace std;

char table[1000][1000]={};
int cityNum;
int banlist[1000] = {};

int main(){
	cin>>cityNum;
	int ban;
	cin>>ban;
	int from, to;
	for(int i = 0; i < ban; i++){
		cin>>from>>to;
		table[from-1][to-1] = -1;
		table[to-1][from-1] = -1;
		banlist[from-1]++;
		banlist[to-1]++;
	}
	int min = 10000;
	int bestcity;
	for(int i = 0; i < cityNum; i++){
		if(banlist[i] < min){
			min = banlist[i];
			bestcity = i;
		}
	}
	if(min == 0){
		cout<<cityNum-1<<endl;
		for(int i = 1; i <= cityNum; i++){
			if(i == bestcity+1)
				continue;
			cout<<bestcity+1<<" "<<i<<endl;
		}
	}
	else{
		int no[1000];
		for(int i = 0; i < 1000; i++)
			no[i] = -1;
		int noIndex = 0;
		for(int i = 0; i < cityNum; i++){
			if(table[bestcity][i] == -1){
				no[noIndex++] = i;
			}
		}
		int con[1000][2] = {};
		int conIndex = 0;
		for(int i = 0; i < noIndex; i++){
			for(int j = 0; j < cityNum; j++){
				if(no[i] == j)
					continue;
				if(table[no[i]][j] != -1){
					con[conIndex][0] = j;
					con[conIndex++][1] = no[i];
					break;
				}
			}
		}
		cout<<cityNum - 1<<endl;
		for(int i = 0; i < cityNum; i++){
			int check = 0;
			for(int ii = 0; ii < noIndex; ii++){
				if(no[ii] == i){
					check = 1;
					break;
				}
			}
			if(check == 1 || bestcity == i)
				continue;
			cout<<bestcity+1<<" "<<i+1<<endl;
		}
		for(int i = 0; i < conIndex; i++){
			cout<<con[i][0]+1<<" "<<con[i][1]+1<<endl;
		}
	}
	return 0;
}