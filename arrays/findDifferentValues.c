#include <stdio.h>
#include <stdlib.h>

    int findDifference(int a[],int n){

        int write=1;

        for(int read=1;read<n;read++){
            
            if(a[read]!=a[write-1]){

                a[write]=a[read];
                write++;

            }


        }

        return write;

    }

int main(){

    int matrix[]={2,3,3,4,4,4,8,8,12,12,12,12,15,15};

    int count = findDifference(matrix,14);

    printf("Number of different values: %d\n",count);

    for(int i=0;i<count;i++){
        printf("%d ",matrix[i]);
    }



}