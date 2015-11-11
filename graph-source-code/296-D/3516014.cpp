//Language: GNU C++



#include <cstdio>   
#include <iostream>
#include <queue>
#include <string.h>   
#include <cmath>
#include <vector>
#include <algorithm>   
using namespace std;
typedef long long ll;
#define sfint(x) scanf("%d",&x)
#define sfint2(x,y) scanf("%d%d",&x,&y)
#define sfint3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sfstr(c) scanf("%s",c)
#define sfdl(x) scanf("%lf",&x)
#define sfll(x) scanf("%I64d",&x)
#define sfch(c) scanf("%c",&c)
#define pfint(x) printf("%d\n",x)
#define fr(i,s,n) for(int i=s;i<n;++i)
#define _fr(i,n,s) for(int i=n-1;i>=s;--i)
#define cl(a) memset(a,0,sizeof(a))
int n;
ll d[600][600];
ll ans[600];
int ch[600];
bool vst[600];
int main(){
#ifdef local
	fi;
#endif
	sfint(n);
	fr(i ,0, n)
	{
		fr(j  ,  0 , n){
			scanf("%I64d",&d[i][j]);
		}
	}
	fr(i , 0 ,n){
		sfint(ch[i]);
		ch[i]--;
		vst[ch[i]] = 1;
	}
	ll sum = 0;
	for(int k = n-1;k>=0;--k){
		vst[ch[k]] = 0;

		fr(i , 0 ,n){
			fr(j , 0 ,n){
				if(!vst[i] && !vst[j])
				if( d[ch[k]][i] + d[i][j] < d[ch[k]][j]){
					d[ ch[k] ][j] = d[ch[k]][i] + d[i][j];
				}
			}
		}
		fr(i , 0 ,n){
			fr(j , 0 ,n){
				if(!vst[i] && !vst[j])
					if( d[i][j] + d[j][ch[k]] < d[i][ch[k]]){
						d[i][ch[k]] = d[i][j] + d[j][ch[k]];
					}
			}
		}

		fr(i , 0 ,n){
			fr(j , 0 , n){
				if(!vst[i] && (!vst[j])  && d[i][j] > d[i][ ch[k]] + d[ch[k]][j]){
					d[i][j] = d[i][ch[k]] + d[ch[k]][j];
				}
			}
		}

		sum = 0;
		fr(i ,0 , n){
			fr(j ,  0 ,n){
				if(!vst[i] && (!vst[j])){
					sum += d[i][j];
				}
			}
		}
		ans[k] = sum;
	}
	/*fr( k ,  0, n){
		fr(i , 0 , n){
			fr(j , 0 , n){
				if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] +  d[k][j];
			}
		}
	}
	sum = 0;
	fr(i , 0 ,n){
		fr(j , 0 ,n){
			sum += d[i][j];
		}
	}
	printf("%d\n",sum);*/
	fr(i , 0 ,n)
	printf("%I64d ",ans[i]);
	return 0;
}
