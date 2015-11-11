//Language: GNU C++


#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<long long int , vector<long long int> > m ;
map<long long int , vector<long long int> > :: iterator it;
int  start1=0 , n;

void dfs(int start , int pre) {
    cout<<start<<" ";
    for(int i=0 ; i<m[start].size() ; i++ ) {
        if(m[start][i] != pre) {
            //pre = start;
            dfs(m[start][i] , start);
        }
    }
    return;
}


int main()
{

    cin>>n;



    for(int i=0 ; i<n ; i++ ) {
        int a , b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }


    for(it = m.begin() ; it!=m.end() ; it++) {
        int temp = (*it).first;
       // cout<<temp<<"-> ";
        //for(int i=0 ; i<m[temp].size() ; i++ ) {
          //  cout<<m[temp][i]<<" ";
        //}
        //cout<<endl;

        if(m[temp].size()==1) start1 = temp;
    }



    dfs(start1 , -1);

    return 0;
}
