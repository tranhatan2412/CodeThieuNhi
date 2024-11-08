#include "dynamicArray.h"

int main()
{
   int n;
   printf("Nhap so phan tu cua mang (0 < n <= INT_MAX): ");
   n = soPhanTu(n, INT_MAX);
   int *a = (int *)malloc(n * sizeInt);
   if (a == NULL)
   {
      printf("Khong the cap phat");
      getch();
      return 0;
   }
   printf("Nhap gia tri cac phan tu: ");
   nhapMang(a, 0, n);
   printf("Xuat mang: ");
   xuatMang(a, n);
   getch();
   short option;
   do
   {
      do
      {
         system("cls");
         printf("1, Chen them cac phan tu vao mang\n");
         printf("2, Xoa 1 phan tu bat ky trong mang\n");
         printf("3, Xoa 1 day cac phan tu lien tiep trong mang\n");
         printf("4, Sap xep mang tang/giam dan\n");
         printf("5, Tim gia tri x trong mang\n");
         printf("0, Thoat chuong trinh\n");
         printf("Moi ban chon chuong trinh (0 - 5): ");
         scanf("%hi", &option);
      } while (option < 0 || option > 5);

      if (option != 0)
      {
         system("cls");
         printf("Xuat mang: ");
         xuatMang(a, n);
      }

      switch (option)
      {
      case 1:
      {
         printf("\n\nChen them phan tu vao mang\n");
         int pos, slThem;
         printf("\nNhap vi tri muon chen vao mang (pos >= 1): ");
         pos = soPhanTu(pos, INT_MAX);
         printf("Nhap so luong phan tu muon chen vao mang (1 <= slThem <= INT_MAX - n): ");
         slThem = soPhanTu(slThem, INT_MAX - n);
         themPhanTu(&a, &n, pos, slThem);
         printf("\nMang sau khi chen: ");
         xuatMang(a, n);
      }
      break;

      case 2:
      {
         int pos;
         printf("\n\nXoa 1 phan tu");
         printf("\nNhap vi tri muon xoa (1 <= pos <= n): ");
         pos = soPhanTu(pos, n);
         xoa1PhanTu(&a, &n, pos);
         printf("\nMang sau khi xoa: ");
         xuatMang(a, n);
      }
      break;

      case 3:
      {
         int begin, end;
         printf("\n\nXoa 1 day cac phan tu lien tiep");
         printf("\nNhap vi tri bat dau xoa (1 <= begin < n): ");
         begin = soPhanTu(begin, n - 1);
         printf("Nhap vi tri ket thuc xoa (beign < end <= n): ");
         do
         {
            end = soPhanTu(end, n);
            if (end > begin)
               break;
            printf("Nhap lai: ");
         } while (1);
         xoaCacPhanTu(&a, &n, begin, end);
         printf("\nMang sau khi xoa: ");
         xuatMang(a, n);
      }
      break;

      case 4:
      {
         int tangHayGiam;
         printf("\n\nSap xep mang tang/giam\n");
         printf("Chon thu tu tang dan hoac giam dan (tang: 1, giam: 0): ");
         scanf("%d", &tangHayGiam);
         sapXep(a, n, tangHayGiam);
         printf("\nMang sau khi sap xep: ");
         xuatMang(a, n);
      }
      break;

      case 5:
      {
         int x, pos;
         printf("\n\nTim gia tri x trong mang\n");
         printf("Nhap gia tri x can tim: ");
         scanf("%d", &x);
         pos = timKiem(a, n, x);
         if (pos == -1)
            printf("Khong tim thay %d trong mang", x);
         else
            printf("Gia tri x = %d nam o vi tri thu %d trong mang\n", x, pos + 1);
      }
      break;

      case 0:
         printf("\n\nThoat chuong trinh!");
         break;
      }
      getch();
   } while (option);
   free(a);
   return 0;
}