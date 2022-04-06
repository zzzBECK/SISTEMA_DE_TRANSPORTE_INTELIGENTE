#include <stdio.h>

int main()
{
  char vet[10];
  int DD[1], MM[1], AA[1];

  scanf("%d/%d/%d", &DD, &MM, &AA);

  printf("%.2d/%.2d/%.2d\n", *MM, *DD, *AA);
  printf("%.2d/%.2d/%.2d\n", *AA, *MM, *DD);
  printf("%.2d-%.2d-%.2d\n", *DD, *MM, *AA);


  return 0;
}