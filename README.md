# SoalShiftSISOP20_modul2_T01

Repository ini Sebagai Laporan Resmi Soal Shift Modul 2 Praktikum Sistem Operasi 2020

## Disusun oleh : 

  - Anis Saidatur Rochma    [05311840000002]
  - Kadek Nesya Kurniadewi  [05311840000009]

### Soal 1

Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:

    Program menerima 4 argumen berupa:
        Detik: 0-59 atau * (any value)
        Menit: 0-59 atau * (any value)
        Jam: 0-23 atau * (any value)
        Path file .sh
    Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai
    Program hanya menerima 1 config cron
    Program berjalan di background (daemon)
    Tidak boleh menggunakan fungsi system()

Contoh: `./program \* 34 7 /home/somi/test.sh`

Pembahasan:

### Soal 2

Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program.

### Soal 2.a.

Deskripsi:
Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].

### Soal 2.b.

Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].


### Soal 3

Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan (multiprocessing).

### Soal 3.a.

Program buatan jaya harus bisa membuat dua direktori di "***/home/[USER]/modul2/***". Direktori yang pertama diberi nama "indomie", lalu *lima detik* kemudian membuat direktori yang kedua bernama "sedaap".


```C	
int main() {
	pid_t child_id,child_id2,child_id3;

	int status;

	child_id = fork();
  
	if (child_id < 0) {
		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	}

	if (child_id == 0) {
	// this is child
		char *argv[] = {"mkdir", "-p", "indomie", NULL};
		execv("/bin/mkdir", argv);
	} else {
	// this is parent
	  while ((wait(&status)) > 0);
	  child_id2 = fork();
  
	if (child_id2 < 0) {
    		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
 	}

 	if (child_id2 == 0) {
    	// this is child
    		sleep (5);
		char *argv[] = {"mkdir", "-p", "sedaap", NULL};
		execv("/bin/mkdir", argv);
 	 } 
```
* membuat direktori pada `/home/nisyua/modul_2/ ` bernama **indomie** menggunakan perintah `mkdir`dan terdapat argumen `-p` yang berfungsi untuk membuat directory pada `/home/nisyua/modul_2` yang belum terbuat.
* syntax argument : `argv[n] = { {your-program-name}, {argument[1]}, {argument[2]},.....,{argument[n-2]}, NULL };`
* parent process menunggu directory baru terbuat, setelah itu sleep(5) atau selang 5 detik parent process membuat child process lagi untuk membuat direktori baru yaitu **sedaap**


### Soal 3.b.

Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori "***/home/[USER]/modul2/***". Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.

```C
child_id3 = fork();
  
	if (child_id3 < 0) {
 		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	 }

	if (child_id3 == 0) {
    	// this is child
		char *argv[] = {"unzip", "jpg.zip", NULL};
		execv("/usr/bin/unzip", argv);
	}
```

### Soal 3.c.
b  
Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori "/home/[USER]/modul2/jpg/") harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke "***/home/[USER]/modul2/sedaap/***" dan semua direktori harus dipindahkan ke "***/home[USER]/modul2/indomie/***".

### Soal 3.d.

Untuk setiap direktori yang dipindahkan ke "***/home/[USER]/modul2/indomie/***" harus membuat dua file kosong. File yang pertama diberi nama "**coba1.txt**", lalu 3 detik kemudian membuat file bernama "**coba2.txt**". (contoh : "***/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt***").

## Kendala 

Kendala yang dialami :
1. Bobot soal yang sangat sulit bagi kami untuk dikerjakan
2. Soal yang dibuat terlalu belibet
3. Soal yang terlalu banyak dan susah, selain itu kami belum terbiasa dengan fungsi-fungsi program c yang bisa digunakan di ubuntu sehingga kami susah untuk mengerjakan semua soal dan membutuhkan waktu yang cukup lama untuk mengerjakannya
a
