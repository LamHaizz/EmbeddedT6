#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    private:
        string Ten;
        int Tuoi;
        string GioiTinh;
        int ID;
        int *ptr;
    public:
        DoiTuong(string ten = "Hoang", int tuoi = 19, string gioiTinh = "Nam");
        ~DoiTuong();
//      void nhapThongTin(string ten, int tuoi, string gioiTinh);
        void hienThi();
        int var;
        static int static_var;
    };
