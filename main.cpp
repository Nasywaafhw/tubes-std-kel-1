#include <iostream>
#include "pasien.h"

int main() {
    listPasien LP;
    listRumahSakit LR;
    createListPasien(LP);
    createListRumahSakit(LR);
    int choice;
    do {
        cout << "========== DATA PASIEN ==========" << endl;
        cout << "1. Insert Data Pasien" << endl;
        cout << "2. Insert Data Rumah Sakit" << endl;
        cout << "3. Search Data Pasien" << endl;
        cout << "4. Search Data Rumah Sakit" << endl;
        cout << "5. Delete Data Pasien" << endl;
        cout << "6. Delete Data Rumah Sakit" << endl;
        cout << "7. Show Jumlah Data Pasien" << endl;
        cout << "8. Show Jumlah Data Rumah Sakit" << endl;
        cout << "9. Show All Data Pasien" << endl;
        cout << "10. Show All Data Rumah Sakit" << endl;
        cout << "11. Exit" << endl;
        cout << "===============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                infoPasien x;
                cout << "Nama Pasien : ";
                cin >> x.nama ;
                cout << "ID Pasien : ";
                cin >> x.id ;
                cout << "Jenis Kelamin Pasien(P/L) : ";
                cin >> x.jenisKelamin ;
                cout << "Penyakit Pasien : ";
                cin >> x.penyakit ;
                adrPasien p = createElmPasien(x);
                insertLastPasien(LP, p);
                break;
            }
            case 2: {
                infoRumahSakit x;
                cout << " ID Pasien : ";
                cin >> x.ID ;
                cout << " Nama Pasien : ";
                cin >> x.namaPasien ;
                cout << " Tanggal Masuk : ";
                cin >> x.tanggalMasuk ;
                cout << " Tanggal Keluar : ";
                cin >> x.tanggalKeluar ;
                cout << " Diagnosa : ";
                cin >> x.diagnosa ;
                adrRumahSakit p = createElmRumahSakit(x);
                insertLastRumahSakit(LR, p);
                break;
            }
            case 3: {
                int id;
                cout << "ID Pasien yang ingin di cari: ";
                cin >> id;
                adrPasien p = searchPasien(LP, id);
                if (p != NULL) {
                    cout << "Pasien found: " << p->info.nama << endl;
                } else {
                    cout << "Pasien not found" << endl;
                }
                break;
            }
            case 4: {
                string namaPasien;
                cout << "Nama Pasien di Rumah Sakit: ";
                cin >> namaPasien;
                adrRumahSakit p = searchRumahSakit(LR, namaPasien);
                if (p != NULL) {
                    cout << "Rumah Sakit found: " << p->info.namaPasien << endl;
                } else {
                    cout << "Rumah Sakit not found" << endl;
                }
                break;
            }
            case 5: {
                int id;
                cout << "ID Pasien yang ingin di hapus: ";
                cin >> id;
                deletePasien(LP, id);
                break;
            }
            case 6: {
                string namaPasien;
                cout << "Nama pasien di Rumah Sakit: ";
                cin >> namaPasien;
                deleteRumahSakit(LR, namaPasien);
                break;
            }
            case 7: {
                int count = countPasien(LP);
                cout << "Total Pasien: " << count << endl;
                break;
            }
            case 8: {
                int count = countRumahSakit(LR);
                cout << "Total Rumah Sakit: " << count << endl;
                break;
            }
            case 9: {
                showAllPasien(LP);
                break;
            }
            case 10: {
                showAllRumahSakit(LR);
                break;
            }
            case 11: {
                // Exit
                cout << "Exiting the program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 11." << endl;
            }
        }
    } while (choice != 11);
    return 0;
}
