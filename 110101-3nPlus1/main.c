#include <stdio.h>

void nn(unsigned int i, unsigned int *contador){
	*contador = 1;
	
	while(i!=1){
		if(i%2==0){ // Even numbers
			i = i/2;
			*contador = *contador + 1;
		} else {
			i = ((i*3)+1);
			*contador = *contador + 1;
		}
	}
	//printf("%u\n",contador);
}



int main(){

	unsigned int i=0,j=0;
	unsigned int max=90;
	unsigned int swap;

	while( scanf("%u %u", &i, &j)!= EOF && (i != 0 || j != 0)){
		swap=0;
		for(unsigned int o=i;o<=j;o++){
			nn(o, &max); //Resolver
			if(max>swap){
				swap=max;
			}
		}
		printf("%u %u %u\n",i,j,swap);
	}

	return 0;
}


