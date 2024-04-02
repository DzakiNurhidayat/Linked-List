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

anggota* searchingAnggota (char cari[], kota *cariKota) {
    anggota *temp;
    temp = cariKota->np;
    while (temp != NULL)
    {
        if (strcmp(temp->info, cari) == 0) {
            return temp;
        } else {
            temp = temp->next;
        }
    }
    return NULL;
}

void insertAwalAnggota (char nilai[], infotype usia, kota *cariKota) {
    anggota *newNode, *temp;
    cekAlokasiAnggota(nilai, usia, &newNode);
    if (cariKota->np == NULL) {
        cariKota->np = newNode;
    } else {
        temp = cariKota->np;
        newNode->next = temp;
        cariKota->np = newNode;
    }
}

char* deleteAnggota (char nodeHapus[], kota *cariKota) {
    anggota *temp, *nodeDelete;
    char *nilai = (char*)malloc(sizeof(char) * 100);
    nodeDelete = searchingAnggota(nodeHapus, cariKota);
    if (nodeDelete == NULL)
    {
        printf("Node yang akan dihapus tidak ditemukan\n");
        return NULL;
    }
    else {
        if (cariKota->np == nodeDelete) {
            cariKota->np = nodeDelete->next;
        }
        else {
            temp = cariKota->np;
            while (temp != NULL && temp->next != nodeDelete)
            {
                temp = temp->next;
            }
            if (temp != NULL)
            {
                temp->next = nodeDelete->next;
            }
        }
        strcpy(nilai, nodeDelete->info);
        nodeDelete->next = NULL;
        free(nodeDelete);
    }
    return nilai;
}

void printListKota (kota *first) {
    kota *temp;
    int i = 1;
    temp = first;
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

void printListAnggota (kota *cariKota) {
    anggota *temp;
    temp = cariKota->np;
    printf("%s -> ", cariKota->info);
    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            printf("%s -> ", temp->info);
            temp = temp->next;
        }
        printf("%s -> ", temp->info);
    }
    printf("NULL\n");
}