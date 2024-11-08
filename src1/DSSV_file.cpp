#include "module_file.hpp"

int main()
{
   sv L = nullptr;
   string tenFile;
   cout << "Nhap ten tap tin can doc va ghi du lieu: ";
   getline(cin, tenFile);
   fileo.open(tenFile, ios::app);
   fileo.close();

   short option;
   do
   {
      system("cls");
      textColor(11);
      cout << "===============MENU===============\n";
      textColor(7);
      cout << "1, Nhap thong tin sinh vien\n";
      cout << "2, Xem danh sach sinh vien\n";
      cout << "3, Tra cuu thong tin\n";
      cout << "4, Loc ra nhung sinh vien bi luu ban\n";
      cout << "5, Cap nhat thong tin sinh vien\n";
      cout << "6, Sap xep danh sach sinh vien\n";
      cout << "7, Xoa sinh vien bang ma\n";
      textColor(14);
      cout << "0, Thoat chuong trinh\n";
      textColor(11);
      cout << "Moi ban chon chuong trinh (0 - 7): ";
      option = ct(option, 0, 7);
      textColor(7);

      if (option == 0)
      {
         textColor(14);
         cout << "\n\nThoat chuong trinh\n";
         system("pause");
         break;
      }
      system("cls");

      switch (option)
      {
      //! 7, Xoa sinh vien bang ma
      case 7:
      {
         if (L == nullptr)
         {
            textColor(12);
            cout << "Chua nhap thong tin sinh vien";
            textColor(14);
         }
         else
         {
            cin.ignore();
            xoa(L, tenFile);
         }
      }
      break;
      //! 6, Sap xep danh sach sinh vien
      case 6:
      {
         if (L == nullptr)
         {
            textColor(12);
            cout << "Chua nhap thong tin sinh vien";
            textColor(14);
         }
         else
         {
            cin.ignore();
            sapXep(L, tenFile);
            textColor(7);
         }
      }
      break;
      //! 5, Cap nhat thong tin sinh vien
      case 5:
      {
         if (L == nullptr)
         {
            textColor(12);
            cout << "Chua nhap thong tin sinh vien";
            textColor(14);
         }
         else
         {
            cin.ignore();
            capNhat(L, tenFile);
            textColor(14);
         }
      }
      break;

      //! 4, Loc ra nhung sinh vien bi luu ban
      case 4:
      {
         if (L == nullptr)
         {
            textColor(12);
            cout << "Chua nhap thong tin sinh vien";
            textColor(14);
         }
         else
         {
            xoaLuuBan(L, tenFile);
            textColor(14);
         }
      }
      break;

         //! 3, Tra cuu thong tin
      case 3:
      {
         if (L == nullptr)
         {
            textColor(12);
            cout << "Chua nhap thong tin sinh vien";
            textColor(14);
         }
         else
         {
            cin.ignore();
            traCuu(L);
            textColor(14);
         }
      }
      break;

         //> 2, Xem danh sach sinh vien
      case 2:
      {
         if (L == nullptr)
         {
            textColor(12);
            cout << "Chua nhap thong tin sinh vien";
            textColor(14);
         }
         else
         {
            dinhDangCot(cout);
            xemDSSV(L);
            textColor(14);
         }
      }
      break;

         //> 1, Nhap thong tin sinh vien
      case 1:
      {
         file.open(tenFile);
         if (!file.is_open())
         {
            cout << "Khong the mo file" << endl;
            system("pause");
            return 0;
         }
         dinhDangCot(file);
         short select;
         do
         {
            system("cls");
            textColor(11);
            cout << "NHAP THONG TIN SINH VIEN\n";
            textColor(7);
            cout << "1, Nhap tu ban phim\n";
            cout << "2, Nhap tu tap tin\n";
            cout << "0, Quay lai menu chinh\n";
            textColor(11);
            cout << "Moi ban chon chuong trinh (0-2): ";
            select = ct(select, 0, 2);
            textColor(7);

            if (select == 0)
            {
               textColor(14);
               cout << "\n\nQuay lai menu chinh";
               break;
            }
            cout << '\n';

            switch (select)
            {
            case 1:
            {
               system("cls");
               cin.ignore();
               taoDSSV(L);
            }
            break;

            case 2:
            {
               taoDSSV(L, tenFile);
               textColor(14);
               if (check1 == -1 && check2 == 0)
                  cout << "Da nhap du lieu tu file " << tenFile << " truoc do" << endl;
               else if (check1 > 0 && check2 == 0)
                  cout << "Nhap du lieu tu file " << tenFile << " thanh cong" << endl;
               else if (check1 == 0 && check2 == 0)
                  cout << "file " << tenFile << " chua co du lieu\n";
            }
            break;
            }
            system("pause");
         } while (1);
         file.close();
      }
      break;
      }
      cout << endl;
      system("pause");
   } while (1);
   giaiPhong(L);
   return 0;
}