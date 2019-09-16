#include <stdio.h>
#include <stdlib.h>
#define larg 17
#define comp 17
#define img 219
#define fund 0

int main(){
	int matriz[larg][comp], matrizg[larg][comp];
	int l, c, i, soma, r, s, n;
	
	system ("color 0d");
	for(l=0; l<larg; l++){
		for(c=0; c<comp; c++){
			matriz[l][c]=fund;
		}
	}
	
	matriz[1][5] = img;
	matriz[2][5] = img;
	matriz[3][5] = img; matriz[3][6] = img;
	matriz[5][1] = img; matriz[5][2] = img;	matriz[5][3] = img; matriz[5][6] = img;	matriz[5][7] = img;
	matriz[6][3] = img; matriz[6][5] = img;	matriz[6][7] = img;
	matriz[7][5] = img; matriz[7][6] = img;
	
	for(l = 0; l < larg/2; l++){
		for(c = 0; c < comp/2; c++){
			matriz[(larg-1)-l][c] = matriz[l][c];
			matriz[l][(comp-1)-c] = matriz[l][c];
			matriz[(larg-1)-l][(comp-1)-c] = matriz[l][c];
		}
	}
		
	for(n=0; ;n++){		
		for(l = 0; l < larg; l++){
			for(c = 0; c < comp; c++){
				matrizg[l][c] = matriz[l][c];
			}
		}
			
		printf("%c%c", 218, 196);
		
		for(i = 0; i<16; i++)
			printf("%c%c",  194, 196);
		printf("%c\n", 191);

		for(l=0; l<larg; l++){
			printf("%c", 179);
			for(c=0; c<comp; c++){
				printf("%c%c", matrizg[l][c], 179);
			}
	
			if (l < larg-1){
				printf("\n%c", 195);
				for(c=0; c<comp-1; c++){
					printf("%c%c", 196, 197);
				}
				printf("%c%c\n", 196,180);
				
			}else{
				printf("\n%c%c", 192, 196);
				for(i = 0; i<16; i++)
					printf("%c%c", 193,196);
				printf("%c\n", 217);
			}
		} 
	
		for (l = 1; l < larg-1; l++){
			for(c = 1; c < comp-1; c++){
				soma = 0;
				for(r = l-1; r < l+2; r++){
					for(s = c-1; s < c+2; s++){
						if (matrizg[r][s] != fund){
							soma++;
						}
					}
				}
			
				if(matrizg[l][c] == fund){
					i = 0;	
				}else{
					i = 1;
				}
				soma -= i;
								
				if ((i == 1 && soma < 2) || (i == 1 && soma > 3)){
					matriz[l][c] = fund;
				}else if ((i == 1 && (soma > 2 || soma <= 3)) || (i == 0 && soma == 3)){
					matriz[l][c] = img;
				}
	
			}
		}		
		system("pause");
		system("cls");
	}
	
	system("pause");
	return 0;
}
