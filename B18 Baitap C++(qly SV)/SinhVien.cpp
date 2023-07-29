#include <iostream>
#include <string>
#include <list>
#include <cassert>

using namespace std;

typedef enum {
    NU,
    NAM,
} TypeGioiTinh;

typedef enum {
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
} TypeHocLuc;

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
    SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, double diem_toan, double diem_ly, double diem_hoa);
    int getID();
    void setTen(string ten);
    string getTen();
    void setTuoi(int tuoi);
    int getTuoi();
    void setDiemToan(double diem_toan);
    double getDiemToan();
    void setDiemLy(double diem_ly);
    double getDiemLy();
    void setDiemHoa(double diem_hoa);
    double getDiemHoa();
    double getDiemTrungBinh();
    TypeHocLuc getHocLuc();
    void calculateDiemTrungBinhAndHocLuc();

};

SinhVien::SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, double diem_toan, double diem_ly, double diem_hoa) {
    static int id = 1000;
    ID = id;
    id++;
    TEN = ten;
    TUOI = tuoi;
    GIOI_TINH = gioi_tinh;

    setDiemToan(diem_toan);
    setDiemLy(diem_ly);
    setDiemHoa(diem_hoa);

    calculateDiemTrungBinhAndHocLuc();
}

int SinhVien::getID() {
    return ID;
}

void SinhVien::setTen(string ten) {
    TEN = ten;
}

string SinhVien::getTen() {
    return TEN;
}

void SinhVien::setTuoi(int tuoi) {
    TUOI = tuoi;
}

int SinhVien::getTuoi() {
    return TUOI;
}

void SinhVien::setDiemToan(double diem_toan) {
    while (diem_toan < 0 || diem_toan > 10) {
        cout << "Diem toan khong hop le. Vui long nhap lai (0 - 10): ";
        cin >> diem_toan;
    }
    DIEM_TOAN = diem_toan;
    calculateDiemTrungBinhAndHocLuc();
}

double SinhVien::getDiemToan() {
    return DIEM_TOAN;
}

void SinhVien::setDiemLy(double diem_ly) {
    while (diem_ly < 0 || diem_ly > 10) {
        cout << "Diem ly khong hop le. Vui long nhap lai (0 - 10): ";
        cin >> diem_ly;
    }
    DIEM_LY = diem_ly;
    calculateDiemTrungBinhAndHocLuc();
}

double SinhVien::getDiemLy() {
    return DIEM_LY;
}

void SinhVien::setDiemHoa(double diem_hoa) {
    while (diem_hoa < 0 || diem_hoa > 10) {
        cout << "Diem hoa khong hop le. Vui long nhap lai (0 - 10): ";
        cin >> diem_hoa;
    }
    DIEM_HOA = diem_hoa;
    calculateDiemTrungBinhAndHocLuc();
}

double SinhVien::getDiemHoa() {
    return DIEM_HOA;
}

double SinhVien::getDiemTrungBinh() {
    return (DIEM_TOAN + DIEM_LY + DIEM_HOA) / 3;
}

TypeHocLuc SinhVien::getHocLuc() {
    return HOC_LUC;
}

void SinhVien::calculateDiemTrungBinhAndHocLuc() {
    DIEM_TRUNG_BINH = (DIEM_TOAN + DIEM_LY + DIEM_HOA) / 3;
    if (DIEM_TRUNG_BINH >= 8)
        HOC_LUC = GIOI;
    else if (DIEM_TRUNG_BINH >= 6.5)
        HOC_LUC = KHA;
    else if (DIEM_TRUNG_BINH >= 5)
        HOC_LUC = TRUNG_BINH;
    else
        HOC_LUC = YEU;
}

void themSinhVien(list<SinhVien>& database) {
    string TEN;
    int TUOI;
    TypeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

    cout << "Ten sinh vien: ";
    cin.ignore();
    getline(cin, TEN);
    cout << "Tuoi: ";
    cin >> TUOI;
    cout << "Gioi tinh (0: Nu, 1: Nam): ";
    int gioiTinhInput;
    cin >> gioiTinhInput;
    GIOI_TINH = static_cast<TypeGioiTinh>(gioiTinhInput);
    cout << "Diem toan: ";
    cin >> DIEM_TOAN;
    cout << "Diem ly: ";
    cin >> DIEM_LY;
    cout << "Diem hoa: ";
    cin >> DIEM_HOA;

    SinhVien newSinhVien(TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);
    database.push_back(newSinhVien);
    cout << "Them sinh vien thanh cong!" << endl;
}

void capNhatThongTinSinhVien(list<SinhVien>& database) {
    int ID;
    cout << "Nhap ID sinh vien can cap nhat: ";
    cin >> ID;

    bool found = false;
    for (auto& sv : database) {
        if (sv.getID() == ID) {
            string TEN;
            int TUOI;
            TypeGioiTinh GIOI_TINH;
            double DIEM_TOAN, DIEM_LY, DIEM_HOA;

            cout << "Ten sinh vien: ";
            cin.ignore();
            getline(cin, TEN);
            sv.setTen(TEN);
            cout << "Tuoi: ";
            cin >> TUOI;
            sv.setTuoi(TUOI);
            cout << "Gioi tinh (0: Nu, 1: Nam): ";
            int gioiTinhInput;
            cin >> gioiTinhInput;
            GIOI_TINH = static_cast<TypeGioiTinh>(gioiTinhInput);
            cout << "Diem toan: ";
            cin >> DIEM_TOAN;
            sv.setDiemToan(DIEM_TOAN);
            cout << "Diem ly: ";
            cin >> DIEM_LY;
            sv.setDiemLy(DIEM_LY);
            cout << "Diem hoa: ";
            cin >> DIEM_HOA;
            sv.setDiemHoa(DIEM_HOA);

            found = true;
            cout << "Cap nhat thong tin sinh vien thanh cong!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ID: " << ID << endl;
    }
}

void xoaSinhVien(list<SinhVien>& database) {
    int ID;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> ID;

    bool found = false;
    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID) {
            database.erase(it);
            found = true;
            cout << "Xoa sinh vien thanh cong!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ID: " << ID << endl;
    }
}

void sapXepTheoDiemTrungBinh(list<SinhVien>& database) {
    database.sort([]( SinhVien& sv1,  SinhVien& sv2) {
        return sv1.getDiemTrungBinh() > sv2.getDiemTrungBinh();
    });
}

void sapXepTheoTen(list<SinhVien>& database) {
    database.sort([]( SinhVien& sv1,  SinhVien& sv2) {
        return sv1.getTen() < sv2.getTen();
    });
}

void hienThiDanhSachSinhVien(list<SinhVien>& database) {
    cout << "Danh sach sinh vien:" << endl;
    for (auto& sv : database) {
        cout << "ID: " << sv.getID() << ", Ten: " << sv.getTen() << ", Tuoi: " << sv.getTuoi()
             << ", Diem toan: " << sv.getDiemToan() << ", Diem ly: " << sv.getDiemLy()
             << ", Diem hoa: " << sv.getDiemHoa() << ", Diem trung binh: " << sv.getDiemTrungBinh()
             << ", Hoc luc: ";
        switch (sv.getHocLuc()) {
            case GIOI:
                cout << "Gioi";
                break;
            case KHA:
                cout << "Kha";
                break;
            case TRUNG_BINH:
                cout << "Trung binh";
                break;
            case YEU:
                cout << "Yeu";
                break;
            default:
                cout << "N/A";
                break;
        }
        cout << endl;
    }
}

int main() {
    list<SinhVien> database;

    int choice;
    do {
        cout << "\n------- Menu -------" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Hien thi danh sach sinh vien" << endl;
        cout << "5. Sap xep sinh vien theo diem trung binh" << endl;
        cout << "6. Sap xep sinh vien theo ten" << endl;
        cout << "7. Tim kiem sinh vien theo ten" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                themSinhVien(database);
                break;
            case 2:
                capNhatThongTinSinhVien(database);
                break;
            case 3:
                xoaSinhVien(database);
                break;
            case 4:
                hienThiDanhSachSinhVien(database);
                break;
            case 5:
                sapXepTheoDiemTrungBinh(database);
                cout << "Sap xep sinh vien theo diem trung binh thanh cong!" << endl;
                break;
            case 6:
                sapXepTheoTen(database);
                cout << "Sap xep sinh vien theo ten thanh cong!" << endl;
                break;
            case 7: {
                string ten;
                cout << "Nhap ten sinh vien can tim: ";
                cin.ignore();
                getline(cin, ten);
                list<SinhVien> result;
                for ( auto& sv : database) {
                    if (sv.getTen() == ten) {
                        result.push_back(sv);
                    }
                }
                if (result.empty()) {
                    cout << "Khong tim thay sinh vien co ten: " << ten << endl;
                } else {
                    hienThiDanhSachSinhVien(result);
                }
                break;
            }
            case 0:
                cout << "Ket thuc chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
