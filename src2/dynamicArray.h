#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int i, j;

typedef struct SV
{
   char mssv[10];
   char hoTen[30];
   float diem;
} SinhVien;

#define sizeInt sizeof(int)
#define sizeSV sizeof(SinhVien)

int soPhanTu(int n, int m)
{
   do
   {
      scanf("%d", &n);
      if (n > 0 && n <= m)
         break;
      printf("Nhap lai: ");
   } while (1);
   return n;
}

void nhapMang(int *a, int begin, int end)
{
   for (i = begin; i < end; ++i)
      scanf("%d", a + i);
}

void xuatMang(int *a, int n)
{
   for (i = 0; i < n; ++i)
      printf("%d ", *(a + i));
}

void hoanDoi(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void daoNguocMang(int *a, int n)
{
   for (i = 0, j = n - 1; i < j; ++i, --j)
      hoanDoi(a + i, a + j);
}

void sapXep(int *a, int n, char tangHayGiam)
{
   char check;
   int end;
   for (i = 0; i < n; ++i)
   {
      check = 0;
      end = n - i - 1;
      for (j = 0; j < end; ++j)
         if (*(a + j) < *(a + j + 1))
         {
            hoanDoi(a + j, a + j + 1);
            check = 1;
         }
      if (!check)
         break;
   }
   if (tangHayGiam)
      daoNguocMang(a, n);
}

int timKiem(int *a, int n, int x)
{
   int pos = -1;
   for (i = 0, j = n - 1; i <= j; ++i, --j)
      if (*(a + i) == x)
      {
         pos = i;
         break;
      }
      else if (*(a + j) == x)
      {
         pos = j;
         break;
      }
   return pos;
}

int timKiemNhiPhan(int *a, int n, int x)
{
   int left = 0, right = n - 1;
   int mid, pos = -1;
   while (left <= right)
   {
      mid = (left + right) / 2;
      if (x == a[mid])
      {
         pos = mid;
         break;
      }
      else if (x > a[mid])
      {
         if (a[mid] > a[mid - 1])
            left = mid + 1;
         else
            right = mid - 1;
      }
      else
      {
         if (a[mid] > a[mid - 1])
            right = mid - 1;
         else
            left = mid + 1;
      }
   }
   return pos;
}

void xoa1PhanTu(int **a, int *n, int pos)
{
   --pos;
   for (i = pos; i < *n - 1; ++i)
      *(*a + i) = *(*a + i + 1);
   --(*n);
   *a = (int *)realloc(*a, *n * sizeInt);
}

void xoaCacPhanTu(int **a, int *n, int begin, int end)
{
   int range = end - begin + 1;
   for (i = begin - 1; i < *n; ++i)
      *(*a + i) = *(*a + i + range);
   *n -= range;
   *a = (int *)realloc(*a, *n * sizeInt);
}

void themPhanTu(int **a, int *n, int pos, int slThem)
{
   int m = *n;
   *n += slThem;
   *a = (int *)realloc(*a, *n * sizeInt);
   if (*a == NULL)
   {
      printf("Khong the cap phat");
      getch();
      return;
   }
   printf("Nhap gia tri %d phan tu can chen: ", slThem);
   if (pos > m)
      nhapMang(*a, m, *n);
   else
   {
      int pos1 = --pos;
      pos = pos + slThem - 1;
      for (i = *n - 1; i > pos; --i)
         *(*a + i) = *(*a + i - slThem);
      nhapMang(*a, pos1, pos + 1);
   }
}

void nhapThongTinSV(SinhVien *sv, int begin, int end)
{
   char lenMssv, lenHoTen;
   for (i = begin; i < end; ++i)
   {
      getchar();
      printf("\nNhap thong tin sinh vien thu %d\n", i + 1);
      printf("\tNhap MSSV: ");
      fgets((sv + i)->mssv, sizeof((sv + i)->mssv), stdin);
      fflush(stdin);
      lenMssv = strlen((sv + i)->mssv);
      if ((sv + i)->mssv[lenMssv - 1] == '\n')
         (sv + i)->mssv[lenMssv - 1] = '\0';
      printf("\tNhap ho ten: ");
      fgets((sv + i)->hoTen, sizeof((sv + i)->hoTen), stdin);
      lenHoTen = strlen((sv + i)->hoTen);
      if ((sv + i)->hoTen[lenHoTen - 1] == '\n')
         (sv + i)->hoTen[lenHoTen - 1] = '\0';
      printf("\tNhap diem: ");
      scanf("%f", &(sv + i)->diem);
   }
}

void xemThongTinSV(SinhVien *sv, int n)
{
   printf("\n%s\t%-15s%-35s%s", "STT", "MSSV", "Ho va ten", "Diem");
   for (i = 0; i < n; ++i)
      printf("\n%d,\t%-15s%-35s%2.1f", i + 1, (sv + i)->mssv, (sv + i)->hoTen, (sv + i)->diem);
}

void xoa1SinhVien(SinhVien **sv, int *n, int pos)
{
   --pos;
   for (i = pos; i < *n - 1; ++i)
      *(*sv + i) = *(*sv + i + 1);
   --(*n);
   *sv = (SinhVien *)realloc(*sv, *n * sizeSV);
}

void xoaCacSinhVien(SinhVien **sv, int *n, int begin, int end)
{
   int range = end - begin + 1;
   for (i = begin - 1; i < *n; ++i)
      *(*sv + i) = *(*sv + i + range);
   *n -= range;
   *sv = (SinhVien *)realloc(*sv, *n * sizeSV);
}

int traCuuDiem(SinhVien *sv, int n, char *soHieu)
{
   int check = -1;
   for (i = 0; i < n; ++i)
   {
      if (!strcmp(soHieu, (sv + i)->mssv))
      {
         check = i;
         break;
      }
   }
   return check;
}

void xoaSvDiemNhoHon5(SinhVien *sv, int *n)
{
   for (j = 0; j < *n;)
   {
      if ((sv + j)->diem < 5)
         xoa1SinhVien(&sv, n, j + 1);
      else
         ++j;
   }
}

void themSinhVien(SinhVien **sv, int *n, int pos, int slThem)
{
   int m = *n;
   *n += slThem;
   *sv = (SinhVien *)realloc(*sv, *n * sizeSV);
   if (*sv == NULL)
   {
      printf("Khong the cap phat");
      getch();
      return;
   }
   printf("Nhap them thong tin cua %d sinh vien: ", slThem);
   if (pos > m)
      nhapThongTinSV(*sv, m, *n);
   else
   {
      int pos1 = --pos;
      pos = pos + slThem - 1;
      for (i = *n - 1; i > pos; --i)
         *(*sv + i) = *(*sv + i - slThem);
      nhapThongTinSV(*sv, pos1, pos + 1);
   }
}
