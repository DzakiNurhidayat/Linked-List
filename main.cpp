/*----------------------------------------------------------------------------*/
/* Dibuat oleh : Muhammad Dzaki Nurhidayat dan Muhammad Fachry Khariansyah */
/* Dengan NIM  : 231511083 dan 231511084*/
/* Deskripsi   : ADT Non Restricted Single Linked List */
/* Tanggal     : 02-04-2024 */
/*----------------------------------------------------------------------------*/

#include "linkedList.h"

// Progress Sampai Hari Ini
// Kami telah menyelesaikan semua poin-poin wajib yang harus ada pada program ini
// Untuk fitur tambahan, kami sudah berhasil menerapkan fitur menghitung jumlah kota serta mengurutkan insert kota secara berurut (ascending)

// Penjelasan Program
// Kami membuat 2 struct, satu untuk kota dan satu untuk anggota
// Proses untuk linked list kota kurang lebih sama dengan linked list biasa, dimana kami memanfaatkan pointer first untuk merujuk elemen kota pertama
// Sementara untuk linked list anggota di tiap kota, kami akan melakukan pencarian kota yang dicari terlebih dahulu, kemudian menginisialisasi satu pointer temp untuk merujuk elemen yang ditunjuk oleh np kota sebagai first dari linked list
// Karena itu kami tidak memakai pointer first atau last pada linked list anggota secara langsung

// Untuk insert kami sudah menerapakan insert secara ascending pada kota sehingga kota sudah dalam bentuk terurut, untuk insert anggota masih menggunakan insert awal
// Saat melakukan tambah atau hapus anggota, jika salah menginputkan nama kota maka program akan langsung ter-close
// Hal yang sama saat salah menginputkan nama anggota, maka program akan langsung ter-close
// Saat melakukan pencarian kota, asumsi kami adalah menyatakan bahwa apakah kota yang dicari itu ada atau tidak
// Saat melakukan pencarian anggota, kami menyelesaikan dengan melakukan looping pada semua anggota setiap kota, jika pada kota tersebut ditemukan anggota yang sama, maka kota tersebut akan ditampilkan

int main() {
    kota *temp, *first;
    int menuChoice, usia, sumKota;
    char nilai[100], nama[100];
    bool cek;
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
        printf("7. Total Data Anggota\n");
        printf("8. Cari Kota\n");
        printf("9. Cari Anggota\n");
        printf("10. Mencari Anggota Termuda/Tertua\n");
        printf("11. Keluar\n");
        printf("Silakan masukan pilihan yang ingin dilakukan : ");
        scanf("%d", &menuChoice);

        switch (menuChoice) 
        {
            case 1:
                printf("\nList Kota :\n");
                printListKota(first);
                break;
            case 2:
                printf("\nList Kota :\n");
                printListKota(first);
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
                printf("\nList Kota :\n");
                cek = printListKota(first);
                if (cek == true) {
                    printf("\nMasukkan Nama Kota yang ingin ditambah Anggotanya: ");
                    scanf("%s", &nilai);
                    temp = searchingKota(nilai,first);
                    printf("\nMasukkan Nama Anggota: ");
                    scanf("%s", &nama);
                    printf("Masukkan Usia Anggota: ");
                    scanf("%d", &usia);
                    insertAwalAnggota(nama,usia,temp);
                }
                break;
            case 5:
                printf("\nList Kota :\n");
                cek = printListKota(first);
                if (cek == true) {
                    printf("\nMasukkan Nama Kota yang ingin dihapus Anggotanya: ");
                    scanf("%s", &nilai);
                    temp = searchingKota(nilai,first);
                    printListAnggota(temp);
                    printf("\nMasukkan Nama Anggota yang ingin dihapus: ");
                    scanf("%s", &nama);
                    strcpy(nama, deleteAnggota(nama,temp));
                    printf("\nAnggota yang dihapus adalah %s\n", nama);
                }
                break;
            case 6:
                sumKota = jumlahKota(first);
                printf("\nJumlah Kota = %d", sumKota);
                break;
            case 7: // Ini nanti diseusain lagi kata-katanya
                printf("\n1. Pada Kota\n");
                printf("2. Semua Kota\n");
                printf("Silahkan Pilih = ");
                scanf("%d", &menuChoice);
                switch (menuChoice) {
                    case 1:
                        cek = printListKota(first);
                        if (cek == true)
                        {
                            printf("Masukkan Kota = ");
                            scanf("%s", &nilai);
                            temp = searchingKota(nilai,first);
                            printf("Jumlah Anggota Pada Kota %s adalah %d", nilai, jumlahAnggota(temp));
                        }
                        break;
                    case 2:
                        printf("Jumlah Anggota Keseluruhan adalah %d\n", jumlahTotal(first));
                        break;
                    default:
                        printf("Pilihan tidak valid\n");
                        break;
                }
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
            case 9:
                printf("\nMasukkan Anggota yang ingin dicari: ");
                scanf("%s", &nilai);
                cek = cariAnggota(nilai, first);
                if (cek == false)
                {
                    printf("\nTidak Ada Data yang Ditemukan");
                }
                printf("\n");
                break;
            case 10:

            default:
                printf("\nPilihan Tidak Valid");
                break;
        } 
    } while (menuChoice != 11);

    return 0;
}