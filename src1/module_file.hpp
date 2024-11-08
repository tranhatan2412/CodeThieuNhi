#include "DSSV_file.hpp"
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace DSLK;
sv A, B;

short check1, check2;

short ct(short, short, short);
void dinhDangCot(ostream &);
void ghiFile(sv, string);
void taoDSSV(sv &);
void taoDSSV(sv &, string);
void dinhDangChu(string &);
void traCuu(sv);
void capNhat(sv, string);
void xepDiemTang(sv);
void xepDiemGiam(sv);
void xepTenTang(sv);
void xepTenGiam(sv);
void sapXep(sv, string);
void xoaLuuBan(sv &, string);
void giaiPhong(sv &);
void xoa(sv &, string);

void dinhDangChu(string &str)
{
   while (str[0] == ' ')
      str.erase(0, 1);
   while (str.at(str.length() - 1) == ' ')
      str.erase(str.rfind(' '));
}

void dinhDangCot(ostream &os)
{
   textColor(11);
   os.width(MSSV);
   os << left << "Ma SV";
   os.width(HOTEN);
   os << left << "Ho ten";
   os.width(DIEM);
   os << left << "Diem";
}

short ct(short n, short begin, short end)
{
   do
   {
      cin >> n;
      if (n >= begin && n <= end)
         break;
      textColor(14);
      cout << "Nhap lai: ";
   } while (1);
   return n;
}

void ghiFile(sv L, string tenFile)
{
   fstream f;
   f.open(tenFile, ios::out);
   dinhDangCot(f);
   sv temp = L;
   while (temp != nullptr)
   {
      f << temp;
      temp = temp->getNext();
   }
   f.close();
}

void taoDSSV(sv &L, string tenFile)
{
   char *c = new char[MAX_CHAR_LINE];
   string s, ht, ma, d;
   sv svMoi;
   if (L == nullptr)
   {
      check1 = 0;
      check2 = -1;
      file.seekp(0, ios::beg);
      file.getline(c, MAX_CHAR_LINE, '\n');
      do
      {
         if (file.eof())
         {
            check2++;
            break;
         }
         ++check1;
         file >> ma;
         file.getline(c, MAX_CHAR_LINE, '\n');
         s = c;
         dinhDangChu(s);
         ht = s.substr(0, HOTEN);
         dinhDangChu(ht);
         s.erase(0, HOTEN);
         d = s.substr(0, 4);
         dinhDangChu(d);
         if (L == nullptr)
         {
            svMoi = new SinhVien(ma, ht, stof(d), L);
            A = L = svMoi;
         }
         else
         {
            B = A;
            svMoi = new SinhVien(ma, ht, stof(d), B->getNext());
            B->setNext(svMoi);
            A = A->getNext();
         }
      } while (1);
   }
   else
   {
      check1 = -1;
      file.seekg(0, ios::beg);
      sv M = nullptr, N;
      file.getline(c, MAX_CHAR_LINE, '\n');
      do
      {
         file >> ma;
         if (ma == L->getMssv())
         {
            check2 = 0;
            break;
         }
         check1++;
         file.getline(c, MAX_CHAR_LINE, '\n');
         s = c;
         dinhDangChu(s);
         ht = s.substr(0, HOTEN);
         dinhDangChu(ht);
         s.erase(0, HOTEN);
         d = s.substr(0, 4);
         dinhDangChu(d);
         if (M == nullptr)
         {
            svMoi = new SinhVien(ma, ht, stof(d), M);
            N = M = svMoi;
         }
         else
         {
            B = N;
            svMoi = new SinhVien(ma, ht, stof(d), B->getNext());
            B->setNext(svMoi);
            N = N->getNext();
         }
      } while (1);
      if (check1 > -1)
      {
         N->setNext(L);
         L = M;
      }
   }
   delete c;
}

void taoDSSV(sv &L)
{
   file.seekg(0, ios::beg);
   sv svMoi;
   dinhDangCot(cout);
   do
   {
      svMoi = new SinhVien;
      cin >> svMoi;
      gotoxy(i, j + 1);
      cout << "                                                                  ";

      if (svMoi->getMssv() == "")
      {
         textColor(14);
         gotoxy(i, j + 1);
         cout << "Dung nhap thong tin                                  " << endl;
         j = 1;
         break;
      }
      else
         ++j;
      file.seekg(0, ios::end);
      file << svMoi;
      gotoxy(i, j + 1);
      textColor(14);
      cout << "Nhap thong tin sinh vien ma " << svMoi->getMssv() << " thanh cong";
      if (L == nullptr)
      {
         svMoi->setNext(L);
         A = L = svMoi;
      }
      else
      {
         B = A;
         svMoi->setNext(B->getNext());
         B->setNext(svMoi);
         A = A->getNext();
      }
      cin.ignore();
   } while (1);
}

void xemDSSV(sv L)
{
   sv temp = L;
   textColor(7);
   while (temp != nullptr)
   {
      cout << temp;
      temp = temp->getNext();
   }
}

void traCuu(sv L)
{
   sv temp;
   string ma = "  ", ht = "  ", yn;
   char c;
   int count = 0;
   bool check = false;
   do
   {
      do
      {
         system("cls");
         dinhDangCot(cout);
         textColor(14);
         gotoxy(i, j);
         getline(cin, ma);

         do
         {
            system("cls");
            dinhDangCot(cout);
            textColor(14);
            gotoxy(i, j);
            cout << ma;
            gotoxy(i + MSSV, j);
            getline(cin, ht);
            textColor(7);

            if (ma == "" && ht == "")
            {
               textColor(14);
               check = true;
               cout << "\n\nHuy tra cuu thong tin\n";
               break;
            }
            else if (ma != "" && ht == "")
            {
               count = 0;
               gotoxy(i, j + 1);
               temp = L;
               while (temp != nullptr)
               {
                  if (temp->getMssv().find(ma) != -1)
                  {
                     ++count;
                     cout << temp;
                  }
                  temp = temp->getNext();
               }
            }
            else if (ma == "" && ht != "")
            {
               count = 0;
               gotoxy(i, j + 1);
               temp = L;
               while (temp != nullptr)
               {
                  if (temp->getHoTen().find(ht) != -1)
                  {
                     ++count;
                     cout << temp;
                  }
                  temp = temp->getNext();
               }
            }
            else
            {
               count = 0;
               gotoxy(i, j + 1);
               temp = L;
               while (temp != nullptr)
               {
                  if (temp->getMssv().find(ma) != -1 && temp->getHoTen().find(ht) != -1)
                  {
                     ++count;
                     cout << temp;
                  }
                  temp = temp->getNext();
               }
            }

            if (!count)
            {
               textColor(12);
               cout << "\n\nKhong tim thay thong tin\n";
            }
            textColor(14);
            cout << "\n\nTiep tuc tra cuu thong tin khong (y/n): ";
            do
            {
               getline(cin, yn);
               if (yn == "y")
                  break;
               else if (yn == "n")
               {
                  check = true;
                  cout << "\nHuy tra cuu thong tin\n";
                  break;
               }
               cout << "Nhap lai: ";
            } while (1);

            if (check)
               break;

            do
            {
               c = getch();
               if (c == 75 || c == 77)
                  break;
            } while (1);
            if (c == 77)
            {
               gotoxy(i + MSSV, j);
               cout << setw(MSSV - 1) << ' ';
            }
            else
               break;
         } while (1);
         if (check)
            break;
         gotoxy(i, j);
         cout << setw(HOTEN - 1) << ' ';
      } while (1);
      if (check)
         break;
   } while (1);
}

void capNhat(sv L, string tenFile)
{
   dinhDangCot(cout);
   sv temp;
   string c, ma, ht, d;
   int count, count1;
   bool check = false, capNhat = false;

   do
   {
      do
      {
         textColor(7);
         gotoxy(i, j);
         cout << setw(MSSV) << ' ';
         gotoxy(i, j);
         getline(cin, ma);
         if (ma == "")
         {
            system("cls");
            check = true;
            textColor(14);
            cout << "Huy cap nhat thong tin\n";
            textColor(7);
            break;
         }
         count = 0;
         temp = L;
         while (temp != nullptr)
         {
            ++count;
            if (!stricmp(temp->getMssv().c_str(), ma.c_str()))
               break;
            temp = temp->getNext();
         }

         if (temp == nullptr)
         {
            textColor(12);
            cout << "Sinh vien " << ma << " da bo hoc";
            textColor(7);
         }
         else
         {
            gotoxy(i, j + 1);
            cout << setw(MAX_CHAR_LINE) << ' ';
            break;
         }
      } while (1);

      if (check)
         break;

      textColor(7);
      gotoxy(i + MAX_CHAR_LINE, j - 1);
      cout << temp;
      gotoxy(i, j + 2);
      cout << "Nhap thong tin moi";
      gotoxy(i, j + 4);
      dinhDangCot(cout);

      do
      {
         count1 = count;
         textColor(7);
         gotoxy(i, j + 5);
         getline(cin, ma);
         if (ma != "")
            temp->setMssv(ma);
         gotoxy(i + MSSV, j + 5);
         getline(cin, ht);
         if (ht != "")
            temp->setHoTen(ht);
         gotoxy(i + MSSV + HOTEN, j + 5);
         getline(cin, d);
         if (d != "")
            temp->setDiem(stof(d));
         if (ma == "" && ht == "" && d == "")
         {
            textColor(14);
            cout << "\nHuy cap nhat\n";
            textColor(7);
            break;
         }
         else
         {
            gotoxy(i + MAX_CHAR_LINE, j - 1);
            cout << temp;
            gotoxy(i, j + 7);
            cout << "Cap nhat thong tin thanh cong";
            capNhat = true;
         }

         textColor(14);
         cout << "\nTiep tuc cap nhat thong tin cua sinh vien nay khong (y/n)?: ";
         do
         {
            getline(cin, c);
            if (c == "y" || c == "n")
               break;
            cout << "Nhap lai: ";
         } while (1);

         if (c == "n")
         {
            cout << "\nHuy cap nhat thong tin cua sinh vien nay\n";
            system("pause");
            system("cls");
            dinhDangCot(cout);
            break;
         }

         gotoxy(i, j + 5);
         cout << setw(100) << ' ';
         gotoxy(i, j + 6);
         cout << setw(100) << ' ';
         gotoxy(i, j + 7);
         cout << setw(100) << ' ';
         gotoxy(i, j + 8);
         cout << setw(100) << ' ';
      } while (1);
   } while (1);
   if (capNhat)
      ghiFile(L, tenFile);
}

void xepDiemGiam(sv L)
{
   string ma, ht;
   float d;
   for (sv i = L; i->getNext() != nullptr; i = i->getNext())
      for (sv j = i->getNext(); j != nullptr; j = j->getNext())
         if (i->getDiem() < j->getDiem())
         {
            d = i->getDiem();
            i->setDiem(j->getDiem());
            j->setDiem(d);
            ht = i->getHoTen();
            i->setHoTen(j->getHoTen());
            j->setHoTen(ht);
            ma = i->getMssv();
            i->setMssv(j->getMssv());
            j->setMssv(ma);
         }
}

void xepDiemTang(sv L)
{
   string ma, ht;
   float d;
   for (sv i = L; i->getNext() != nullptr; i = i->getNext())
      for (sv j = i->getNext(); j != nullptr; j = j->getNext())
         if (i->getDiem() > j->getDiem())
         {
            d = i->getDiem();
            i->setDiem(j->getDiem());
            j->setDiem(d);
            ht = i->getHoTen();
            i->setHoTen(j->getHoTen());
            j->setHoTen(ht);
            ma = i->getMssv();
            i->setMssv(j->getMssv());
            j->setMssv(ma);
         }
}

void xepTenGiam(sv L)
{
   string ma, ht;
   float d;
   for (sv i = L; i->getNext() != nullptr; i = i->getNext())
      for (sv j = i->getNext(); j != nullptr; j = j->getNext())
         if (stricmp(i->getHoTen().substr(0, i->getHoTen().find(' ')).c_str(), j->getHoTen().substr(0, j->getHoTen().find(' ')).c_str()) < 0)
         {
            d = i->getDiem();
            i->setDiem(j->getDiem());
            j->setDiem(d);
            ht = i->getHoTen();
            i->setHoTen(j->getHoTen());
            j->setHoTen(ht);
            ma = i->getMssv();
            i->setMssv(j->getMssv());
            j->setMssv(ma);
         }
   for (sv i = L; i->getNext() != nullptr; i = i->getNext())
      for (sv j = i->getNext(); j != nullptr; j = j->getNext())
         if (stricmp(i->getHoTen().substr(i->getHoTen().rfind(' ') + 1).c_str(), j->getHoTen().substr(j->getHoTen().rfind(' ') + 1).c_str()) < 0)
         {
            d = i->getDiem();
            i->setDiem(j->getDiem());
            j->setDiem(d);
            ht = i->getHoTen();
            i->setHoTen(j->getHoTen());
            j->setHoTen(ht);
            ma = i->getMssv();
            i->setMssv(j->getMssv());
            j->setMssv(ma);
         }
}

void xepTenTang(sv L)
{
   string ma, ht;
   float d;
   for (sv i = L; i->getNext() != nullptr; i = i->getNext())
      for (sv j = i->getNext(); j != nullptr; j = j->getNext())
         if (stricmp(i->getHoTen().substr(0, i->getHoTen().find(' ')).c_str(), j->getHoTen().substr(0, j->getHoTen().find(' ')).c_str()) > 0)
         {
            d = i->getDiem();
            i->setDiem(j->getDiem());
            j->setDiem(d);
            ht = i->getHoTen();
            i->setHoTen(j->getHoTen());
            j->setHoTen(ht);
            ma = i->getMssv();
            i->setMssv(j->getMssv());
            j->setMssv(ma);
         }
   for (sv i = L; i->getNext() != nullptr; i = i->getNext())
      for (sv j = i->getNext(); j != nullptr; j = j->getNext())
         if (stricmp(i->getHoTen().substr(i->getHoTen().rfind(' ') + 1).c_str(), j->getHoTen().substr(j->getHoTen().rfind(' ') + 1).c_str()) > 0)
         {
            d = i->getDiem();
            i->setDiem(j->getDiem());
            j->setDiem(d);
            ht = i->getHoTen();
            i->setHoTen(j->getHoTen());
            j->setHoTen(ht);
            ma = i->getMssv();
            i->setMssv(j->getMssv());
            j->setMssv(ma);
         }
}

void sapXep(sv L, string tenFile)
{
   string d, ht;
   char c;
   bool check = false;
   dinhDangCot(cout);
   gotoxy(i, j);
   xemDSSV(L);
   do
   {

      textColor(14);
      gotoxy(i + MSSV, j);
      getline(cin, ht);
      textColor(7);

      if (ht == "asc")
      {
         xepTenTang(L);
         gotoxy(i, j);
         xemDSSV(L);
      }
      else if (ht == "desc")
      {
         xepTenGiam(L);
         gotoxy(i, j);
         xemDSSV(L);
      }

      do
      {
         textColor(14);
         gotoxy(i + MSSV + HOTEN, j);
         getline(cin, d);
         gotoxy(i, j);
         cout << setw(MAX_CHAR_LINE) << ' ';
         gotoxy(i + MSSV + HOTEN, j);
         cout << d;
         if (d == "asc")
            xepDiemTang(L);
         else if (d == "desc")
            xepDiemGiam(L);
         else if (ht != "asc" && ht != "desc" && d != "asc" && d != "desc")
         {
            check = true;
            break;
         }
         gotoxy(i, j);
         xemDSSV(L);

         do
         {
            c = getch();
            if (c == 75 || c == 77)
               break;
         } while (1);

         if (c == 75)
            break;
         textColor(14);
         gotoxy(i, j);
         cout << setw(MAX_CHAR_LINE) << ' ';

      } while (1);
      if (check)
      {
         system("cls");
         textColor(14);
         cout << "Huy cap nhat";
         textColor(7);
         break;
      }
      gotoxy(i, j);
      cout << setw(MAX_CHAR_LINE) << ' ';
   } while (1);

   ghiFile(L, tenFile);
}

void xoaLuuBan(sv &L, string tenFile)
{
   fstream f;
   int count = 0;
   f.open("LuuBan.txt");
   dinhDangCot(cout);
   dinhDangCot(f);
   textColor(7);
   sv P = nullptr;
   while (L != nullptr)
   {
      if (L->getDiem() < 5)
      {
         P = L;
         cout << P;
         f << P;
         ++count;
         L = L->getNext();
         delete P;
      }
      else
         break;
   }
   if (L->getNext() != nullptr)
   {
      sv Q, R;
      Q = R = L;
      while (Q->getNext() != nullptr)
      {
         Q = Q->getNext();
         if (Q->getDiem() < 5)
         {
            P = Q;
            cout << P;
            f << P;
            ++count;
            R->setNext(Q->getNext());
            delete P;
            Q = R;
         }
         else
            R = Q;
      }
   }
   if (!count)
   {
      textColor(14);
      cout << "\n\nKhong co sinh vien nao bi luu ban";
      textColor(7);
   }
   else
      ghiFile(L, tenFile);
   f.close();
}

void xoa(sv &L, string tenFile)
{
   string ma;
   sv P, Q, R;
   R = nullptr;
   bool check = false;
   cout << "Nhap ma sinh vien can xoa: ";
   getline(cin, ma);
   if (ma == "")
   {
      textColor(14);
      cout << "Huy xoa";
      textColor(7);
      return;
   }
   if (!stricmp(ma.c_str(), L->getMssv().c_str()))
   {
      check = true;
      R = L;
      L = L->getNext();
      delete R;
      textColor(14);
      cout << "Xoa sinh vien ma " << ma << " thanh cong";
      textColor(7);
   }
   else
   {
      P = Q = L;
      while (P->getNext() != nullptr)
      {
         P = P->getNext();
         if (!stricmp(ma.c_str(), P->getMssv().c_str()))
         {
            R = P;
            Q->setNext(P->getNext());
            delete R;
            textColor(14);
            cout << "Xoa sinh vien ma " << ma << " thanh cong";
            textColor(7);
            check = true;
            break;
         }
         else
            Q = P;
      }
   }
   if (!check)
   {
      textColor(14);
      cout << "\n\nKhong tim thay sinh vien";
      textColor(7);
   }
   else
      ghiFile(L, tenFile);
}

void giaiPhong(sv &L)
{
   sv temp = nullptr;
   while (L != nullptr)
   {
      temp = L;
      L = L->getNext();
      delete temp;
   }
}