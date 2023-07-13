
#include "main.hpp"


DoiTuong::DoiTuong(string ten, int tuoi, string gioiTinh){
    static int id = 100;
    ptr = &id;
    ID = id;
    id++;
            
    Ten = ten;
    Tuoi = tuoi;
    GioiTinh = gioiTinh;
}
DoiTuong::~DoiTuong(){
    *ptr = 100;
    cout << "Ten : "<<Ten<<endl;
}


//void nhapThongTin(string ten, int tuoi, string gioiTinh){
//            Ten = ten;
//            Tuoi = tuoi;
//           GioiTinh = gioiTinh;
//        }

void DoiTuong::hienThi(){
    cout<<"Id : "<<ID<<endl;
    cout << "Ten: "<< Ten << endl;
    cout<< "Tuoi: "<< (int)Tuoi <<endl;
    cout << "Gioi Tinh: "<<GioiTinh<<endl;
}
int DoiTuong::static_var; // 0xc1





void test1(){
    DoiTuong dt("Hang", 18 , "Nu");
    dt.hienThi();

    DoiTuong dt1("Ngoc", 19 , "Nu");
    dt.hienThi();

    DoiTuong dt2("Tuyet", 20 , "Nu");
    dt.hienThi();
}

void test2(){
    DoiTuong dt("Vy", 19 , "Nu");
    dt.hienThi();

    DoiTuong dt1("Oanh", 18 , "Nu");
    dt.hienThi();

    DoiTuong dt2("Nga", 18 , "Nu");
    dt.hienThi();
}

int main (int argc, char const *argv[])
{
    DoiTuong dt,dt1, dt2;

    printf("Dia chi dt.var = %p\n", &dt.var);
    printf("Dia chi dt1.var = %p\n", &dt1.var);
    printf("Dia chi dt2.var = %p\n", &dt2.var);

    printf("Dia chi dt.static_var = %p\n", &dt.static_var);
    printf("Dia chi dt1.static_var = %p\n", &dt1.static_var);
    printf("Dia chi dt2.static_var = %p\n", &dt2.static_var);


   //test1();
   //test2();

    return 0;
}