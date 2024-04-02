#include "linkedList.h"

int main () {
    kota *temp;
    char nilai[100];
    kota *first = NULL;
    insertAwalKota("Bandung", &first);
    insertAwalKota("Cimahi", &first);
    insertAkhirKota("Kudus", &first);
    insertAwalKota("Jakarta", &first);
    insertTengahKota("Surabaya", "Jakarta", &first);
    printListKota(first);
    
    temp = searchingKota("Bandung", first);
    insertAwalAnggota("Dzaki", 20, temp);
    insertAwalAnggota("Ahmad", 17, temp);
    insertAwalAnggota("Restu", 17, temp);
    
    temp = searchingKota("Kudus", first);
    insertAwalAnggota("Fachry", 17, temp);
    printListAnggota(temp);

    temp = searchingKota("Bandung", first);
    printListAnggota(temp);
    deleteAnggota ("Restu", temp);
    printListAnggota(temp);
}