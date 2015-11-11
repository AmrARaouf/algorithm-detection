//Language: GNU C++


#include<iostream>
#include<list>
#include<algorithm>
#include<vector>

using namespace std;

int m,n;

list<int> *arr;


#define maxx 10000007


int main()
{
// m is no of nodes and n is no of edges

cin >> m >> n;

vector< pair<int,int> > edges;
arr=new list<int>[m+1];

for(int i=0;i<n;i++)
{
    int a,b;
    cin >> a >> b;


    arr[a].push_back(b);
    arr[b].push_back(a);


    edges.push_back(make_pair(a,b));
}

list<int>::iterator it;


for(int i=1;i<=m;i++)
{

/*  cout << i << "->" ;
    for(it=arr[i].begin();it!=arr[i].end();it++)
        cout << *it << " ";

    cout << endl;
*/
    arr[i].sort();
    //sort(arr[i].begin(),arr[i].end());
    
/*

    cout << i << "->" ;
    for(it=arr[i].begin();it!=arr[i].end();it++)
        cout << *it << " ";



    cout << endl;   

*/

}

/*

cout << "printing the edges\n";

for(int i=0;i<edges.size();i++)
    cout << edges[i].first << " " << edges[i].second << endl;

// the algo starts
*/


int ans=maxx;

for(int i=0;i<n;i++)
{
        // for every edge as the list is sorted search in parallel

        int a=edges[i].first;
        int b=edges[i].second;


        list<int>::iterator it1,it2;


        for(it1=arr[a].begin(),it2=arr[b].begin();; )
        {

            if(it1==arr[a].end())
                break;

            if(it2==arr[b].end())
                break;

            if((*it1)==(*it2))
            {
                int temp=arr[*it1].size()+arr[a].size()+arr[b].size();

                if(temp<ans)
                    ans=temp;


                it1++;
                it2++;


            

            }
            else if(((*it1)>(*it2)))
                    it2++;
            else
                it1++;
        }

}

        if(ans==maxx)           
            cout << -1 << endl;
        else
            cout << ans-6 << endl;



                



 
                                
                    

            
        


return 0;
}