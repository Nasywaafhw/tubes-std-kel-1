#include <iostream>
#include "pasien.h"

void createListPasien(listPasien &L) {
    L.first = NULL;
}

void createListRumahSakit(listRumahSakit &L) {
    L.first = NULL;
}

bool isEmptyPasien(listPasien L) {
    return L.first == NULL;
}

bool isEmptyRumahSakit(listRumahSakit L) {
    return L.first == NULL;
}

adrPasien createElmPasien(infoPasien x) {
    adrPasien p = new elmPasien;
    p->info = x;
    p->next = NULL;
    createListRumahSakit(p->data);
    return p;
}

adrRumahSakit createElmRumahSakit(infoRumahSakit x) {
    adrRumahSakit p = new elmRumahSakit;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirstPasien(listPasien &L, adrPasien p) {
    p->next = L.first;
    L.first = p;
}

void insertFirstRumahSakit(listRumahSakit &L, adrRumahSakit p) {
    p->next = L.first;
    L.first = p;
}

void insertLastPasien(listPasien &L, adrPasien p) {
    if (isEmptyPasien(L)) {
        L.first = p;
    } else {
        adrPasien last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void insertLastRumahSakit(listRumahSakit &L, adrRumahSakit p) {
    if (isEmptyRumahSakit(L)) {
        L.first = p;
    } else {
        adrRumahSakit last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void deletePasien(listPasien &L, int id) {
    adrPasien p = L.first;
    adrPasien prev = NULL;
    while (p != NULL && p->info.id != id) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Pasien not found" << endl;
    } else {
        if (prev == NULL) {
            L.first = p->next;
        } else {
            prev->next = p->next;
        }
        delete p;
    }
}

void deleteRumahSakit(listRumahSakit &L, string namaPasien) {
    adrRumahSakit p = L.first;
    adrRumahSakit prev = NULL;
    while (p != NULL && p->info.namaPasien != namaPasien) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Rumah Sakit not found" << endl;
    } else {
        if (prev == NULL) {
            L.first = p->next;
        } else {
            prev->next = p->next;
        }
        delete p;
    }
}

adrPasien searchPasien(listPasien L, int id) {
    adrPasien p = L.first;
    while (p != NULL && p->info.id != id) {
        p = p->next;
    }
    return p;
}

adrRumahSakit searchRumahSakit(listRumahSakit L, string namaPasien) {
    adrRumahSakit p = L.first;
    while (p != NULL && p->info.namaPasien != namaPasien) {
        p = p->next;
    }
    return p;
}

int countPasien(listPasien L) {
    int count = 0;
    adrPasien p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int countRumahSakit(listRumahSakit L) {
    int count = 0;
    adrRumahSakit p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void showAllPasien(listPasien L) {
    adrPasien p ;
    if (first(L) == NULL){
        cout << "Tidak ada data" << endl;
    } else {
        cout << "===== Data Pasien =====" << endl;
        p = first(L);
        while (p != NULL) {
            cout << "Nama   : " << info(p).nama << endl;
            cout << "ID    : " << info(p).id << endl;
            cout << "Jenis kelamin(P/L) : " << info(p).jenisKelamin << endl;
            cout << "Penyakit   : " << info(p).penyakit << endl;
            cout << endl;
            p = next(p);
        }
        cout << "------------------------------------" << endl;
    }
}

void showAllRumahSakit(listRumahSakit L) {
    adrRumahSakit p;
    if (first(L) == NULL) {
        cout << "Tidak ada data" << endl;
    } else {
        p = first(L);
        while (p != NULL) {
            cout << "Nama Pasien       : " << info(p).namaPasien << endl;
            cout << "ID          : " << info(p).ID << endl;
            cout << "Tanggal Masuk  : " << info(p).tanggalMasuk << endl;
            cout << "Tanggal Keluar   : " << info(p).tanggalKeluar << endl;
            cout << "Diagnosa   : " << info(p).diagnosa << endl;
            cout << endl;
            p = next(p);
        }
        cout << "------------------------------------" << endl;
    }
}
