#include <stdio.h>
struct CauThu
{
     char HoTen[100];
     int SBT;
     int D;
};
typedef struct CauThu CT;
void Nhap(CT a[], int n)
{
     printf("Nhap thong tin cac cau thu: ");
     int i;
     for (i = 0; i < n; i++)
     {
          printf("\nNhap ho ten: ");
          fflush(stdin);
          gets(a[i].HoTen);
          printf("Nhap so ban thang: ");
          scanf("%d", &a[i].SBT);
          printf("Nhap doi bong (1-3): ");
          scanf("%d", &a[i].D);
     }
}
void Show(CT a[], int n)
{
     int i;
     for (i = 0; i < n; i++)
     {
          printf("\nHo ten cau thu: %s", a[i].HoTen);
          printf("\nSo ban thang: %d", a[i].SBT);
          printf("\nDoi bong: %d", a[i].D);
     }
}
void maxBT(CT a[], int n)
{
     int sum1 = 0, sum2 = 0, sum3 = 0;
     int i;
     for (i = 0; i < n; i++)
     {
          if (a[i].D == 1)
               sum1 += a[i].SBT;
          else if (a[i].D == 2)
               sum2 += a[i].SBT;
          else
               sum3 += a[i].SBT;
     }
     int max = sum1, k = 1;
     printf("\nTong so ban thang cua doi 1, 2, 3 lan luot: %d, %d, %d", sum1, sum2, sum3);
     if (sum2 >= max && sum2 >= sum3)
          k = 2;
     else if (sum3 >= max && sum3 >= sum2)
          k = 3;
     printf("\nDoi co tong so ban thang nhieu nhat la: %d", k);
}
void sortCT(CT a[], int n)
{
     if(n < 3)
     {
          printf("\nDanh sach < 3 cau thu!");
          return;
     }
     int i, j;
     for (i = 0; i < n - 1; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               if (a[i].SBT < a[j].SBT)
               {
                    int tmp = a[i].SBT;
                    a[i].SBT = a[j].SBT;
                    a[j].SBT = tmp;
               }
          }
     }
     printf("\n 3 cau thu co so ban thang nhieu nhat la: ");
     for (i = 0; i < 3; i++)
     {
          printf("\nHo ten cau thu: %s", a[i].HoTen);
          printf("\nSo ban thang: %d", a[i].SBT);
          printf("\nDoi bong: %d", a[i].D);
     }
}
int main()
{
     int n;
     printf("Nhap so cau thu: ");
     scanf("%d", &n);
     CT a[100];
     Nhap(a, n);
     Show(a, n);
     maxBT(a, n);
     sortCT(a, n);
     return 0;
}