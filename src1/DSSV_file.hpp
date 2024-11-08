#include <iostream>
#include <windows.h>
#include <ios>
#include <iomanip>
#include <fstream>

#define MAX_CHAR_LINE 60
#define MSSV 15
#define HOTEN 25
#define DIEM 4
using namespace std;

int i = 0, j = 1;
void gotoxy(int x, int y)
{
   COORD toaDo;
   toaDo.X = x;
   toaDo.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toaDo);
}

void textColor(int x)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

ofstream fileo;
fstream file;

namespace DSLK
{

   class SinhVien;
   typedef SinhVien *sv;

   class SinhVien
   {
   private:
      string mssv;
      string hoTen;
      float diem;
      sv next;

   public:
      SinhVien() : mssv(""), hoTen(""), diem(0), next(nullptr) {}
      SinhVien(string, string, float, sv);
      void setMssv(string ma) { mssv = ma; }
      string getMssv() { return mssv; }
      void setHoTen(string ht) { hoTen = ht; }
      string getHoTen() { return hoTen; }
      void setDiem(float d) { diem = d; }
      float getDiem() { return diem; }
      void setNext(sv link) { next = link; }
      sv getNext() { return next; }

      friend istream &operator>>(istream &, sv &);
      friend ostream &operator<<(ostream &, sv &);
   };

   SinhVien::SinhVien(string ma, string ht, float d, sv link)
   {
      mssv = ma;
      hoTen = ht;
      diem = d;
      next = link;
   }

   istream &operator>>(istream &is, sv &svMoi)
   {
      bool check;
      char count = 0;
      string ma;
      textColor(7);
      char *s = new char[MAX_CHAR_LINE];
      do
      {
         check = true;
         gotoxy(i, j);
         getline(is, svMoi->mssv);
         if (svMoi->mssv == "")
            return is;
         file.seekg(0, ios::beg);
         do
         {
            file.getline(s, MAX_CHAR_LINE, '\n');
            if (file.eof())
               break;
            file >> ma;
            if (!stricmp(ma.c_str(), svMoi->mssv.c_str()))
            {
               check = false;
               count = 1;
               gotoxy(i, j);
               cout << "                                                        ";
               gotoxy(i, j + 1);
               textColor(12);
               cout << "Da ton tai sinh vien co ma " << ma <<"                   ";
               textColor(7);
               break;
            }
         } while (1);
         if (check)
         {
            if (count)
            {
               gotoxy(i, j + 1);
               cout << "                                                          ";
            }
            break;
         }
      } while (1);
      delete s;
      gotoxy(i + MSSV, j);
      getline(is, svMoi->hoTen);
      gotoxy(i + MSSV + HOTEN, j);
      is >> svMoi->diem;
      return is;
   }

   ostream &operator<<(ostream &os, sv &svMoi)
   {
      os << endl;
      os.width(MSSV);
      os << left << svMoi->mssv;
      os.width(HOTEN);
      os << left << svMoi->hoTen;
      os << fixed;
      os.width(DIEM);
      os << setprecision(1) << svMoi->diem;
      return os;
   }
}
