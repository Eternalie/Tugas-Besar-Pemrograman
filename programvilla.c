#include <stdio.h> //header standar input output dalam bahasa C
#include <time.h>
#include <stdlib.h>
#include <string.h> //hai gek

// Dekalarasi variable global yang di gunakan pada program pemesanan villa ini :
int kategori ;
int pilihanmenu ;
time_t waktuserver; 
int villa ;


// Struct User untuk menyimpan member nama, username, password
typedef struct {
    char nama[50];
    char username[12];
    char password[10];
    char email[50];
}User;

User u; 

//Deklarasi fungsi-fungsi yang digunkan pada program pemesanan villa
void header ();
void menu ();
void deskripsi_villa ();
void lokasi_villa ();
void list_villa ();
void pesan_villa ();
void riwayat_pemesanan ();
void menu_program ();
void waktu ();
void menu_masuk ();
void masuk ();
void record(User u1, char file[]);
void error_alert ();
void daftar ();
void listVilla ();

// assign namaFile (nF) agar menyimpan string "logRecord.txt"
char namaFile[] = "logRecord.txt";

// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){
  system ("color F5");
  header ();
  system ("cls");
  deskripsi_villa ();
  system ("cls");
  menu_masuk();
  menu_program();
}


void header (){
  system ("cls");
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");	
	printf  ("\t\t\t\t\t||                TUGAS BESAR PEMROGRAMAN              ||\n");
	printf  ("\t\t\t\t\t||            Program Pemesanan Villa Anyelir          ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t||          Program disusun dan dibuat oleh :          ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t||  1. Gusti Ayu Wahyu Whurapsari       (2105551042)   ||\n");
	printf  ("\t\t\t\t\t||  2. Putu Eternalie Prajnani Welaga   (2105551046)   ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t||           Program Studi Teknologi Informasi         ||\n");
	printf  ("\t\t\t\t\t||                   Fakultas Teknik                   ||\n");
	printf  ("\t\t\t\t\t||                 Universitas Udayana                 ||\n");
	printf  ("\t\t\t\t\t||                       2021                          ||\n");
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t         Tekan ENTER  untuk melanjutkan....\n");
    printf  ("\t\t\t\t\t=========================================================\n");
	getchar ();
  system ("cls");
}

void menu (){
	system ("cls");
    ktgri:
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|                 KATEGORI MENU VILLA ANYELIR             |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Kategori                             |\n");
    printf ("\t\t\t\t\t|-------|-------------------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Lihat Lokasi Villa                           |\n");
    printf ("\t\t\t\t\t|   2   |    Lihat List Villa                             |\n");
    printf ("\t\t\t\t\t|   3   |    Pesan Villa                                  |\n");
    printf ("\t\t\t\t\t|   4   |    Riwayat Pemesanan Villa                      |\n");
    printf ("\t\t\t\t\t|   5   |    Exit                                         |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");

    printf ("\n\t\t\t\t\t||Masukkan No Pilihan Anda :");
        scanf  ("%d",&kategori);
        system ("cls");
        //pada menu switch case bagian ini , merupakan lanjutan proses dari pilihan user yang di inputkan sebelumnya pada pilihan pada MENU program.
        switch (kategori)
        {

            case 1:
                lokasi_villa();
                goto ktgri;
                break;
            case 2:
                list_villa();
                goto ktgri;
                break;
            case 3:
                pesan_villa();
                goto ktgri;
                break;
            case 4:
                riwayat_pemesanan ();
                goto ktgri;
                break;
            case 5:
                exit (0);
                break;
            default:
                printf ("Silahkan ketik ulang pilihan anda");
                goto ktgri;
                break;
        }
    }


void deskripsi_villa (){
    system ("cls");
	printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|    *      *     *   *      *  *****   *      ***   ***  |\n");
    printf ("\t\t\t\t\t|   * *     * *   *     *   *   *       *       *    *  * |\n");
    printf ("\t\t\t\t\t|  *****    *   * *       *     *****   *       *    ***  |\n");
    printf ("\t\t\t\t\t| *     *   *     *       *     *       *       *    * *  |\n");
    printf ("\t\t\t\t\t|*       *  *     *       *     *****   *****  ***   *  * |\n");
    printf ("\t\t\t\t\t|             SELAMAT DATANG DI VILLA ANYELIR             |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|Villa  Anyelir  adalah  salah  satu  villa  yang  baru   |\n");
    printf ("\t\t\t\t\t|beroperasi sejak bulan November 2021. Villa ini memiliki |\n");
    printf ("\t\t\t\t\t|5 cabang yang telah menyebar di sekitar Denpasar, Kuta   |\n");
    printf ("\t\t\t\t\t|Ubud, Jimbaran, dan Canggu.                              |\n");
    printf ("\t\t\t\t\t|Villa Anyelir memiliki beberapa fasilitas seperti kamar  |\n");
    printf ("\t\t\t\t\t|yang nyaman,  kamar mandi luas,  ruangan ber AC, dan ada |\n");
    printf ("\t\t\t\t\t|kolam renang di dalamnya.                                |\n");
    printf ("\t\t\t\t\t|                                                         |\n");
    printf ("\t\t\t\t\t|Villa Anyelir memadukan arsitektur Bali dan modern yang  |\n");
    printf ("\t\t\t\t\t|membuat pengunjung senantiasa nyaman sehingga ingin lagi |\n");
    printf ("\t\t\t\t\t|menyewa villa ini. Jika ingin melakukan pemesanan segera |\n");
    printf ("\t\t\t\t\t|hubungi kontak di bawah ini.                             |\n");
    printf ("\t\t\t\t\t|                        0361000000                       |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|           Tekan enter untuk menuju menu....             |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    getchar ();
  system ("cls");
}

void lokasi_villa(){
	int pilih1 ;
    printf ("\n");
    printf ("\t\t\t\t\t|============================================================|\n");
    printf ("\t\t\t\t\t|                          LOKASI VILLA                      |\n");
    printf ("\t\t\t\t\t|============================================================|\n");
    printf ("\t\t\t\t\t|  Lokasi    |                    Alamat                     |\n");
    printf ("\t\t\t\t\t|------------|-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Anyelir No.61, Denpasar Timur, Bali      |\n");
    printf ("\t\t\t\t\t|1. Denpasar | ----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Hayam Wuruk No.05, Denpasar Timur, Bali  |\n");
    printf ("\t\t\t\t\t|------------|-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Raya Kesambi No.42, Kuta, Bali           |\n");
    printf ("\t\t\t\t\t|2. Kuta     |-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Dewi Sri No.80, Kuta, Bali               |\n");
    printf ("\t\t\t\t\t|------------|-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Raya Pengosekan No.67, Ubud, Bali        |\n");
    printf ("\t\t\t\t\t|3. Ubud     | ----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Raya Pengosekan No.102, Ubud, Bali       |\n");
    printf ("\t\t\t\t\t|------------|-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Raya Uluwatu No.121, Jimbaran, Bali      |\n");
    printf ("\t\t\t\t\t|            |-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|4. Jimbaran |Jalan Bukit Permai No.66, Jimbaran, Bali       |\n");
    printf ("\t\t\t\t\t|            |-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Raya Uluwatu No.46, Jimbaran, Bali       |\n");
    printf ("\t\t\t\t\t|------------|-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Sahadewa No.21, Canggu, Bali             |\n");
    printf ("\t\t\t\t\t|            |-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|5. Canggu   |Jalan Pantai Berawa No.61, Canggu, Bali        |\n");
    printf ("\t\t\t\t\t|            |-----------------------------------------------|\n");
    printf ("\t\t\t\t\t|            |Jalan Nelayan No.81, Canggu, Bali              |\n");
    printf ("\t\t\t\t\t|------------------------------------------------------------|\n");
    printf ("\t\t\t\t\t|============================================================|\n");
    printf ("\t\t\t\t\t|               Tekan 1  untuk kembali ke menu....           |\n");
    printf ("\t\t\t\t\t|============================================================|\n");
    tekan1 :
    printf ("\t\t\t\t\t|Tekan 1 : ") ;
	scanf  ("%d", &pilih1);
	if (pilih1== 1)
		menu ();
	else 
		printf ("\t\t\t\t\t| Silahkan ketik ulang 1 \n");
		goto tekan1 ;
	 
}
void list_villa(){
	char menuList;
	system ("cls");
    listVilla ();
	printf ("\t\t\t|Pesan Villa [Y/T] : ") ;
	scanf  ("%s", &menuList);
	system ("cls");
	if (menuList== 'Y'|| menuList == 'y')
		pesan_villa ();
	else 
		menu ();
	 
}

void listVilla (){
	
	system ("cls");
	printf ("\t\t\t|=========================================================================================================================================|\n");
    printf ("\t\t\t|                                                       LIST VILLA ANYELIR                                                                |\n");
    printf ("\t\t\t|-----------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf ("\t\t\t|ID VILLA   |    NAMA VILLA   |         FASILITAS           |    HARGA LUNAS  |      DP      | KAPASITAS | CHECK IN  | CHECK OUT |  KET   |\n");
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|---------- |-----------|--------|\n");
    printf ("\t\t\t|    1      |   Anyelir 1     |Dua Lantai, Kolam Renang     | Rp. 1.800.000   | Rp.900.000   | 6 orang   |12.00 WITA |14.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Anyelir No  |Dua Kamar Tidur, Dua Kasur   |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |  61, Denpasar   |Dua Kamar Mandi dengan Bathup|                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Timur, Bali )   |Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Dua Balkon, TV, Towel, AC    |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    2      |   Anyelir 2     |Tiga Lantai, Kolam Renang    | Rp. 1.650.000   | Rp.750.000   | 4 orang   |11.00 WITA |14.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Hayam Wuruk |Empat Kamar Tidur,Empat Kasur|                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           | No.05, Denpasar |Satu Kamar Mandi dgn Bathup  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Timur, Bali )   |Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Tiga Balkon, TV, Towel, AC   |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    3      |   Anyelir 3     |Dua Lantai,Kolam Renang Lt.2 | Rp. 1.750.000   | Rp.800.000   | 2 orang   |12.00 WITA |13.30 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Raya Kesambi|Dua Kamar Tidur, Dua Kasur   |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |   No.42, Kuta   |Satu Kamar Mandi dgn Bathup  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |     Bali )      |Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, Satu Balkon, TV, AC   |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Tiga Towel, PRIVATE VILLA    |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    4      |   Anyelir 4     |Tiga Lantai,Kolam Renang Lt.3| Rp. 3.800.000   | Rp.1.400.000 | 5 orang   |14.00 WITA |13.30 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Dewi Sri    |Dua Kamar Tidur, Empat Kasur |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |   No.80 , Kuta  |Tiga Kamar Mandi dgn Bathup  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |     Bali )      |Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, Satu Balkon, TV, AC,  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Tiga Towel, Satu Ruang Tamu  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    5      |   Anyelir 5     |Tiga Lantai, AC, Shower,     | Rp. 7.750.000   | Rp.3.800.000 | 42 orang  |12.00 WITA |18.00 WITA |3 hari  |\n");
    printf ("\t\t\t|           |(Jl. Raya Pengo- |7 Kamar Tidur, 14 Kasur Besar|                 |              |           |           |           |2 malam |\n");
    printf ("\t\t\t|           |  sekan No.76    |Lima Kamar Mandi dgn Bathup  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |  Ubud, Bali )   |Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, Empat Balkon, 8 TV,   |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |10 Towel, 1 Ruang Tamu Besar |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Tempat Karaoke, Biliyard     |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Mini Lt.2       |                 |              |           |           |           |        |\n");  
    printf ("\t\t\t|           |                 |Kolam Renang Besar Lt.3      |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Party Villa, Ruang Mandi Air |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Hangat                       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    6      |   Anyelir 6     |Tiga Lantai, AC,             | Rp. 5.800.000   | Rp.1.500.000 | 30 orang  |12.00 WITA |14.30 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Raya Pengo- |5 Kamar Tidur, 5 Kasur Besar |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |  sekan No.102   |Lima Kamar Mandi dgn Shower  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |  Ubud, Bali )   |Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, 3 Balkon, 5 TV,       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |6 Towel, 1 Ruang Tamu Besar  |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Sound System, Biliyard       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Lt.3            |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    7      |   Anyelir 7     |Tiga Lantai, AC,             | Rp. 4.800.000   | Rp.2.000.000 | 7 orang   |14.00 WITA |13.30 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Raya Uluwatu|4 Kamar Tidur, 8 Kasur       |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |      No.121     |4 Kamar Mandi dgn Bathup     |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Jimbaran, Bali )|Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, 3 Balkon, 2 TV,       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |4 Towel, 1 Ruang Tamu        |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Lt.2            |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    8      |   Anyelir 8     |Dua Lantai, AC,              | Rp. 4.300.000   | Rp.2.000.000 | 6 orang   |12.00 WITA |14.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Bukit Permai|2 Kamar Tidur, 2 Kasur Besar |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |      No.66      |2 Kamar Mandi dgn Bathup     |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Jimbaran, Bali )|Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, 1 Balkon, TV,         |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Towel, 1 Ruang Tamu          |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Lt.2, Satu      |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Kamar Utama dengan 2 Kasur   |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    9      |   Anyelir 9     |Tiga Lantai, AC, Shower      | Rp. 5.960.000   | Rp.3.000.000 | 40 orang  |12.00 WITA |15.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Raya Uluwatu|4 Kamar Tidur, 4 Kasur Besar |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |      No.46      |4 Kamar Mandi dgn Bathup     |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Jimbaran, Bali )|Satu Ruang Makan, Satu Dapur |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |besar, 2 Balkon, TV,         |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |6 Towel, 1 Ruang Tamu        |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Lt.2,           |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Satu Ruang Tamu Utama, Satu  |                 |              |           |           |           |        |\n");
	printf ("\t\t\t|           |                 |Ruang Tamu Biasa, Karaoke,   |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Ruang Party                  |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    10     |   Anyelir 10    |Dua Lantai, Ruang Dinner     | Rp. 2.750.000   | Rp.1.000.000 | 6 orang   |12.00 WITA |14.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Sahadewi    |3 Kamar Tidur, 3 Kasur       |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |      No.21      |1 Kamar Mandi dgn Bathup     |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Br. Umacandi, Ds|Satu Ruang Makan, Satu Dapur,|                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Buduk, Mengwi,  |1 Balkon, TV, AC             |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |     Bali)       |3 Towel, 1 Ruang Tamu        |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Lt.1,           |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Satu Ruang Tamu Utama,       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Ruang Mandi Air Hangat       |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    11     |   Anyelir 11    |Tiga Lantai, Ruang Dinner    | Rp. 4.120.000   | Rp.1.800.000 | 8 orang   |14.00 WITA |16.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           |(Jl. Pantai      |5 Kamar Tidur, 5 Kasur       |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |   Berawa No.61  |3 Kamar Mandi dgn 1 Bathup   |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Canggu, Bali)   |Satu Ruang Makan, Satu Dapur,|                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |2 Balkon, TV, AC             |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |4 Towel, 1 Ruang Tamu        |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang Lt.1,           |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Satu Ruang Tamu Utama,       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Ruang Mandi Air Hangat       |                 |              |           |           |           |        |\n");
	printf ("\t\t\t|-----------|-----------------|-----------------------------|-----------------|--------------|-----------|-----------|-----------|--------|\n");
    printf ("\t\t\t|    12     |   Anyelir 12    |Tiga Lantai, Ruang Dinner    | Rp. 4.800.000   | Rp.1.500.000 | 25 orang  |14.00 WITA |15.00 WITA |2 hari  |\n");
    printf ("\t\t\t|           | (Jl. Nelayan    |6 Kamar Tidur, 6 Kasur       |                 |              |           |           |           |1 malam |\n");
    printf ("\t\t\t|           |    No.81        |5 Kamar Mandi dgn 2 Bathup   |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           | Canggu, Bali)   |Satu Ruang Makan, Satu Dapur,|                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |2 Balkon, TV, AC, Wi-Fi      |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |3 Towel, 1 Ruang Tamu        |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Kolam Renang dekat pantai,   |                 |              |           |           |           |        |\n"); 
    printf ("\t\t\t|           |                 |Satu Ruang Tamu Utama,       |                 |              |           |           |           |        |\n");
    printf ("\t\t\t|           |                 |Ruang Mandi Air Hangat       |                 |              |           |           |           |        |\n");
	printf ("\t\t\t|=========================================================================================================================================|\n");
}
void pesan_villa (){
	int salahpilih ;
	listVilla ();
	printf  ("\t\t\t|Silahkan ketik ID VILLA yang ingin dipesan : ");
	scanf ("%d", &villa);
	printf ("\t\t\t|=========================================================================================================================================|\n");
	system ("cls");
	switch (villa)
	{
		case 1 :
		break ;
		
		case 2 :
		break ;
		
		case 3 :
		break ;
		
		case 4 :
		break ;
		
		case 5 :
		break ;
		
		case 6 :
		break ;
		
		case 7 :
		break ;
		
		case 8 :
		break ;
		
		case 9 :
		break ;
		
		case 10 :
		break ;
		
		case 11 :
		break ;
		
		case 12 :
		break ;
		
	default :
		error_alert();
		printf ("\t\t\t | Jika ingin keluar tekan 1, jika lanjut tekan 2 : \n ");
		scanf ("%d", &salahpilih);
		if (salahpilih==1)
			menu ();
		else 
			pesan_villa ();
	}
	
}


void riwayat_pemesanan (){

}


void menu_program(){
	system ("cls");
    pilih:

    printf ("\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                   MENU PROGRAM                 |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Menu Program                |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    MENU                                |\n");
    printf ("\t\t\t\t\t|   2   |    EXIT                                |\n");
    printf ("\t\t\t\t\t|================================================|\n"); 
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\n\t\t\t\t\t Masukan Pilihan Anda => ");
    scanf  ("%d",&pilihanmenu);
    printf ("\t\t\t\t\t|================================================|\n");
    system ("cls");

    // pada switch case bagian ini , disini akan memproses dari inputan yang sudah dimasukkan oleh user pada proses pemiihan pemilihan menu sebelumnya dan mengantarkan program pada fungsi yang merupakan panggilan dari pilihan yang di inputkan oleh user.
    switch (pilihanmenu)
    {
        //pada case 1 ini, program akan memanggil fungsi yang sudah dibuat yaitu fungsi yang bernama void menu();
        case 1:
            menu ();
            break;
        case 2:
            system (EXIT_SUCCESS);
            break;
        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            error_alert();
            //goto pilih; dimana syntax ini akan membawa user kembali ke menu pemilihan program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesaui apa yang sudah ditampilkan pada menu pilihan.
            goto pilih;
            break;
    }
}


void menu_masuk(){
    // Variabel pilihan yang digunakan untuk menyimpan pilihan pengguna antara Masuk dengan Registrasi
    int pilihan;

    // Instruksi yang diberikan kepada pengguna
    instruksi:
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                PILIHAN MENU MASUK              |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Menu Masuk                          |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Masuk                               |\n");
    printf ("\t\t\t\t\t|   2   |    Registrasi                          |\n");
    printf ("\t\t\t\t\t|   3   |    Exit                                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|| Masukkan pilihan Anda => ");
    scanf  ("%d", &pilihan);
    printf ("\t\t\t\t\t|================================================|\n");
    // Membersihkan Layar terminal 
    system ("cls");

    /* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pilihan jika pengguna menuliskan 1 maka akan dipanggil fungsi masuk()
       jika pengguna menuliskna 2 maka akan dipanggil fungsi registrasi()    */
    switch (pilihan){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk
        masuk();
        break;
    case 2:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi registrasi
        daftar();
        break;
    case 3:
        exit(1);
        break;
    default:
        error_alert();
        // Kembali ke label instruksi jika terjadi kesalahan dalam menginput pilihan
        goto instruksi;
        break;
    }
}

void masuk(){
    /*  Variabel username[12] digunakan untuk menyimpan input username
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan username yang sudah terdaftar pada file logRecord.txt   */
    char username[12];

    /*  Variabel password[10] digunakan untuk menyimpan input password
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan password yang sudah terdaftar pada file logRecord.txt   */
    char password[10];

    // Variabel pilihan untuk pilihan user apakah ingin mendaftar atau keluar
    int pilihan;

    // Membuat pointer record untuk menunjuk pada file "logRecord.txt"
    FILE *record;
    // Membuka file dengan mode "r"
    record = fopen (namaFile, "r");
    if (record == NULL){
        fputs ("Error, Tidak terdapat File untuk penyimpanan akun\n", stderr);
        daftar();
    }

    // Memperlihatkan tanggal login
    waktu();
    // Instruksi untuk LOGIN
    printf ("\t\t\t\t\t||================================================||\n");
    printf ("\t\t\t\t\t|| LOGIN\n");
    printf ("\t\t\t\t\t||================================================||\n");
    printf ("\t\t\t\t\t|| Username: ");
    scanf  ("%s", username);
    printf ("\t\t\t\t\t||================================================||\n");
    printf ("\t\t\t\t\t|| Password: ");
    scanf  ("%s", password);
    printf ("\t\t\t\t\t||================================================||\n");
    system ("cls");
    // Membeaca file "logRecord.txt"
    while(fread(&u,sizeof(u),1,record)){
        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
            printf ("\t\t\t\t\t||===============================================||\n");
            printf ("\t\t\t\t\t||                Login Berhasil!                ||\n");
            printf ("\t\t\t\t\t||===============================================||\n");

        }
        //  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program
        else {
            printf ("\t\t\t\t\t||===============================================||\n");
            printf ("\t\t\t\t\t||            Akun tidak terdaftar!              ||\n");
            printf ("\t\t\t\t\t||===============================================||\n");

            instruksi:
            printf ("\t\t\t\t\t||===============================================||\n");
            printf ("\t\t\t\t\t||Ketik 1 untuk daftar");
            printf ("\n\t\t\t\t\t||Ketik 2 untuk masuk ulang");
            printf ("\n\t\t\t\t\t||Ketik 3 untuk EXIT\n");
            printf ("\t\t\t\t\t||===============================================||\n");
            printf ("\n\t\t\t\t\t||Pilihan: ");
            scanf ("%d", &pilihan);
            system ("cls");
            // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi daftar
            if (pilihan == 1){
                daftar();
            /* Menggunakan fungsi recursive kepada fungsi masuk agar pengguna
               dapat melakukan percobaan masuk kembali jika terjadi kesalahan penulisan */
            } else if (pilihan==2) {
                masuk();
            } else if (pilihan ==3){
                exit(1);
            } else {
                printf ("\t\t\t\t\t ERROR");
                goto instruksi;
            }
        }
    }
    fclose(record);
    return;
}

void daftar(){
    // Membuat pointer regis untuk file "logRecord.txt"
    FILE *regis;

    // Membuka file "logRecord.txt" dengan mode "w"
    regis = fopen(namaFile,"w");

    // Melakukan Pengecekan apakah pointer regis menunjuk kepada file yang dituju ("logRecord.txt")
    if (regis == NULL)
    {
        fputs("ERROR, Tidak ada File!", stderr);
        exit(1);
    }

    // Instruksi untuk menginput nama
    printf("\n\t\t\t\t\t Silahkan registrasi akun anda!\n\n");
    getchar();
    printf("\t\t\t\t\t Nama Lengkap: ");
    gets(u.nama);
    printf("\t\t\t\t\t Email anda: ");
    scanf ("%s", u.email);
    printf("\n\t\t\t\t\t Hallo %s!\n", u.nama);
    printf ("\t\t\t\t\t Silahkan membuat username (max 12 karakter) serta membuat password (max 10 karakter)\n");

    // Instruksi untuk menginput username serta password
    printf("\n\t\t\t\t\t Enter Username:");
    scanf ("%s", u.username);
    printf("\n\t\t\t\t\t Enter Password:");
    scanf ("%s", u.password);

    // Menuliskan nama yang diinput oleh pengguna kedalam file "logRecord.txt"
    fwrite(&u,sizeof(u),1,regis);
    fclose(regis);
    printf("\n\t\t\t\t\t Registrasi Selesai!");
    printf ("\n\t\t\t\t\t Akun anda terdaftar, silahkan mencoba !");
    getchar();

    // Membersikan layar terminal
    system ("cls");
    // Memanggil fungsi masuk()
    masuk();
}


void record(User u, char file[] ){
    time( & waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    //Mendeklarasikan tipe data file dengan pointer *rc yang bertujuan untuk pointer pada file "logRecord.txt"
    FILE *rc;
    //Assign rc untuk membuka file binary Record.dat dan menggunakan mode "r" untuk membaca textfile
    rc = fopen(file, "r");
    //Menggunakan fungsi fread untuk membaca isi dari file "logRecord.txt"
    fread (&u, sizeof(u), 1, rc);
    //Menggunakan fungsi fclose untuk menutup file "logRecord.txt" agar tidak diproses lagi
    fclose (rc);

    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user
    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t||Nama        Username       Tanggal      \n");
    printf("\t\t\t\t\t||%s\t%s\t\t%i-%i-%i\n",u.nama, u.username, waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
    printf("\t\t\t\t\t|=========================================|\n");

}

void waktu(){
    time( & waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    printf("\n\t\t\t\t\t||================Tanggal: %i/%i/%i==============||\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
}

void error_alert(){
    printf   ("\t\t\t\t\t===============================================  \n");
    printf   ("\t\t\t\t\t||     Pilihan yang Anda masukan Salah!!!     || \n");
    printf   ("\t\t\t\t\t||   Silahkan Memilih Pilihan yang Sudah ada  || \n");
    printf   ("\t\t\t\t\t===============================================  \n");
}
