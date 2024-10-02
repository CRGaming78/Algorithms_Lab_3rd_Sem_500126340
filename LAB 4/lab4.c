#include <stdio.h>

void sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int kth_largest(int arr[],int n,int k){
    sort(arr,n);
    return arr[n-k];
}

int kth_smallest(int arr[],int n,int k){
    sort(arr,n);
    return arr[k-1];
}

int main(){
    int n,k;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d",&k);
    if (k>0 && k<=n){
        printf("%drd largest element is %d\n",k,kth_largest(arr,n,k));
        printf("%drd smallest element is %d\n",k,kth_smallest(arr,n,k));
    } else {
        printf("Invalid value of k. Please enter a value between 1 and %d.\n", n);
    }
    return 0;
}
