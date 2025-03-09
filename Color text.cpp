#include <stdio.h>
void red () {
  printf("\033[1;31m");
}

void yellow () {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

int main () {
  red();
  printf("Hello ");
  yellow();
  printf("world\n");
  reset();
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  printf("x=%d and y=%d and z=%d",x,y,z);
  return 0;
}
