#include <stdio.h>
#include <limits.h>

    int minrow(int matrix[][3],int rows,int cols,int *index);

int main(){

    int matrix[3][3] = {

        {24,35,67},
        {12,67,90},
        {43,54,84}

    };

    int index=0;
    int minTotal=minrow(matrix,3,3,&index);
    

    printf("Minimum Total:%d\n",minTotal);
    printf("Min Index:%d\n",index); 


    return 0;
}

    int minrow(int matrix[][3],int rows,int cols,int *index){

        int min=INT_MAX;
        
        for(int i=0;i<rows;i++){
            
            int sum=0;

            for(int j=0;j<cols;j++){
                sum += matrix[i][j];
            }

            if(sum<min){
                
                min=sum;
                *index=i;

            }

        }

            return min;

    }
