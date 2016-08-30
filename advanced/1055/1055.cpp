#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
const int N = 1e5+10;
struct stu {
	char name[15];
	int age, val;
	stu(){}
	stu(char *s, int a, int b) {
		strcpy(name, s);
		age = a, val = b;
	}
	void init() {
		scanf("%s%d%d", name, &age, &val);
	}
	bool friend operator < (stu a, stu b) {
		if (a.val != b.val)
			return a.val > b.val;
		if (a.age != b.age)
			return a.age < b.age;
		return strcmp(a.name, b.name) < 0;
	}
	void print() {
		printf("%s %d %d\n", name, age, val);
	}
}tmp;

stu v[210][N];
int cnt[210];
rope<stu> *ro[210], *bk[210];
int main()
{
	stu inf("aaa", 300, -0x3f3f3f3f);
	int n, m, l, r, k;
	int _age = 0;
	scanf("%d%d", &n, &m);
	while (n--) {
		tmp.init();
		v[tmp.age][cnt[tmp.age]++] = tmp;
		_age = max(_age, tmp.age);
	}
	for (int i = 1; i <= _age; i++) {
		sort(v[i], v[i]+cnt[i]);
		ro[i] = new rope<stu>(v[i], v[i]+cnt[i]);
		bk[i] = new rope<stu>(*ro[i]);
	}
	for (int cas = 1; cas <= m; cas++) {
		printf("Case #%d:\n", cas);
		scanf("%d%d%d", &k, &l, &r);
		l = max(1, l), r = min(_age, r);
		int f = 0;
		while (k) {
			int ff = 0, pos;
			stu t = inf;
			for (int i = l; i <= r; i++) {
				if (!ro[i]->empty()) {
					ff = 1;
					if (ro[i]->at(0) < t) {
						t = ro[i]->at(0);
						pos = i;
					}
				}
			}
			if (!ff) {
				break;
			} else {
				t.print();
				ro[pos]->erase(0, 1);
				k--;
				f = 1;
			}
		}
		if (!f)
			puts("None");
		else {
			for (int i = 1; i <= _age; i++)
				ro[i] = new rope<stu>(*bk[i]);
		}
	}
	return 0;
}