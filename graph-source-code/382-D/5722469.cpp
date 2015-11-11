//Language: GNU C++0x


#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const char *error = "Impossible";

int dist[2000][2000];
char tab[2000][2000];
int visited[2000][2000];
bool rev_visited[2000][2000];
bool loop_found = false;

int dfs(int i, int j, int vnum) {
  if (visited[i][j] > 0) {
    if (visited[i][j] == vnum) {
      loop_found = true;
      return -1;
    } else {
      return dist[i][j];
    } 
  }

  visited[i][j] = vnum;
  if (tab[i][j] == '>') dist[i][j] = dfs(i, j+1, vnum) + 1;
  if (tab[i][j] == '<') dist[i][j] = dfs(i, j-1, vnum) + 1;
  if (tab[i][j] == '^') dist[i][j] = dfs(i-1, j, vnum) + 1;
  if (tab[i][j] == 'v') dist[i][j] = dfs(i+1, j, vnum) + 1;
  return dist[i][j];
}

void rev_dfs(int i, int j) {
  rev_visited[i][j] = true;
  if (tab[i][j-1] == '>') rev_dfs(i, j-1);
  if (tab[i][j+1] == '<') rev_dfs(i, j+1);
  if (tab[i-1][j] == 'v') rev_dfs(i-1, j);
  if (tab[i+1][j] == '^') rev_dfs(i+1, j);
}

pair<int,int> path_from_max(int i, int j) {
  int lasti = i, lastj = j;
  while (tab[i][j] != '#') {
    lasti = i;
    lastj = j;
    if (tab[i][j] == '>') {j++;}
    else if (tab[i][j] == '<') {j--;}
    else if (tab[i][j] == '^') {i--;}
    else if (tab[i][j] == 'v') {i++;}
  }
  return make_pair(lasti, lastj);
}

int main() {
    ios_base::sync_with_stdio(0);

    int result = -1;
    char nline;

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
	cin >> tab[i][j];
      }
    }
    
    if (n <= 2 || m <= 2) {
      cout << 0 << endl;
      return 0;
    }
    
    int max_value = 0;
    int counter = 5;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
	if (tab[i][j] != '#' && dist[i][j] == 0) {
	  max_value = max(max_value, dfs(i, j, counter++));
	  if (loop_found) {
	    cout << result << endl;
	    return 0;
	  }
	}
      }
    }
    vector<pair<int,int> > maxes;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
	if (dist[i][j] == max_value)
	  maxes.push_back(make_pair(i,j));
      }
    }
    if (maxes.size() == 1) {
      result = max_value*2-1;
    } else {
      result = max_value*2-1;
      pair<int,int> fst = *maxes.begin();
      pair<int,int> start = path_from_max(fst.first, fst.second);
      rev_dfs(start.first, start.second);
      for (auto p : maxes) {
	if (rev_visited[p.first][p.second] != true) {
	  result = max_value * 2;
	  break;
	}
      }
    }
    
    cout << result << endl;
    return 0;
}
