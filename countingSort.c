#include<stdio.h>
#include<stdlib.h>

void printArray(int array[], int n);
void simpleSort(int array[], int n);
int *countKeyEquals(int array[], int n, int m);
int *countKeysLess(int array[], int m);
int *rearrange(int array[], int less[], int n, int m);
int *countingSort(int array[], int m, int n);

int main(){

    int A[] = {2, 1, 1, 2, 5, 4, 4, 3, 0};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array before sorting\n");
    printArray(A, n);
    
    // Sorting Algorithms
    // simpleSort(A, n);
    int *sortedArray = countingSort(A, n, 6);

    printf("Array sorted\n");
    printArray(sortedArray, n);  
    
    return 0;
}

void simpleSort(int array[], int n){
    // only for arrays in which elements is either 1 or 2
    int k = 0;
    for (int i = 0; i < n; i++){
        if (array[i] == 1){
            k++;
        }
    }

    for (int i = 0; i < k; i++){
        array[i] = 1;
    }

    for (int i = k; i < n; i++){
        array[i] = 2;
    }
}


int *countKeyEquals(int array[], int n, int m){
    int *equal = malloc(sizeof(int));
    for (int i = 0; i < m; i++){
        equal[i] = 0;
    }

    int key;
    for (int i = 0; i < n; i++){
        key = array[i];
        equal[key]++;
    }
    return equal;
}

int *countKeysLess(int array[], int m){
    int *less = malloc(sizeof(int));
    less[0] = 0;

    for (int i = 1; i < m; i++){
        less[i] = less[i - 1] + array[i - 1];
    }
    return less;
}

int *rearrange(int array[], int less[], int n, int m){
    int *B = malloc(n * sizeof(int));
    int *next = malloc(m * sizeof(int));
    int key, index;

    for (int i = 0; i < m; i++){
        next[i] = less[i];
    }

    for (int i = 0; i < n; i++){
        key = array[i];
        index = next[key];
        B[index] = array[i];
        next[key]++;
    }

    return B;
}

int *countingSort(int array[], int n, int m){
    int *equals;
    equals = countKeyEquals(array, n, m);    

    int *less;
    less = countKeysLess(equals, m);

    int *sortedArray;
    sortedArray = rearrange(array, less, n, m);

    free(equals);
    free(less);
    free(sortedArray);
    return sortedArray;
}

void printArray(int array[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}