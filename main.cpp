#include "linkedList.h"

// int main () {
//     int sumKota;
//     kota *temp;
//     char nilai[100];
//     kota *first = NULL;
//     insertAwalKota("Bandung", &first);
//     insertAwalKota("Cimahi", &first);
//     insertAkhirKota("Kudus", &first);
//     insertAwalKota("Jakarta", &first);
//     insertTengahKota("Surabaya", "Jakarta", &first);
//     printListKota(first);
    
//     temp = searchingKota("Bandung", first);
//     insertAwalAnggota("Dzaki", 20, temp);
//     insertAwalAnggota("Ahmad", 17, temp);
//     insertAwalAnggota("Restu", 17, temp);
    
//     temp = searchingKota("Kudus", first);
//     insertAwalAnggota("Fachry", 17, temp);
//     printListAnggota(temp);

//     temp = searchingKota("Bandung", first);
//     printListAnggota(temp);
//     deleteAnggota ("Restu", temp);
//     printListAnggota(temp);

//     sumKota = jumlahKota(first);
//     printf("Jumlah Kota = %d", sumKota);
// }

int main() {
    kota *temp, *first;
    int menuChoice, usia, sumKota;
    char nilai[100], nama[100];
    first = NULL;
    
    do {
        printf("\n<---------- Program Membuat Pendataan Kota dan Penduduk ---------->\n");
        printf("-------------------------------------------------------------------\n");
        printf("Pilhan Menu : \n");
        printf("1. Tampilkan data kota\n");
        printf("2. Tampilkan data Anggota\n");
        printf("3. Insert kota\n");
        printf("4. Tambah Anggota\n");
        printf("5. Hapus Anggota\n");
        printf("6. Total Kota\n");
        // printf("7. Total Data Orang\n");
        printf("8. Cari Kota\n");
        printf("9. Cari Anggota\n");
        printf("10. Keluar\n");
        printf("Silakan masukan pilihan yang ingin dilakukan : ");
        scanf("%d", &menuChoice);

        switch (menuChoice) 
        {
            case 1:
                printf("\nList Kota :\n");
                printListKota(first);
                break;
            case 2:
                printf("\nMasukkan Kota yang ingin dicari: ");
                scanf("%s", &nilai);
                temp = searchingKota(nilai,first);
                printf("\nList Anggota: ");
                printListAnggota(temp);
                break;   
            case 3:
                printf("\nMasukkan Nama Kota: ");
                scanf("%s", &nilai);
                insertKota(nilai, &first);
                break;
            case 4:
                printf("\nMasukkan Nama Kota yang ingin ditambah Anggotanya: ");
                scanf("%s", &nilai);
                temp = searchingKota(nilai,first);
                printf("\nMasukkan Nama Anggota: ");
                scanf("%s", &nama);
                printf("\nMasukkan Usia Anggota: ");
                scanf("%d", &usia);
                insertAwalAnggota(nama,usia,temp);
                break;
            case 5:
                printf("\nMasukkan Nama Kota yang ingin dihapus Anggotanya: ");
                scanf("%s", &nilai);
                temp = searchingKota(nilai,first);
                printf("\nMasukkan Nama Anggota yang ingin dihapus: ");
                scanf("%s", &nama);
                strcpy(nama, deleteAnggota(nama,temp));
                printf("\nAnggota yang dihapus adalah %s\n", nama);
                break;
            case 6:
                sumKota = jumlahKota(first);
                printf("\nJumlah Kota = %d", sumKota);
                break;
            case 8:
                printf("\nMasukkan Nama Kota yang ingin dicari: ");
                scanf("%s", &nilai);
                temp = searchingKota(nilai,first);
                if (temp == NULL)
                {
                    printf("\nKota Tidak Ditemukan\n");
                } else
                {
                    printf("\nKota Ditemukan\n");
                }
                break;
        } 
    } while (menuChoice != 10);

    return 0;
}