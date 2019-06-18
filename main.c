#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "addition.h"
#include "division.h"
#include "factorial.h"
#include "multiplication.h"
#include "structure.h"
#include "subtraction.h"

int main(){
        int hello[102] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};

        struct int_struct a,b, dest, dest1;
        
        char *c,*d;
        int i;

        c = (char*)malloc(1000 * sizeof(char));
        d = (char*)malloc(1000 * sizeof(char));

        printf("Number 1: \n");
        scanf("%s",c);

        printf("Number 2: \n");
        scanf("%s",d);

        a.array = (int*)malloc(strlen(c) * sizeof(int));
        b.array = (int*)malloc(strlen(d) * sizeof(int));
        a.arraylength = strlen(c);
        b.arraylength = strlen(d);

        for (i = 0; i <= strlen(c) - 1; i++){
                a.array[i] = c[i] - '0';        
        }

        for (i = 0; i <= strlen(d) - 1; i++){
                b.array[i] = d[i] - '0';
        }

        
        divide(a,b,&dest);
        for (i = 0; i <= dest.arraylength - 1; i++){
              printf("%d",dest.array[i]);
        }
        

        //free(a.array);
        //free(b.array);
        //free(c);
        //free(d);
        return 0;
}