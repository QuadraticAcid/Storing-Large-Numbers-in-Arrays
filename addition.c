#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "addition.h"

void add(struct int_struct augend, struct int_struct addend, struct int_struct *dest){
       	int *tmp_augend, *tmp_addend, *tmp_return, length=0, shift1=0, shift2=0, i=0, j=0, total=0, onesdigit=0, tensdigit=0;

        if (augend.arraylength >= addend.arraylength){
		length = augend.arraylength;
		shift1 = length - augend.arraylength;
		shift2 = length - addend.arraylength;
	}
	else{
		length = addend.arraylength;
		shift1 = length - augend.arraylength;
		shift2 = length - addend.arraylength;
	}

        tmp_augend = (int*)malloc(length* sizeof(int));
        tmp_addend = (int*)malloc(length* sizeof(int));
        tmp_return = (int*)malloc((length + 1)* sizeof(int));

        for (i = 0; i <= augend.arraylength - 1; i++){
                tmp_augend[i + shift1] = augend.array[i];
        }

        for (i = 0; i <= addend.arraylength - 1; i++){
                tmp_addend[i + shift2] = addend.array[i];

        }

        for (i = length - 1; i >= 0; i--){
                total = tmp_augend[i] + tmp_addend[i];
                if ((total + tmp_return[i + 1]) >= 10){
                        tensdigit = floor((total + tmp_return[i + 1])/10);
                        onesdigit = (total + tmp_return[i + 1]) - floor((total + tmp_return[i + 1])/10) * 10;

                        tmp_return[i] = tensdigit;
                        tmp_return[i + 1] = onesdigit;
                }
                else{
			tmp_return[i + 1] = tmp_return[i + 1] + total;
		}  
        }

        for (i = 0; i <= length - 1;i++){
		if (tmp_return[i] != 0 || i == augend.arraylength + addend.arraylength - 1){
			break;
		}
		else{
			j++;
		}
	}
	dest->array = (int*)malloc((length - j) * sizeof(int));

	for (i = 0; i <= length - j ; i++){
		dest->array[i] = tmp_return[i + j];
        }
	dest->arraylength = length - j + 1;
        
	free(tmp_augend);
	free(tmp_addend);
	free(tmp_return);
}
