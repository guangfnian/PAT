#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 1e5+10;
int st[N], top = 0;
int main() {
  int n, k, cnt = 0;
  char op[20];
  scanf("%d", &n);
  tree<double, null_type, less<double>, rb_tree_tag, tree_order_statistics_node_update> bbt; 
  while (n--) {
    scanf("%s", op);
    switch(op[1])
    {
      case 'o':
        if (top == 0) puts("Invalid");
        else {
          printf("%d\n", st[--top]);
          bbt.erase(bbt.lower_bound(double(st[top])));
        }
        break;
      case 'u': scanf("%d", &k); st[top++] = k; bbt.insert(k+0.0000000005*(cnt++)); break;
      case 'e':
        if (top == 0) puts("Invalid");
        else {
          k = (top+1) >> 1;
          printf("%d\n", (int)(*bbt.find_by_order(k-1)));
        }
    }
  }
  return 0;
}