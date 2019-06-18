#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "factorial.h"
#include "multiplication.h"
#include "subtraction.h"

void factorial(struct int_struct n, struct int_struct *dest){
        struct int_struct one,total;
        int i = 0;

        if (n.arraylength == 1 && (n.array[0] == 0 || n.array[0] == 1)){
                dest->array = (int*)calloc(1,sizeof(int));
                dest->array[0] = 1;
                dest->arraylength = 1;
                return;
        }

        one.array = calloc(1,sizeof(int));
        one.array[0] = 1;
        one.arraylength = 1;

        total.array = calloc(1,sizeof(int));
        total.array[0] = 1;
        total.arraylength = 1;

        while (i == 0){
                multiply(n,total,&total);
                subtract(n,one,&n);                
  
                if (n.array[0] == 1 && n.arraylength == 1){
                        break;
                }
                
        }
        dest->array = (int*)calloc(total.arraylength,sizeof(int));
        for (i = 0; i <= total.arraylength - 1;i++){
                dest->array[i] = total.array[i];
        }
        dest->arraylength = total.arraylength;
        //free(one.array);
        //free(total.array);
        return;
}
