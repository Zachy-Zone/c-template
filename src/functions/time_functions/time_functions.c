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
#include "variables.h"

#include "time_functions.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: currentTime
Description: Prints the current time in a string format
-----------------------------------------------------------------------------------------------------------
*/

void currentTime(char *data)
{  
  // Variables
  time_t current_date_and_time;
  struct tm current_UTC_date_and_time;
  
  // get the current time
  time(&current_date_and_time);

  // get a time struct and get it in UTC
  gmtime_r(&current_date_and_time,&current_UTC_date_and_time);

  // format the time struct to a string
  strftime(data,MAXIMUM_TIME_STRING_SIZE,"%a %d %b %Y %H:%M:%S UTC",&current_UTC_date_and_time);

  return;
}