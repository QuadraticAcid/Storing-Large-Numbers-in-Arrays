#ifndef MEM_H
#define MEM_H

/*
extern int *allocate_mem(int ***arr, int x, int y);
extern void deallocate_mem(int ***arr, int *arr_data);*/

extern void allocate_mem(int*** arr, int x, int y);
extern void deallocate_mem(int*** arr, int y);


#endif