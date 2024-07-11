#include <stdio.h>

int main(){
	int j = 0;
	for(int i = 33; i <= 255; ++i){
        if(i == 153){
            printf("\n\npressionae ENTER tecla para continuar.....");
            getchar();
        }
        if(j % 10 == 0){
            printf("\n\n");
            j = 0;
        }
        printf("%03d %c\t",i,i);
        ++j;
	}	
    printf("\n\n");
	return 0;	
}