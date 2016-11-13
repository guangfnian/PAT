#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	vector<int> a, b, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		a.push_back(k);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		b.push_back(k);
	}
	t = a;
	make_heap(t.begin(), t.end());
	int p = n;
	while (t != b && p >= 0) {
		pop_heap(t.begin(), t.begin()+p);
		p--;
	}
	if (t == b) {
		puts("Heap Sort");
		pop_heap(t.begin(), t.begin()+p);
		b = t;
	} else {
		puts("Insertion Sort");
		p = 1;
		while (p < n && b[p-1] <= b[p]) {
			p++;
		}
		sort(b.begin(), b.begin()+p+1);
	}
	printf("%d", b[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", b[i]);
	}
	puts("");
	return 0;
}

