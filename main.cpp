#include "linkedList.h"

int main () {
    kota *first = NULL;
    insertAwalKota("Bandung", &first);
    insertAwalKota("Cimahi", &first);
    insertAkhirKota("Kudus", &first);
    insertAwalKota("Jakarta", &first);
    insertTengahKota("Surabaya", "Jakarta", &first);
    printListKota(&first);
}