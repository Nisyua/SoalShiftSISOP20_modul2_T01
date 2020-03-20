# SoalShiftSISOP20_modul2_T01

Repository ini Sebagai Laporan Resmi Soal Shift Modul 2 Praktikum Sistem Operasi 2020

## Disusun oleh : 

  - Anis Saidatur Rochma    [05311840000002]
  - Kadek Nesya Kurniadewi  [05311840000009]

## Soal 1

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

## Soal 2

Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program.

## A 

Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].

```C
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
```
* Pertama-tama, kita harus input library yang diperlukan

```C
int main() {
    pid_t child_id, child_id1, child_id2, child_id3;

    int status;

    child_id1 = fork();
    if (child_id1 < 0) {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }
    if (child_id1 == 0) {  
        char *argv[] = {"mkdir", "-p", "khusus", NULL};
        execv("/bin/mkdir", argv);
    }
```
* Selain input library, kita juga harus mendeklarasikan variabel yang akan digunakan seperti ` pid_t child_id, child_id1, child_id2, child_id3;`
* Kemudian kode selanjutnya dibuat untuk membuat folder bernama `khusus` pada direktori "***/home/[USER]/***"
```C
char str[50], var[100], final[100], save[100]; 
    int a; // untuk t=(t%1000)+100
    time_t t, w; //deklarasi variabel
    t = time(NULL);
    struct tm *tm, *wm; 
    
    tm = localtime(&t);
    strftime(str, 50, "khusus/%Y-%m-%d_%H:%M:%S", tm);
```
* kita harus mendeklarasikan string terlebih dahulu :
  `str[50]` adalah besar string untuk nama folder,
  `var[100]` adalah besar string untuk urlnya,
  `final[100]` adalah besar string untuk nama filenya,
  `save[100]` adalah gabungan dari str(nama folder) dan file(nama file).
```C
child_id2 = fork();
	if (child_id2 < 0) {
		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	}
	if (child_id2== 0) {
		char *argv[] = {"mkdir", "-p", str, NULL};
		execv("/bin/mkdir", argv);
	}
```
* variabel t digunakan untuk menyimpan timestamp dalam format epoch
* variabel `tm` digunakan untuk menyimpan timestamp yang sudah sesuai dengan localtime
* `strftime` digunakan untuk melakukan formating dari waktu `tm` menjadi string sesuai dengan format yg diminta (YYYY-mm-dd_HH:ii:ss) ke dalam buffer str sebesar 50.
* Kode diatas merupakan kode yang akan membuat folder baru di dalam folder **khusus** yang nantinya nama folder tersebut sesuai dengan timestamp sesuai dengan format yang diminta yaitu ***(YYYY-mm-dd_HH:ii:ss)***
### Screenshots
   1. Setelah program sudah dicompile dan sudah di run, maka nanti pada ***/home/[USER]/*** ada folder baru dengan nama `khusus`
   
![](img/ssfolderkhusus.jpg)

   2. Jika folder khusus tersebut dibuka, akan ada folder baru dengan format nama timestamp ***(YYYY-mm-dd_HH:ii:ss)***
   
![](img/ssfolder.jpg)

## B

*Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran **(t%1000)+100 piksel** dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].
* soal nomor 2B ini merupakan lanjutan dari soal nomor 2A dan saling berhubungan sehingga code yang dibuat menjadi satu, untuk memenuhi permintaan soal nomor 2B ini memiliki source code seperti dibawah ini :
```C
	child_id3 = fork(); 
	
	if (child_id3 < 0) {
	    exit(EXIT_FAILURE);
	}
	int i;
	for (i=0;i<20;i++) {
		w = time(NULL);
		wm = localtime(&w);		
		a = (w%1000)+100;
		sprintf (var, "https://picsum.photos/%d", a); //link download yang akan dituju
		strftime(final, 50, "%Y-%m-%d_%H:%M:%S", wm);
		sprintf (save, "%s/%s", str, final); 
		char *args[] = {"wget", "-O", save, var, NULL}; 
		if (fork()==0) execv("/usr/bin/wget", args);
		sleep(5);
	}    
}
```
* `child_id3` ini merupakan step untuk melakukan penyimpanan gambar yang akan di download pada link `https://picsum.photos/` dan nantinya akan disimpan didalam folder baru `child_id2` dengan format nama timestamp yang merupakan child dari `child_id1` yaitu folder dengan nama `khusus`
* pada langkah ini, kita melakukan looping sebanyak 20 kali karena maksimal gambar yang akan disimpan pada `child_id3` maksimal 20 gambar. Gambar yang nantinya akan didownload memiliki format nama timestamp yaitu ***%Y-%m-%d_%H:%M:%S***
* `if (fork()==0) execv("/usr/bin/wget", args);` perintah ini merupakan perintah untuk melakukan downloading dengan waktu download 5 detik setiap gambarnya menggunakan perintah `sleep(5);`

### Screenshot
Screenshot 20 gambar dengan format nama timestamp yang terletak dalam folder baru didalam folder khusus dengan format nama timestamp

![](img/ss20gambar.jpg)

## Soal 3

*Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan (multiprocessing).*

[Source Code](http://github.com/SoalShiftSISOP20_modul2_T01/soal_3/jaya112.c)
### Library yang digunakan

```C
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> //pid_t
#include <unistd.h> //fork()
#include <syslog.h>
#include <wait.h>
#include <dirent.h>
#include <sys/unistd.h>
#include <sys/wait.h>
```

## A

*Program buatan jaya harus bisa membuat dua direktori di "***/home/[USER]/modul2/***". Direktori yang pertama diberi nama "indomie", lalu *lima detik* kemudian membuat direktori yang kedua bernama "sedaap".

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

* `pid_t child_id,child_id2,child_id3;` untuk menyimpan PID (Parent ID) di masing-masing variabel child. sedangkan untuk `int status` berfungsi untuk deklarasi variabel status bertipe integer.
* membuat direktori pada `/home/nisyua/modul_2/ ` bernama **indomie** menggunakan perintah `mkdir`dan terdapat argumen `-p` yang berfungsi untuk membuat directory pada `/home/nisyua/modul_2` yang belum terbuat.
* syntax argument : `argv[n] = { {your-program-name}, {argument[1]}, {argument[2]},.....,{argument[n-2]}, NULL };`
* parent process menunggu directory baru terbuat, setelah itu sleep(5) atau selang 5 detik parent process membuat child process lagi untuk membuat direktori baru yaitu **sedaap** perintah tersebut disimpan dalam  `argv`


## B

Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori "***/home/[USER]/modul2/***". 

```C
child_id3 = fork();
  
	if (child_id3 < 0) {
 		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	 }

	if (child_id3 == 0) {
    	// this is child
		char *argv[] = {"unzip", "jpg.zip", NULL}; //
		execv("/usr/bin/unzip", argv);
	}
```

* `if (child_id3 == 0)` maka proses berhasil/dapaat dijalankan. 
* Untuk mengekstrak file **jpg.zip** menggunakan perintah `unzip` yang dieksekusi oleh `execv("/usr/bin/unzip", argv);`


## C

*Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori "***/home/[USER]/modul2/jpg/"***) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke "***/home/[USER]/modul2/sedaap/***" dan semua direktori harus dipindahkan ke "***/home[USER]/modul2/indomie/***".

```C
child_id4 = fork();

	if (child_id4 < 0){
		exit(EXIT_FAILURE);
	}

	if (child_id4 == 0){
		execl("/usr/bin/find", "find", "/home/nisyua/modul_2/jpg", "-type", "f", "-name", "*", "-exec", "mv", "-t", "/home/nisyua/modul_2/sedaap", "{}", "+", (char *) NULL);
	} else {
	while ((wait(&status)) > 0);
	  child_id5 = fork();

	if(child_id5 < 0) {
		exit(EXIT_FAILURE);
	}

	if(child_id5 == 0) {
		execl("/usr/bin/find", "find", "/home/nisyua/modul_2/jpg/", "-mindepth", "1", "-type", "d", "-name", "*", "-exec", "mv", "-t", "/home/nisyua/modul_2/indomie/", "{}", "+", (char *) NULL);
	}
```
* Pada proses `if (child_id4 == 0)` , `find` di jpg yang bertipe file dengan semua nama di direktori ***/home/nisyua/modul_2/jpg*** setelah itu `move` semuanya ke ***sedaap*** dan tunggu selama 2detik. 
* Sama seperti child_id4, pada proses `if(child_id5 == 0)` juga sama sistemnya. `find` di jpg yang bertipe direktori pada ***/home/nisyua/modul_2/jpg***, lalu pindahkan semua ke direktori ***indomie***

## D
*Untuk setiap direktori yang dipindahkan ke "***/home/[USER]/modul2/indomie/***" harus membuat dua file kosong. File yang pertama diberi nama "**coba1.txt**", lalu 3 detik kemudian membuat file bernama "**coba2.txt**". (contoh : "***/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt***").

```C
child_id6 = fork();

	if (child_id6 < 0) {
		exit(EXIT_FAILURE);
	}

	if (child_id6 == 0) {
		execl("/usr/bin/find", "find", "/home/nisyua/modul_2/indomie", "-mindepth", "1", "-type", "d", "-name", "*", "-exec", "sh", "-c", "for d; do touch $d/coba1.txt;done", "{}", "+", (char *) NULL);
	} else {
	while(wait((&status)) > 0);
	sleep(3);
	execl("/usr/bin/find", "find", "/home/nisyua/modul_2/indomie", "-mindepth", "1", "-type", "d", "-name", "*", "-exec", "sh", "-c", "for d; do touch $d/coba2.txt;done", "{}", "+", (char *) NULL);
```
* Terdapat fungsi `find` yang berfungsi untuk mencari semua nama yang bertipe direktori di ***/home/nisyua/modul_2/indomie*** 
* Berfungsi untuk membuat fie ***coba1.txt*** di tiap direktori yang ada.
```C
"-exec", "sh", "-c", "for d; do touch $d/coba1.txt;done", "{}", "+", (char *) NULL);
```
* Sleep(3) atau selang 3 detik, maka membuat file ***Coba2.txt*** pada setiap direktori yang ada
```c
"-exec", "sh", "-c", "for d; do touch $d/coba2.txt;done", "{}", "+", (char *) NULL);
``` 

## Screenshots
![](img/mod2no3.png)
![](img/mod2no3_1.png)
![](img/mod2no3_2.png)
![](img/indomie.png)
![](img/indomie2.png)
![](img/indomietxt.png)

## Kendala 

Kendala yang dialami :
1. Bobot soal yang sangat sulit bagi kami untuk dikerjakan
2. Soal yang dibuat terlalu belibet
3. Soal yang terlalu banyak dan susah, selain itu kami belum terbiasa dengan fungsi-fungsi program c yang bisa digunakan di ubuntu sehingga kami susah untuk mengerjakan semua soal dan membutuhkan waktu yang cukup lama untuk mengerjakannya
4. Jarak yang cukup jauh mengakibatkan kami susah untuk berkordinasi karena Covid-19 .
