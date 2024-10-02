#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for (int j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<= R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
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
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void printArray(int arr[],int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *a,int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=(low-1);
    for (int j=low;j<=high-1;j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
}

void quickSort(int arr[],int low,int high) {
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main() {
    int choice;
    int arr[100], n, i;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nMenu:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Print Array\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            mergeSort(arr,0,n-1);
            printf("Array after Merge Sort:\n");
            printArray(arr,n);
            break;
        case 2:
            quickSort(arr,0,n-1);
            printf("Array after Quick Sort:\n");
            printArray(arr,n);
            break;
        case 3:
            printArray(arr,n);
            break;
        case 4:
            printf("Exiting..");
            return 0;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}