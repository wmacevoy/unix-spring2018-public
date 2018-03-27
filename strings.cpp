#include <string>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, const char *argv[]) {

  const char *programName = argv[0];
  const char *pathArg = argv[1];

  std::string name = programName;
  std::string path = pathArg;

  std::string dirPath = path + ".d";

  mkdir(dirPath.c_str(),0755); 

  return 0;
}
