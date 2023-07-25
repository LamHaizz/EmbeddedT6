#include <iostream>
#include<string>

using namespace std;

class DoiTuong
{
protected:
    string TEN;
    int TUOI;
    string DIA_CHI;
public:
    void themThongTin(string ten, int tuoi, string dia_chi);
    voi hienthi();
};

void DoiTuong::themThongTin(string ten, int tuoi, string dia_chi){
    TEN = ten;
    TUOI = tuoi;
    DIA_CHI =dia_chi;
}

void DoiTuong::hienthi(){
    cout << "Ten : "<<TEN<<endl;
    cout << "Tuoi: "<< TUOI<<endl;
    cout <<"Dia Chi: "<<DIA_CHI<<endl;
}

class SinhVien : public DoiTuong{
    public:
        int MSSV;
        void themThongTin(string ten, int tuoi, string dia_chi,int mssv);
        void hienThi();
};

void SinhVien::hienThi(){
    cout << "Ten : "<<TEN<<endl;
    cout << "Tuoi: "<< TUOI<<endl;
    cout <<"Dia Chi: "<<DIA_CHI<<endl;
    cout <<"MSSV: "<<MSSV<<endl;
}


int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.themThongTin("Hoang",13, "Go Vap");
    dt.hienthi();

    SinhVien sv;

    sv.MSSV = 101;
    return 0;
}

