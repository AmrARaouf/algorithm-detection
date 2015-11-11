//Language: GNU C++


#include <iostream>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define debug( x ) cout << #x << " = " << x << endl
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define EPS 1E-9
#define INF 1000000000

using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef vector<int> vi;

vector<vi> orden(26,vi(26,0));



int main(){
    int n; cin >> n;

    vector<string> palabras;
    f(i,0,n){
        string s; cin >> s;
        palabras.pb(s);
    }

    vi valores;
     vi usados(26,0);
    f(i,0,n-1){
        string s1 = palabras[i];
        string s2 = palabras[i+1];
        int tope = min(s1.size(),s2.size());
        bool encuentra = false;
        f(j,0,tope){
            if(s1[j] == s2[j]) continue;
            orden[s1[j]-'a'][s2[j]-'a'] = 1;
            encuentra = true;
            break;
        }
        if(!encuentra){
            if(s1.size() > s2.size()){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }


    f(k,0,26){
        f(i,0,26){
            f(j,0,26){
                if(orden[i][k] == 1 && orden[k][j] == 1){
                    orden[i][j] = 1;
                }
            }
        }
    }

    f(i,0,26){
        f(j,0,26){
            if(orden[i][j] == 1 && orden[j][i]== 1){
                //Contradiccion
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    vi res;
    set<int> ignorar;
    f(k,0,26){
        f(i,0,26){
            if(ignorar.count(i) != 0) continue;
            bool es = true;
            f(j,0,26){
                if(orden[i][j]==1){
                    es = false;
                    break;
                }
            }
            if(es){
                /*
                    Lo agregamos a res y ya no lo tenemos en cuenta
                */
                res.pb(i);
                f(j,0,26){
                    orden[j][i] = 0;
                }
                ignorar.insert(i);
            }
        }
    }

    for(int i = res.size()-1; i >= 0; i--){
        cout<<char(res[i]+'a');
    }
    cout<<endl;

    return 0;
}
