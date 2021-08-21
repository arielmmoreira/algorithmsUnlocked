#include<stdio.h>
#include<math.h>

void printArray(int A[], int n);
void selectionSort(int A[], int n);
void insertionSort(int A[], int n);
void mergeSort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

int main(){
    // Variables
    int A[10] = {12, 9, 3, 7, 14, 11, 6, 2, 10, 5};

    int n = sizeof(A) / sizeof(A[0]);

    // Showing outputs
    printf("Array before sorting\n");
    printArray(A, n);

        // Sorting algorithms
    // selectionSort(A, n);
    // insertionSort(A, n);
    mergeSort(A, 0, n - 1);

    printf("Array sorted\n");
    printArray(A, n);
    return 0;

}

void printArray(int A[], int n){
    printf("A = ");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int n){
    int smallest;
    for (int i = 0; i < n; i++){
        smallest = i;
        for (int j = i + 1; j <= n; j++){
            if (A[j] < A[smallest]){
                smallest = j;
            }
        }
        int tmp = A[i];
        A[i] = A[smallest];
        A[smallest] = tmp;
    }
}

void insertionSort(int A[], int n){
    int key;
    int j;
    for (int i = 1; i < n; i++){
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void mergeSort(int A[], int p, int r){
    // printArray(A, r + 1);
    if (p < r) {
        int q = (p + r) / 2;
        

        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        merge(A, p, q, r + 1);
    }    
}        

void merge(int A[], int p, int q, int r){
    
    // p = 0; q = 4; r = 9
    int n1 = q - p + 1; // n1 = 5
    int n2 = r - q - 1; // n2 = 5
    int B[n1 + 1];
    int C[n2 + 1];

    for (int i = 0; i < n1; i++){
        B[i] = A[i + p];
    }

    for (int i = 0; i < n2; i++){
        C[i] = A[i + q + 1];
    }
    
    B[n1] = (int)INFINITY;
    C[n2] = (int)INFINITY;

    int i = 0;
    int j = 0;
    for (int k = p; k < r; k++){
        if (B[i] <= C[j]){
            A[k] = B[i];
            i++;
        } else{
            A[k] = C[j];
            j++;
        }
    }
}