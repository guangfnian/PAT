#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10, st = 5e4;
char s[N];
int main() {
	fill(s, s+N, '0');
	scanf("%s", s+st);
	int f = 0;
	if (s[st] == '+') {
		s[st] = '0';
	} else if (s[st] == '-') {
		f = 1;
		s[st] = '0';
	}
	int l = strlen(s);
	int dot, e;
	for (int i = st; i < l; i++) {
		if (s[i] == '.') {
			dot = i;
		} else if (s[i] == 'E') {
			e = i;
			break;
		}
	}
	int p = atoi(s+e+1);
	s[e] = 0;
	for (int i = e+1; i <= l+5; i++) {
		s[i] = '0';
	}

	if (p > 0) {
		while (p > 0) {
			if (s[dot+1] == 0) {
				s[dot+1] = '0';
				s[dot] = 0;
			}
			swap(s[dot], s[dot+1]);
			dot++;
			p--;
		}
		if (s[dot+1] == 0) {
			s[dot] = 0;
		}
	} else {
		while (p < 0) {
			swap(s[dot], s[dot-1]);
			dot--;
			p++;
		}
	}
	p = 0;
	while (s[p] == '0') {
		p++;
	}
	if (s[p] == '.') {
		p--;
	}
	if (f) {
		putchar('-');
	}
	puts(s+p);
	return 0;
}

