
#include"header.cpp"

SinhVien::SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, double diem_toan, double diem_ly, double diem_hoa) {
    static int id = 1000;
    ID = id;
    id++;
    TEN = ten;
    TUOI = tuoi;
    GIOI_TINH = gioi_tinh;
    DIEM_TOAN = diem_toan;
    DIEM_HOA = diem_hoa;
    DIEM_LY = diem_ly;

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

void SinhVien::setGioiTinh(int gioi_tinh_input){
    GIOI_TINH = (TypeGioiTinh)gioi_tinh_input;
}

string SinhVien :: getGioiTinh(){
    switch (GIOI_TINH)
    {
    case NAM:
        return "Nam";
        break;
    case NU:
        return "Nu";
        break;
    default:
        return "Khong hop le";
        break;
    }
}


void SinhVien::setDiemToan(double diem_toan) {

    assert((diem_toan >= 0 && diem_toan <= 10) && "Diem toan khong hop le.");
    DIEM_TOAN = diem_toan;
    
}

double SinhVien::getDiemToan() {
    return DIEM_TOAN;
}

void SinhVien::setDiemLy(double diem_ly) {

    assert((diem_ly >= 0 && diem_ly <= 10) && "Diem ly khong hop le.");
    DIEM_LY = diem_ly;
   
}

double SinhVien::getDiemLy() {
    return DIEM_LY;
}

void SinhVien::setDiemHoa(double diem_hoa) {

    assert((diem_hoa >= 0 && diem_hoa <= 10) && "Diem hoa khong hop le.");
    DIEM_HOA = diem_hoa;


}

double SinhVien::getDiemHoa() {
    return DIEM_HOA;
}

double SinhVien::getDiemTrungBinh() {
    return (DIEM_TOAN + DIEM_LY + DIEM_HOA) / 3;
}

TypeHocLuc SinhVien::getHocLuc() {
    if (DIEM_TRUNG_BINH >= 8)
        return HOC_LUC = GIOI;
    else if(DIEM_TRUNG_BINH >= 6.5)
        return HOC_LUC = KHA;
    else if (DIEM_TRUNG_BINH >= 5)
        return HOC_LUC = TRUNG_BINH;
    else
        return HOC_LUC = YEU;
    // return HOC_LUC;
}


void SinhVien::updateDiemTrungBinh(double diem_trung_binh){
    DIEM_TRUNG_BINH = diem_trung_binh;
}

void SinhVien::updateHocLuc(TypeHocLuc hoc_luc){
    HOC_LUC = hoc_luc;
}
    

void themSinhVien(list<SinhVien>& database) {
    string TEN;
    int TUOI;
    TypeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

    cout << "Ten sinh vien: ";
    cin>> TEN;
    cout << "Tuoi: ";
    cin >> TUOI;
    cout << "Gioi tinh (0: Nu, 1: Nam): ";
    int gioiTinhInput;
    cin >> gioiTinhInput;
    GIOI_TINH = (TypeGioiTinh)gioiTinhInput;
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
            // cin.ignore();
            // getline(cin, TEN);
            sv.setTen(TEN);
            cout << "Tuoi: ";
            cin >> TUOI;
            sv.setTuoi(TUOI);
            cout << "Gioi tinh (0: Nu, 1: Nam): ";
            int gioiTinhInput;
            cin >> gioiTinhInput;
            GIOI_TINH = (TypeGioiTinh)gioiTinhInput;
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

bool Compare (const char arr1[], const char arr2[]){
    for (int i = 0; arr1[i] != '\0' || arr2[i] != '\0'; i++ ){
    if ((arr1[i] - arr2[i]) > 0){
        return true;
    } else if ((arr1[i] - arr2[i]) < 0){
      return false;
    } else {
      return true;
    }
    }   
}

TypeGioiTinh convertStringToGioiTinh(const std::string& gioiTinhStr) {
    if (gioiTinhStr == "Nam") {
        return NAM;
    } else {
        return NU;
    } 
}

void swapSinhVien(SinhVien& sv1, SinhVien& sv2) {
    // Swap TEN
    std::string temp = sv1.getTen();
    sv1.setTen(sv2.getTen());
    sv2.setTen(temp);

    // Swap TUOI
    int tempTuoi = sv1.getTuoi();
    sv1.setTuoi(sv2.getTuoi());
    sv2.setTuoi(tempTuoi);

    // Swap GIOI_TINH
    std::string tempGioiTinhStr = sv1.getGioiTinh();
    TypeGioiTinh tempGioiTinh = convertStringToGioiTinh(tempGioiTinhStr);
    sv1.setGioiTinh(convertStringToGioiTinh(sv2.getGioiTinh()));
    sv2.setGioiTinh(tempGioiTinh);

    // Swap DIEM_TOAN
    double tempDiemToan = sv1.getDiemToan();
    sv1.setDiemToan(sv2.getDiemToan());
    sv2.setDiemToan(tempDiemToan);

    // Swap DIEM_LY
    double tempDiemLy = sv1.getDiemLy();
    sv1.setDiemLy(sv2.getDiemLy());
    sv2.setDiemLy(tempDiemLy);

    // Swap DIEM_HOA
    double tempDiemHoa = sv1.getDiemHoa();
    sv1.setDiemHoa(sv2.getDiemHoa());
    sv2.setDiemHoa(tempDiemHoa);

    // Swap DIEM_TRUNG_BINH
    double tempDiemTrungBinh = sv1.getDiemTrungBinh();
    sv1.updateDiemTrungBinh(sv2.getDiemTrungBinh());
    sv2.updateDiemTrungBinh(tempDiemTrungBinh);

    // Swap HOC_LUC
    TypeHocLuc tempHocLuc = sv1.getHocLuc();
    sv1.updateHocLuc(sv2.getHocLuc());
    sv2.updateHocLuc(tempHocLuc)  ;
}

void sapXepTheoDiemTrungBinh(list<SinhVien>& database) {
    for (auto it = database.begin(); it != database.end(); it++)
    {
        for (auto it2 = std::next(it); it2 != database.end(); it2++)
        {
            if (it->getDiemTrungBinh() > it2->getDiemTrungBinh())
            {
                 swapSinhVien(*it, *it2);
            }
            
        }
        
    }

}

void sapXepTheoTen(list<SinhVien>& database) {
    for (auto it = database.begin(); it != database.end(); it++)
    {
        for (auto it2 = std::next(it); it2 != database.end(); it2++)
        {
            if (Compare(it->getTen().c_str(), it2->getTen().c_str()))
            {
                 swapSinhVien(*it, *it2);
            }
            
        }
        
    }
    
}

void hienThiDanhSachSinhVien(list<SinhVien>& database) {
    cout << "Danh sach sinh vien:" << endl;
    for (auto& sv : database) {
        cout << "ID: " << sv.getID() << ", Ten: " << sv.getTen() << ", Tuoi: " << sv.getTuoi()<<", Gioi Tinh: "<<sv.getGioiTinh() 
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
