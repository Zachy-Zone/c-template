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
#include "define_macros_test.h"

#include "variables_test.h"

#include "time_functions.h"
#include "string_functions.h"

#include "time_functions_test.h"
#include "string_functions_test.h"

#include "c_template_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Name: Global Variables
-----------------------------------------------------------------------------------------------------------
*/

unsigned int countTest;
char data_test[BUFFER_SIZE];



/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: test
Description: Run the test
-----------------------------------------------------------------------------------------------------------
*/

void test(void)
{
  // Variables
  int total_test = TOTAL_TEST;
  int count = 0;
  char data[MAXIMUM_TIME_STRING_SIZE];

  // initialize the variables
  //test_settings = 1;
  //debug_settings = 1;
  //production_settings = 0;

  // set the database to the test database
  //memset(database_name,0,sizeof(database_name));
  //memcpy(database_name,DATABASE_NAME_TEST,sizeof(DATABASE_NAME_TEST)-1);

  // reset the test database
  //delete_database(DATABASE_COLLECTION_TEST);

  // get the current UTC time as a string
  currentTime(data);

  // print the start message
  fprintf(stdout,COLOR_PRINT_YELLOW TEST_OUTLINE "\nStarting " PROGRAM_VERSION " Test\n%s\n" TEST_OUTLINE "\n" COLOR_PRINT_END,data);
  fflush(stdout);

  // start the timer
  clock_t begin = clock();
  
  // run the tests
  count += time_functions_test();
  count += string_functions_test();

  // get the timer data
  clock_t end = clock();
  double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;  

  // delete the database
  //delete_database(DATABASE_NAME_TEST);

  // write the end test message
  fprintf(stdout,COLOR_PRINT_YELLOW TEST_OUTLINE "\n" PROGRAM_VERSION " Test Results\n%s\nCompleted in: %f seconds, Passed Test: %u, Failed Test: %u\n" TEST_OUTLINE "\n" COLOR_PRINT_END,data,timeSpent,count,total_test - count);
  fflush(stdout);
  return;
}
