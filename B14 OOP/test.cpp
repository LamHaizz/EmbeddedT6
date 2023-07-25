#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string TEN;
        int NAM_SINH;
        string DIA_CHI;
        int tinhTuoi(int namSinh);
    public:
        void themThongTin(string ten, int namSinh, string dia_chi);
        void hienThi();
};

int DoiTuong::tinhTuoi(int namSinh){
    return 2023 - namSinh;
}

void DoiTuong::themThongTin(string ten, int namSinh, string dia_chi){
    TEN = ten;
    NAM_SINH = namSinh;
    DIA_CHI = dia_chi;
}

void DoiTuong::hienThi(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Nam sinh: "<<NAM_SINH<<endl;
    cout<<"Dia Chi: "<<DIA_CHI<<endl;
    cout<<"Tuoi: "<<tinhTuoi(NAM_SINH)<<endl;
    }

class SinhVien : public DoiTuong{
    private:
        int MSSV;
    public:
        SinhVien();
        int getMSSV();
        void hienThi();
        void themThongTin(string ten, int namSinh, string dia_chi, int mssv);
};

int SinhVien::getMSSV(){
    return MSSV;
}

SinhVien::SinhVien(){
    static int mssv = 1000;
    MSSV = mssv;
    mssv++;
}

void SinhVien::themThongTin(string ten, int namSinh, string dia_chi, int mssv){
    TEN = ten;
    NAM_SINH = namSinh;
    DIA_CHI = dia_chi;
    MSSV = mssv;
}

void SinhVien::hienThi(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Nam Sinh: "<<NAM_SINH<<endl;
    cout<<"Dia Chi: "<<DIA_CHI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;
}

int main(int argc, char const *argv[])
{
    DoiTuong dt;

    dt.themThongTin("Hoang" , 1997 ,"Go Vap");

    dt.hienThi();

    SinhVien sv;
 
    sv.themThongTin("Nhung", 2001, "Tan Binh",1004);

    sv.hienThi();
    return 0;
}
