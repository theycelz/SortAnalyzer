#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#elif defined(__APPLE__) || defined(__linux__)
#include <sys/time.h>
#else
#error "Unsupported platform"
#endif

double get_time() {
#ifdef _WIN32
    LARGE_INTEGER frequency, time;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return (double)time.QuadPart / (double)frequency.QuadPart;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1e6;
#endif
}

double measure_time(void (*sort_function)(int*, size_t), int* array, size_t size) {
    double start, end;
    
    start = get_time();
    sort_function(array, size);
    end = get_time();
    
    return end - start;
}

void run_sorts(int *array, int size, int repetitions, double *times) {
    void (*sort_functions[])(int*, size_t) = {
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

            times[i] += measure_time(sort_functions[i], temp_array, (size_t)size);
            
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



void clear_cache() {
    const int size = 20 * 1024 * 1024; // 20 MB
    char *buffer = (char*)malloc(size);
    for (int i = 0; i < size; i++)
        buffer[i] = rand();
    for (int i = 0; i < size; i++)
        buffer[i] += 1;
    free(buffer);
}

int main() {
    int inc, fim, stp, rpt;
    double times[6];
    FILE *log_file;
    
    srand(time(NULL));

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
            
            clear_cache(); // Limpa o cache antes de cada conjunto de testes
            
            run_sorts(array, size, rpt, times);
            print_results(stdout, size, times);
            print_results(log_file, size, times);

            free(array);
        }
    }

    fclose(log_file);
    return 0;
}