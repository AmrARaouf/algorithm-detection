//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

#define ll long long 

vector<string> split(string s, char pattern){
	vector<string> v;
	int prev = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == pattern){
			v.push_back(s.substr(prev, i-prev));
			prev = i+1;
		}
	}
	v.push_back(s.substr(prev, s.size()));
	return v;
}

int pos(int v){
	int count = 0;
	while(v!=0){
		count++;
		v = v/2;
	}
	return count;
}

int toint(string s){
	int count = 0;
	for(int i=0; i<s.size(); i++){
		count = count*10 + (s[i]-'0');
		
	}
	return count;
}

template<typename T> T findmax(T a, T b){
	if(a > b){
		return a;
	}
	return b;
}

template<typename T> T findmin(T a, T b){
	if(a < b){
		return a;
	}
	return b;
}

template <typename T> void printdoublevector(vector<T> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return ;
}
			
template <typename T> void printvector(vector<T> v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}

void set(vector<int> &v, vector<int> &s, vector<int> &count){
	int prev = v[0];
	s.push_back(v[0]);
	count.push_back(1);
	for(int i=1; i<v.size(); i++){
		if(prev == v[i]){
			count[count.size()-1]++;
		}
		else{
			s.push_back(v[i]);
			count.push_back(1);
		}
		prev = v[i];
	}
	return;
}


template <typename T> T power(T x, int y){
	if(y == 0){
		return 1;
	}
	if(y == 1){
		return x;
	}
	if(y%2 == 0){
		T res = power(x, y/2);
		return res*res;
	}
	else{
		T res = power(x, (y-1)/2);
		return res*res*x;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<double> vertex(n);
	for(int i=0; i<n; i++){
		cin >> vertex[i];
	}
	int s, e, val;
	vector<vector<pair<double, double> > > v(n);
	for(int i=0; i<m; i++){
		cin >> s >> e >> val;
		v[s-1].push_back(make_pair(e-1, val));
		v[e-1].push_back(make_pair(s-1, val));
	}
	double max = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j].second != 0){
				max = findmax(max, (vertex[i]+vertex[v[i][j].first])/v[i][j].second);
			}
		}
	}
	cout << setprecision(10) << max << endl;
	return 0;
}
