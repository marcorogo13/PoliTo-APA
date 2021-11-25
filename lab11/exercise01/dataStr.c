#include "dataStr.h"

int
readData (
  FILE *fp,
  data_t *data
  )
{
  char  row[MAXC];

  int retValue;


  retValue = fscanf(fp, "%s %s %d %d", data->registerNumber, data->surname, &data->numberCreditLoaded, &data->numberCreditPassed);
  

  return (retValue);
}


void
writeData (
  FILE *fp,
  data_t data
  )
{
  fprintf(fp, "%s\n", data.registerNumber);

  return;
}


int
compare (
  data_t d1,
  data_t d2
  )
{
  return (strcmp(d1.registerNumber, d2.registerNumber));
}

