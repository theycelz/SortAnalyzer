#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helpers.h"
#define TAM 10000

typedef enum {
    RANDOM,
    REVERSE,
    SORTED,
    NEARLY_SORTED
} ArrayType;

void run_sorts(int *array, int size, int repetitions, double *times);
void print_results(FILE *file, int size, double *times);
void generate_array(int *array, int size, ArrayType type);

int main() {
    int inc, fim, stp, rpt;
    double times[6];
    FILE *log_file;
    
    srand(time(NULL)); // Inicidaliza o gerador de números aleatórios

    printf("Digite o inicio do vetor: ");
    scanf("%d", &inc);
    printf("Digite o fim do vetor: ");
    scanf("%d", &fim);
    printf("Digite o intervalo entre dois vetores: ");
    scanf("%d", &stp);
    printf("Digite quantas vezes o vetor deve repetir: ");
    scanf("%d", &rpt);

    log_file = fopen("log_file.txt", "w");
    if (!log_file) {
        fprintf(stderr, "Error opening log file\n");
        return 1;
    }

    const char *headers[] = {"RANDOM", "REVERSE", "SORTED", "NEARLY SORTED"};
    for (int i = 0; i < 4; i++) {
        printf("\n[[%s]]\n", headers[i]);
        printf("   n     Bubble     Insertion    Merge       Quick        Heap      Counting\n");
        printf("-----------------------------------------------------------------------------\n");
        fprintf(log_file, "\n[[%s]]\n", headers[i]);
        fprintf(log_file, "   n     Bubble     Insertion    Merge       Quick        Heap      Counting\n");
        fprintf(log_file, "-----------------------------------------------------------------------------\n");

        for (int size = inc; size <= fim; size += stp) {
            int *array = malloc(size * sizeof(int));
            if (!array) {
                fprintf(stderr, "Memory allocation failed\n");
                fclose(log_file);
                return 1;
            }

            generate_array(array, size, i);
            run_sorts(array, size, rpt, times);
            print_results(stdout, size, times);
            print_results(log_file, size, times);

            free(array);
        }
    }

    fclose(log_file);
    return 0;
}

void run_sorts(int *array, int size, int repetitions, double *times) {
    void (*sort_functions[])(int*, int) = {
        bubble_sort_algorithm, insertion_sort_algorithm, merge_sort_algorithm,
        quick_sort_algorithm, heap_sort_algorithm, counting_sort_algorithm
    };

    for (int i = 0; i < 6; i++) {
        times[i] = 0;
        for (int j = 0; j < repetitions; j++) {
            int *temp_array = malloc(size * sizeof(int));
            if (!temp_array) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            memcpy(temp_array, array, size * sizeof(int));

            clock_t begin = clock();
            sort_functions[i](temp_array, size);
            clock_t end = clock();

            times[i] += (double)(end - begin) / CLOCKS_PER_SEC;
            free(temp_array);
        }
        times[i] /= repetitions;
    }
}

void print_results(FILE *file, int size, double *times) {
    fprintf(file, "%d", size);
    for (int i = 0; i < 6; i++) {
        fprintf(file, "    %f", times[i]);
    }
    fprintf(file, "\n");
}

void generate_array(int *array, int size, ArrayType type) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % TAM;
    }

    switch (type) {
        case RANDOM:
            break;
        case REVERSE:
            merge_sort_algorithm(array, size);
            flip_array(array, size);
            break;
        case SORTED:
            merge_sort_algorithm(array, size);
            break;
        case NEARLY_SORTED:
            merge_sort_algorithm(array, size);
            randomize_array(array, size);
            break;
    }
}