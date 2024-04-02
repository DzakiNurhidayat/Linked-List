#include "linkedList.h"

void cekAlokasiKota (char nilai[], kota **newNode) {
    *newNode = (kota *) malloc(sizeof(kota));
    if (*newNode == NULL) {
        printf("Memory Sudah Full\n");
    } else {
        strcpy((*newNode)->info, nilai);
        (*newNode)->nk = NULL;
        (*newNode)->np = NULL;
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
}

kota* searchingKota(char cari[], kota *first) {
    kota *temp;
    temp = first;
    while (temp != NULL) {
        if (strcmp(temp->info, cari) == 0) {
            return temp;
        } else {
            temp = temp->nk;
        }
    }
    return NULL;
}

void insertTengahKota (char nilai[], char cari[], kota **first) {
    kota *newNode, *temp;
    cekAlokasiKota(nilai, &newNode);
    if (*first == NULL) {
        *first = newNode;
    } else {
        temp = searchingKota(cari, *first);
        if (temp != NULL)
        {
            newNode->nk = temp->nk;
            temp->nk = newNode;
        }
        else
        {
            printf("Nilai yang dicari tidak ada \n");
        }
    }
}

void printListKota (kota **first) {
    kota *temp;
    int i = 1;
    temp = *first;
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