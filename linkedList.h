/*----------------------------------------------------------------------------*/
/* Dibuat oleh : Muhammad Dzaki Nurhidayat dan Muhammad Fachry Khariansyah */
/* Dengan NIM  : 231511083 dan 231511084*/
/* Deskripsi   : ADT Non Restricted Single Linked List */
/* Tanggal     : 02-04-2024 */
/*----------------------------------------------------------------------------*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int infotype; // Untuk variabel lokal usia

typedef struct kota {
    char info[100]; // Nama Kota
    struct kota *nk; // Pointer yang menunjuk node Kota
    struct anggota *np; // Pointer yang menunjuk node Anggota
} kota;

typedef struct anggota {
    char info[100]; // Nama Anggota
    infotype usia; // Usia Anggota
    struct anggota *next; // Pointer yang menunjuk node Anggota
} anggota;

// Alokasi Memori
void cekAlokasiKota(char nilai[], kota **newNode); // Alokasi untuk Node Kota
void cekAlokasiAnggota(char nilai[], infotype usia, anggota **newNode); // Alokasi untuk Node Anggota

// Insert Kota
// Karena sudah menggunakan insert secara terurut, maka insertTengah dan Akhir sudah tidak diperlukan
void insertAwalKota(char nilai[], kota **first);
void insertKota(char nilai[], kota **first);
// void insertAkhirKota(char nilai[], kota **first);
// void insertTengahKota (char nilai[], char cari[], kota **first);

// Insert Anggota
void insertAwalAnggota (char nilai[], infotype usia, kota *cariKota); /* Melakukan insert pada anggota dengan metode insertAwal */

// Delete Anggota
char* deleteAnggota (char nodeHapus[], kota *cariKota); /* Melakukan delete pada anggota sesuai nilai yang dimasukkan atau dapat disebut juga deleteTengah */

// Print List
bool printListKota (kota *first); /* Melakukan print pada setiap kota yang sudah ada pada program */ 
bool printListAnggota (kota *cariKota); /* Melakukan print pada data anggota pada satu kota yang sudah dipilih sebelumnya */ 

// Searching
kota* searchingKota(char cari[], kota *first); /* Melakukan pencarian apakah kota ada pada linked list, modul ini sangat penting karena akan digunakan untuk mencari
                                                kota yang akan diterapkan ketika melakukan print, insert, dan delete anggota */ 
anggota* searchingAnggota (char cari[], kota *cariKota); /* Melakukan pencarian apakah anggota terdapat pada suatu kota */ 
bool cariAnggota (char cari[], kota *first); /* Merupakan pencarian yang merangkap juga dengan print, ini akan mencari anggota pada setiap kota yang ada. 
                                                Jika terdapat pada kota tersebut maka akan melakukan print terhadap kota tersebut */ 

// Jumlah Kota dan Anggota
int jumlahKota (kota *first);
int jumlahAnggota (kota *cariKota);
int jumlahTotal (kota *first);

// Umur

#endif /* LINKEDLIST_H */