//Language: GNU C++


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

struct A
{
       vector<int>heads;
	   int count;
       //vector<int>cocks;
};

struct GROOOP
{
      vector<int>participants;
};

vector<GROOOP>group_list;

vector<A>list;

bool Check(GROOOP &Cur_group, int Cur_user)
{
bool ret = true;

for (long i = 0; i<Cur_group.participants.size(); ++i)
{
 for(long j = 0; j<list[Cur_user].heads.size(); ++j)
 {
          if(list[Cur_user].heads[j]==Cur_group.participants[i])
          ret=false;
 }   
 for(long j = 0; j<list[Cur_group.participants[i]].heads.size(); ++j)
 {
          if(list[Cur_group.participants[i]].heads[j]==Cur_user)
          ret=false;
 }
 if(ret==false)
 break;
}     
   
   if(ret==true)
   Cur_group.participants.push_back(Cur_user);
   
   return ret;
   
}

int main()
{
    long n, r, cur_h;
    A shlak;
	shlak.count=1;
    GROOOP shlak_GR;
    cin>>n;
	long Max = 1;
    group_list.reserve(n);
    shlak.heads.reserve(n);
   // shlak.cocks.reserve(n);
   list.resize(n,shlak);
    
    for(long Q = 0; Q<n; ++Q)
    {
             cin>>r;
             list[Q].heads.push_back(r-1);
             }
    for(long Q = 0; Q<n; ++Q)
    {
             cur_h=list[Q].heads[0];
             while(cur_h!=(-2))
                               {
                               //list[Q].heads.push_back(list[cur_h].heads[0]);
                               //list[cur_h].cocks.push_back(Q);
							   ++list[Q].count;
							   Max=max((long)list[Q].count, Max);
                               cur_h=list[cur_h].heads[0];
                               }
    }   
    
    //shlak_GR.participants.push_back(0);
    //group_list.push_back(shlak_GR);
    //shlak_GR.participants.resize(0);
   
    //for(long Q = 1; Q<n; ++Q)
    //{
    //       bool used = false;  
    //       for(long W = 0; W < group_list.size(); ++W)
    //       {
    //                if(Check(group_list[W],Q)==true)
    //                used=true;
    //       }  
    //       if(used == false)
    //       {
   ///                shlak_GR.participants.push_back(Q);
   //                group_list.push_back(shlak_GR);
   //                shlak_GR.participants.resize(0);
   //        }
   // }    
    
    cout<<Max;
}
