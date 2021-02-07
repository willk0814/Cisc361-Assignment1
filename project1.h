#include <stdio.h>
#include <stdlib.h>

typedef struct MP3{
	char* artistName;
	char* songTitle;
	int year;
	int runTime;
	struct MP3* next;
	struct MP3* prev;
} MP3;

