//Language: GNU C++0x


#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mp make_pair
#define pb push_back
typedef vector<LL> VL;
LL Min(LL x,LL y){return (x>y?y:x);}
LL Max(LL x,LL y){return (x>y?x:y);}
map <char,vector<char> > mymap;
map<char,vector<char> >::iterator iter; 
LL n;
string str[200];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	for(LL i=0;i<26;i++){
		vector<char> tmpo;
		mymap.insert(pair<char,vector<char> >(mp(char(i+97),tmpo)));
	}
	cin>>n;
	for(LL i=0;i<n;i++){cin>>str[i];}
	for(LL i=0;i<n-1;i++){
		// we will consider only str[i] and str[i+1] string
		LL siz=Min(LL(str[i].size()),LL(str[i+1].size()));
		// if second string is a prefix of the first, then impossible
		bool poss=false;
		if(LL(str[i].size())>LL(str[i+1].size())){
			poss=true;
			for(LL iii=0;iii<siz;iii++){
				if(str[i][iii]!=str[i+1][iii]){poss=false;}
			}
		}
		if(poss){cout<<"Impossible\n";return 0;}
		for(LL j=0;j<siz;j++){
			if(str[i][j]!=str[i+1][j]){
				// str[i][j] should come before str[i+1][j] in the order
				iter=mymap.find(str[i+1][j]);
				if(iter==mymap.end()){
					vector <char> tmp_vect;tmp_vect.pb(str[i][j]);
					mymap.insert(pair<char,vector<char> >(mp(str[i+1][j],tmp_vect)));
				}else{
					(iter->second).pb(str[i][j]);
				}
//				cout<<str[i][j]<<","<<str[i+1][j]<<"\n";
				break;
			}
		}
	}
	string order="";
	while(true){
		// find a char which have no alphabet before it
		if(LL(mymap.size())==0){break;}
		iter=mymap.begin();
		char ch='-';
		while(iter!=mymap.end()){
			if(LL((iter->second).size())==0){
				ch=iter->first;
				break;
			}
			iter++;
		}
		if(ch=='-'){cout<<"Impossible\n";return 0;}
		// erase ch from every where
		order=order+ch;
		mymap.erase(ch);
		if((mymap.size())==0){break;}
		iter=mymap.begin();
		while(iter!=mymap.end()){
			for(LL ii=0;ii<LL((iter->second).size());ii++){
				if((iter->second)[ii]==ch){
					(iter->second).erase((iter->second).begin()+ii);ii--;
				}
			}
			iter++;
		}
	}
	cout<<order<<"\n";
	return 0;
}
