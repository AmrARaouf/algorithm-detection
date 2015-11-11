//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > graph[2*(int)1e5 + 10];
int n;


int main()
{
	vector<int> zero;
	set<pair<int,int> > black;
	set<pair<int,int> > white;
	cin >> n;
	int firstb = -1;
	int firstw = -1;
	bool bl[(int)1e5 + 10];
	int vis[(int)1e5 + 10];
	memset(vis,0,sizeof vis);
	memset(bl , 0 , sizeof bl);
	for(int i = 0 ; i < n ; i++)
	{
		int one , two;
		cin >> one >> two;
		if(two == 0)
		{

		    if(one)
			  bl[i] = 1;
			
			zero.push_back(i);
			continue;
		}
		if(one)
		{
			firstb =i;
			bl[i] = 1;
			black.insert(make_pair(two,i));
		}else
		{
			firstw = i;
			white.insert(make_pair(two , i));
		}
	}

	while(black.size() > 0 && white.size() > 0)
	{
		auto b = black.begin();
		auto w = white.begin();
		pair<int , int> currb = *b;
		pair<int , int> currw = *w;
		if(currb.first < currw.first)
		{
			auto en = white.end();
			en--;
			currw = *en;
			graph[currw.second + 1].push_back(make_pair(currb.second + 1, currb.first));
			black.erase(currb);
			white.erase(currw);
			currw.first -= currb.first;
			white.insert(currw);
		}else
		{
			auto en = black.end();
			en--;
			currb = *en;
			graph[currb.second + 1].push_back(make_pair(currw.second + 1, currw.first));
			white.erase(currw);
			black.erase(currb);
			currb.first -= currw.first;
			black.insert(currb);
		}
	}
	
	bool fb = false;
	bool fw = false;
	if(firstb == -1)
	{
		for(int i = 0 ; i< zero.size() ;i++)
			if(bl[zero[i]])
			{
				fb = true;
				firstb = zero[i];
				vis[zero[i]] = 1;
				break;
			}
	}
	if(firstw == -1)
	{
		for(int i = 0; i < zero.size() ; i++)
		{
			if(!bl[zero[i]])
			{
				fw = true;
				firstw = zero[i];
				vis[zero[i]] = 1;
				break;
			}
		}
	}
	
	if(fb || fw)
	{
		cout << firstw + 1 << " " << firstb + 1 << " " << 0 << endl;
		
	}

	for(int i = 1 ; i <= n ;i++)
	{
		for(int j = 0 ; j < graph[i].size();j++)
		{
			cout << i << " " << graph[i][j].first << " " << graph[i][j].second << endl;
		}
		//cout << endl;
	}

	for(int i = 0 ; i < zero.size() ;i++)
	{
		if(vis[zero[i]])
			continue;
		if(bl[zero[i]])
		{
			cout << firstw + 1 << " " << zero[i] + 1 << " " << 0 << endl;
		}
		else
		{
			cout << firstb + 1 << " " << zero[i] + 1 << " " << 0 << endl;
		}
	}
	return 0;
}