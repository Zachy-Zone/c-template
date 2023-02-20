/*
********************************************************************************************************************************************************
Parts of this file, similarities of code or ideas are from X-CASH Foundation - All Rights Reserved Copyright (C) 2018-2022
See "X-CASH Foundation - Copyrighted Software License" for more details
********************************************************************************************************************************************************
*/

#ifndef DEFINE_MACRO_FUNCTIONS_H_   /* Include guard */
#define DEFINE_MACRO_FUNCTIONS_H_

#include "define_macros.h"
#include "variables.h"


/*
-----------------------------------------------------------------------------------------------------------
Using define macros instead of functions for increased efficiency
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: pointer_reset
Description: Reset the memory used by the pointer, and sets the pointer to NULL to avoid a dangling pointer
Parameters:
  pointer - Any pointer type
-----------------------------------------------------------------------------------------------------------
*/

#define pointer_reset(pointer) \
free(pointer); \
pointer = NULL;

#endif