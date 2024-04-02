#include "linkedList.h"

int main () {
    kota *temp, *temp2;
    kota *first = NULL;
    insertAwalKota("Bandung", &first);
    insertAwalKota("Cimahi", &first);
    insertAkhirKota("Kudus", &first);
    insertAwalKota("Jakarta", &first);
    insertTengahKota("Surabaya", "Jakarta", &first);
    printListKota(first);
    temp = searchingKota("Bandung", first);
    temp = searchingKota("Kudus", first);
    insertAwalAnggota("Dzaki", 20, temp);
    insertAwalAnggota("Ahmad", 17, temp);
    insertAwalAnggota("Fachry", 17, temp);
    printListAnggota(temp);
}