#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void Display(struct Array arr){
    int i;
    printf("\nElements are:\n");
    for(i=0; i<arr.length; i++)
        printf("%d. %d\n",i, arr.A[i]);
}

void Append(struct Array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length++] = x;
        printf("*****Element Appended succesfully*****\n");  
    }
}

void Insert(struct Array *arr, int index, int x){
    int i;
    if(index>=0 && index<=arr->length){
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
        printf("*****Element Inserted succesfully*****\n"); 
    }
    else
        printf("*****Invalid Input! Please Enter Vaild Index (0 - %d)*****", arr->length-1);
}

int Delete(struct Array *arr, int index){
    int i, x=-1;

    if(index>=0 && index<arr->length){
        x = arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        printf("*****Element Deleted succesfully*****\n"); 
    }
    else
        printf("*****Invalid Input! Please Enter Vaild Index (0 - %d)*****", arr->length-1);
    return x;
}

int LinearSearch(struct Array arr, int key){
    int i;
    for(i=0; i<arr.length; i++){
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

int LinearSearch_T(struct Array *arr, int key){
    int i;
    for(i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            if(arr->A[0] == key){   //Handle when key element is already at index 0.
                return 0;
            }
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int LinearSearch_MTF(struct Array *arr, int key){
    int i;
    for(i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch_loop(struct Array arr, int key){
    int l=0;
    int h=arr.length-1;
    int mid;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int BinarySearch_recursion(int A[], int key, int l, int h){
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return BinarySearch_recursion(A, key, l, mid-1);
        else
            return BinarySearch_recursion(A, key, mid+1, h);
    }
    return -1;
}

void main(){
    struct Array arr;
    int n, i;
    int choice;
    int x, index, key;

    printf("Enter size of an array:\t");
    scanf("%d", &arr.size); //set size of an array
    arr.A = (int *)malloc(arr.size*sizeof(int));    //create array inside heap

    printf("How Many elements you want to add:\t");
    scanf("%d", &n);    //taking input as length of an array.
    printf("Start Entering elements upto %d:\n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr.A[i]);
    }
    arr.length = n; //set array length

    system("clear"); 
    while(choice !=0){
        printf("\n\n*****MAIN MENU******\n\n");
        printf("\n0. Exit");
        printf("\n1. Display");
        printf("\n2. Append");
        printf("\n3. Insert");
        printf("\n4. Delete");
        printf("\n5. Linear Search");
        printf("\n6. Linear Search (Transposition)");
        printf("\n7. Linear Search (Move To Front)");
        printf("\n8. Binary Search (Using Loop)");
        printf("\n9. Binary Search (Using Tail Recursion)");

        printf("\n\nEnter your choice:\t");
        scanf("%d", &choice);
        
        switch(choice){
            case 0 :    printf("\n*****Program Exiting*****\n");
                        system("clear");    //clear screen
                        break;

            case 1 :    system("clear");    //clear screen
                        Display(arr);
                        break;

            case 2 :    system("clear");
                        printf("Enter the element you want to append: ");
                        scanf("%d", &x);
                        Append(&arr , x);
                        break;
                
            case 3 :    system("clear");
                        printf("At what index you want to insert which element (index, element):\t");
                        scanf("%d %d", &index, &x);
                        Insert(&arr, index, x);
                        break;
                    
            case 4 :    system("clear");
                        printf("Which index element you want to delete: \t");
                        scanf("%d", &index);
                        printf("Deleted value = %d", Delete(&arr, index));
                        break;
                    
            case 5 :    system("clear");
                        printf("Which element you want to search: \t");
                        scanf("%d", &key);
                        x = LinearSearch(arr, key);
                        if(x == -1)
                            printf("Key Not Found!!");
                        else
                            printf("Key found at index %d", x);
                        break;

            case 6 :    system("clear");
                        printf("Which element you want to search: \t");
                        scanf("%d", &key);
                        x = LinearSearch_T(&arr, key);
                        if(x == -1)
                            printf("Key Not Found!!");
                        else
                            printf("Key found at index %d", x);
                        break;

            case 7 :    system("clear");
                        printf("Which element you want to search: \t");
                        scanf("%d", &key);
                        x = LinearSearch_MTF(&arr, key);
                        if(x == -1)
                            printf("Key Not Found!!");
                        else
                            printf("Key found at index %d", x);
                        break;
                
            case 8 :    system("clear");
                        printf("Which element you want to search: \t");
                        scanf("%d", &key);
                        x = BinarySearch_loop(arr, key);
                        if(x == -1)
                            printf("Key Not Found!!");
                        else
                            printf("Key found at index %d", x);
                        break;

            case 9 :    system("clear");
                        printf("Which element you want to search: \t");
                        scanf("%d", &key);
                        x = BinarySearch_recursion(arr.A, key, 0, arr.length-1);
                        if(x == -1)
                            printf("Key Not Found!!");
                        else
                            printf("Key found at index %d", x);
                        break;
            
            default :   printf("*****Choose Vaild Option*****");
                        break;
        }
    }
}