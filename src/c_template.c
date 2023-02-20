/*
********************************************************************************************************************************************************
Parts of this file, similarities of code or ideas are from X-CASH Foundation - All Rights Reserved Copyright (C) 2018-2022
See "X-CASH Foundation - Copyrighted Software License" for more details
********************************************************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <pthread.h>
#include <netdb.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "define_macros_test.h"
#include "structures.h"
#include "variables.h"

#include "time_functions.h"
#include "c_template_test.h"
#include "c_template.h"

/*
-----------------------------------------------------------------------------------------------------------
Global Variables
-----------------------------------------------------------------------------------------------------------
*/

// Parameters
unsigned int totalThreads;
unsigned int productionSettings;


/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: setParameters
Description: Sets the parameters
Parameters:
  parametersCount - The parameter count
  parameters - The parameters
-----------------------------------------------------------------------------------------------------------
*/

void setParameters(int parametersCount, char* parameters[])
{
  // define macros
  #define MINIMUM_THREADS_AMOUNT 2

  // Variables
  int count;

  // set the default parameter settings
  productionSettings = 1;
  totalThreads = get_nprocs();

  // check the parameters
  for (count = 0; count < parametersCount; count++)
  { 
    if (strncmp(parameters[count],"--test",BUFFER_SIZE) == 0)
    {
      productionSettings = 0;
      test();
      exit(0);
    }
    if (strncmp(parameters[count],"--parameters",BUFFER_SIZE) == 0)
    {
      printf(INVALID_PARAMETERS_ERROR_MESSAGE);
      exit(0);
    }
    if (strncmp(parameters[count],"--total-threads",BUFFER_SIZE) == 0)
    {
      if (totalThreads >= MINIMUM_THREADS_AMOUNT)
      {
        sscanf(parameters[count+1], "%d", &totalThreads);
      }
      else
      {
        totalThreads = MINIMUM_THREADS_AMOUNT;
      }
    }    
  }
  return;

  #undef MINIMUM_THREADS_AMOUNT
}


/*
-----------------------------------------------------------------------------------------------------------
Name: printSettings
Description: Prints the settings
-----------------------------------------------------------------------------------------------------------
*/

void printSettings(void)
{
  // Variables
  char data[MAXIMUM_TIME_STRING_SIZE];

  // get the current UTC time as a string
  currentTime(data);

  // print the settings
  fprintf(stdout,COLOR_PRINT_YELLOW TEST_OUTLINE "\nStarting " PROGRAM_VERSION "\n%s\n\nSETTINGS\nPort: %u\nThreads: %u\n" TEST_OUTLINE "\n" COLOR_PRINT_END,data,PROGRAM_PORT,totalThreads);
  fflush(stdout);
  return;
}

/*
-----------------------------------------------------------------------------------------------------------
Name: start_timer_threads
Description: Starts the timer threads
-----------------------------------------------------------------------------------------------------------
*/

void start_timer_threads(void)
{
  return;
}



/*
-----------------------------------------------------------------------------------------------------------
Name: main
Description: The start point of the program
Parameters:
  parametersCount - The parameter count
  parameters - The parameters
Return: 0 if successfull
-----------------------------------------------------------------------------------------------------------
*/

int main(int parametersCount, char* parameters[])
{
  // initialize the random seed
  srand(time(NULL));

  // set the parameters
  setParameters(parametersCount,parameters);

  // print the settings
  printSettings();

  return 0;
}