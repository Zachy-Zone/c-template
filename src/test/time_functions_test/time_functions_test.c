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

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "define_macros_test.h"

#include "time_functions.h"

#include "variables_test.h"
#include "time_functions_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: time_functions_test
Return: The number of passed file_functions test
-----------------------------------------------------------------------------------------------------------
*/

int time_functions_test(void)
{
  // reset the global variables
  countTest = 0;

  // Define Macros

  // Variables

  // write the start test message
  fprintf(stdout,COLOR_PRINT_YELLOW TEST_OUTLINE "\ntime_functions_test - Total test: %u\n" TEST_OUTLINE "\n\n" COLOR_PRINT_END,TIME_FUNCTIONS_TOTAL_TEST);
  fflush(stdout);

  // start the timer
  clock_t begin = clock();

  // run the test

  // currentTime
  memset(data_test,0,sizeof(data_test));
  currentTime(data_test);
  if (strstr(data_test,"UTC") != NULL)
  {
    fprintf(stdout,COLOR_PRINT_GREEN "PASSED! currentTime" COLOR_PRINT_END);
    fflush(stdout);
    countTest++;
  }
  else
  {
    fprintf(stdout,COLOR_PRINT_RED "FAILED! currentTime" COLOR_PRINT_END);
    fflush(stdout);
  }

  // get the timer data
  clock_t end = clock();
  double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;  

  // write the end test message
  fprintf(stdout,COLOR_PRINT_YELLOW "\n\n" TEST_OUTLINE "\ntime_functions_test - Completed in: %f seconds, Passed test: %u, Failed test: %u\n" TEST_OUTLINE "\n\n\n" COLOR_PRINT_END,timeSpent,countTest,TIME_FUNCTIONS_TOTAL_TEST-countTest);
  fflush(stdout);
  return countTest;
}