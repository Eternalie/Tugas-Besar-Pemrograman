#include <stdio.h> //header standar input output dalam bahasa C
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define JUM_BLOK 1		/* sebuah record */

time_t waktuserver; 
//deklarasi variabel :
int passwordbenar;
char passP[20], passwordP[20];
float deposito = 500000 ;
float biaya_ADM = 2000 ;
char jawab ;

// Struct User untuk menyimpan member nama, username, password
typedef struct {
    char nama[50];
    char username[12];
    char password[10];
    char email[50];
}User;

User u; 


// Struct Pesan
typedef struct {
	int nomor_villa;
	char nama_pemesan[50];
	char noHP [15];
	char email [50];
	int orang ;
	int tglCI ;
	int blnCI ;
	int thnCI ;
	int tglCO ;
	int blnCO ;
	int thnCO ;
	float totalPembayaran ;
	float DPpemesan ;
	float sisaPembayaran ;	
}pesan_villa;
pesan_villa pesanvl;

//Deklarasi fungsi-fungsi yang digunkan pada program pemesanan villa
void header ();
void menu_masuk();
void masuk_admin();
void daftar();
void error_alert();
void masuk_pengunjung ();
void ambil_password();
void selesai();
void menuadm();
void record(User u, char file[]);
void waktu();
void menu_pengunjung();
void list_villa ();
void lokasi_villa ();
void list_villa_pengunjung ();
void pesan_villa_anyelir ();
void lihat_data_pesanan ();
void hapus_pesanan ();
void pemesanan_villa();

// assign namaFile (nF) agar menyimpan string "logRecord.txt"
char namaFile[] = "logRecord.txt";

int main (){
   system ("color F5");
   header ();
   menu_masuk ();
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

void menu_masuk (){
	system ("cls");
	// Variabel pilihan yang digunakan untuk menyimpan pilihan pengguna antara Masuk dengan Registrasi
    int pilihan;

    // Instruksi yang diberikan kepada pengguna
    
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                PILIHAN MENU MASUK              |\n");
    printf ("\t\t\t\t\t|                  VILLA ANYELIR                 |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Menu Masuk                          |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Masuk Sebagai Admin                 |\n");
    printf ("\t\t\t\t\t|   2   |    Masuk Sebagai Pengunjung            |\n");
    printf ("\t\t\t\t\t|   3   |    Registrasi Pengunjung               |\n");
    printf ("\t\t\t\t\t|   4   |    Exit                                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|================================================|\n");
    instruksi:
    printf ("\t\t\t\t\t|| Masukkan pilihan Anda => ");
    scanf  ("%d", &pilihan);
    printf ("\t\t\t\t\t|================================================|\n");
    system ("cls");
    switch (pilihan){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk
        masuk_admin();
        break;
    case 2 :
    	masuk_pengunjung ();
    break ;
    case 3:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi registrasi
        daftar();
        break;
    case 4:
        exit(1);
        break;
    default:
        error_alert();
        // Kembali ke label instruksi jika terjadi kesalahan dalam menginput pilihan
        goto instruksi;
        break;
    }
}

void masuk_admin (){
	system("cls");
	ambil_password ();
	printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                   MENU MASUK                   |\n");
    printf ("\t\t\t\t\t|                 PEGAWAI ANYELIR                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t| Masukkan password : ");
	scanf("%s", &passP);
	passwordbenar=strcmp(passP,passwordP);
	if(passwordbenar !=0){
		printf("\t\t\t\t\t Password yang anda masukan salah!");
		printf("\t\t\t\t\t Kembali ke menu utama\n");
		getch();
		system("cls");
		main();
	}
	else{
		selesai(); //void selesai dapat kalian ubah ke void menu
	}
    
}

void ambil_password(){
	FILE *file;
	file=fopen("passwordAdmin.txt", "r");
	fscanf(file, "%s", passwordP);
	fclose(file);
}

void selesai(){
	printf("\t\t\t\t\t\t\tLOGIN SUKSES!\n");
	getch(); fflush(stdin);
	menuadm();
}


void masuk_pengunjung (){
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
    printf ("\t\t\t\t\t||                       LOGIN                    ||\n");
    printf ("\t\t\t\t\t||                 PENGUNJUNG ANYELIR             ||\n");
    printf ("\t\t\t\t\t||================================================||\n");
    printf ("\t\t\t\t\t|| Username: ");
    scanf  ("%s", username);
    printf ("\t\t\t\t\t|| Password: ");
    scanf  ("%s", password);
    printf ("\t\t\t\t\t||================================================||\n");
    system ("cls");
    // Membeaca file "logRecord.txt"
    while(fread(&u,sizeof(u),1,record)){
        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
            menu_pengunjung();
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
                masuk_pengunjung();
            } else if (pilihan ==3){
                exit(1);
            } else {
                printf ("\t\t\t\t\t HARAP MASUKKAN PILIHAN YANG SESUAI [1-3]\n");
                goto instruksi;
            }
        }
    }
    fclose(record);
    return;
}

   
void daftar (){
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
    menu_pengunjung();
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

void error_alert (){
	printf   ("\t\t\t\t\t===============================================  \n");
    printf   ("\t\t\t\t\t||     Pilihan yang Anda masukan Salah!!!     || \n");
    printf   ("\t\t\t\t\t||   Silahkan Memilih Pilihan yang Sudah ada  || \n");
    printf   ("\t\t\t\t\t===============================================  \n");
}

void menuadm (){
	char a ;
	int kategori ;
	system ("cls");
	ulangi :
	printf ("\n\n");
	printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|                        KATEGORI MENU                    |\n");
    printf ("\t\t\t\t\t|                    PEGAWAI VILLA ANYELIR                |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Kategori                             |\n");
    printf ("\t\t\t\t\t|-------|-------------------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Lihat List Villa                             |\n");
    printf ("\t\t\t\t\t|   2   |    Pesan Villa                                  |\n");
    printf ("\t\t\t\t\t|   3   |    Lihat Data Pesanan                           |\n");
    printf ("\t\t\t\t\t|   4   |    Hapus Pesanan                                |\n"); 
    printf ("\t\t\t\t\t|   5   |    Exit                                         |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t| Masukkan No Pilihan Anda : ");
	scanf  ("%d",&kategori);
    system ("cls");
    switch (kategori){
    	case 1 :
    		list_villa ();
    		printf ("\t\t\t|                                                     Proses Pemesanan [Y/T]? : ");
    		scanf  ("%s", &a);
    		if (a=='Y'|| a=='y')
    			pesan_villa_anyelir();
    		else
    			menuadm ();
    	break ;
    	
    	case 2 :
    		pesan_villa_anyelir ();
    	break ;
    	
    	case 3 :
    		lihat_data_pesanan ();
    	break ;
    
    	case 4 :
    		hapus_pesanan ();
    	break ;
    	
    	case 5 :
    		menu_masuk ();
    	break ;
    	
    	default :
    		error_alert ();
    		goto ulangi ;
    	break ;
	}
}

void pesan_villa_anyelir (){
	system ("cls");
	printf ("\n\n");
	printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|                   PESAN VILLA ANYELIR                   |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    FILE*dtpesan ;
    dtpesan = fopen ("datapesan.txt", "ab");
    if (dtpesan== NULL ){
		printf("\t\t\t\t\t|File tidak dapat dibuat!\r\n");
		menuadm();
	}
	do {
		printf ("\t\t\t\t\t| Masukkan Id Villa     : ");
		scanf  ("%d", &pesanvl.nomor_villa);
		if (pesanvl.nomor_villa >=1 && pesanvl.nomor_villa <=12){
			pemesanan_villa ();
				printf ("\t\t\t\t\t| Nama Pemesan          : "); fflush(stdin); gets (pesanvl.nama_pemesan);
				printf ("\t\t\t\t\t| No HP Pemesan         : "); fflush(stdin); scanf ("%s", &pesanvl.noHP);
				printf ("\t\t\t\t\t| Email Pemesan         : "); fflush(stdin); scanf ("%s", &pesanvl.email);
				printf ("\t\t\t\t\t| Jumlah Orang          : "); fflush(stdin); scanf ("%d", &pesanvl.orang);
				printf ("\t\t\t\t\t| Check In [DD/MM/YYYY] : "); fflush(stdin); scanf ("%d/%d/%d", &pesanvl.tglCI, &pesanvl.blnCI, &pesanvl.thnCI);
				printf ("\t\t\t\t\t| Deposito              : Rp.%.2f\n", deposito);
				printf ("\t\t\t\t\t| Biaya Admin           : Rp.%.2f\n", biaya_ADM);
				printf ("\t\t\t\t\t| Total Pembayaran      : Rp.%.2f\n", pesanvl.totalPembayaran);
				printf ("\t\t\t\t\t| DP Pemesan            : "); fflush(stdin); scanf ("%f", &pesanvl.DPpemesan);
				pesanvl.sisaPembayaran = pesanvl.totalPembayaran - pesanvl.DPpemesan ;
				printf ("\t\t\t\t\t| Sisa Pembayaran       : Rp.%.2f\n", pesanvl.sisaPembayaran);
		    	fwrite(&pesanvl, sizeof(pesanvl), 1, dtpesan);
		}
		else {
			fflush(stdin);
			printf ("\t\t\t\t\t| HARAP MASUKKAN ID VILLA DENGAN BENAR \n");
			getch();
			pesan_villa_anyelir();
				
		}
		printf ("\t\t\t\t\t Data pemesanan tersimpan. \n");
		printf("\t\t\t\t\t  Pesan villa lagi? (Y/T) : "); fflush(stdin);
	    scanf("%s", &jawab)	;
	}
	while (jawab == 'Y'||jawab=='y');
	fclose(dtpesan);		
	menuadm();
}


void pemesanan_villa (){
	if (pesanvl.nomor_villa==1){
		pesanvl.totalPembayaran = 1800000 + biaya_ADM + deposito ;	
	}
	else if(pesanvl.nomor_villa==2){
		pesanvl.totalPembayaran = 1650000 + biaya_ADM + deposito ;	
	}
	else if (pesanvl.nomor_villa==3){
		pesanvl.totalPembayaran = 1750000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==4){
		pesanvl.totalPembayaran = 3800000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==5){
		pesanvl.totalPembayaran = 7750000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==6){
		pesanvl.totalPembayaran = 5800000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==7){
		pesanvl.totalPembayaran = 4800000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==8){
		pesanvl.totalPembayaran = 4300000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==9){
		pesanvl.totalPembayaran = 5960000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==10){
		pesanvl.totalPembayaran = 2750000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==11){
		pesanvl.totalPembayaran = 4120000 + biaya_ADM + deposito ;
	}
	else if (pesanvl.nomor_villa==12){
		pesanvl.totalPembayaran = 4800000 + biaya_ADM + deposito ;
	}
}


void lihat_data_pesanan (){
	char opsi_kembali;
	system ("cls");
	printf ("\t\t\t|===================================================================================================================|\n");
	printf ("\t\t\t|                                              DATA PEMESAN VILLA ANYELIR                                           |\n");
	printf ("\t\t\t|===================================================================================================================|\n");
	printf ("\t\t\t| Kode Villa |     Nama Pemesan      |        NO HP      |     Check In     |  Total Pembayaran | Sisa Pembayaran   |\n");
	printf ("\t\t\t|------------|-----------------------|-------------------|------------------|-------------------|-------------------|\n");                                                                                          
	FILE*dtpesan ;
    dtpesan = fopen ("datapesan.txt", "rt");
    if (dtpesan== NULL ){
		printf("\t\t\t| FILE TIDAK DAPAT DIBUKA!\r\n");
		menuadm();
	}
		/* Ambil isi file ngenggunakan fungsi fread(), lalu tampilkan ke layar */
	while ((fread(&pesanvl, sizeof(pesanvl), JUM_BLOK, dtpesan)) == JUM_BLOK )
	printf ("\t\t\t|     %d              %s            %s           %d/%d/%d        Rp.%.2f      Rp.%.2f\n", pesanvl.nomor_villa, pesanvl.nama_pemesan, pesanvl.noHP, pesanvl.tglCI, pesanvl.blnCI, pesanvl.thnCI, pesanvl.totalPembayaran, pesanvl.sisaPembayaran);
	fclose(dtpesan);
	printf("\t\t\t|===================================================================================================================|\n");
	opsi :
	printf("\t\t\t| Kembali ke menu ketik Y : ");
	scanf ("%s", &opsi_kembali);
	if (opsi_kembali=='Y'||opsi_kembali=='y')
	    menuadm();
	else 
	    goto opsi ;
}

void hapus_pesanan (){
	system ("cls");
	lihat_data_pesanan ();
	printf ("\n\n");
	printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|                       HAPUS PESANAN                     |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
}

void menu_pengunjung (){
    system ("cls");
    int pilihan_deskripsi ;
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
    printf ("\t\t\t\t\t|hubungi admin.                                           |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|          Tekan 1 untuk melihat lokasi vila              |\n");
	printf ("\t\t\t\t\t|          Tekan 2 untuk melihat list vila                |\n");
	printf ("\t\t\t\t\t|          Tekan 3 untuk kembali ke menu                  |\n");          
    printf ("\t\t\t\t\t|=========================================================|\n");
    tekan_benar :
    printf ("\t\t\t\t\t|                      Tekan : ");
    scanf  ("%d", &pilihan_deskripsi);
    if (pilihan_deskripsi==1){
    	lokasi_villa ();
	}
	else if (pilihan_deskripsi==2){
		list_villa_pengunjung ();
	}
	else if (pilihan_deskripsi==3){
		menu_masuk ();
		
	}
	else {
		error_alert ();
		goto tekan_benar ;
	}
}

void lokasi_villa (){
	int pilih1 ;
	system ("cls");
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
    printf ("\t\t\t\t\t|         Tekan  1 untuk kembali ke menu pengunjung          |\n");
    printf ("\t\t\t\t\t|============================================================|\n");
    tekan1 :
    printf ("\t\t\t\t\t| Tekan      : ") ;
	scanf  ("%d", &pilih1);
	if (pilih1== 1)
		menu_pengunjung ();
	else 
		printf ("\t\t\t\t\t| Silahkan ketik ulang 1 \n");
		goto tekan1 ;
   
}

void list_villa (){
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

void list_villa_pengunjung (){
	int pilih ;
	list_villa ();
    printf ("\t\t\t|                                                PROSES PEMESANAN HARAP PANGGIL ADMIN                                                     |\n");
    printf ("\t\t\t|=========================================================================================================================================|\n");
    masukkan1 :
    printf ("\t\t\t| Tekan 1 untuk kembali ke menu pengunjung      : ") ;
	scanf  ("%d", &pilih);
	if (pilih== 1){
	
		menu_pengunjung ();
	}
	else {
		printf ("\t\t\t| Silahkan ketik ulang 1 \n");
		goto masukkan1 ;
	}
}


