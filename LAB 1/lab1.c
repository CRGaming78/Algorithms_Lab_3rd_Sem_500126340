#include<stdio.h>
void linear(int arr[],int size){
    int num;
    printf("Enter the element to find: ");
    scanf("%d",&num);
    for(int i=0;i<size;i++){
        if(arr[i]==num){
            printf("Element %d found at index %d.\n",num,i);
            return;
        }
    }
    printf("Element %d not found in the array.\n",num);
}

void sort(int arr1[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr1[j]>arr1[j+1]){
                int temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
}

void binary1(int arr[],int size){
    int left=0;
    int right=size-1;
    int target;
    printf("Enter the element to find: ");
    scanf("%d",&target);
    while (left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            printf("Element %d is at index %d.\n",target,mid);
            return;
        }
        if(arr[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    printf("Element %d not found in the array.\n",target);
}

void binary2(int arr[],int left,int right,int target){
    if(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            printf("Element %d is found at %d",target,mid);
            return;
        }
        if(arr[mid]<target){
            return binary2(arr,mid+1,right,target);
        }else{
            return binary2(arr,left,mid-1,target);
        }
    }
    printf("Element %d not found in the array.\n",target);
}

int main(){
    int s,i,c;
    printf("Enter the size of the array: ");
    scanf("%d",&s);
    int arr1[s];
    for(i=0;i<s;i++){
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("\n--- Menu ---\n");
    printf("1. Linear search\n");
    printf("2. Binary search- Iterative\n");
    printf("3. Binary search- Reccursive\n");
    printf("\n Enter your choice: ");
    scanf("%d",&c);
    switch(c){
        case 1:
            linear(arr1,s);
            break;
        case 2:
            sort(arr1,s);
            binary1(arr1,s);
            break;
        case 3:
            int left=0;
            int right=s-1;
            int target;
            printf("Enter the element to find: ");
            scanf("%d",&target);
            sort(arr1,s);
            binary2(arr1,left,right,target);
            break;
        default:
            printf("Wrong number entered");
    }
}