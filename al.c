#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *inFile;
  FILE *outFile;

  if (argc < 2 || argc > 3) {
    printf("Invalid parameter\nUsage: <program> <path to input file> <optional "
           "path to output file>\n");
    exit(1);
  }

  inFile = fopen(argv[1], "r");
  if (inFile) {
    /*readfile*/
  } else {
    printf("Could not open/read file %s\n", argv[1]);
    exit(-1);
  }

  if (arc == 3) {
    outFile = fopen(argv[2], "w");
    if (outFile) {
      /*write file*/
    } else {
      printf("Could not open/write file %s\n", argv[2]);
      exit(-1);
    }
  }else{
  	/*print output in console*/
  }

  return 0;
}