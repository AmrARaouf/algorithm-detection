//Language: GNU C++


#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector <vector < pair < pair <long long, long long> , long long > > > v;
vector <long long> l;

int main(){

    long long n,m,x,y,w;
    cin>>n>>m;
    vector <pair < pair <long long, long long> , long long > > t;
    for(long long i=0;i<n;i++)
        v.push_back(t);
        
    for(long long i=0;i<m;i++){
        cin>>x>>y>>w;
        v[x-1].push_back(make_pair(make_pair(y-1,-w),i+1));
        v[y-1].push_back(make_pair(make_pair(x-1,-w),i+1));
        l.push_back(w);
    }
    
    cin>>y;
    
    priority_queue < pair < pair <pair <long long, long long>, long long>, long long > > q;
    q.push(make_pair(make_pair(make_pair(0,0),y-1),0));
    set <long long> mark;
    vector <long long> r;
    long long rr=0;
    
    while(q.size()>0){
        pair < pair <pair <long long, long long> , long long>, long long > p = q.top();
        q.pop();
        
        if(mark.count(p.first.second) > 0)
            continue;
        
        mark.insert(p.first.second);
        if(p.second!=0){
            //cout<<"% "<<p.first.first.first<<endl;
            r.push_back(p.second);
            rr += l[p.second-1];
        }
        
        
        for(long long i=0;i<v[p.first.second].size();i++){
            if(mark.count(v[p.first.second][i].first.first)==0){
                q.push(make_pair(make_pair(make_pair(p.first.first.first+v[p.first.second][i].first.second, v[p.first.second][i].first.second) , v[p.first.second][i].first.first),v[p.first.second][i].second));
            }
        }
        
    }
    
    cout<<rr<<endl;
    if(rr > 0){
        for(long long i=0;i<r.size()-1;i++)
            cout<<r[i]<<" ";
        cout<<r[r.size()-1]<<endl;
    }
    return 0;
}