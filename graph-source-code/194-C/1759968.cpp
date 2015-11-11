//Language: GNU C++


#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cmath"
#include "string"
using namespace std;
int a[55][55],b[55][55],n,m,ans,k;
string s;
/*dassadasdasdasd
dasdasdasd
as waqdffdasdasdas
dfgdfgfghfiujhifghoifjgohifgohi
dfoigudfighdiofghldiughdiugfh
as
d
asd
asdfoijasdpogiuhspdg
dfgijdoifjg
*/
int _____________1,______________222;
int zaaaaaaaa,maaaaa,zimbirti;
void prov2(int x,int y){
	b[x][y]=0;
	if(x>1 && b[x-1][y]==1)prov2(x-1,y);
	if(x<n && b[x+1][y]==1)prov2(x+1,y);
	if(y>1 && b[x][y-1]==1)prov2(x,y-1);
	if(y<m && b[x][y+1]==1)prov2(x,y+1);
}
bool prov(){
	k=0;
	for(int g=1;g<=n;g++)
		for(int h=1;h<=m;h++)
			b[g][h]=a[g][h];
		for(int g=1;g<=n;g++)
		for(int h=1;h<=m;h++)
			if(b[g][h]==1){
					k++; prov2(g,h);
				}
				return k>1;
	}
	/*dasasasasassadass*/
	int main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<m;j++)
				if(s[j]=='#'){a[i][j+1]=1; ans++;}
			}
		if(ans<3){cout<<-1; return 0;}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]==1){
						a[i][j]=0;
						if(prov()){cout<<1; return 0;}
						a[i][j]=1;
					}
		cout<<2;
		return 0;


}
