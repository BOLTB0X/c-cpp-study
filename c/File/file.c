#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char s1[10];
    int num1;
    FILE *fp = fopen("hello.txt", "r");

    // fprintf(fp, "%s %d\n", "Hello", 100);

    // fprintf(stdout, "%s %d\n", "Hello", 100);
    fscanf(stdin, "%s %d", s1, &num1);
    // fscanf(fp, "%s %d", s1, &num1);
    printf("%s %d\n", s1, num1); // Hello 100
    fclose(fp);

    return 0;
}