#include"Sort.h"

// Á´Ê½»ùÊýÅÅÐò
#define MAX_NUM_OF_KEY 8
#define RADIX 10
#define MAX_SPACE 10000
typedef int KeysType;
typedef char InfoType;
typedef struct {
	KeysType Key;
	InfoType otherItems;
}SLCell;
typedef struct {
	SLCell r[MAX_SPACE];
	int keyNum;
	int recNum;
}SLList;
typedef int ArrType[RADIX];

