#include<stdio.h>
#include<math.h>

void printArray(int array[], int n);
void selectionSort(int array[], int n);
void insertionSort(int array[], int n);
void mergeSort(int array[], int p, int r);
void merge(int array[], int p, int q, int r);
int partition(int array[], int p, int r);
void quicksort(int array[], int p, int r);

int main(){
    // Variables
    int A[] = {12, 9, 3, 7, 14, 11, 6, 2, 10, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array before sorting\n");
    printArray(A, n);

    // Sorting algorithms

    // selectionSort(A, n);
    // insertionSort(A, n);
    // mergeSort(A, 0, n - 1);
    // quicksort(A, 0, n - 1);



    printf("Array sorted\n");
    printArray(A, n);
    return 0;

}

void printArray(int array[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selectionSort(int array[], int n){
    int smallest;
    for (int i = 0; i < n; i++){
        smallest = i;
        for (int j = i + 1; j <= n; j++){
            if (array[j] < array[smallest]){
                smallest = j;
            }
        }
        int tmp = array[i];
        array[i] = array[smallest];
        array[smallest] = tmp;
    }
}

void insertionSort(int array[], int n){
    int key;
    int j;
    for (int i = 1; i < n; i++){
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void mergeSort(int array[], int p, int r){
    if (p < r) {
        int q = (p + r) / 2;
        
        mergeSort(array, p, q);
        mergeSort(array, q + 1, r);

        merge(array, p, q, r + 1);
    }    
}        

void merge(int array[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q - 1;
    int B[n1 + 1];
    int C[n2 + 1];

    for (int i = 0; i < n1; i++){
        B[i] = array[i + p];
    }

    for (int i = 0; i < n2; i++){
        C[i] = array[i + q + 1];
    }
    
    B[n1] = (int)INFINITY;
    C[n2] = (int)INFINITY;

    int i = 0;
    int j = 0;
    for (int k = p; k < r; k++){
        if (B[i] <= C[j]){
            array[k] = B[i];
            i++;
        } else{
            array[k] = C[j];
            j++;
        }
    }
}

int partition(int array[], int p, int r){
    int q = p;
    int tmp;
    for (int i = p; i < r; i++){
        if (array[i] <= array[r]){
            tmp = array[q];
            array[q] = array[i];
            array[i] = tmp;
            q++;
        }
    }
    tmp = array[q];
    array[q] = array[r];
    array[r] = tmp;
    return q;
}

void quicksort(int array[], int p, int r){
    if (p < r){
        int q = partition(array, p, r);
        quicksort(array, p, q - 1);
        quicksort(array, q + 1, r);
    }
}