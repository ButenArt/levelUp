#include <stdio.h>

int main()
{
    int a,c;
    int b = 5;
    float x, y = -.5, z;
    printf("a=");
    scanf("%d", &a);
x = c = a;
printf("a=%d, c=%d, x=%f\n",a,c,x);
a += b;
printf("a=%d\n", a);
x += b+a;
printf("x=%f\n", x);
b += a--;
printf("b=%d\n", b);
x-= ++c;
printf("x=%f\n",x);
c = a/b;
printf(" c=%4f\n",c);
c = a%b;
printf(" c=%f\n",c);
x = 5.3;
y+= ((x-1)/x);
printf(" x = %f\n y = %.2f\n\n x = %.0f\n y = %.0f\n ", x - 1, y);
z = a/2;
printf(" z = %f\n", z);
z = (float) a/2;
printf(" z = %f\n", z);
y= x/2;
printf(" y = %f\n", y);
y = (int)x/2;
printf(" y = %f\n", y);
z = a%2 - (x+b)/c + (x-y)/(a-1) + 1/4*a - y+ + +b/3.;
printf(" a = %d b = %d c = %d x = %fy = %fz = %f\n", a, b, c, x, y, z);
    return 0;
}
