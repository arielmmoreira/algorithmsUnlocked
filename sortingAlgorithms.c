#include<stdio.h>
#include<math.h>

void printArray(int A[], int n);
void selectionSort(int A[], int n);
void insertionSort(int A[], int n);
void merge(int A[], int p, int q, int r);

int main(){
    // Variables
    int A[10] = {7, 10, 3, 1, 5, 13, 8, 12, 4, 6};
    int n = sizeof(A) / sizeof(int);

    // Showing outputs
    printf("Array before sorting\n");
    printArray(A, n);

        // Sorting algorithms
    // selectionSort(A, n);
    // insertionSort(A, n);

    printf("Array sorted\n");
    printArray(A, n);

    


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

void merge(int A[], int p, int q, int r){
    int n1 = q - p;
    int n2 = r - q;
    int B[n1 + 1];
    int C[n2 + 1];
    for (int i = 0; i < n1; i++){
        B[i] = A[i];
    }
    for (int i = 0; i < n2; i++){
        C[i] = A[i + q];
    }
    B[n1 + 1] = (int)INFINITY;
    C[n2 + 1] = (int)INFINITY;

    int i = 0;
    int j = 0;
    for (int k = 0; k < r; k++){
        if (B[i] <= C[j]){
            A[k] = B[i];
            i++;
        } else if(B[i] > C[j]){
            A[k] = C[j];
            j++;
        }
    }

}