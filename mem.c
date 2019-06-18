#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

void allocate_mem(int*** arr, int x, int y){
	*arr = (int**)malloc(y * sizeof(int*));
	
	for(int i = 0; i < y; i++){
		(*arr)[i] = (int*)malloc(x * sizeof(int));
	}
} 

void deallocate_mem(int*** arr, int y){
	for (int i = 0; i < y; i++){
		free((*arr)[i]);
	}
	free(*arr); 
}

