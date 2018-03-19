#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void myls_bad_sys(const char *dir) {
  char cmd[1024];
  snprintf(cmd,sizeof(cmd),"/bin/ls '%s'",dir);
  system(cmd);
}

void myls(const char *dir) {
  // char buf[1024];
  // snprinf(sizeof(buf),buf,"/bin/ls '%s'",dir);
  // system(cmd);
  int pid = fork();
  if (pid == 0) {
    execl("/bin/ls","ls","--",dir,0);
    exit(1);
  } else {
    waitpid(pid,0,0);
  }
}

int main(int argc, char *argv[])
{
  if (argc == 1) {
    myls(".");
  } else {
    for (int i=1; i<argc; ++i) {
      myls(argv[i]);
    }
  }

  return 0;
}
