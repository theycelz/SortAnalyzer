#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"

#define MAX 10001

// Merge Sort
void merge_halves(int *v, int *temp, int ini, int meio, int fim) {
    int i = ini, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    while (i <= meio) temp[k++] = v[i++];
    while (j <= fim) temp[k++] = v[j++];

    for (i = 0; i < k; i++) {
        v[ini + i] = temp[i];
    }
}

void recursive_mergesort(int *v, int *temp, int ini, int fim) {
    if (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        recursive_mergesort(v, temp, ini, meio);
        recursive_mergesort(v, temp, meio + 1, fim);
        merge_halves(v, temp, ini, meio, fim);
    }
}

void merge_sort_algorithm(int *v, int n) {
    int *temp = malloc(n * sizeof(int));
    recursive_mergesort(v, temp, 0, n - 1);
    free(temp);
}


/* Insertion */

void insertion_sort_algorithm(int *v, int n) {
    int key, i, j;
    for (j = 1; j < n; j++) {
        key = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i = i - 1;
        }
        v[i + 1] = key;
    }
}

/*Bubble */

void bubble_sort_algorithm(int *v, int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

/*Heap Sort*/
int left_child(int pai){
    return 2*pai + 1;
}

int right_child(int pai){
    return 2*pai + 2;
}

void fix_heap(int *v, int n, int i){
    int maior = i;
    int left = left_child(i);
    int right = right_child(i);

    if(left < n && v[left] > v[maior]){
        maior = left;
    }
    if(right < n && v[right] > v[maior]){
        maior = right;
    }
    if(maior!=i){
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
        fix_heap(v, n, maior);
    }
}

void initialize_max_heap(int *v, int n){
    for(int i = n/2; i>=0; i--){
        fix_heap(v, n, i);
    }
}

void heap_sort_algorithm(int *v, int n){
    initialize_max_heap(v, n);

    for(int i = n-1; i>0; i--){
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        fix_heap(v, i, 0);
    }
}

/*Quick Sort*/
void quick_sort_recursive(int *v, int ini, int fim) {
    if (ini >= fim) return;
    
    int pivot = v[ini];
    int lt = ini, gt = fim;
    int i = ini + 1;
    
    while (i <= gt) {
        if (v[i] < pivot) {
            int temp = v[lt];
            v[lt] = v[i];
            v[i] = temp;
            lt++;
            i++;
        } else if (v[i] > pivot) {
            int temp = v[i];
            v[i] = v[gt];
            v[gt] = temp;
            gt--;
        } else {
            i++;
        }
    }
    
    quick_sort_recursive(v, ini, lt - 1);
    quick_sort_recursive(v, gt + 1, fim);
}

void quick_sort_algorithm(int *v, int n) {
    quick_sort_recursive(v, 0, n - 1);
}

/*Counting Sort*/
void counting_sort_algorithm(int *v, int n) {
    if (n <= 1) return;

    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
    }

    int *count = calloc(max + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        count[v[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = output[i];
    }

    free(count);
    free(output);
}

/*Retorna média*/
double get_average(double *v, int n){
    double media = 0.0;
    for(int i = 0; i<n; i++){
        media = media + v[i];
    }
    return media/n;
}

/*Inverte vetor*/
void flip_array(int *v, int n){
    if(n>0){
        int *aux = calloc(n, sizeof(int));
        int iteration_count = 0;

        for(int i = 0; i<n; i++){
            aux[i] = v[i];
        }

        for(int j = n-1; j >= 0; j--){
            v[iteration_count++] = aux[j];
        }
    }
}

/*Embaralha vetor*/
void randomize_array(int *v, int n){
    srand(time(NULL));
    int index1, index2;
    int qtde = n * 0.1;
    for(int i = 0; i<qtde; i++){
        index1 = rand() % n;
        index2 = rand() % n;
        int temp = v[index1];
        v[index1] = v[index2];
        v[index2] = temp;
    }
}