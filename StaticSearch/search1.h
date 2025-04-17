#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define GT(a, b) ((a) > (b))
#define GQ(a, b) ((a) >= (b))

#define SEQ(a, b) (!strcmp(a,b))
#define SLT(a, b) (strcmp(a,b) < 0)
#define SLQ(a, b) (strcmp(a,b) <= 0)
#define SGT(a, b) (strcmp(a,b) > 0)
#define SGQ(a, b) (strcmp(a,b) >= 0)

typedef int KeyType;
typedef char InfolType;
typedef struct {
	KeyType key;
	InfolType infol;
}ElemType;

typedef struct {
	ElemType* elem; // 元素数组(elem[0]为哨兵)
	int length;
}SSTable; // Sorted String Table

int sequentialSearch(SSTable ST, KeyType key);
int binarySearch(SSTable ST, KeyType key);
int binarySearch1(SSTable ST, KeyType key, int left, int right);