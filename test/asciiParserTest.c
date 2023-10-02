#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/*****************************TEMPLATE INCLUDE**************************************/
#define ASCII_PARSER_INLINE_IMPLEMENTATION
#define ASCII_PARSER_STATIC_IMPLEMENTATION

//following just for testing
#define ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
#include "asciiParser_t.h" //Prototype
#undef ASCII_PARSER_ONLY_PROTOTYPE_DECLARATION
#include "asciiParser_t.h" //Implementation
/***********************************************************************************/
int main(void)
{
    clock_t startTime = clock();
    
    assert(0xCAFECAFE ==  ascii_parseUnsignedHex("cafecafe"));
    assert(0xCAFE ==  ascii_parseUnsignedHex("cafe"));
    assert(0x1234 ==  ascii_parseUnsignedHex("1234"));
    assert(0xaBc9 ==  ascii_parseUnsignedHex("aBc9"));


    assert(12345 ==  ascii_parseUnsignedDecimal("12345"));
    assert(99999 ==  ascii_parseUnsignedDecimal("99999"));
    assert(0 ==  ascii_parseUnsignedDecimal("000000"));
    assert(9 ==  ascii_parseUnsignedDecimal("000009"));


    assert(-99999 ==  ascii_parseSignedDecimal("-99999"));
    assert(99999 ==  ascii_parseSignedDecimal("+99999"));
    assert(99999 ==  ascii_parseSignedDecimal("99999"));
    assert(0 ==  ascii_parseSignedDecimal("-0"));
    assert(0 ==  ascii_parseSignedDecimal("+0"));
    assert(0 ==  ascii_parseSignedDecimal("0"));

    assert(0x0a == ascii_parseByteHex("0A"));
    assert(0xa0 == ascii_parseByteHex("a0"));
    assert(0xff == ascii_parseByteHex("ff"));

    assert(0xcf == ascii_parseByteHex("cf"));
    assert(0xfc == ascii_parseByteHex("fc"));

    double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    printf("Done in %f seconds\n", elapsedTime);
}