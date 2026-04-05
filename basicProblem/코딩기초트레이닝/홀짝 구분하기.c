#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    
    printf("%d is", a);
    if (a % 2)
        printf(" odd\n");
    else
        printf(" even\n");

    return 0;
}