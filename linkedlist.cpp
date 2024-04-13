/*----------------------------------------------------------------------------*/
/* Dibuat oleh : Muhammad Dzaki Nurhidayat dan Muhammad Fachry Khariansyah */
/* Dengan NIM  : 231511083 dan 231511084*/
/* Deskripsi   : ADT Non Restricted Single Linked List */
/* Tanggal     : 02-04-2024 */
/*----------------------------------------------------------------------------*/

#include "linkedList.h"


// Dibuat Oleh M. Dzaki
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


// Dibuat Oleh M. Dzaki
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

// Dibuat Oleh M. Fachry
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

// Dibuat Oleh M. Fachry
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

// Dibuat Oleh M. Dzaki
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

// Dibuat Oleh M. Fachry
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

// Dibuat Oleh M. Fachry
// Ini merupakan Modul Insert yang sudah menerapkan ascending ordering
void insertKota(char nilai[], kota **first) {
    kota *newNode, *temp, *temp2;
    cekAlokasiKota(nilai, &newNode);
    
    if (*first == NULL || strcmp((*first)->info, nilai) >= 0) {
        insertAwalKota(nilai, first);
    } else {
        temp = *first;
        while (temp != NULL && strcmp(temp->info, nilai) < 0) {
            temp2 = temp;
            temp = temp->nk;
        }
        newNode->nk = temp;
        temp2->nk = newNode;
    }
}

// Dibuat Oleh M. Dzaki
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

// Dibuat Oleh M. Dzaki
bool cariAnggota (char cari[], kota *first) {
    kota *temp;
    anggota *temp2;
    temp = first;
    int i = 1;
    bool cek = false;
    printf("Data %s Ditemukan : ", cari);
    while (temp != NULL) {
        temp2 = searchingAnggota (cari, temp);
        if (temp2 != NULL) {
            printf("\n%d. %s", i, temp->info);
            cek = true;
            i++;
        }
        temp = temp->nk;
    }
    return cek;
}

// Dibuat Oleh M. Fachry
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

// Dibuat Oleh M. Dzaki
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

// Dibuat Oleh M. Dzaki
bool printListKota (kota *first) {
    kota *temp;
    bool cek = false;
    int i = 1;
    temp = first;
    if (temp != NULL)
    {
        cek = true;
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
    return cek;
}

// Dibuat Oleh M. Dzaki
bool printListAnggota (kota *cariKota) {
    anggota *temp;
    bool cek = false;
    temp = cariKota->np;
    printf("%s = ", cariKota->info);
    if (temp != NULL)
    {
        cek = true;
        while (temp->next != NULL)
        {
            printf("%s -> ", temp->info);
            temp = temp->next;
        }
        printf("%s -> ", temp->info);
    }
    printf("NULL\n");
    return cek;
}

// Dibuat Oleh M. Fachry
int jumlahKota (kota *first)
{
    kota *temp;
    int jumlahKota;
    temp = first;
    jumlahKota = 0;
    while (temp != NULL)
    {
        temp = temp->nk;
        jumlahKota++;
    }
    return jumlahKota;
}

int jumlahAnggota (kota *cariKota) {
    anggota *temp;
    int jumlah;
    temp = cariKota->np;
    jumlah = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        jumlah++;
    }
    return jumlah;
}

int jumlahTotal (kota *first) {
    kota *temp;
    int total;
    temp = first;
    total = 0;
    while (temp != NULL)
    {
        total = total + jumlahAnggota(temp);
        temp = temp->nk;
    }
    return total;
}

// anggota* cekUmur (kota *cariKota) {
//     anggota *temp, *anggotaMuda, *anggotaTua;
//     int umurMuda, umurTua;
    
//     temp = cariKota->np;
//     anggotaMuda, anggotaTua = temp;
//     umurMuda, umurTua = temp->usia;
//     while (temp != NULL)
//     {
//         if (/* condition */)
//         {
//             /* code */
//         }
        
//     }
    
// }

// anggota* umurTermuda (kota *cariKota) {
//     anggota *temp;
//     int umurMuda;
//     temp = cariKota->np;
//     umurMuda = temp->usia;
//     while (temp != NULL)
//     {
//         if (umurMuda > temp->usia)
//         {
//             umurMuda = temp->usia;
//         }
//         temp = temp->next;
//     }
//     return umurMuda;
// }

// anggota* umurTertua (kota *cariKota) {
//     anggota *temp;
//     int umurTua;
//     temp = cariKota->np;
//     umurTua = temp->usia;
//     while (temp != NULL)
//     {
//         if (umurTua < temp->usia)
//         {
//             umurTua = temp->usia;
//         }
//         temp = temp->next;
//     }
//     return umurTua;
// }

// void infoUmurSemua (kota *first) {
//     kota *temp;
//     anggota *temp2;
//     int umurMuda, umurTua;
//     temp = first;
//     while (temp != NULL)
//     {
//         if (umurMuda > umurTermuda(temp))
//         {
//             umurMuda = umurTermuda(temp);
//         }
//         if (umurTua < umurTertua(temp))
//         {
//             umurTua = umurTertua(temp);
//         }
//         temp = temp->nk;
//     }
//     printf("Umur termuda : %d (Anggota)")
// }

