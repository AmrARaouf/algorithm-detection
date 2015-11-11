//Language: GNU C++0x


#include <iostream>
#include <vector>
using namespace std;
const int MN = 10000;
vector<int> v[MN];
int v2[MN];

vector<int> reitti;
void f(int x) {
    while(v[x].size()) {
        int q = v[x].back();
        v[x].pop_back();
        f(q);
    }
    reitti.push_back(x);
}
void tulosta(char x) {
    if(x <= 'z' - 'a') {
        x += 'a';
    }
    else if(x < 2*('z' - 'a' + 1)) {
        x += 'A' -( 'z' - 'a' + 1);
    }
    else {
        x += '0' -( ('z' - 'a') * 2 + 2);
    }
    cout<<x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        int q[3];
        string s;
        cin>>s;

        for(int j = 0; j < 3; ++j) {
            if(s[j] >= 'a' && s[j] <= 'z') {
                s[j] -= 'a';
            }
            else if(s[j] >= 'A' && s[j] <= 'Z') {
                s[j] -= 'A' - ('z' - 'a' + 1);
            }
            else {
                s[j] -= '0' - (('z' - 'a')*2 + 2);
            }
            q[j] = s[j];
        }
        /*
        cout<<"lol ";
        tulosta(q[0]);
        cout<<" ";
        tulosta(q[1]);
        cout<<" ";
        tulosta(q[2]);
        cout<<'\n';
        */
        v[q[0]*100+q[1]].push_back(q[1]*100+q[2]);
        ++v2[q[1]*100+q[2]];
    }
    int aa = 0;
    int bb = 0;
    for(int i = 0; i < MN; ++i) {
        if((int)v[i].size() - v2[i] == -1) ++aa;
        else if((int)v[i].size() - v2[i] == 1) ++bb;
        else if((int)v[i].size() - v2[i] != 0) {
                cout<<"NO\n";
                return 0;
        }
    }
    if(aa > 0 || bb > 0) {
        if(aa > 1 || bb > 1 || aa != bb) {
                cout<<"NO\n";
                return 0;
        }
    }
    for(int i = 0; i < MN; ++i) {
        if(v[i].size() > v2[i]) {
            f(i);
            goto ohi;
        }
    }
    for(int i = 0; i < MN; ++i) {
        if(v[i].size()) {
            f(i);
            goto ohi;
        }
    }
    ohi:;
            if(reitti.size() < n+1) {
                cout<<"NO\n";
                return 0;
            }
    cout<<"YES\n";
    tulosta(reitti.back()/100);
    for(int i = reitti.size()-1; i >= 0; --i) {
        tulosta(reitti[i]%100);
    }
    cout<<'\n';
}
