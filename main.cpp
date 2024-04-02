#include "linkedList.h"

int main () {
    kota *first = NULL;
    insertAwalKota("Bandung", &first);
    insertAwalKota("Cimahi", &first);
    printListKota(&first);
}