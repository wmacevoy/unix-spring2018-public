#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>

void myls(const char *dirname) {
  DIR *dir = opendir(dirname);
  if (dir == NULL) {
    perror(NULL);
    exit(1);
  }
  for (;;) {
    struct dirent *entry = readdir(dir);
    if (entry == NULL) break;
    printf("%s\n", entry->d_name);
  }
  if (closedir(dir) != 0) {
    perror(NULL);
    exit(1);
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
