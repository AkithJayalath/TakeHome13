#include<stdio.h>
// Declaring functions used
void printArray(int arr[],int n);
void merge(int arr[],int p,int q,int r);
void mergeSort(int arr[],int l,int r);

int main(void){
    int array[]={-5,3,-2,3,2};
    int length=sizeof(array)/sizeof(array[0]);
  
  // Array before sorting
    printf("Input Array :");
    printArray(array,length);
    printf("\n");
  // Array before sorting
    printf("Output Array :");
    mergeSort(array,0,length-1);
    printArray(array,length);
    return 0;
}

// Fucntion used for printing the array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("\t%2d",arr[i]);
    }
}
// Function used for merging the two subArrays
void merge(int arr[],int p,int q,int r){

  int n1=q-p+1;
  int n2=r-q;

  int L[n1],M[n2];

  for(int i=0;i<n1;i++)
    L[i]=arr[p+i];
  for(int j=0;j<n2;j++)
    M[j]=arr[q+1+j];

  int i,j,k;
  i=0;
  j=0;
  k=p;

  while(i<n1 && j<n2){
    if(L[i]<= M[j]){
      arr[k]=L[i];
      i++;
    }else{
      arr[k]= M[j];
      j++;
    }
    k++;
  }
  
  while(i<n1){
    arr[k]=L[i];
    i++;
    k++;
  }

  while(j<n2){
    arr[k]=M[j];
    j++;
    k++;
  }
}
// Function used for merge sort
void mergeSort(int arr[],int l,int r){
  if(l<r){
    int m=l+(r-l)/2;

    mergeSort(arr,l, m);
    mergeSort(arr, m + 1, r);
    
    merge(arr,l, m, r);
  }
}
