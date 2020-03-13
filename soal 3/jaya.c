#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <unistd.h>

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
 	 } else {
	child_id3 = fork();
  
  if (child_id3 < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

     if (child_id3 == 0) {
    // this is child
        char *argv[] = {"unzip", "jpg.zip", NULL};
        execv("/usr/bin/unzip", argv);
    }
   // char *argv[] = {"mkdir", "-p", "folderku", NULL};
   // execv("/bin/mkdir", argv);
 // } else {
   //   wait (5);
     // char *argv[] = {"touch", "folderku/fileku.txt", NULL};
     // execv("/usr/bin/touch", argv);
	//MASIH 3A DAN 3B AJA
  }
}
}

