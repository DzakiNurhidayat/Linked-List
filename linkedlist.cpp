#include "linkedList.h"


void cekAlokasiKota (char nilai[], kota **newNode) {
    *newNode = (kota *) malloc(sizeof(kota));
    if (*newNode == NULL) {
        printf("Memory Sudah Full\n");
    } else {
        strcpy((*newNode)->info, nilai);
        (*newNode)->nk = NULL;
    }
}

void cekAlokasiAnggota (char nilai[], infotype usia, anggota **newNode) {
    *newNode = (anggota *) malloc(sizeof(anggota));
    if (*newNode == NULL) {
        printf("Memory Sudah Full\n");
    } else {
        strcpy((*newNode)->info, nilai);
        (*newNode)->usia = usia;
        (*newNode)->next = NULL;
    }
}

void insertAwalKota (char nilai[], kota **first) {
    kota *newNode;
    cekAlokasiKota(nilai, &newNode);
    if (*first == NULL) {
        *first = newNode;
    } else {
        newNode->nk = *first;
    }
    *first = newNode;
    newNode->np = NULL;
}

void insertAkhirKota (char nilai[], kota **first) {
    kota *newNode, *temp;
    cekAlokasiKota(nilai, &newNode);
    if (*first == NULL) {
        *first = newNode;
    } else {
        temp = *first;
        while (temp->nk != NULL)
        {
            temp = temp->nk;
        }
        temp->nk = newNode;
        
    }
    newNode->np = NULL;
}

void printListKota (kota **first) {
    kota *temp;
    int i = 1;
    if (temp != NULL)
    {
        while (temp->nk != NULL)
        {
            printf("%d. %s\n", i, temp->info);
            temp = temp->nk;
            i++;
        }
        printf("%d. %s\n", i, temp->info);
    }
    else
    {
        printf("List Kota kosong\n");
    }
}