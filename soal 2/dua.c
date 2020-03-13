#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

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
	char str[50], var[100], final[100], save[100];
	int a; // untuk t=(t%1000)+100
	time_t t, w;
	t = time(NULL);
	//printf("%ld\n", t); coba print bisa apa g
	struct tm *tm, *wm;
	tm = localtime(&t);
	strftime(str, 50, "khusus/%Y-%m-%d_%H:%M:%S", tm);
	//printf("%s\n", str);
	
	child_id2 = fork();
  
	if (child_id2 < 0) {
		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	}

	if (child_id2== 0) {
		char *argv[] = {"mkdir", "-p", str, NULL};
	  	execv("/bin/mkdir", argv);
	}
	
	//sleep (5);
	child_id3 = fork();
	
	if (child_id3 < 0) {
	exit(EXIT_FAILURE);
	}
	
	int i;
	for (i=0;i<20;i++) {
		w = time(NULL);
		wm = localtime(&w);
		//char *argv[] = {"mkdir", "-p", "khusus", NULL};
		a = (w%1000)+100;
		sprintf (var, "https://picsum.photos/%d", a);
		strftime(final, 50, "%Y-%m-%d_%H:%M:%S", wm);
		sprintf (save, "%s/%s", str, final);
		char *args[] = {"wget", "-O", save, var, NULL};
		
		strftime(str, 50, "khusus/%Y-%m-%d_%H:%M:%S", wm);
		if (fork()==0) execv("/usr/bin/wget", args);
	  	//execv("/bin/mkdir", argv);
		sleep(1);
	}
	
	
	
}

