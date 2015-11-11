//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int step[][2] = {{1,0} , {-1,0} , {0,1} , {0,-1} , {1,1} , {1,-1} , {-1,1} , {-1,-1} , {0,0}} ;
struct node {
	int x , y ;
	int sta[10] ;
	int time ;
} ; 
string mp[10] ;
int MP[10] ;
int vis[10][10][10] ;
bool wall[10][10] ;
/*void Print (int *land , int x , int y) {
	int a[10] ;
	for (int i = 0 ; i < 8 ; i ++) {
		int j = 0 ;
		int tmp = land[i] ;
		memset (a , 0 , sizeof(a)) ;
		while ( tmp ) {
			a[j++] = tmp & 1 ;
			tmp >>= 1 ;
		}
		for (int k = 0 ; k < 8 ; k ++) {
			printf ("%d " , a[k]) ;
		} puts ("") ;
	}
}*/

void bfs () {
	node tmp , ans ;
	tmp.x = 7 ; tmp.y = 0 ;
	for (int i = 0 ; i < 8 ; i ++) tmp.sta[i] = MP[i] ;
	queue<node> q ;
	tmp.time =0 ;
	while (!q.empty () ) q.pop () ;
	q.push (tmp) ;
	int cnt = 0 ;
	while (!q.empty ()) {
		ans = q.front () ; q.pop () ;
		/*if (wall[ans.x][ans.y] == 0 && ans.x == 3) {
			Print(ans.sta , ans.x , ans.y) ;
			wall[ans.x][ans.y] = 1 ;
			puts ("") ;
		}*/
		for (int i = 0 ; i < 9 ; i ++) {
			tmp = ans ;
			tmp.x += step[i][0] ; tmp.y += step[i][1] ;
			if (tmp.x < 0 || tmp.y < 0 || tmp.x == 8 || tmp.y == 8) continue ;
			int bit = 1 << tmp.y ;
			if (bit & tmp.sta[tmp.x] ) {
				continue ;
			}
			tmp.time ++ ;
			if (tmp.time > 8) tmp.time = 8 ;
			vis[tmp.time][tmp.x][tmp.y] ++ ;
			if (vis[tmp.time][tmp.x][tmp.y] > 100) continue ;
			for (int j = 6 ; j >= 0 ; j --) {
				tmp.sta[j+1] = tmp.sta[j] ;
			}
			tmp.sta[0] = 0 ;
			if (tmp.x == 0 && tmp.y == 7) {
				puts ("WIN") ;
				return ;
			}
			if (bit & tmp.sta[tmp.x] ) {
				continue ;
			}
			q.push(tmp) ;
		}
	}
	puts ("LOSE") ; 
}


int main () {
	for (int i = 0 ; i < 8 ; i ++) {
		cin >> mp[i] ;
		for (int j = 0 ; j < 8 ; j ++) {
			if (mp[i][j] ==  'S') {
				MP[i] += 1 << j ;
			}
		}
	}
//	Print (MP , 7 , 0) ;
//	puts ("") ;
	bfs () ;
	return 0 ;
}

 	  	   				  		 		     	 	 		