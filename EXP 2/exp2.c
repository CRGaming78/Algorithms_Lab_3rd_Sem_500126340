#include <stdio.h>

void insertionSort(int arr[],int n){
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int leftArray[n1],rightArray[n2];
    for(int i=0;i<n1;i++)
        leftArray[i]=arr[left+i];
    for(int j=0;j<n2;j++)
        rightArray[j]=arr[mid+1+j];
    int i=0,j= 0,k=left;
    while(i<n1 && j<n2){
        if(leftArray[i]<=rightArray[j]){
            arr[k]=leftArray[i];
            i++;
        }else{
            arr[k]=rightArray[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=leftArray[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void printArray(int arr[],int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Choose sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d",&choice);
    if (choice==1){
        printf("Performing Insertion Sort...\n");
        insertionSort(arr,n);
    }else if (choice==2){
        printf("Performing Merge Sort...\n");
        mergeSort(arr,0,n-1);
    }else{
        printf("Invalid choice!\n");
        return 1;
    }
    printf("Sorted array: \n");
    printArray(arr,n);
    return 0;
}