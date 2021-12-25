#include <stdio.h>
void Nhap(int a[], int n)
{
    int i;
    printf("Nhap lan luot cac phan tu cua mang: ");
    for (i - 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void Xuat(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int Count(int a[], int n)
{
    int i;
    int dem2 = 0, dem5 = 0;
    for( i = 0; i < n; i++)
    {
        do
        {
            if(a[i] % 2 == 0)
            {
                dem2++;
                a[i] /= 2;
            }
            else if(a[i] % 5 == 0)
            {
                dem5++;
                a[i] /= 5;
            }
            else
                break;
        } while (a[i] > 0);
    }
    if(dem2 > 0 && dem5 > 0)
        return dem2 < dem5 ? dem2 : dem5;
    return 0;
}
int main()
{
    int a[1000];
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    Nhap(a, n);
    Xuat(a, n);
    printf("\nCo %d chu so 0 tan cung cua tich cac so tren", Count(a,n));
    return 0;
}