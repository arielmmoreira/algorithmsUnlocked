#include<stdio.h>

int linearSearch(int A[], int n, int x);
int betterLinearSearch(int A[], int n, int x);
int sentinelLinearSearch(int A[], int n, int x);
int recursiveLinearSearch(int A[], int n, int i, int x);

int main(){

    // Variables
    int A[10] = {7, 10, 3, 1, 5, 13, 8, 12, 4, 6};
    int n = sizeof(A) / sizeof(int);
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

    // Binary Search (only if sorted arrays)

}

int linearSearch(int A[], int n, int x){
    int answer = -1;
    for (int i = 0; i < n; i++){
        if (A[i] == x){
            answer = i;
        }
    }
    return answer;
}

int betterLinearSearch(int A[], int n, int x){
    int answer = -1;
    for (int i = 0; i < n; i++){
        if (A[i] == x){
            return i;
        }
    }
    return answer;
}

int sentinelLinearSearch(int A[], int n, int x){
    int last = A[n - 1];
    A[n - 1] = x;
    int i = 0;
    while (A[i] != x){
        i++;
    }
    A[n - 1] = last;
    if (i < n - 1 || A[n - 1] == x){
        return i;
    }
    return -1;
}

int recursiveLinearSearch(int A[], int n, int i, int x){
    if (i > n - 1){
        return -1;
    }
    else if (A[i] == x){
        return i;
    }
    return recursiveLinearSearch(A, n, i + 1, x);
}
