#include<stdio.h>

int linearSearch(int array[], int n, int x);
int betterLinearSearch(int array[], int n, int x);
int sentinelLinearSearch(int array[], int n, int x);
int recursiveLinearSearch(int array[], int n, int i, int x);
int binarySearch(int array[], int n, int x);
int recursiveBinarySearch(int array[], int p, int r, int x);

int main(){

    // Variables
    int A[10] = {7, 10, 3, 1, 5, 13, 8, 12, 4, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 1;

    // Calling functions
    int linear = linearSearch(A, n, x);
    int betterLinear = betterLinearSearch(A, n, x);
    int sentinelLinear = sentinelLinearSearch(A, n, x);
    int recursiveLinear = recursiveLinearSearch(A, n, 0, x);
    
    //Showing outputs
    printf("Linear Search: %d\n", linear);
    printf("Better Linear Search: %d\n", betterLinear);
    printf("Sentinel Linear Search: %d\n", sentinelLinear);
    printf("Recursive Linear Search: %d\n", recursiveLinear);

    // Binary Search (only with sorted arrays)
    int B[] = {1, 3, 5, 7, 13, 17, 20, 26, 29};
    n = sizeof(B) / sizeof(B[0]);
    x = 29;

    int binary = binarySearch(B, n, x);
    int recursiveBinary = recursiveBinarySearch(B, 0, n - 1, x);

    printf("Binary Search: %d\n", binary);
    printf("Recursive Binary Search: %d\n", recursiveBinary);


}

int linearSearch(int array[], int n, int x){
    int answer = -1;
    for (int i = 0; i < n; i++){
        if (array[i] == x){
            answer = i;
        }
    }
    return answer;
}

int betterLinearSearch(int array[], int n, int x){
    int answer = -1;
    for (int i = 0; i < n; i++){
        if (array[i] == x){
            return i;
        }
    }
    return answer;
}

int sentinelLinearSearch(int array[], int n, int x){
    int last = array[n - 1];
    array[n - 1] = x;
    int i = 0;
    while (array[i] != x){
        i++;
    }
    array[n - 1] = last;
    if (i < n - 1 || array[n - 1] == x){
        return i;
    }
    return -1;
}

int recursiveLinearSearch(int array[], int n, int i, int x){
    if (i > n - 1){
        return -1;
    }
    else if (array[i] == x){
        return i;
    }
    return recursiveLinearSearch(array, n, i + 1, x);
}

int binarySearch(int array[], int n, int x){
    int p = 0;
    int r = n;
    while (p <= r){
        int q = (p + r) / 2;
        if (array[q] == x){
            return q;
        } else if (array[q] > x){
            r = q - 1;
        } else {
            p = q + 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int array[], int p, int r, int x){
    if (p > r){
        return -1;
    }
    int q = (p + r) / 2;
    if (array[q] == x){
        return q;
    } else if (array[q] > x){
        return recursiveBinarySearch(array, p, q - 1, x);
    } else {
        return recursiveBinarySearch(array, q + 1, r, x);
    }
}