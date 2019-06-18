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
        struct int_struct a,b, dest;
        
        char *c,*d;
        int i,type;

        c = (char*)malloc(1000 * sizeof(char));
        d = (char*)malloc(1000 * sizeof(char));
        
        printf("1. Add\n2. Subtract\n 3. Multiply\n 4. Divide\n 5. Factorial\n");
        scanf("%d",&type);
        
        if (type == 5){
                printf("Number 2: \n");
                scanf("%s",c);

                a.array = (int*)malloc(strlen(c) * sizeof(int));
                for (i = 0; i <= strlen(c) - 1; i++){
                        a.array[i] = c[i] - '0';        
                }  
                
                factorial(a,&dest);
                for (i = 0; i <= dest.arraylength - 1; i++){
                        printf("%d",dest.array[i]);
                }
                free(dest.array);
                free(a.array);
                free(c);
                free(d);
        }
        else{
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

                if (type == 1){
                        add(a,b,&dest);
                }
                else if (type == 2){
                        subtract(a,b,&dest);
                }
                else if (type == 3){
                        multiply(a,b,&dest);
                }
                else if (type == 4){
                        divide(a,b,&dest);
                }
                for (i = 0; i <= dest.arraylength - 1; i++){
                      printf("%d",dest.array[i]);
                }
                
                free(dest.array);
                free(a.array);
                free(b.array);
                free(c);
                free(d);
        }
        return 0;
}
