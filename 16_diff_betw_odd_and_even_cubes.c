#include <stdio.h>
#include <math.h>
int main () {
    int n;
    double r,s,k=0;
    int i;
    (void)scanf("%d", &n);
    for (i=1;i< n+1; i++) {
        (void)scanf("%lf", &s);
        r= pow(-1,i+1.0);
        r=r*pow(s,3);
        k=k+r;
    }
    printf("%lf", k);
    return 0;
}
