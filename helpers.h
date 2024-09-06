// helpers.h
#ifndef _TIMER_
#define _TIMER_

// Bubble Sort
void bubble_sort_algorithm(int *array, int lenght);

// Insertion Sort
void insertion_sort_algorithm(int *array, int lenght);

// Merge Sort
void merge_halves(int *array, int start, int midpoint, int end); // Remover o parâmetro temp

void recursive_mergesort(int *array, int start, int end); // Remover o parâmetro temp

void merge_sort_algorithm(int *array, int lenght);

// Heap Sort
int left_child(int pai);

int right_child(int pai);

void fix_heap(int *array, int lenght, int i);

void initialize_max_heap(int *array, int lenght);

void heap_sort_algorithm(int *array, int lenght);

// Quick Sort
void quick_sort_algorithm(int *array, int lenght);

void quick_sort_recursive(int *array, int start, int end);

int partition(int *array, int start, int end);

// Counting Sort
void counting_sort_algorithm(int *array, int lenght);

// Retorna média do tempo
double get_average(double *array, int lenght);

// Inverte vetor
void flip_array(int *array, int lenght);

// Embaralha vetor
void randomize_array(int *array, int lenght);

#endif
