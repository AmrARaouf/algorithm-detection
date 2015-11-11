//Language: GNU C++0x


#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
	int boss;
	vector<int> adrel;
	vector<int> rmrel;
	vector<pair<int, int>> qry;
	vector<node*> child;
	void set(int x) {
		boss = x;
		adrel.clear();
		rmrel.clear();
		child.clear();
		qry.clear();
	}
}man[111111];

vector<int> store[111111];

bool ans[111111], qryon[111111];

int GetBoss(int x) {
	if (man[x].boss == x) {
		return x;
	}
	return man[x].boss = GetBoss(man[x].boss);
}

void VisitTree(const node& root) {
	for (int i = 0; i < root.adrel.size(); ++i) {
		qryon[root.adrel[i]] = true;
	}
	for (int i = 0; i < root.qry.size(); ++i) {
		int x = root.qry[i].first;
		int y = root.qry[i].second;
		if (qryon[x]) {
			store[x].push_back(y);
		}
	}
	for (int i = 0; i < root.rmrel.size(); ++i) {
		int x = root.rmrel[i];
		if (qryon[x]) {
			for (int j = 0; j < store[x].size(); ++j) {
				ans[store[x][j]] = true;
			}
		}
	}
	
	for (int i = 0; i < root.child.size(); ++i) {
		VisitTree(*(root.child[i]));
	}
	for (int i = 0; i < root.qry.size(); ++i) {
		int x = root.qry[i].first;
		if (qryon[x]) {
			store[x].pop_back();
		}
	}
	for (int i = 0; i < root.adrel.size(); ++i) {
		qryon[root.adrel[i]] = false;
	}
}

int main() {
	int n, m, docct, qryct;
	while (scanf("%d%d", &n, &m) != EOF) {
		docct = qryct = 0;
		for (int i = 1; i <= n; ++i) {
			man[i].set(i);
			store[i].clear();
		}
		int t;
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &t);
			if (t == 1) {
				int x, y;
				scanf("%d%d", &x, &y);
				man[x].boss = y;
				man[y].child.push_back(&man[x]);		
			} else if (t == 2) {
				int x, y;
				++docct;
				scanf("%d", &x);
				y = GetBoss(x);
				man[y].adrel.push_back(docct);
				man[x].rmrel.push_back(docct);
			} else {
				int x, y;
				++qryct;
				scanf("%d%d", &x, &y);
				man[x].qry.push_back(make_pair(y,qryct));
			}
		}
		for (int i = 1; i <= qryct; ++i) {
			qryon[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			if (man[i].boss == i) {
				VisitTree(man[i]);
			}
		}
		for (int i = 1; i <= qryct; ++i) {
			if (ans[i]) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}