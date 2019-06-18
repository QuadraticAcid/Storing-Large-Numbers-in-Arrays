#include <stdio.h>
#include <stdlib.h>

#include "mem.h"

/*int *allocate_mem(int*** arr, int x, int y){
	//int x: rows indices. int y: column indices
	*arr = (int**)malloc(x * sizeof(int*));
	int *arr_data = malloc( x * y * sizeof(int));
  
	for(int i=0; i<x; i++){
		(*arr)[i] = arr_data + i * y;
	}
	return arr_data; 
}

void deallocate_mem(int*** arr, int* arr_data){
	free(arr_data);
	free(*arr);
}*/
void allocate_mem(int*** arr, int x, int y){
  *arr = (int**)malloc(y*sizeof(int*));
  
  for(int i=0; i<y; i++)
    (*arr)[i] = (int*)malloc(x*sizeof(int));
} 

void deallocate_mem(int*** arr, int y){
    for (int i = 0; i < y; i++)
        free((*arr)[i]);
    free(*arr); 
}

