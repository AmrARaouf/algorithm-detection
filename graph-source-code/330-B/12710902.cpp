//Language: GNU C++11


#include <bits\stdc++.h>
#define ll long long
#define stdp pair <int,int>
#define mod 1000000007
using namespace std;
FILE *file;

/*

                                    _      
	 _ __    __ _  ___   ___  __ _ | | ___ 
	| '_ \  / _` |/ __| / __|/ _` || |/ __|
	| |_) || (_| |\__ \| (__| (_| || |\__ \
	| .__/  \__,_||___/ \___|\__,_||_||___/
	|_|                                    
	 _          _                       _       
	| |_  _ __ (_)  __ _  _ __    __ _ | |  ___ 
	| __|| '__|| | / _` || '_ \  / _` || | / _ \
	| |_ | |   | || (_| || | | || (_| || ||  __/
	 \__||_|   |_| \__,_||_| |_| \__, ||_| \___|
	                             |___/          


*/
#define P_level 101
vector < vector <int> > P(P_level);
void fP(int n = P_level)
{
	P[0].push_back(1);
	P[1].push_back(1);
	P[1].push_back(1);
	for (int i = 2; i < 101; i++)
	{
		P[i].push_back(1);
		for (int j = 0; j < P[i - 1].size() - 1; j++)
		{
			P[i].push_back(P[i - 1][j] + P[i - 1][j + 1]);
		}
		P[i].push_back(1);
	}
}


int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}

bool myfnc(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}

/*class troll
{
public:
	ll n;
	ll sum=0;
	vector <ll> p;
public:
	void get_number(void)
	{
		cin >> n;
	}
	void get_numbers(void)
	{
		int x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			sum += x;
			p.push_back(x);
		}
	}


};*/

/*map <int, bool> in_set;
map < int, vector <int> > adj_list;
map < int, set <int> > res;

void build_list(int v1, int v2, int n)
{
	if (in_set[v2] == false)
	{
		res[v1].insert(v2);
		in_set[v2] = true;
		for (int i = 0; i < adj_list[v2].size(); i++)
		{
			build_list(v1, adj_list[v2][i], n);
		}
	}
}
*/

map <stdp, bool> nope;
vector <stdp> road;
int o[10000];

int main()
{
#ifndef ONLINE_JUDGE
	//freopen_s(&file, "input.txt", "r", stdin);
#endif
	//fP(); //Pascal's triangle
	ios::sync_with_stdio(false);

	int n,m;
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		nope[make_pair(x,y)] = true;
		o[x]++;
		o[y]++;
	}

	int _m = n,p;
	for (int i = 1; i <= n; i++)
	{
		if (o[i] < _m)
		{
			_m = o[i];
			p = i;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!nope[make_pair(p, i)] && i!=p)
		{
			road.push_back(make_pair(p, i));
		}
		else
		{
			/*for (int j = 2; j <= n; j++)
			{
				if (j != i && !nope[make_pair(j, i)])
				{
					road.push_back(make_pair(j, i));
				}
			}*/
		}
	}

	cout << road.size() << endl;
	for (int i = 0; i < road.size(); i++)
	{
		cout << road[i].first << " " << road[i].second << endl;
	}



	return 0;
}

/*
             ____     ______   ____     _____   __  __   __  __     
            /\  _`\  /\  _  \ /\  _`\  /\___ \ /\ \/\ \ /\ \/\ \    
            \ \,\L\_\\ \ \L\ \\ \ \/\ \\/__/\ \\ \ \ \ \\ \ \/'/'   
             \/_\__ \ \ \  __ \\ \ \ \ \  _\ \ \\ \ \ \ \\ \ , <    
               /\ \L\ \\ \ \/\ \\ \ \_\ \/\ \_\ \\ \ \_\ \\ \ \\`\  
               \ `\____\\ \_\ \_\\ \____/\ \____/ \ \_____\\ \_\ \_\
                \/_____/ \/_/\/_/ \/___/  \/___/   \/_____/ \/_/\/_/
                                                                    
                                                                    
                       __                 ___    ___      
                      /\ \__             /\_ \  /\_ \     
                      \ \ ,_\  _ __   ___\//\ \ \//\ \    
                       \ \ \/ /\`'__\/ __`\\ \ \  \ \ \   
                        \ \ \_\ \ \//\ \L\ \\_\ \_ \_\ \_ 
                         \ \__\\ \_\\ \____//\____\/\____\
                          \/__/ \/_/ \/___/ \/____/\/____/
                                                          
*/

/*
	 ____                                 _____                  __      
	/\  _`\                              /\  __`\            __ /\ \__   
	\ \ \L\ \      __        __       __ \ \ \/\ \   __  __ /\_\\ \ ,_\  
	 \ \ ,  /    /'__`\    /'_ `\   /'__`\\ \ \ \ \ /\ \/\ \\/\ \\ \ \/  
	  \ \ \\ \  /\ \L\.\_ /\ \L\ \ /\  __/ \ \ \\'\\\ \ \_\ \\ \ \\ \ \_ 
	   \ \_\ \_\\ \__/.\_\\ \____ \\ \____\ \ \___\_\\ \____/ \ \_\\ \__\
		\/_/\/ / \/__/\/_/ \/___L\ \\/____/  \/__//_/ \/___/   \/_/ \/__/
                             /\____/                                     
                             \_/__/                                      
           ___                                                            __      
          /\_ \                       __                     __          /\ \__   
     _____\//\ \       __        __  /\_\      __     _ __  /\_\     ____\ \ ,_\  
	/\ '__`\\ \ \    /'__`\    /'_ `\\/\ \   /'__`\  /\`'__\\/\ \   /',__\\ \ \/  
	\ \ \L\ \\_\ \_ /\ \L\.\_ /\ \L\ \\ \ \ /\ \L\.\_\ \ \/  \ \ \ /\__, `\\ \ \_ 
	 \ \ ,__//\____\\ \__/.\_\\ \____ \\ \_\\ \__/.\_\\ \_\   \ \_\\/\____/ \ \__\
	  \ \ \/ \/____/ \/__/\/_/ \/___L\ \\/_/ \/__/\/_/ \/_/    \/_/ \/___/   \/__/
	   \ \_\                     /\____/                                          
	    \/_/                     \_/__/                                           

*/

