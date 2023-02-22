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

#include "string_functions.h"

#include "variables_test.h"
#include "string_functions_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: string_functions_test
Return: The number of passed file_functions test
-----------------------------------------------------------------------------------------------------------
*/

int string_functions_test(void)
{
  // reset the global variables
  countTest = 0;

  // Define Macros

  // Variables

  // write the start test message
  fprintf(stdout,COLOR_PRINT_YELLOW TEST_OUTLINE "\nstring_functions_test - Total test: %u\n" TEST_OUTLINE "\n\n" COLOR_PRINT_END,STRING_FUNCTIONS_TOTAL_TEST);
  fflush(stdout);

  // start the timer
  clock_t begin = clock();

  // run the test

  // createSession
  clock_t createSessionBegin = clock();
  memset(data_test,0,sizeof(data_test));
  if (createSession(data_test) == 1 && strlen(data_test) == SESSION_LENGTH)
  {
    fprintf(stdout,COLOR_PRINT_GREEN "PASSED! createSession - Completed in: %f seconds\n" COLOR_PRINT_END,(double)(clock() - createSessionBegin) / CLOCKS_PER_SEC);
    fflush(stdout);
    countTest++;
  }
  else
  { 
    fprintf(stdout,COLOR_PRINT_RED "FAILED! createSession\n" COLOR_PRINT_END);
    fflush(stdout);
  }

  // get the timer data
  clock_t end = clock();
  double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

  // write the end test message
  fprintf(stdout,COLOR_PRINT_YELLOW "\n\n" TEST_OUTLINE "\nstring_functions_test - Completed in: %f seconds, Passed test: %u, Failed test: %u\n" TEST_OUTLINE "\n\n\n" COLOR_PRINT_END,timeSpent,countTest,STRING_FUNCTIONS_TOTAL_TEST-countTest);
  fflush(stdout);
  return countTest;
}