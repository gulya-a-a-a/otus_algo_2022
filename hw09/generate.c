#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>

typedef enum { Ascending, Descending, Random } NumbersOrder;

int main(int argc, char *const *argv) {
  int c = 0;

  unsigned int uiMaxCount = 10;
  char szOutputPath[128] = {};
  NumbersOrder isSortedOrder = Random;

  while ((c = getopt(argc, argv, "n:o:s:")) != -1) {
    switch (c) {
    case 'n':
      uiMaxCount = atoi(optarg);
      break;

    case 'o':
      sprintf(szOutputPath, "%s", optarg);
      break;

    case 's':
      int value = atoi(optarg);
      if (value > Random || value < Ascending) {
        printf("Wrong order of numbers. Should be 0 < s < 2.");
        return EXIT_FAILURE;
      }
      isSortedOrder = (NumbersOrder)value;
      break;
    default:
      break;
    }
  }

  if (!strncmp(szOutputPath, "\0", 1)) {
    sprintf(szOutputPath, "tests");
  }

  struct stat sb = {};
  if ((stat(szOutputPath, &sb) != 0) || !S_ISDIR(sb.st_mode)) {
    mkdir(szOutputPath, S_IRWXU);
  }

  char szFileName[256] = {};
  sprintf(szFileName, "%s/%d.bin", szOutputPath, uiMaxCount);

  const int sizeOfValueType = sizeof(short);
  short *randomValues = malloc(uiMaxCount * sizeOfValueType);

  srand(time(NULL));
  for (int i = 0; i < uiMaxCount; ++i) {
    switch (isSortedOrder) {
    case Ascending:
      randomValues[i] = i & 0xffff;
      break;

    case Descending:
      randomValues[i] = (uiMaxCount - i) & 0xffff;
      break;

    case Random:
      randomValues[i] = rand() & 0xffff;
      break;

    default:
      break;
    }
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
