//Language: GNU C++


#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <utility>
#include <map>
using namespace std;
void dfs(deque<string> &tour, map<string, vector<string> > &mpOut, 
        const string &u)
{
    vector<string> &adj = mpOut[u];
    while(adj.size() > 0){
        const string v = adj.back();
        //remove edge
        adj.pop_back();
        dfs(tour, mpOut, v);
    }
    tour.push_front(u);
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    int n; //[1, 2e5]
    cin >> n;
    if(n == 1){
        string s;
        cin >> s;
        cout << "YES" << endl;
        cout << s << endl;
        return 0;
    }
    map<string, vector<string> >mpOut; //out
    map<string, vector<string> >mpIn;//in
    map<string, int> mpD; //degree
    for(int i = 0;i < n; i++){
        string s;
        cin >> s;
        //e: s0s1 -> s1s2
        //if there is solution, one of the edges will be the correct path
        const string s1 = s.substr(0, 2);
        const string s2 = s.substr(1, 2);
        mpOut[s1].push_back(s2);
        mpIn[s2].push_back(s1);
        //zero-initialized, outDegree ,-1
        mpD[s1] -= 1;
        //inDegree, + 1
        mpD[s2] += 1;
        //no-zero degree vertex
    }
    int oddIn = 0, oddOut = 0;
    string inS, outS;
    for(map<string, int>::const_iterator it = mpD.begin();
            it != mpD.end(); it++){
        const string &key = it->first;
        int diff = it->second;
        if((diff > 1) || (diff < -1)){
            cout << "NO" << endl;
            return 0;
        }
        if(diff == 1){
            if(oddIn == 1){
                cout << "NO" << endl;
                return 0;
            }
            oddIn ++;
            inS = it->first;
        }else if(diff == -1){
            if(oddOut == 1){
                cout << "NO" << endl;
                return 0;
            }
            oddOut ++;
            outS = it->first;
        }
    }
    if(oddIn + oddOut == 1){
        cout << "NO" << endl;
        return 0;
    }

    int es = n;
    if(oddIn){
        //Add a edge from inS to outS, both have equal inDegree and outDegree
        mpOut[inS].push_back(outS);
        mpIn[outS].push_back(inS);
        es ++;
    }//else the first and the last key are same.
     //we can cut at any position, just select the begin 

    //Find one solution. Is it the correct one?
    deque<string>tour;
    dfs(tour, mpOut, mpOut.begin()->first);
    if(es + 1 != tour.size()){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    string left = "", right = "";
    //cut between inS -> outS 
    bool cut = false;
    while(!tour.empty()){
        string &s = tour.front();
        if(left.size() == 0){
            left += s;
        }else{
            if(!cut){
                if((left.substr(left.size() - 2, 2) == inS) && 
                        (s == outS)){
                    cut = true;
                    right = s;
                }else{
                    left += s.substr(1);
                }
            }else{
                right += s.substr(1);
            }
        }
        tour.pop_front();
    }
    string ans;
    if(right.size()){ 
        //left.size() must >= 2, ignore the first(the same as the right's end)
        //-1 , select the second of the next -1 again
        ans = right + left.substr(2);
    }else{
        if(oddIn){
            //no cutting, impossible
            ans = left;
            //cout << "impossible" << endl;
        }else{
            //we have to append the first to the last to add
            //all edges! left[0] overlapped, left[1] was used.
            //cout << "cycle" << endl;
            ans = left;
        }
    }
        
    cout << ans << endl;

    return 0;
}
