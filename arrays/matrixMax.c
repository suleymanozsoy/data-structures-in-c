#include <stdio.h>


    int findMax(int arr[],int n,int *index){
        
       int max=arr[0];
      
       *index = 0;
       
       for (int i = 1; i < n; i++){

            if(arr[i]>max){

                max = arr[i];
                *index = i;

            }

       }
       
       return max;

    }

int main(){

    int matrix[]={

        3,1,8,4,
        2,7,5,3,
        6,0,3,2

    };

    int maxIndex;

    int max = findMax(matrix,12,&maxIndex);

    int rowIndex = (maxIndex/4); 
    int colIndex = (maxIndex%4);

    printf("Maximum value: %d\n",max);
    printf("Row index: %d\n",rowIndex);
    printf("Col index: %d\n",colIndex);

}