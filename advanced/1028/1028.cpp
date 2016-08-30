#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct stu {
	char id[9], name[9];
	int grade;
	void init() {
		scanf("%s%s%d", id, name, &grade);
	}
	void print() {
		printf("%s %s %d\n", id, name, grade);
	}
}tmp;
vector<stu> v;
int main()
{
	int n, tag;
	scanf("%d%d", &n, &tag);
	for (int i = 0; i < n; i++) {
		tmp.init();
		v.push_back(tmp);
	}
	switch(tag) {
		case 1: sort(v.begin(), v.end(), [](stu a, stu b){return strcmp(a.id, b.id) < 0;}); break;
		case 2: sort(v.begin(), v.end(), [](stu a, stu b){int k = strcmp(a.name, b.name); if (k != 0) return k < 0 ; return strcmp(a.id, b.id) < 0;});break;
		case 3: sort(v.begin(), v.end(), [](stu a, stu b){if (a.grade != b.grade) return a.grade < b.grade; return strcmp(a.id, b.id) < 0;});break;
	}
	for (stu i: v)
		i.print();
	return 0;
}