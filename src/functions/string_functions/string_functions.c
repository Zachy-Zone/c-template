#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>
#include <openssl/sha.h>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "variables.h"

#include "string_functions.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: bytesToString
Description: Converts bytes to a string
Parameters:
  bin - The binary data
  binsz - The size of the binary data
  result - The string to save to
-----------------------------------------------------------------------------------------------------------
*/

void bytesToString(const unsigned char *bin, const unsigned int binsz,char* result)
{
  // Constants
  const unsigned char hex_str[]= "0123456789abcdef";

  // Variables
  unsigned int count;  

  for (count = 0; count < binsz; count++)
  {
    result[count * 2 + 0] = hex_str[(bin[count] >> 4) & 0x0F];
    result[count * 2 + 1] = hex_str[(bin[count]     ) & 0x0F];
  }
  return;
}


/*
-----------------------------------------------------------------------------------------------------------
Name: createSession
Description: Creates a random session
Parameters:
  result - The string where you want the random string to be saved to
Return: 0 if an error has occured, 1 if successfull
-----------------------------------------------------------------------------------------------------------
*/

int createSession(char *result)
{
  // Variables
  unsigned char data[SESSION_LENGTH];
  unsigned char hash[SHA512_DIGEST_LENGTH];

  // generate cryptographically secure random bytes
  if ((getrandom(data,SESSION_LENGTH,0)) == -1)
  {
    return 0;
  }

  // generate the hash
  SHA512(data,SESSION_LENGTH,hash);
  
  // convert the binary to a string
  bytesToString(hash,SHA512_DIGEST_LENGTH,result);

  return 1;
}
