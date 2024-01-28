#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int maximum(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
void countSort(int arr[],int n){
    printf("CountSort being implemented\n");
    int i,j;
    int max=maximum(arr,n); //Find maximum element
    int* count=(int *)malloc((max+1)*sizeof(int)); ///Create Count Array///
    for(int i=0;i<max+1;i++){       ///Initialize Array Elements
        count[i]=0;
    }
    for(int i=0;i<n;i++){           ////Increment corresponding index in the count array
        count[arr[i]]=count[arr[i]]+1;
    }
    i=0;
    j=0;
    while(i<=max){
        if(count[i]>0){
            arr[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    int arr[]={9,1,3,5,3,22,7,6};
    int n=8;
    printArray(arr,n);
    countSort(arr,n);
    printArray(arr,n);
}
