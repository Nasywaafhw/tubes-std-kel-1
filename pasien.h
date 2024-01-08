#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include <iostream>
#include <string>
#define Nil NULL
#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)
#define last(L) ((L).last)
using namespace std;

typedef struct elmPasien *adrPasien;
typedef struct elmRumahSakit *adrRumahSakit;

struct listPasien {
    adrPasien first;
};

struct listRumahSakit {
    adrRumahSakit first;
};

struct infoPasien {
    int id;
    string nama;
    string jenisKelamin;
    string penyakit;
};
struct infoRumahSakit {
    int ID;
    string namaPasien;
    string tanggalMasuk;
    string tanggalKeluar;
    string diagnosa;
};

struct elmPasien {
    infoPasien info;
    adrPasien next;
    listRumahSakit data;
};

struct elmRumahSakit {
    infoRumahSakit info;
    adrRumahSakit next;
};
void createListPasien(listPasien &L);
void createListRumahSakit(listRumahSakit &L);
bool isEmptyPasien(listPasien L);
bool isEmptyRumahSakit(listRumahSakit L);
adrPasien createElmPasien(infoPasien x);
adrRumahSakit createElmRumahSakit(infoRumahSakit x);
void insertFirstPasien(listPasien &L, adrPasien p);
void insertFirstRumahSakit(listRumahSakit &L, adrRumahSakit p);
void insertLastPasien(listPasien &L, adrPasien p);
void insertLastRumahSakit(listRumahSakit &L, adrRumahSakit p);
void deletePasien(listPasien &L, int id);
void deleteRumahSakit(listRumahSakit &L, string namaPasien);
adrPasien searchPasien(listPasien L, int id);
adrRumahSakit searchRumahSakit(listRumahSakit L, string namaPasien);
int countPasien(listPasien L);
int countRumahSakit(listRumahSakit L);
void showAllPasien(listPasien L);
void showAllRumahSakit(listRumahSakit L);

#endif // PASIEN_H_INCLUDED
