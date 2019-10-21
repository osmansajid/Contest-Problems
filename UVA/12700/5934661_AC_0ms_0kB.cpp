#include <stdio.h>
 #include<string.h>
int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    char s[99];
    scanf("%s", s);
    int i, cnt[99] = {};
    for (i = 0; s[i]; i++) {
      cnt[s[i]]++;
    }
    printf("Case %d: ", C++);
    if (cnt['A'] == N) {
      puts("ABANDONED");
    } else if ((cnt['B'] + cnt['A']) == N) {
      puts("BANGLAWASH");
    } else if ((cnt['W'] + cnt['A']) == N) {
      puts("WHITEWASH");
    } else if (cnt['B'] == cnt['W']) {
      printf("DRAW %d %d\n", cnt['B'], cnt['T']);
    } else if (cnt['B'] > cnt['W']) {
      printf("BANGLADESH %d - %d\n", cnt['B'], cnt['W']);
    } else {
      printf("WWW %d - %d\n", cnt['W'], cnt['B']);
    }
  }
  return 0;
}
