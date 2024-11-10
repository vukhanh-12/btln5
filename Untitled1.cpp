#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>
using namespace std;

struct ThiSinh {
    int sbd;  
    string hoTen;
    string gioiTinh;
    int khuVuc; 
    float toan, van, anh, mon1, mon2, mon3;
    string nganhXetTuyen[5]; 
    string khoiXetTuyen;
    int soNganh; 
    float tongDiem;
    ThiSinh* next;

    ThiSinh(int _sbd, string _hoTen, string _gioiTinh, int _khuVuc,
        float _toan, float _van, float _anh, float _mon1, float _mon2, float _mon3,
        string* _nganhXetTuyen, int _soNganh, string _khoiXetTuyen)
        : sbd(_sbd), hoTen(_hoTen), gioiTinh(_gioiTinh), khuVuc(_khuVuc),
        toan(_toan), van(_van), anh(_anh), mon1(_mon1), mon2(_mon2), mon3(_mon3),
        soNganh(_soNganh), khoiXetTuyen(_khoiXetTuyen), next(NULL) {
        	
        for (int i = 0; i < soNganh; i++) {
            nganhXetTuyen[i] = _nganhXetTuyen[i];
        }
        tinhTongDiem();
    }
    
    void tinhTongDiem() {
        float diemKhuVuc = (khuVuc == 1) ? 0.75 : (khuVuc == 2) ? 0.5 : 0.25;
        if (khoiXetTuyen == "A00")
            tongDiem = toan + mon1 + mon2 + diemKhuVuc;
        else if (khoiXetTuyen == "A01")
            tongDiem = toan + mon1 + anh + diemKhuVuc;
        else if (khoiXetTuyen == "B00")
            tongDiem = toan + mon2 + mon3 + diemKhuVuc;
        else if (khoiXetTuyen == "B01")
            tongDiem = toan + mon3 + van + diemKhuVuc;
        else if (khoiXetTuyen == "C00")
            tongDiem = van + mon1 + mon2 + diemKhuVuc;
    }
};

struct DanhSachThiSinh {
    ThiSinh* head;
    int size;
    DanhSachThiSinh() : head(NULL), size(0) {}
    
    bool kiemTraTonTai(int sbd);
    void themThiSinh();
    void themThiSinhVaoCuoi();
    void themNhieuThiSinh(int n);
    void suaThongTin(int sbd);
    void xoaThiSinh(int sbd);
    void xoaThiSinhDau();
    void xoaThiSinhCuoi();
    void sapXepTheoTen();
    void inDanhSach();
    void lietKeThiSinhDau();
    void hocBong();
    void xoaTatCa();
    void docFile() ;
};

bool DanhSachThiSinh::kiemTraTonTai(int sbd) {
    ThiSinh* hienTai = head;
    while (hienTai) {
        if (hienTai->sbd == sbd) return true;
        hienTai = hienTai->next;
    }
    return false;
}


void DanhSachThiSinh::themThiSinh() {
    int sbd, khuVuc, soNganh;
    string hoTen, gioiTinh, khoiXetTuyen;
    float toan, van, anh, mon1, mon2, mon3 = 0; 
    string nganhXetTuyen[5];

    cout << "Nhap so bao danh: "; cin >> sbd;
    if (kiemTraTonTai(sbd)) {
        cout << "Thi sinh da ton tai!" << endl;
        return;
    }
    cout << "Nhap ho va ten: "; cin.ignore(); getline(cin, hoTen);
    cout << "Nhap gioi tinh (Nam/Nu): "; getline(cin, gioiTinh);
    cout << "Nhap khu vuc (1/2/3): "; cin >> khuVuc;
    while (khuVuc < 1 || khuVuc > 3) {
        cout << "Vui long nhap khu vuc hop le (1, 2 hoac 3): "; cin >> khuVuc;
    }
    cout << "Nhap khoi xet tuyen (A00, A01, B00, B01, C00): "; cin >> khoiXetTuyen;
    while (khoiXetTuyen != "A00" && khoiXetTuyen != "A01" && khoiXetTuyen != "B00" && khoiXetTuyen != "B01" && khoiXetTuyen != "C00") {
        cout << "Khoi nganh xet tuyen khong ho le.Vui long nhap lai (A00, A01, B00, B01, C00): "; cin >> khoiXetTuyen;
    }

    cout << "Nhap diem Toan: "; 
    cin >> toan;
    while (toan < 0 || toan > 10) {
        cout << "Diem Toan khong hop le. Vui long nhap lai (0-10): "; 
        cin >> toan;
    }

    cout << "Nhap diem Van: "; 
    cin >> van;
    while (van < 0 || van > 10) {
        cout << "Diem Van khong hop le. Vui long nhap lai (0-10): "; 
        cin >> van;
    }

    cout << "Nhap diem Anh: "; 
    cin >> anh;
    while (anh < 0 || anh > 10) {
        cout << "Diem Anh khong hop le. Vui long nhap lai (0-10): "; 
        cin >> anh;
    }

    if (khoiXetTuyen == "A00" || khoiXetTuyen == "A01") {
        cout << "Nhap diem Ly: "; 
        cin >> mon1;
        while (mon1 < 0 || mon1 > 10) {
            cout << "Diem Ly khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon1;
        } 
        cout << "Nhap diem Hoa: "; 
        cin >> mon2;
        while (mon2 < 0 || mon2 > 10) {
            cout << "Diem Hoa khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon2;
        }
    }
    else if (khoiXetTuyen == "B00" || khoiXetTuyen == "B01") {
        cout << "Nhap diem Hoa: "; 
        cin >> mon1;
        while (mon1 < 0 || mon1 > 10) {
            cout << "Diem Hoa khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon1;
        }
        cout << "Nhap diem Sinh: "; 
        cin >> mon2;
        while (mon2 < 0 || mon2 > 10) {
            cout << "Diem Sinh khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon2;
        }
        if (khoiXetTuyen == "B01") {
            cout << "Nhap diem Su: "; 
            cin >> mon3;
            while (mon3 < 0 || mon3 > 10) {
                cout << "Diem Su khong hop le. Vui long nhap lai (0-10): "; 
                cin >> mon3;
            }
        }
    }
    else if (khoiXetTuyen == "C00") {
        cout << "Nhap diem Su: "; 
        cin >> mon1;
        while (mon1 < 0 || mon1 > 10) {
            cout << "Diem Su khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon1;
        }
        cout << "Nhap diem Dia: "; 
        cin >> mon2;
        while (mon2 < 0 || mon2 > 10) {
            cout << "Diem Dia khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon2;
        }
        cout << "Nhap diem GDCD: "; 
        cin >> mon3;
        while (mon3 < 0 || mon3 > 10) {
            cout << "Diem GDCD khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon3;
        }
    }
    cout << "Nhap so luong nganh muon xet tuyen (toi da 5): "; cin >> soNganh;
    while (soNganh < 1 || soNganh > 5) {
        cout << "Vui long nhap so nganh tu 1 den 5: "; cin >> soNganh;
    }

    cout << "Nhap cac nganh xet tuyen (CNTT, DTVT, KeToan, QTKD, Logistics):" << endl;
    for (int i = 0; i < soNganh; i++) {
        cout << "Nganh " << i + 1 << ": "; cin >> nganhXetTuyen[i];
    }

    ThiSinh* ts = new ThiSinh(sbd, hoTen, gioiTinh, khuVuc, toan, van, anh, mon1, mon2, mon3, nganhXetTuyen, soNganh, khoiXetTuyen);
    ts->next = head;
    head = ts;
    size++;
    cout << "Them thi sinh thanh cong!" << endl;
}

void DanhSachThiSinh::themThiSinhVaoCuoi() {
    int sbd, khuVuc, soNganh;
    string hoTen, gioiTinh, khoiXetTuyen;
    float toan, van, anh, mon1, mon2, mon3 = 0;
    string nganhXetTuyen[5];
    cout << "Nhap so bao danh: "; cin >> sbd;
    if (kiemTraTonTai(sbd)) {
        cout << "Thi sinh da ton tai!" << endl;
        return;
    }
    cout << "Nhap ho va ten: "; cin.ignore(); getline(cin, hoTen);
    cout << "Nhap gioi tinh (Nam/Nu): "; getline(cin, gioiTinh);
    cout << "Nhap khu vuc (1/2/3): "; cin >> khuVuc;
    while (khuVuc < 1 || khuVuc > 3) {
        cout << "Vui long nhap khu vuc hop le (1, 2 hoac 3): "; cin >> khuVuc;
    }
    cout << "Nhap khoi xet tuyen (A00, A01, B00, B01, C00): "; cin >> khoiXetTuyen;
    while (khoiXetTuyen != "A00" && khoiXetTuyen != "A01" && khoiXetTuyen != "B00" && khoiXetTuyen != "B01" && khoiXetTuyen != "C00") {
        cout << "Khoi nganh xet tuyen khong ho le.Vui long nhap lai(A00, A01, B00, B01, C00): "; cin >> khoiXetTuyen;
    }
   cout << "Nhap diem Toan: "; 
    cin >> toan;
    while (toan < 0 || toan > 10) {
        cout << "Diem Toan khong hop le. Vui long nhap lai (0-10): "; 
        cin >> toan;
    }
    cout << "Nhap diem Van: "; 
    cin >> van;
    while (van < 0 || van > 10) {
        cout << "Diem Van khong hop le. Vui long nhap lai (0-10): "; 
        cin >> van;
    }
    cout << "Nhap diem Anh: "; 
    cin >> anh;
    while (anh < 0 || anh > 10) {
        cout << "Diem Anh khong hop le. Vui long nhap lai (0-10): "; 
        cin >> anh;
    }
    if (khoiXetTuyen == "A00" || khoiXetTuyen == "A01") {
        cout << "Nhap diem Ly: "; 
        cin >> mon1;
        while (mon1 < 0 || mon1 > 10) {
            cout << "Diem Ly khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon1;
        }
        cout << "Nhap diem Hoa: "; 
        cin >> mon2;
        while (mon2 < 0 || mon2 > 10) {
            cout << "Diem Hoa khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon2;
        }
    }
    else if (khoiXetTuyen == "B00" || khoiXetTuyen == "B01") {
        cout << "Nhap diem Hoa: "; 
        cin >> mon1;
        while (mon1 < 0 || mon1 > 10) {
            cout << "Diem Hoa khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon1;
        }
        cout << "Nhap diem Sinh: "; 
        cin >> mon2;
        while (mon2 < 0 || mon2 > 10) {
            cout << "Diem Sinh khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon2;
        }
        if (khoiXetTuyen == "B01") {
            cout << "Nhap diem Su: "; 
            cin >> mon3;
            while (mon3 < 0 || mon3 > 10) {
                cout << "Diem Su khong hop le. Vui long nhap lai (0-10): "; 
                cin >> mon3;
            }
        }
    }
    else if (khoiXetTuyen == "C00") {
        cout << "Nhap diem Su: "; 
        cin >> mon1;
        while (mon1 < 0 || mon1 > 10) {
            cout << "Diem Su khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon1;
        }

        cout << "Nhap diem Dia: "; 
        cin >> mon2;
        while (mon2 < 0 || mon2 > 10) {
            cout << "Diem Dia khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon2;
        }
        cout << "Nhap diem GDCD: "; 
        cin >> mon3;
        while (mon3 < 0 || mon3 > 10) {
            cout << "Diem GDCD khong hop le. Vui long nhap lai (0-10): "; 
            cin >> mon3;
        }
    }
    cout << "Nhap so luong nganh muon xet tuyen (toi da 5): "; cin >> soNganh;
    while (soNganh < 1 || soNganh > 5) {
        cout << "Vui long nhap so nganh tu 1 den 5: "; cin >> soNganh;
    }
    cout << "Nhap cac nganh xet tuyen (CNTT, DTVT, KeToan, QTKD, Logistics):" << endl;
    for (int i = 0; i < soNganh; i++) {
        cout << "Nganh " << i + 1 << ": "; cin >> nganhXetTuyen[i];
    }
    ThiSinh* ts = new ThiSinh(sbd, hoTen, gioiTinh, khuVuc, toan, van, anh, mon1, mon2, mon3, nganhXetTuyen, soNganh, khoiXetTuyen);
    if (!head) {
        head = ts;
    }
    else {
        ThiSinh* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = ts;
    }
    size++;
    cout << "Them thi sinh vao cuoi thanh cong!" << endl;
}
void DanhSachThiSinh::themNhieuThiSinh(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho thi sinh thu " << (i + 1) << ":\n";
        themThiSinh();
    }
}
void DanhSachThiSinh::xoaThiSinhDau() {
    if (head == NULL) {
        cout << "Danh sach rong, khong co thi sinh de xoa!" << endl;
        return;
    }
    ThiSinh* temp = head;    
    head = head->next;       
    delete temp;             
    size--;                
    cout << "Xoa thi sinh dau danh sach thanh cong!" << endl;
}
void DanhSachThiSinh::xoaThiSinhCuoi() {
    if (head == NULL) {
        cout << "Danh sach rong, khong co thi sinh de xoa!" << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;         
        head = NULL;         
    }
    else {
        ThiSinh* temp = head;
        while (temp->next && temp->next->next) { 
            temp = temp->next;
        }
        delete temp->next;   
        temp->next = NULL;   
    }
    size--;      
    cout << "Xoa thi sinh cuoi danh sach thanh cong!" << endl;
}
void DanhSachThiSinh::suaThongTin(int sbd) {
    ThiSinh* hienTai = head;
    while (hienTai) {
        if (hienTai->sbd == sbd) {
        
            cout << "Nhap ho va ten moi: "; cin.ignore(); getline(cin, hienTai->hoTen);
            cout << "Nhap gioi tinh (Nam/Nu): "; getline(cin, hienTai->gioiTinh);
            cout << "Nhap khu vuc moi (1/2/3): "; cin >> hienTai->khuVuc;
            while (hienTai->khuVuc < 1 || hienTai->khuVuc > 3) {
                cout << "Vui long nhap khu vuc hop le (1, 2 hoac 3): "; cin >> hienTai->khuVuc;
            }
            cout << "Nhap khoi xet tuyen moi (A00, A01, B00, B01, C00): "; cin >> hienTai->khoiXetTuyen;
            while (hienTai->khoiXetTuyen != "A00" && hienTai->khoiXetTuyen != "A01" && hienTai->khoiXetTuyen != "B00" && hienTai->khoiXetTuyen != "B01" && hienTai->khoiXetTuyen != "C00") {
                cout << "Khoi nganh xet tuyen khong ho le.Vui long nhap lai(A00, A01, B00, B01, C00): "; cin >> hienTai->khoiXetTuyen;
            }
            cout << "Nhap diem Toan moi: "; 
            cin >> hienTai->toan;
            while (hienTai->toan < 0 || hienTai->toan > 10) {
                cout << "Diem Toan khong hop le. Vui long nhap lai (0-10): "; 
                cin >> hienTai->toan;
            }
            cout << "Nhap diem Van moi: "; 
            cin >> hienTai->van;
            while (hienTai->van < 0 || hienTai->van > 10) {
                cout << "Diem Van khong hop le. Vui long nhap lai (0-10): "; 
                cin >> hienTai->van;
            }
            cout << "Nhap diem Anh moi: "; 
            cin >> hienTai->anh;
            while (hienTai->anh < 0 || hienTai->anh > 10) {
                cout << "Diem Anh khong hop le. Vui long nhap lai (0-10): "; 
                cin >> hienTai->anh;
            }
            if (hienTai->khoiXetTuyen == "A00" || hienTai->khoiXetTuyen == "A01") {
                cout << "Nhap diem Ly moi: "; 
                cin >> hienTai->mon1;
                while (hienTai->mon1 < 0 || hienTai->mon1 > 10) {
                    cout << "Diem Ly khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon1;
                }
                
                cout << "Nhap diem Hoa moi: "; 
                cin >> hienTai->mon2;
                while (hienTai->mon2 < 0 || hienTai->mon2 > 10) {
                    cout << "Diem Hoa khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon2;
                }
            }
            else if (hienTai->khoiXetTuyen == "B00" || hienTai->khoiXetTuyen == "B01") {
                cout << "Nhap diem Hoa moi: "; 
                cin >> hienTai->mon1;
                while (hienTai->mon1 < 0 || hienTai->mon1 > 10) {
                    cout << "Diem Hoa khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon1;
                }

                cout << "Nhap diem Sinh moi: "; 
                cin >> hienTai->mon2;
                while (hienTai->mon2 < 0 || hienTai->mon2 > 10) {
                    cout << "Diem Sinh khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon2;
                }

                if (hienTai->khoiXetTuyen == "B01") {
                    cout << "Nhap diem Su moi: "; 
                    cin >> hienTai->mon3;
                    while (hienTai->mon3 < 0 || hienTai->mon3 > 10) {
                        cout << "Diem Su khong hop le. Vui long nhap lai (0-10): "; 
                        cin >> hienTai->mon3;
                    }
                }
            }
            else if (hienTai->khoiXetTuyen == "C00") {
                cout << "Nhap diem Su moi: "; 
                cin >> hienTai->mon1;
                while (hienTai->mon1 < 0 || hienTai->mon1 > 10) {
                    cout << "Diem Su khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon1;
                }

                cout << "Nhap diem Dia moi: "; 
                cin >> hienTai->mon2;
                while (hienTai->mon2 < 0 || hienTai->mon2 > 10) {
                    cout << "Diem Dia khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon2;
                }

                cout << "Nhap diem GDCD moi: "; 
                cin >> hienTai->mon3;
                while (hienTai->mon3 < 0 || hienTai->mon3 > 10) {
                    cout << "Diem GDCD khong hop le. Vui long nhap lai (0-10): "; 
                    cin >> hienTai->mon3;
                }
            }

            hienTai->tinhTongDiem();
            cout << "Cap nhat thong tin thanh cong!" << endl;
            return;
        }
        hienTai = hienTai->next;
    }
    cout << "Thi sinh khong tim thay!" << endl;
}

void DanhSachThiSinh::xoaThiSinh(int sbd) {
    ThiSinh* hienTai = head;
    ThiSinh* truoc = NULL;

    while (hienTai) {
        if (hienTai->sbd == sbd) {
            if (truoc) {
                truoc->next = hienTai->next;
            }
            else {
                head = hienTai->next;
            }
            delete hienTai;
            size--;
            cout << "Xoa thi sinh thanh cong!" << endl;
            return;
        }
        truoc = hienTai;
        hienTai = hienTai->next;
    }
    cout << "Thi sinh khong tim thay!" << endl;
}

void DanhSachThiSinh::inDanhSach() {
    ThiSinh* hienTai = head;
    if (!hienTai) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    cout << "Danh sach thi sinh:\n";
    while (hienTai) {
    	cout << "----------------------------------------------------\n";
        cout << "| SBD:" << hienTai->sbd << "| Ho Ten:" << hienTai->hoTen
            << "|Tong Diem:" << fixed << setprecision(2) << hienTai->tongDiem << "|"<< endl;
        cout << "----------------------------------------------------\n"   ;
        hienTai = hienTai->next;
    }
}

void DanhSachThiSinh::lietKeThiSinhDau() {
    ThiSinh* hienTai = head;
    cout << "Danh sach thi sinh dau cac nganh:\n";
    while (hienTai) {
        for (int i = 0; i < hienTai->soNganh; i++) {
            string nganh = hienTai->nganhXetTuyen[i];
            bool datDiem = false;
            if ((nganh == "CNTT" && hienTai->tongDiem >= 25.5 && hienTai->khoiXetTuyen == "A00") ||
                (nganh == "DTVT" && hienTai->tongDiem >= 24 && (hienTai->khoiXetTuyen == "A00" || hienTai->khoiXetTuyen == "A01")) ||
                (nganh == "KeToan" && hienTai->tongDiem >= 23 && (hienTai->khoiXetTuyen == "A00" || hienTai->khoiXetTuyen == "C00")) ||
                (nganh == "QTKD" && hienTai->tongDiem >= 23.5 && (hienTai->khoiXetTuyen == "B01" || hienTai->khoiXetTuyen == "C00")) ||
                (nganh == "Logistics" && hienTai->tongDiem >= 26 && (hienTai->khoiXetTuyen == "A00" || hienTai->khoiXetTuyen == "C00"))) {
                datDiem = true;
            }
            if (datDiem) {
                cout << "Thi sinh:" << hienTai->hoTen << " (SBD: " << hienTai->sbd << ") - Nganh: " << nganh << " - Tong diem: " << hienTai->tongDiem << endl;
            }
        }
        hienTai = hienTai->next;
    }
}

void DanhSachThiSinh::hocBong() {
    if (!head || !head->next) {
        cout << "Danh sach khong du thi sinh de xet hoc bong!" << endl;
        return;
    }
    ThiSinh* max1 = head;
    ThiSinh* max2 = NULL;
    ThiSinh* hienTai = head->next;
    while (hienTai) {
        if (hienTai->tongDiem > max1->tongDiem) {
            max2 = max1;
            max1 = hienTai;
        }
        else if (!max2 || hienTai->tongDiem > max2->tongDiem) {
            max2 = hienTai;
        }
        hienTai = hienTai->next;
    }
    cout << "2 Thi sinh co diem cao nhat duoc xet hoc bong:\n";
    cout << "1. " << max1->hoTen << " (SBD: " << max1->sbd << ") - Tong diem: " << max1->tongDiem << endl;
    if (max2) {
        cout << "2. " << max2->hoTen << " (SBD: " << max2->sbd << ") - Tong diem: " << max2->tongDiem << endl;
    }
}
void DanhSachThiSinh::xoaTatCa() {
    while (head) {
        ThiSinh* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
    cout << "Da xoa tat ca thi sinh!" << endl;
}
void DanhSachThiSinh::sapXepTheoTen() {
    if (!head || !head->next) {
        cout << "Danh sach khong du thi sinh de sap xep!" << endl;
        return;
    }

    for (ThiSinh* i = head; i != NULL; i = i->next) {
        for (ThiSinh* j = i->next; j != NULL; j = j->next) {
            if (i->hoTen > j->hoTen) {
                swap(*i, *j); 
            }
        }
    }
    cout << "Da sap xep danh sach theo sinh theo ten!" << endl;
}
void DanhSachThiSinh::docFile() {
    ifstream file("test.txt");
    if (!file) {
        cout << "Loi: Khong the mo file!" << endl;
        return;
    }

    int sbd, khuVuc, soNganh;
    string hoTen, gioiTinh, khoiXetTuyen;
    float toan, van, anh, mon1, mon2, mon3;
    string nganhXetTuyen[5];
    ThiSinh* ts = NULL;
    while (file >> sbd) {
        file.ignore(); 
        getline(file, hoTen);
        getline(file, gioiTinh);
        file >> khuVuc;
        file.ignore(); 
        getline(file, khoiXetTuyen);
        file >> toan >> van >> anh >> mon1 >> mon2 >> mon3;
        file >> soNganh;
        file.ignore();  

        for (int i = 0; i < soNganh; ++i) {
            getline(file, nganhXetTuyen[i]);
        }

        ts = new ThiSinh(sbd, hoTen, gioiTinh, khuVuc, toan, van, anh, mon1, mon2, mon3, nganhXetTuyen, soNganh, khoiXetTuyen);
        ts->next = head;
        head = ts;
        size++;
    }
    file.close(); 
    cout << "doc file thanh cong !" << endl;  
	}
int main() {
    DanhSachThiSinh ds;
    int luaChon, sbd, soLuong;
    while (true) {
    	cout << "====================MENU=================\n ";
        cout << "|1.Them thi sinh                        |\n ";
		cout << "|2.Them nhieu thi sinh                  |\n ";
		cout << "|3.them thi sinh vao cuoi danh sach     |\n ";
		cout << "|4.Xoa thong tin(SBD)                   |\n ";
		cout << "|5.Xoa thong tin dau danh sach          |\n ";
		cout << "|6.Xoa thong tin cuoi danh sach         |\n ";
		cout << "|7.Sua thong tin                        |\n ";
        cout << "|8.Sap xep theo ten                     |\n ";
		cout << "|9.In danh sach                         |\n ";
		cout << "|10.Liet ke thi sinh dau cac nganh      |\n ";
        cout << "|11.Xet hoc bong                        |\n ";
        cout << "|12.Xoa tat ca thi sinh                 |\n ";
        cout << "|13.doc file                            |\n ";
		cout << "|0. Thoat                               |\n ";
		cout << "=========================================\n";
		cout << " nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            ds.themThiSinh();
            break;
        case 2:
            cout << "Nhap so luong thi sinh muon them: ";
            cin >> soLuong;
            ds.themNhieuThiSinh(soLuong);
            break;
		case 3:
            ds.themThiSinhVaoCuoi();
            break;
        case 4:
            cout << "Nhap SBD can xoa: ";
            cin >> sbd;
            ds.xoaThiSinh(sbd);
            break;
        case 5:
            ds.xoaThiSinhDau();
            break;
        case 6:
            ds.xoaThiSinhCuoi();
            break;
        case 7:
            cout << "Nhap SBD can sua: ";
            cin >> sbd;
            ds.suaThongTin(sbd);
            break;
        case 8:
            ds.sapXepTheoTen();
            break;
        case 9:
            ds.inDanhSach();
            break;
        case 10:
            ds.lietKeThiSinhDau();
            break;
        case 11:
            ds.hocBong();
            break;
        case 12:
            ds.xoaTatCa();
            break;
        case 13: 
		    ds.docFile();
		    break;     
        case 0:
            ds.xoaTatCa();
            return 0;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    }
    return 0;
}

