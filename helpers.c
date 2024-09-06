#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "helpers.h"

#define TAM 10000
#define MAX 10001

/* Algoritmo Bubble Sort
   Complexidade de tempo: O(n^2)
   Complexidade de espaço: O(1) */
void bubble_sort_algorithm(int *array, size_t length) {
    bool swapped;
    for (size_t i = 0; i < length - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/* Algoritmo Insertion Sort
   Complexidade de tempo: O(n^2)
   Complexidade de espaço: O(1) */
void insertion_sort_algorithm(int *array, size_t length) {
    int current_value;
    size_t i, j;
    for (j = 1; j < length; j++) {
        current_value = array[j];
        i = j - 1;
        while (i < length && array[i] > current_value) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = current_value;
    }
}

/* Algoritmo Merge Sort
   Complexidade de tempo: O(n log n)
   Complexidade de espaço: O(n) */

void merge_halves(int *array, size_t start, size_t midpoint, size_t end) {
    size_t left_part_size = midpoint - start + 1;
    size_t right_part_size = end - midpoint;
    
    int *left_array = malloc(left_part_size * sizeof(int));
    int *right_array = malloc(right_part_size * sizeof(int));

    if (!left_array || !right_array) {
        fprintf(stderr, "Memory allocation failed in merge_halves\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < left_part_size; i++)
        left_array[i] = array[start + i];

    for (size_t j = 0; j < right_part_size; j++)
        right_array[j] = array[midpoint + 1 + j];

    size_t i = 0, j = 0, k = start;

    while (i < left_part_size && j < right_part_size) {
        if (left_array[i] <= right_array[j])
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }

    while (i < left_part_size)
        array[k++] = left_array[i++];

    while (j < right_part_size)
        array[k++] = right_array[j++];

    free(left_array);
    free(right_array);
}

void recursive_mergesort(int *array, size_t start, size_t end) {
    if (start < end) {
        size_t midpoint = start + (end - start) / 2;

        recursive_mergesort(array, start, midpoint);
        recursive_mergesort(array, midpoint + 1, end);
        
        merge_halves(array, start, midpoint, end);
    }
}

void merge_sort_algorithm(int *array, size_t length) {
    recursive_mergesort(array, 0, length - 1);
}

/* Algoritmo Heap Sort
   Complexidade de tempo: O(n log n)
   Complexidade de espaço: O(1) */
   
// Função para obter o índice do filho esquerdo
size_t left_child(size_t parent_index) {
    return 2 * parent_index + 1;
}

// Função para obter o índice do filho direito
size_t right_child(size_t parent_index) {
    return 2 * parent_index + 2;
}

// Função para ajustar o heap
void fix_heap(int *array, size_t length, size_t i) {
    size_t largest_index = i;
    size_t left_index = left_child(i);
    size_t right_index = right_child(i);

    if (left_index < length && array[left_index] > array[largest_index]) {
        largest_index = left_index;
    }
    if (right_index < length && array[right_index] > array[largest_index]) {
        largest_index = right_index;
    }
    if (largest_index != i) {
        swap(&array[i], &array[largest_index]);
        fix_heap(array, length, largest_index);
    }
}

// Função para construir o max-heap
void initialize_max_heap(int *array, size_t length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        fix_heap(array, length, i);
    }
}

// Função para implementar o Heap Sort
void heap_sort_algorithm(int *array, size_t length) {
    // Construa o heap
    initialize_max_heap(array, length);

    // Extraia os elementos um por um
    for (size_t i = length - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        fix_heap(array, i, 0);
    }
}

/* Algoritmo Quick Sort
   Complexidade de tempo: O(n log n) média, O(n^2) pior caso
   Complexidade de espaço: O(log n) */

size_t median_of_three(int *array, size_t start, size_t end) {
    size_t mid = start + (end - start) / 2;
    if (array[start] > array[mid])
        swap(&array[start], &array[mid]);
    if (array[mid] > array[end])
        swap(&array[mid], &array[end]);
    if (array[start] > array[mid])
        swap(&array[start], &array[mid]);
    return mid;
}

size_t partition(int *array, size_t start, size_t end) {
    size_t pivot_index = median_of_three(array, start, end);
    int pivot_value = array[pivot_index];
    swap(&array[pivot_index], &array[end]);
    
    size_t i = start - 1;

    for (size_t j = start; j < end; j++) {
        if (array[j] <= pivot_value) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[end]);
    return i + 1;
}

void quick_sort_recursive(int *array, size_t start, size_t end) {
    if (start < end) {
        size_t p = partition(array, start, end);
        if (p > 0) quick_sort_recursive(array, start, p - 1);
        quick_sort_recursive(array, p + 1, end);
    }
}

void quick_sort_algorithm(int *array, size_t length) {
    quick_sort_recursive(array, 0, length - 1);
}

/* Algoritmo Counting Sort
   Complexidade de tempo: O(n + k) onde k é o range de valores
   Complexidade de espaço: O(n + k) */
void counting_sort_algorithm(int *array, size_t length) {
    if (length == 0) return;

    int min = array[0], max = array[0];
    for (size_t i = 1; i < length; i++) {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }

    size_t range = max - min + 1;
    int *count = calloc(range, sizeof(int));
    int *output = malloc(length * sizeof(int));

    if (!count || !output) {
        fprintf(stderr, "Memory allocation failed in counting_sort_algorithm\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < length; i++)
        count[array[i] - min]++;

    for (size_t i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = length - 1; i >= 0; i--) {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    for (size_t i = 0; i < length; i++)
        array[i] = output[i];

    free(count);
    free(output);
}

/* Função de cálculo de média */
double get_average(const double *array, size_t length) {
    double sum = 0.0;
    for (size_t i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}

/* Função para embaralhar vetor */
void randomize_array(int *array, size_t length) {
    srand(time(NULL));
    for (size_t i = length - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        swap(&array[i], &array[j]);
    }
}

/* Função para inverter vetor */
void flip_array(int *array, size_t length) {
    for (size_t i = 0, j = length - 1; i < j; i++, j--) {
        swap(&array[i], &array[j]);
    }
}

/* Função auxiliar para trocar dois elementos */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Função auxiliar para gerar arrays*/

void generate_array(int *array, int size, ArrayType type) {
    switch (type) {
        case RANDOM:
            for (int i = 0; i < size; i++) {
                array[i] = rand() % TAM;
            }
            break;
        case REVERSE:
            for (int i = 0; i < size; i++) {
                array[i] = size - i - 1;
            }
            break;
        case SORTED:
            for (int i = 0; i < size; i++) {
                array[i] = i;
            }
            break;
        case NEARLY_SORTED:
            generate_nearly_sorted_array(array, size);
            break;
    }
}

/*Função para gerar vetores parcialmente sortidos*/


void generate_nearly_sorted_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    int num_errors = size / 6;
    for (int i = 0; i < num_errors; i++) {
        int idx = rand() % size;
        int new_value = rand() % size;
        array[idx] = new_value;
    }
}


