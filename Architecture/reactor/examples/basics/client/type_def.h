


//*************************************
//*************************************
//********** GENERAL DEFINES **********
//*************************************
//*************************************

//****************************************
//****************************************
//***** GLOBAL DATA TYPE DEFINITIONS *****
//****************************************
//****************************************

#ifndef GLOBAL_DATA_TYPE_INIT		//(Do only once)
#define	GLOBAL_DATA_TYPE_INIT

#define	CONSTANT	const			//Define used for this as some compilers require an additional qualifier such as 'rom' to signify that a constant should be stored in program memory

#undef BOOL
#undef TRUE
#undef FALSE
#undef BYTE
#undef SIGNED_BYTE
#undef WORD
#undef SIGNED_WORD
#undef DWORD
#undef SIGNED_DWORD

//BOOLEAN - 1 bit:
typedef enum _BOOL { FALSE = 0, TRUE } BOOL;
//BYTE - 8 bit unsigned:
typedef unsigned char BYTE;
//SIGNED_BYTE - 8 bit signed:
typedef signed char SIGNED_BYTE;			//Don't use "char" - it is not necessarily signed!
//WORD - 16 bit unsigned:
typedef unsigned short int WORD;
//SIGNED_WORD - 16 bit signed:
typedef signed short int SIGNED_WORD;
//DWORD - 32 bit unsigned:
typedef unsigned int DWORD;
//SIGNED_DWORD - 32 bit signed:
typedef signed int SIGNED_DWORD;

//BYTE BIT ACCESS:
typedef union _BYTE_VAL
{
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
    } bits;
    BYTE Val;
} BYTE_VAL;

//WORD ACCESS
typedef union _WORD_VAL
{
    WORD val;
    struct
    {
        BYTE LSB;
        BYTE MSB;
    } byte;
    BYTE v[2];
} WORD_VAL;
#define LSB(a)          ((a).v[0])
#define MSB(a)          ((a).v[1])

//DWORD ACCESS:
typedef union _DWORD_VAL
{
    DWORD val;
    struct
    {
        BYTE LOLSB;
        BYTE LOMSB;
        BYTE HILSB;
        BYTE HIMSB;
    } byte;
    struct
    {
        WORD LSW;
        WORD MSW;
    } word;
    BYTE v[4];
} DWORD_VAL;
#define LOWER_LSB(a)    ((a).v[0])
#define LOWER_MSB(a)    ((a).v[1])
#define UPPER_LSB(a)    ((a).v[2])
#define UPPER_MSB(a)    ((a).v[3])

//EXAMPLE OF HOW TO USE THE DATA TYPES:-
//	DWORD_VAL variable_name;		    //Define the variable
//	variable_name.val = 0xffffffff;		//Writing 32 bit value
//	variable_name.word.LSW = 0xffff;	//Writing 16 bit value to the lower word 
//	variable_name.byte.LOLSB = 0xff;	//Writing 8 bit value to the low word least significant byte
//	variable_name.v[0] = 0xff;			//Writing 8 bit value to byte 0 (least significant byte)

#endif		//GLOBAL_DATA_TYPE_INIT








