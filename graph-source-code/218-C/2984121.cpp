//Language: GNU C++0x


#include <iostream>
#include <forward_list>
#include <set>
#include <iterator>
using namespace std;

struct disj {
public:
	set<int> x;
	set<int> y;
};
forward_list<disj> all;

void Insert(int x, int y);

int main() {
	int n, x, y;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		Insert(x,y);
	}
	cout << distance(all.begin(), all.end())-1;
	return 0;
}

void Insert(int x, int y) {
	forward_list<disj>::iterator itx, ity;
	for (itx=all.begin(); itx!=all.end(); ++itx) {
		if (itx->x.find(x)!=itx->x.end()) {
			break;
		}
	}
	for (ity=all.begin(); ity!=all.end(); ++ity) {
		if (ity->y.find(y)!=ity->y.end()) {
			break;
		}
	}

	if (itx==all.end() && ity==all.end()) {
		disj temp;
		temp.x.insert(x);
		temp.y.insert(y);
		all.push_front(temp);
	}
	else if (itx==all.end()) {
		ity->x.insert(x);
	}
	else if (ity==all.end()) {
		itx->y.insert(y);
	}
	else if (itx!=ity) {
		auto tempit=ity;
		++tempit;
		if (tempit!=all.end()) {
			itx->x.insert( ity->x.begin(), ity->x.end() );
			itx->y.insert( ity->y.begin(), ity->y.end() );
			swap(ity->x,tempit->x);
			swap(ity->y,tempit->y);
			all.erase_after(ity);
		}
		else {
			tempit=itx;
			++tempit;
			ity->x.insert( itx->x.begin(), itx->x.end() );
			ity->y.insert( itx->y.begin(), itx->y.end() );
			swap(itx->x,tempit->x);
			swap(itx->y,tempit->y);
			all.erase_after(itx);
		}
	}
	return;
}
