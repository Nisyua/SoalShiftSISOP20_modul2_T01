#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> //pid_t
#include <unistd.h> //fork()
#include <syslog.h>
#include <wait.h>
#include <dirent.h>
#include <sys/unistd.h>
#include <sys/wait.h>


int main() {
	pid_t child_id,child_id2,child_id3,child_id4,child_id5,child_id6;
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
	} else {
	while((wait(&status)) > 0);
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
	} else {
	while(wait((&status)) > 0);
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
            }
					}
				}
			}
		}
  	}
}
