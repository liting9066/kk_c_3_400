#include <stdio.h>
#include <stdlib.h>
#define MOD(a,b) (a)%(b)

#define W 16

/*
 * get dim1 indices from dim3
 */
int get_indices1(int x,int y,int z){
	
	return z+64*x+320*y;
}


/*
 * generate the inverse theta matrix
 */
void inv_theta_mat(){
	for(int y = 0; y < 5;y++){
		for(int x = 0;x < 5; x++){
			for(int z = 0 ;z < 64; z++){
				int cur = get_indices1(x,y,z);
				
			}
		}
	}
}


/*
*  search differential 3-round trails according to Keccak Reference
*/


int main(){

	//initial rho offset table
	int rho_offset[5][5]={{0,1,190,28,91},{36,300,6,55,276},{3,10,171,153,231},{105,45,15,21,136},{210,66,253,120,78}};
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			rho_offset[i][j]=MOD(rho_offset[i][j],W);
			printf("%d ", rho_offset[i][j]);
		}
		printf("\n");
	}
	
	//begin to search 
	for(int x0=0;x0<5;x0++){
		for(int x2=x0+1;x2<5;x2++){
			for(int y0 = 0;y0 < 5;y0++){
				for(int y2 = y0+1;y2 < 5;y2++){
					int res=MOD((rho_offset[y0][x0]-rho_offset[y2][x0]+rho_offset[y2][x2]-rho_offset[y0][x2]+W),W);
					if(res==0){
						//compute z2 when z0=0
						int z2 = MOD((rho_offset[y2][x0] - rho_offset[y2][x2]+W),W);
						printf("x0:%d x2:%d y0:%d y2:%d -- z0:0 z2:%d\n",x0,x2,y0,y2,z2);
					}
				}
			}
		
		}
	}
	
	
	printf("SEARCH\n");

}
