#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>  
#include <stddef.h>
#include <time.h>
#include <stdio.h>

#pragma once

typedef enum {
    RANDOM,
    REVERSE,
    SORTED,
    NEARLY_SORTED
} ArrayType;

// Bubble Sort
void bubble_sort_algorithm(int *array, size_t length);

// Insertion Sort
void insertion_sort_algorithm(int *array, size_t length);

// Merge Sort
void merge_halves(int *array, size_t start, size_t midpoint, size_t end);
void recursive_mergesort(int *array, size_t start, size_t end);
void merge_sort_algorithm(int *array, size_t length);

// Heap Sort
size_t left_child(size_t parent_index);
size_t right_child(size_t parent_index);
void fix_heap(int *array, size_t length, size_t i);
void initialize_max_heap(int *array, size_t length);
void heap_sort_algorithm(int *array, size_t length);

// Quick Sort
void quick_sort_algorithm(int *array, size_t length);
void quick_sort_recursive(int *array, size_t start, size_t end);
size_t partition(int *array, size_t start, size_t end);

// Counting Sort
void counting_sort_algorithm(int *array, size_t length);

// Funções auxiliares
double get_average(const double *array, size_t length);
void flip_array(int *array, size_t length);
void randomize_array(int *array, size_t length);
void swap(int *a, int *b);

// Funções de geração e execução
void generate_nearly_sorted_array(int *array, int size);
void generate_array(int *array, int size, ArrayType type);
/*void clear_cache(void);
void run_sorts(int *array, int size, int repetitions, double *times);
void print_results(FILE *file, int size, double *times);*/

#endif // HELPERS_H