#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "subtraction.h"

void subtract(struct int_struct minuend, struct int_struct subtrahend, struct int_struct *dest){
	int *tmp_minuend, *tmp_subtrahend, *tmp_return, length, shift1, shift2, i, j;

	if (minuend.arraylength >= subtrahend.arraylength){
		length = minuend.arraylength;
		shift1 = length - minuend.arraylength;
		shift2 = length - subtrahend.arraylength;
	}
	else{
		length = subtrahend.arraylength;
		shift1 = length - minuend.arraylength;
		shift2 = length - subtrahend.arraylength;
	}

	tmp_minuend = (int*)malloc(length * sizeof(int));
	tmp_subtrahend = (int*)malloc(length * sizeof(int));
	tmp_return = (int*)malloc(length * sizeof(int));
	
        for (i = 0; i <= minuend.arraylength - 1; i++){
                tmp_minuend[i + shift1] = minuend.array[i];
        }

        for (i = 0; i <= subtrahend.arraylength - 1; i++){
                tmp_subtrahend[i + shift2] = (-1) * subtrahend.array[i];
        }

	for (i = length - 1 ;i >= 0;i--){
		tmp_return[i] = tmp_return[i] + tmp_minuend[i] + tmp_subtrahend[i];
		
		if (tmp_return[i] < 0 && i != 0){
			tmp_return[i] = tmp_return[i] + 10;
			tmp_return[i - 1] = tmp_return[i - 1] - 1;
		}
	}
        
	for(i = 0; i <= length - 1;i++){
		if (tmp_return[i] != 0 || i == length - 1){
			break;
		}
		else{
			j++;
		}
	}
        
       	dest->array = (int*)malloc((length - j) * sizeof(int));

        for(i = 0; i <= length - j - 1; i++){
                dest->array[i] = tmp_return[i + j];
        }
	dest->arraylength = length - j;

      
	free(tmp_return);
	free(tmp_minuend);
	free(tmp_subtrahend);
}

int greaterthan(struct int_struct a, struct int_struct b){
        struct int_struct result;

        subtract(a,b,&result);
        if(result.array[0] < 0){
                free(result.array);
                return -1;
        }
        else{
                free(result.array);
                return 1;
        }    
}
