#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int infotype;

typedef struct kota {
    char info[100]; // Nama Kota
    struct kota *nk; // Pointer untuk node Kota
    struct anggota *np; // Pointer untuk node Anggota
} kota;

typedef struct anggota {
    char info[100];
    infotype usia;
    struct anggota *next;
} anggota;

// Alokasi Memori
void cekAlokasiKota(char nilai[], kota **newNode); // Alokasi untuk Node Kota
void cekAlokasiAnggota(char nilai[], infotype usia, anggota **newNode); // Alokasi untuk Node Anggota

// Insert Kota
void insertAwalKota(char nilai[], kota **first);
void insertAkhirKota(char nilai[], kota **first);
void insertTengahKota (char nilai[], char cari[], kota **first);

// Insert Anggota
void insertAwalAnggota (char nilai[], infotype usia, kota *cariKota);

// Delete Anggota
char* deleteAnggota (char nodeHapus[], kota *cariKota);

// Print List
void printListKota (kota *first);
void printListAnggota (kota *cariKota);

// Searching
kota* searchingKota(char cari[], kota *first);
anggota* searchingAnggota (char cari[], kota *cariKota);


#endif /* LINKEDLIST_H */