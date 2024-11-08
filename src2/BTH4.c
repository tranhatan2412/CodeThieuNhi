#include "dynamicArray.h"

int main()
{
   int n;
   printf("Nhap so luong sinh vien (0 < n <= INT_MAX): ");
   n = soPhanTu(n, INT_MAX);
   printf("Nhap thong tin sinh vien\n");
   SinhVien *sv = (SinhVien *)malloc(n * sizeSV);
   if (sv == NULL)
   {
      printf("Khong the cap phat");
      getch();
      return 0;
   }
   nhapThongTinSV(sv, 0, n);
   printf("\nHien thong tin sinh vien");
   xemThongTinSV(sv, n);
   getch();

   short option;
   do
   {
      do
      {
         system("cls");
         printf("1, Them sinh vien vao danh sach\n");
         printf("2, Tra cuu diem bang mssv\n");
         printf("3, Xoa nhung sinh vien co diem nho hon 5\n");
         printf("4, Xem thong tin cac sinh vien\n");
         printf("0, Thoat chuong trinh\n");
         printf("Moi ban chon chuong trinh (0 - 4): ");
         scanf("%hi", &option);
      } while (option < 0 || option > 4);

      if (option != 0)
      {
         system("cls");
         printf("Danh sach sinh vien\n");
         xemThongTinSV(sv, n);
      }

      switch (option)
      {
      case 1:
      {
         printf("\n\nThem sinh vien vao danh sach");
         int pos, slThem;
         printf("\nNhap vi tri muon chen vao mang (>= 1): ");
         pos = soPhanTu(pos, INT_MAX);
         printf("Nhap so luong phan tu muon chen vao mang (>= 1 va <= INT_MAX - n): ");
         slThem = soPhanTu(slThem, INT_MAX - n);
         themSinhVien(&sv, &n, pos, slThem);
         xemThongTinSV(sv, n);
      }
      break;

      case 2:
      {
         char soHieu[10], lenSoHieu;
         printf("\n\nTra cuu diem bang mssv\n");
         getchar();
         printf("Nhap ma sinh vien can tra cuu: ");
         fgets(soHieu, sizeof(soHieu), stdin);
         lenSoHieu = strlen(soHieu);
         if (soHieu[lenSoHieu - 1] == '\n')
            soHieu[lenSoHieu - 1] = '\0';
         int traCuu = traCuuDiem(sv, n, soHieu);
         if (traCuu == -1)
            printf("Khong co sinh vien nao co ma la %s", soHieu);
         else
            printf("Diem cua sinh vien co ma %s la %.1f", soHieu, sv[traCuu].diem);
      }
      break;

      case 3:
      {
         printf("\n\nDanh sach sinh vien sau khi xoa cac sinh vien co diem nho hon 5");
         xoaSvDiemNhoHon5(sv, &n);
         xemThongTinSV(sv, n);
      }
      break;

      case 4:
         system("cls");
         xemThongTinSV(sv, n);
         break;

      case 0:
         printf("\nThoat chuong trinh!");
         break;
      }
      getch();
   } while (option);
   free(sv);
   return 0;
}