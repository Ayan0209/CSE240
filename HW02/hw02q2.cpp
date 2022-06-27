#include <stdio.h>

#define addm(a,b) (a+b)
//macro to calculate sum

#define squared_addm(a,b) ({typeof(a) _a=a; typeof(b) _b=b; (_a*_a)+(_b*_b);})
//macro to calculate squared sum

#define absm(a) ((a<0) ? -a : a)
//macro to find abs

#define oddm(a) ((a%2!=0) ? 1 : 0)
//macro to find odd or not

int addf (int a, int b)
{
    return (a + b);
}

int squared_addf (int a, int b)
{
    return a * a + b * b;
}

int absf (int a)
{
    if (a < 0){
            return -a;
    }
    else{
      return a;
    }
}

int oddf (int a)
{
    if (a % 2 != 0){
      return 1;
    }
    else
    {
      return 0;
    }
}

int main ()
{
    int a = 3, b = 6;
    printf ("addf (a, b) = %d\n", addf (a, b));
    printf ("addm (a, b) = %d\n", addm (a, b));
    printf ("addf (a++, b--) = %d\n", addf (a++, b--));
    a = 3, b = 6;                       //reset a,b values
    printf ("addm (a++, b--) = %d\n", addm (a++, b--));

    a = 3, b = 6;
    printf ("squared_addf (a, b) = %d\n", squared_addf (a, b));
    printf ("squared_addm (a, b) = %d\n", squared_addm (a, b));
    printf ("squared_addf (--a, b++) = %d\n", squared_addf (--a, b++));
    a = 3, b = 6;
    printf ("squared_addm (--a, b++) = %d\n", squared_addm (--a, b++));
    
    a = 3, b = 6;
    printf ("absf(a) = %d\n", absf(a));
    printf ("absm(a) = %d\n", absm(a));
    printf ("absf(--a) = %d\n", absf(--a));
    a = 3, b = 6;
    printf ("absm(--a) = %d\n", absm(--a));
    
    a = 3, b = 6;
    printf ("oddf(a) = %d\n", oddf(a));
    printf ("oddm(a) = %d\n", oddm(a));
    printf ("oddf(++a) = %d\n", oddf(++a));
    a = 3, b = 6;
    printf ("oddm(++a) = %d\n", oddm(++a));
    return 0;
}
