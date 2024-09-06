#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"

#define MAX 10001


/* Algoritmo Bubble Sort*/
void bubble_sort_algorithm(int *array, int lenght) {
    int swapped;
    for (int i = 0; i < lenght - 1; i++) {
        swapped = 0;
        for (int j = 0; j < lenght - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tempValue = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempValue;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

/*Algoritmo Insertion Sort*/
/*Função para execução do algoritmo Insertion Sort*/
void insertion_sort_algorithm(int *array, int lenght) {
    int currentValue, i, j;
    for (j = 1; j < lenght; j++) {
        currentValue = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > currentValue) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = currentValue;
    }
}

/*ALgoritmo Merge Sort*/

void merge_halves(int *array, int start, int midpoint, int end){
    int leftPartSize = midpoint - start + 1;
    int rightPartSize = end - midpoint;
    
    int *leftArray = malloc(leftPartSize * sizeof(int));
    int *rightArray = malloc(rightPartSize * sizeof(int));

    for (int i = 0; i < leftPartSize; i++)
        leftArray[i] = array[start + i];

    for (int j = 0; j < rightPartSize; j++)
        rightArray[j] = array[midpoint + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < leftPartSize && j < rightPartSize) {
        if (leftArray[i] <= rightArray[j])
            array[k++] = leftArray[i++];
        else
            array[k++] = rightArray[j++];
    }

    while (i < leftPartSize)
        array[k++] = leftArray[i++];

    while (j < rightPartSize)
        array[k++] = rightArray[j++];

    free(leftArray);
    free(rightArray);
}


void recursive_mergesort(int *array, int start, int end){
    if(start < end){
        int midpoint = start + (end-start)/2;

        recursive_mergesort(array, start, midpoint);
        recursive_mergesort(array, midpoint + 1, end);
        
        merge_halves(array, start, midpoint, end);
    }
}

void merge_sort_algorithm(int *array, int lenght){
    recursive_mergesort(array, 0, lenght-1);
}




/*Algoritmo  Heap Sort*/
int left_child(int parentIndex){
    return 2*parentIndex + 1;
}

int right_child(int parentIndex){
    return 2*parentIndex + 2;
}


void fix_heap(int *array, int length, int i) {
    int largestIndex = i;
    int leftIndex = left_child(i);
    int rightIndex = right_child(i);

    if (leftIndex < length && array[leftIndex] > array[largestIndex]) {
        largestIndex = leftIndex;
    }
    if (rightIndex < length && array[rightIndex] > array[largestIndex]) {
        largestIndex = rightIndex;
    }
    if (largestIndex != i) {
        int tempValue = array[i];
        array[i] = array[largestIndex];
        array[largestIndex] = tempValue;
        fix_heap(array, length, largestIndex);
    }
}


void initialize_max_heap(int *array, int lenght) {
    for (int i = lenght / 2 - 1; i >= 0; i--) {
        fix_heap(array, lenght, i);
    }
}


void heap_sort_algorithm(int *array, int lenght){
    initialize_max_heap(array, lenght);

    for(int i = lenght-1; i>0; i--){
        int tempValue = array[0];
        array[0] = array[i];
        array[i] = tempValue;
        fix_heap(array, i, 0);
    }
}

/*Quick Sort*/
int partition(int *array, int start, int end) {
    int pivotValue = array[start];
    int i = start, j = end;

    while (i < j) {
        while (i <= end && array[i] <= pivotValue) i++;
        while (array[j] > pivotValue) j--;
        if (i < j) {
            int tempValue = array[i];
            array[i] = array[j];
            array[j] = tempValue;
        }
    }

    array[start] = array[j];
    array[j] = pivotValue;
    return j;
}

void quick_sort_recursive(int *array, int start, int end) {
    if (start < end) {
        int p = partition(array, start, end);
        quick_sort_recursive(array, start, p - 1);
        quick_sort_recursive(array, p + 1, end);
    }
}

void quick_sort_algorithm(int *array, int lenght){
    quick_sort_recursive(array, 0, lenght-1);
}

/*Counting Sort*/
void counting_sort_algorithm(int *array, int lenght) {
    int highestValue = 0;
    for (int i = 0; i < lenght; i++) {
        if (array[i] > highestValue)
            highestValue = array[i];
    }

    int *countArray = calloc(highestValue + 1, sizeof(int));
    if (!countArray) {
        fprintf(stderr, "Memory allocation failed");
        return;
    }

    for (int i = 0; i < lenght; i++)
        countArray[array[i]]++;

    int index = 0;
    for (int i = 0; i <= highestValue; i++) {
        while (countArray[i] > 0) {
            array[index++] = i;
            countArray[i]--;
        }
    }

    free(countArray);
}


/*Retorna média*/
double get_average(double *array, int lenght){
    double media = 0.0;
    for(int i = 0; i<lenght; i++){
        media = media + array[i];
    }
    return media/lenght;
}

/*Inverte vetor*/
void flip_array(int *array, int lenght){
    if(lenght>0){
        int *aux = calloc(lenght, sizeof(int));
        int iteration_count = 0;

        for(int i = 0; i<lenght; i++){
            aux[i] = array[i];
        }

        for(int j = lenght-1; j >= 0; j--){
            array[iteration_count++] = aux[j];
        }
    }
}

/*Embaralha vetor*/
void randomize_array(int *array, int lenght){
    srand(time(NULL));
    int index1, index2;
    int qtde = lenght * 0.1;
    for(int i = 0; i<qtde; i++){
        index1 = rand() % lenght;
        index2 = rand() % lenght;
        int tempValue = array[index1];
        array[index1] = array[index2];
        array[index2] = tempValue;
    }
}