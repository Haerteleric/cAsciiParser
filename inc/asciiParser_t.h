/**
 * Portable ASCII Parser template implementation
 * 
 * Author:    Haerteleric
 * 
 * MIT License
 * 
 * Copyright (c) 2023 Eric Härtel
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/
#include <stddef.h>
#include <stdbool.h>

#ifndef _ASCII_PARSER_INCLUDED
#define _ASCII_PARSER_INCLUDED
#endif

#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_isValidBinaryChar(char c)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    if ( (c < '0') || (c > '1') )
    {
        return false;
    }

    return true;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)


#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_isValidDecimalChar(char c)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    if ( (c < '0') || (c > '9') )
    {
        return false;
    }

    return true;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_isValidHexadecimalChar(char c)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    if(
        ( (c >= '0') && (c <= '9') )
        || ( (c >= 'a') && (c <= 'f') )
        || ( (c >= 'A') && (c <= 'F') )
    )
    {
        return true;
    }

    return false;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_isValidAlphaNumericChar(char c)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    if(
        ( (c >= '0') && (c <= '9') )
        || ( (c >= 'a') && (c <= 'z') )
        || ( (c >= 'A') && (c <= 'Z') )
    )
    {
        return true;
    }

    return false;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_onlyContainsValidDecimalChars(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    while ( true )
    {
        if( !ascii_isValidDecimalChar(*str) )
        {
            break;
        }
        str++;
    }
    
    return (*str == '\0');
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_onlyContainsValidHexadecimalChars(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    while ( true )
    {
        if( !ascii_isValidHexadecimalChar(*str) )
        {
            break;
        }
        str++;
    }
    
    return (*str == '\0');
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_onlyContainsValidBinaryChars(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    while ( true )
    {
        if( !ascii_isValidBinaryChar(*str) )
        {
            break;
        }
        str++;
    }
    
    return (*str == '\0');
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
bool ascii_onlyContainsValidAlphaNumericChars(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    while ( true )
    {
        if( !ascii_isValidBinaryChar(*str) )
        {
            break;
        }
        str++;
    }
    
    return (*str == '\0');
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
unsigned char ascii_hexChar2UnsignedValue(char input)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    if( (input >= 'A') && (input <= 'Z') )
    {
        return input - ('A'- 0xA);
    }
    else if ( (input >= 'a') && (input <= 'z') )
    {
        return input - ('a'- 0xA);
    }
    else if ( (input >= '0') && (input <= '9') )
    {
        return input - ('0');
    }
    else
    {
        return 0xFF;
    }
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
unsigned char ascii_parseByteHex(const char *str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{  
    unsigned char result = ascii_hexChar2UnsignedValue(*str);
    if(ascii_isValidHexadecimalChar(*(++str)))
    {
        result <<= 4;
        result += ascii_hexChar2UnsignedValue(*str);
    }
    return result;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
unsigned int ascii_parseUnsignedHex(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    unsigned int result = 0;
    for (unsigned int i = 0; i < (sizeof(unsigned int)*2); i++)
    {
        if(!ascii_isValidHexadecimalChar(str[i]))
           break;

        result <<= 4;
        result |= ascii_hexChar2UnsignedValue(str[i]);
    }
    return result;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
unsigned int ascii_parseUnsignedDecimal(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    unsigned int decMask = 1000000000; // 4,294,967,295 is unsigned int Max (2^32)
    unsigned int result = 0;
    char currentDigit = 0;

    while (decMask)
    {
        currentDigit = *(str++);

        if(!ascii_isValidDecimalChar(currentDigit))
            break;

        result *=10;

        //Offset ASCI
        currentDigit -= '0';

        result += currentDigit;
    }
    return result;
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)



#ifdef ASCII_PARSER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef ASCII_PARSER_STATIC_IMPLEMENTATION
static
#endif 
int ascii_parseSignedDecimal(const char * str)
#ifdef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
  int signum = 1;
  if(*str == '-')
  {
      signum = -1;
      str++;
  }
  if(*str == '+')
  {
      str++;
  }
  return signum * ascii_parseUnsignedDecimal(str);
}
#endif // NOT(ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION)
