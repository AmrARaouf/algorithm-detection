//Language: GNU C++11


#include<bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> v[70000];
int nof[70000];
string str, ans;

void dfs(int vertex)
{
    while(!v[vertex].empty())
    {
        int next= v[vertex].back();
        v[vertex].pop_back();
        dfs(next);
    }

    ans.push_back(vertex%256);
}

int main()
{
    int t, i, j, n, m, a, b, c, start, stop, pos, nof_pos, neg, nof_neg;

    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>str;
        start= str[0]*256 + str[1];
        stop= str[1]*256 + str[2];

        v[start].push_back(stop);
        nof[start]++;
        nof[stop]--;
    }

    pos= start;
    nof_pos= neg= nof_neg= 0;
    for(i=0;i<70000;++i)
    {
        if(nof[i]>0)
        {
            pos= i;
            ++nof_pos;
        }
        else if(nof[i]<0)
        {
            neg= i;
            ++nof_neg;
        }
    }

    if(nof_pos>1 || nof_neg>1 || nof[pos]>1 || nof[neg]<-1)
    {
        cout<<"NO";
        return 0;
    }

    dfs(pos);

    ans.push_back(pos/256);
    //cout<<"size= "<<ans.size()<<"\n";
    if(ans.size()!=n+2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(i=ans.size()-1;i>=0;--i)
    cout<<ans[i];

    return 0;
}






