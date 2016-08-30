#include <bits/stdc++.h>
using namespace std;
struct stu {
	char name[15], sex[2], id[15];
	int grade;
}t;
vector<stu> F, M;
int main() {
	int n;
	bool f = 1;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%s%s%d", t.name, t.sex, t.id, &t.grade);
		if (t.sex[0] == 'F')
			F.push_back(t);
		else M.push_back(t);
	}
	if (!F.size()) {
		puts("Absent");
		f = 0;
	} else {
		sort(F.begin(), F.end(), [](stu a, stu b){return a.grade > b.grade;});
		printf("%s %s\n", F[0].name, F[0].id);
	}
	if (!M.size()) {
		puts("Absent");
		f = 0;
	} else {
		sort(M.begin(), M.end(), [](stu a, stu b){return a.grade < b.grade;});
		printf("%s %s\n", M[0].name, M[0].id);
	}
	if (!f) puts("NA");
	else {
		printf("%d\n", F[0].grade-M[0].grade);
	}
	return 0;
}