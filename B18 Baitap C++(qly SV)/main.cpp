#include <iostream>
#include <string>
#include <assert>

typedef enum{
    NU,
    NAM,
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class SinhVien {
    private:
        int ID;
        string TEN;
        int TUOI;
        TypeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;
        TypeHocLuc HOC_LUC;
    public:
        SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa);
        int getID();
        void setTen(string ten);
        string getTen();
        void setTuoi(int tuoi);
        int getTuoi();

};

SinhVien::SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa){
            static int id = 1000;
            ID = id;
            id++
            TEN = ten;
            TUOI = tuoi;
            GIOI_TINH = gioi_tinh;

            assert((diem_toan >= 0 && diem_toan <= 10) && "Diem toan khong hop le");
            DIEM_TOAN = diem_toan;
            DIEM_LY = diem_ly;
            DIEM_HOA = diem_hoa;
        }

void themSinhVien(list<SinhVien> &database){
        string TEN;
        int TUOI;
        TypeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;

        do
        {
            cout<<"Ten sinh vien";
            cin>>TEN;
        } while (/* condition */);
        
}

int main(int argc, char const *argv[])
{
    list<SinhVien> database;
    

    return 0;
}
