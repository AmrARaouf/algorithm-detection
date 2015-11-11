//Language: GNU C++11


//#include <bits/stdc++.h>
//using namespace std;
//const double pi = 3.14159265359;
//int arr[100005], arr2[200005], cnt = 0;
//
//struct node {
//  int l, r, mx, indx;
//  node *nextl, *nextr;
//  node(int a, int b) {
//      mx = -1;
//      nextl = nextr = 0;
//      l = a, r = b;
//  }
//};
//
//void build(node *tree, int left, int right) {
//  cnt++;
//  if (left == right) {
//      tree->mx = arr2[left];
//      tree->indx = left;
//      return;
//  }
//  tree->nextl = new node(left, left + (right - left) / 2);
//  tree->nextr = new node(left + (right - left) / 2 + 1, right);
//  build(tree->nextl, left, left + (right - left) / 2);
//  build(tree, left + (right - left) / 2 + 1, right);
//}
//
//pair<int, int> work(node *tree, bool chk) {
//  if (tree->l == tree->r)
//      return make_pair(tree->mx, tree->indx);
//  pair<int, int> a = work(tree->nextl, chk), b = work(tree->nextr, chk);
//  if (a.first > b.first)
//      tree->indx = a.second, tree->mx = a.first;
//  else {
//      tree->mx = b.first, tree->indx = b.second;
//      if (chk and a.first == b.first)
//          tree->indx = max(a.second, b.second);
//      else if (a.first == b.first)
//          tree->indx = min(a.second, b.second);
//  }
//  return make_pair(tree->mx, tree->indx);
//}
//
//void test(node *tree) {
//  cout << tree->mx << ' ' << tree->indx << ' ' << tree->l << ' ' << tree->r
//          << endl;
//  if (tree->r == tree->l)
//      return;
//  test(tree->nextr);
//  test(tree->nextl);
//}
//
//pair<int, int> get_max(node *tree, int ll, int rr, bool chk) {
//  if (tree->l >= ll and tree->r <= rr) {
//      return make_pair(tree->mx, tree->indx);
//  }
//  pair<int, int> ret = make_pair(-1, -1);
//  if ((ll >= tree->l and ll <= tree->r)
//          or (rr >= tree->l and rr <= tree->r)) {
//      pair<int, int> a = get_max(tree->nextl, ll, rr, chk), b = get_max(
//              tree->nextr, ll, rr, chk);
//      if (a.first > b.first)
//          swap(a, ret);
//      else if (a.first < b.first)
//          swap(b, ret);
//      else {
//          if (a.second > b.second)
//              swap(a, b);
//          if (chk)
//              swap(b, ret);
//          else
//              swap(a, ret);
//      }
//  }
//  return ret;
//}
//
//int findl(node *tree, int val, int ll, int rr) {
//  if (ll == rr) {
//      return ll;
//  }
//  pair<int, int> a = get_max(tree, ll, ll + (rr - ll) / 2, 0), b = get_max(
//          tree, ll + (rr - ll) / 2 + 1, rr, 0);
//  if (a.first > val) {
//      return findl(tree, val, ll, ll + (rr - ll) / 2);
//  } else if (b.first > val) {
//      return findl(tree, val, ll + (rr - ll) / 2 + 1, rr);
//  } else
//      return -1;
//}
//
//int findr(node *tree, int val, int ll, int rr) {
//  if (ll == rr)
//      return ll;
//  pair<int, int> a = get_max(tree, ll, ll + (rr - ll) / 2, 1), b = get_max(
//          tree, ll + (rr - ll) / 2 + 1, rr, 1);
//  if (b.first > val) {
//      return findr(tree, val, ll + (rr - ll) / 2+1, rr);
//  } else if (a.first > val) {
//      return findr(tree, val, ll, ll + (rr - ll) / 2);
//  } else
//      return -1;
//}
//
//int main() {
////    freopen("tst.txt", "r", stdin);
////    cout << 100000 << endl;
////    for(int i = 0;i < 100000;i++)
////        cout << 1 << ' ';
//  int n;
//  scanf("%d", &n);
//  node *tree = new node(0, 2 * n - 1);
//  for (int i = 0; i < n; i++) {
//      scanf("%d", &arr2[i]);
//      arr2[n + i] = arr2[i];
//  }
//  if(n == 1) {
//      cout << "-1 -1";
//      return 0;
//  }
//  build(tree, 0, 2 * n - 1);
//  work(tree, 0);
//  for(int i = 0;i < n;i++) {
//      int a = findr(tree, arr2[i], i + 1, i + n), b = findl(tree, arr2[i], i + 1, i + n);
//      if(a >= n) a -= n;
//      if(b >= n) b -= n;
//      if(a == -1)a--;
//      if(b == -1)b--;
//      printf("%d %d\n", a+1, b+1);
//  }
//  return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int n, ar1[101], ar2[101], pos = 1;
bool lst[101][101], mem[101];

bool check(int a, int b, int c, int d) {
    return (c < a and a < d) or (c < b and b < d);
}

bool reach(int from, int to) {
    mem[from] = 1;
    if(from == to)
        return 1;
    bool ret = 0;
    for(int i = 1;i < pos;i++) {
        if(!mem[i] and lst[from][i])
            ret |= reach(i, to);
    }
    return ret;
}

int main() {
    cin >> n;
    while(n--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            ar1[pos] = a;
            ar2[pos] = b;
            for(int i = 1;i < pos;i++) {
                if(check(a, b, ar1[i], ar2[i]))
                    lst[pos][i] = 1;
                if(check(ar1[i], ar2[i], a, b))
                    lst[i][pos] = 1;
            }
            pos++;
        }
        else {
            memset(mem, 0, sizeof mem);
            if(reach(a, b))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
