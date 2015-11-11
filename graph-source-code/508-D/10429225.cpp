//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 211111;

string s[MAXN];

unordered_map<string, set<int> > in, out;

int n;
vector<char> ans;
vector<string> all;

void dfs(const string& str) {
  while (!in[str].empty()) {
    int p = *in[str].begin();
    in[str].erase(p);
    string next_s = s[p].substr(1, 2);
    dfs(next_s);
  }
  ans.push_back(str[1]);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    in[s[i].substr(0, 2)].insert(i);
    out[s[i].substr(1, 2)].insert(i);
    all.push_back(s[i].substr(0, 2));
    all.push_back(s[i].substr(1, 2));
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  
  bool has_euclid_path = true;
  string start = in.begin()->first, end;
  int cnt_start = 0, cnt_end = 0;
  for (const auto& s : all) {
    if (in[s].size() > out[s].size()) {
      if (in[s].size() != out[s].size() + 1) {
        has_euclid_path = false;
        break;
      } else {
        start = s;
        ++cnt_start;
      }
    } else if (in[s].size() < out[s].size()) {
      if (out[s].size() != in[s].size() + 1) {
        has_euclid_path = false;
        break;
      } else {
        end = s;
        ++cnt_end;
      }
    }
  }

  has_euclid_path &= (cnt_start == cnt_end && cnt_start <= 1);

  if (!has_euclid_path) {
    puts("NO");
    return 0;
  }

  dfs(start);

  if (ans.size() == n + 1) {
    puts("YES");
    putchar(start[0]);
    for (int i = ans.size() - 1; i >= 0; --i) {
      putchar(ans[i]);
    }
    puts("");
  } else {
    puts("NO");
  }
}
