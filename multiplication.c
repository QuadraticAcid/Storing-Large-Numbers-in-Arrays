#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "multiplication.h"
#include "mem.h"

void multiply(struct int_struct multiplier, struct int_struct multiplicand, struct int_struct *dest){
	int **array2, *tmp_return, i, j, total, onesdigit, tensdigit;
     
	allocate_mem(&array2, multiplier.arraylength + multiplicand.arraylength,multiplicand.arraylength);
        tmp_return = malloc((multiplier.arraylength + multiplicand.arraylength)* sizeof(int));

	for (i = multiplicand.arraylength - 1; i >= 0; i--){
		for (j = multiplier.arraylength - 1; j >= 0;j --){
			total = multiplier.array[j] * multiplicand.array[i];
			
			if ((total + array2[i][i + j + 1]) >= 10){
				tensdigit = floor((total + array2[i][i + j + 1]) / 10);
				onesdigit = total + array2[i][i + j + 1] - floor((total + array2[i][i + j + 1]) / 10) * 10;
				array2[i][i + j] = tensdigit;
				array2[i][i + j + 1] = onesdigit;
			}
			else{
				array2[i][i + j + 1] = array2[i][i + j + 1] + total;
			}
		}
	}

	for (i = multiplier.arraylength + multiplicand.arraylength - 1;i >= 0;i--){
		total = 0;
		for (j = multiplicand.arraylength - 1; j >= 0;j--){
			total = total + array2[j][i];
		}
	
		if ((total + tmp_return[i]) >= 10){
			tensdigit = floor((total + tmp_return[i]) / 10);
			onesdigit = (total + tmp_return[i]) - floor((total + tmp_return[i]) / 10) * 10;
			
                        tmp_return[i - 1] = tensdigit;
			tmp_return[i] = onesdigit;
		}
		else{
			tmp_return[i] = tmp_return[i] + total;
		}	
	}

	j = 0;
	for(i = 0; i <= multiplier.arraylength + multiplicand.arraylength - 1;i++){
		if (tmp_return[i] != 0 || i == multiplier.arraylength + multiplicand.arraylength - 1){
			break;
		}
		else{
			j++;                        
		}
	}	

	dest->array = calloc((multiplier.arraylength + multiplicand.arraylength - j) , sizeof(int));

        for (i = 0; i <= multiplier.arraylength + multiplicand.arraylength - j - 1; i++){
                dest->array[i] = tmp_return[i + j];
        }

        dest->arraylength = multiplier.arraylength + multiplicand.arraylength - j;
	
        deallocate_mem(&array2, multiplicand.arraylength);
        free(tmp_return);
}