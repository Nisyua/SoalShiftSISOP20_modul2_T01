#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main (int argc, char *argv[]) {
  if (argc != 5) {
    printf("Argumen salah\n");
    exit(EXIT_FAILURE);
  }
  if (!(((atoi(argv[1]) >= 0) && (atoi(argv[1]) < 60)) || ((strcmp(argv[1],"*")) == 0))) {
    printf("Argumen pertama antara 0-59 or *\n");
    exit(EXIT_FAILURE);
  }
  if (!(((atoi(argv[2]) >= 0) && (atoi(argv[2]) < 60)) || ((strcmp(argv[2],"*")) == 0))) {
    printf("Argumen kedua antara 0-59 or *\n");
    exit(EXIT_FAILURE);
  }
  if (!(((atoi(argv[3]) >= 0) && (atoi(argv[3]) < 24)) || ((strcmp(argv[3],"*")) == 0))) {
    printf("Argumen ketiga antara 0-23 or *\n");
    exit(EXIT_FAILURE);
  }

  struct tm tm;
  time_t varwaktu;

  pid_t pid, sid; // Variabel untuk menyimpan PID
  pid = fork(); // Menyimpan PID dari Child Process

  if (pid < 0) {
     exit(EXIT_FAILURE); // Keluar saat fork gagal
  }
  if (pid > 0) {
    exit(EXIT_SUCCESS); // Keluar saat fork berhasil
  }
  umask(0);
  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
    varwaktu = time(NULL);
    tm = *localtime(&varwaktu);
    if ((tm.tm_sec == atoi(argv[1]) || ((strcmp(argv[1],"*")) == 0)) && (tm.tm_min == atoi(argv[2]) || ((strcmp(argv[2],"*")) == 0)) && (tm.tm_hour == atoi(argv[3]) || ((strcmp(argv[3],"*") == 0)))) {

      if (fork()==0) {
        execl("/bin/bash", "bash", argv[4], NULL);
        sleep(1);
      }
    }
  }
}
