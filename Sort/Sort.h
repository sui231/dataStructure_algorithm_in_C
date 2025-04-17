#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 20
#define NULL_KEY 0
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

#define SEQ(a, b) (!strcmp(a,b))
#define SLT(a, b) (strcmp(a,b) < 0)
#define SLQ(a, b) (strcmp(a,b) <= 0)

typedef int KeyType;
typedef InfoType;
typedef int Status;

typedef struct RecordType {
	KeyType key;
	InfoType info;
}RecordType; // record type
typedef RecordType ElemType;

typedef struct SqList {
	RecordType r[MAXSIZE + 1]; // r[0]ÎªÉÚ±ø»ò»º³åÇø
	int length;
}SqList;

void swap(RecordType* a, RecordType* b);