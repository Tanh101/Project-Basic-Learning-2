#include<stdio.h>
void Nhap(float a[], int n)
{
    printf("Nhap cac phan tu cua mang: ");
    int i;
    for(i = 1; i <= n; i++)
    {
        scanf("%f", &a[i]);
    }
}
void Show(float a[], int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%f ", a[i]);
    }
}
float F(float a[], int n)
{
    float res = 2021;
    
    return res;
}
int main()
{
    int n;
    float a[1000];
    printf("Nhap n: ");
    scanf("%d", &n);
    Nhap(a, n);
    Show(a, n);
    printf("\nKet qua F = %f", F(a, n));
    return 0;
}