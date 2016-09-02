#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main()
{
	int n, m, mx = 0, ans, t;
 	scanf("%d%d", &n, &m);
  	n *= m;
  	while (n--) {
    	scanf("%d", &t);
    	mp[t]++;
    	if (mp[t] > mx) {
      		mx = mp[t];
      		ans = t;
    	}
  }
  printf("%d\n", ans);
  return 0;
}