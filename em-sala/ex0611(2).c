#include <stdio.h>

int main(){
	int* p;
    int* r;
    int* q;

    p = malloc(sizeof(int));
    *p = 5;

    q = malloc(sizeof(int));
    q = p;
    r = p;

    printf("%d", *p);

	return 0;
}