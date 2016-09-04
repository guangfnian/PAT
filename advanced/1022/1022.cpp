#include <bits/stdc++.h>
using namespace std;
const int N = 90;
struct node
{
    int cnt;
    char id[9], title[N], author[N], key[9][15], pub[N], year[N];
    void init() {
        char tmp[N];
        gets(id);
        gets(title);
        gets(author);
        gets(tmp);
        stringstream s;
        s << tmp;
        cnt = 0;
        while (s >> key[cnt++]);
        cnt--;
        gets(pub);
        gets(year);
    }
    bool friend operator < (node a, node b) {
        return strcmp(a.id, b.id) < 0;
    }
}book[11000];
int main() {
    int n, m;
    char tmp[110];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        book[i].init();
    }
    sort(book, book+n);
    scanf("%d", &m);
    getchar();
    while (m--) {
        gets(tmp);
        puts(tmp);
        int ok = 0;
        if (tmp[0] == '1') {
            for (int i = 0; i < n; i++) {
                if (strcmp(tmp+3, book[i].title) == 0) {
                    puts(book[i].id);
                    ok = 1;
                }
            }
        } else if (tmp[0] == '2') {
            for (int i = 0; i < n; i++) {
                if (strcmp(tmp+3, book[i].author) == 0) {
                    puts(book[i].id);
                    ok = 1;
                }
            }
        } else if (tmp[0] == '3') {
            for (int i = 0; i < n; i++) {
                int f = 0;
                for (int j = 0; j < book[i].cnt; j++) {
                    if (strcmp(tmp+3, book[i].key[j]) == 0) {
                        f = 1;
                        ok = 1;
                        break;
                    }
                }
                if (f)
                    puts(book[i].id);
            }
        } else if (tmp[0] == '4') {
            for (int i = 0; i < n; i++) {
                if (strcmp(tmp+3, book[i].pub) == 0) {
                    puts(book[i].id);
                    ok = 1;
                }
            }
        } else if (tmp[0] == '5') {
            for (int i = 0; i < n; i++) {
                if (strcmp(tmp+3, book[i].year) == 0) {
                    puts(book[i].id);
                    ok = 1;
                }
            }
        }
        if (!ok) puts("Not Found");
    }
    return 0;
}