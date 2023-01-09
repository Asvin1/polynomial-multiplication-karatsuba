#include <stdio.h>
#include <math.h>
long long pol(long long *arr,int n)
{
    int c=3*n-1;
    long long num=0;
    for(int i=0;i<n;i++)
    {
        num+=arr[i]*pow(10,c);
        c-=3;
    }
    num=num/100;
    return num;
}
int getSize(long long num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}
long long karatsuba(long long X, long long Y)
{
    if (X < 10 && Y < 10)
        {return X * Y;}
    int size = fmax(getSize(X), getSize(Y));
    int n = (int)(size / 2.0);
    long long p = (long)pow(10, n);
    long long a = (long)(X / (double)p);
    long long b = X % p;
    long long c = (long)(Y / (double)p);
    long long d = Y % p;
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long e = karatsuba(a + b, c + d) - ac - bd;
    return (long long)(pow(10 * 1L, 2 * n) * ac + pow(10 * 1L, n) * e + bd);
}
int main()
{
  long long a, b,c;
  long long arr[3]={1,11,3};//Coefficients of first polynomial
  long long arr1[3]={4,5,0};//Coefficients of second polynomial
  a=pol(arr,3);
  b=pol(arr1,3);
  c=karatsuba(a,b);
  long long ct=c;
  int n=0;
  while(ct!=0)
  {
    printf("%d-",ct%1000);
    ct=ct/1000;
  }
}