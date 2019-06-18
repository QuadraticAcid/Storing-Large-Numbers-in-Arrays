#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "division.h"
#include "addition.h"
#include "multiplication.h"
#include "subtraction.h"

void divide(struct int_struct numerator, struct int_struct denominator, struct int_struct *dest){
	if (denominator.array[0] == 1 && denominator.arraylength == 1){
		int i;
		dest->array = (int*)malloc(numerator.arraylength * sizeof(int));
		dest->arraylength = numerator.arraylength;

		for (i = 0; i <= numerator.arraylength - 1; i++){
			dest->array[i] = numerator.array[i];
		}
		return;
	}
	else if (denominator.array[0] == 0 && denominator.arraylength == 1){
		dest->array = (int*)malloc(sizeof(int));
		dest->arraylength = 1;
		dest->array[0] = -1;
	}
	else{
		struct int_struct ten, tmp, tmp_return;
		int i, j = 0, shift, count = 0, yes = 0;

		ten.array = (int*)malloc(2 * sizeof(int));
		ten.array[0] = 1;
		ten.array[1] = 0;
		ten.arraylength = 2;

		tmp_return.array = (int*)malloc(0*sizeof(int));
		tmp_return.arraylength = 0;

		while (j <= 10){
			if (greaterthan(numerator, denominator) == -1){
				multiply(numerator, ten, &numerator);

			}
			else{
				while(greaterthan(numerator, denominator) == 1){
					subtract(numerator, denominator, &numerator);
					count++;
			}
			tmp_return.arraylength += 1;
			tmp_return.array = (int*)realloc(tmp_return.array, sizeof(int) * (tmp_return.arraylength));
			tmp_return.array[tmp_return.arraylength - 1] = count;
			count = 0;
			yes = 1;
			}
			j++;
		}

		dest->array = (int*)malloc(tmp_return.arraylength * sizeof(int));
		dest->arraylength = tmp_return.arraylength;
		for (i = 0; i <= tmp_return.arraylength - 1; i++){
			dest->array[i] = tmp_return.array[i];
		}
		
		free(tmp_return.array);
		free(ten.array);
	}
}
