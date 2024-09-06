#ifndef _TIMER_
#define _TIMER_

// Bubble Sort
void bubble_sort_algorithm(int *v, int n);

// Insertion Sort
void insertion_sort_algorithm(int *v, int n);

// Merge Sort
void merge_halves(int *v, int *temp, int ini, int meio, int fim);
void recursive_mergesort(int *v, int *temp, int ini, int fim);
void merge_sort_algorithm(int *v, int n);

// Heap Sort
int left_child(int pai);
int right_child(int pai);
void fix_heap(int *v, int n, int i);
void initialize_max_heap(int *v, int n);
void heap_sort_algorithm(int *v, int n);

// Quick Sort
void quick_sort_algorithm(int *v, int n);
void quick_sort_recursive(int *v, int ini, int fim);

// Counting Sort
void counting_sort_algorithm(int *v, int n);

// Retorna média do tempo
double get_average(double *v, int n);

// Inverte vetor
void flip_array(int *v, int n);

// Embaralha vetor
void randomize_array(int *v, int n);

#endif