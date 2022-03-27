#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *const *argv) {
  int c = 0;
  unsigned int uiMaxCount = 10;
  while ((c = getopt(argc, argv, "n:")) != -1) {
    switch (c) {
    case 'n':
      uiMaxCount = atoi(optarg);
      break;

    default:
      break;
    }
  }

  char szFileName[32] = {};
  sprintf(szFileName, "tests/%d.bin", uiMaxCount);

  const int sizeOfValueType = sizeof(short);
  short *randomValues = malloc(uiMaxCount * sizeOfValueType);

  srand(time(NULL));
  for (int i = 0; i < uiMaxCount; ++i) {
    // randomValues[i] = rand() & 0xffff;
    randomValues[i] = (uiMaxCount - i) & 0xffff;
  }

  FILE *pFile = fopen(szFileName, "wb+");

  if (!pFile) {
    printf("ERROR: File open proccess failed.\n");
    return EXIT_FAILURE;
  }

  unsigned int result =
      fwrite(randomValues, sizeOfValueType, uiMaxCount, pFile);

  if (result != uiMaxCount) {
    printf("ERROR: Writing process failed.\n");
    return EXIT_FAILURE;
  }

  fclose(pFile);
  free(randomValues);

  return EXIT_SUCCESS;
}
