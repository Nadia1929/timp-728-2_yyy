#include <stdio.h>
int main () {
    int n,s;
    int k=0;
    int i;
    (void)scanf ("%d", &n);
    for (i=1; i< n+1; i++) {
        (void)scanf ("%d", &s);
        if (s>0) {
            k=k+1;
        }
    }
    printf ("%d", k);
    return 0;
}