# Projeto de Comparação de Algoritmos de Ordenação

## Visão Geral do Projeto
Este projeto implementa e compara o desempenho de vários algoritmos de ordenação utilizando diferentes tipos e tamanhos de arrays de entrada. O objetivo é fornecer insights sobre a eficiência de diferentes métodos de ordenação em várias condições.

## Algoritmos Implementados
1. Bubble Sort (Ordenação por Flutuação)
2. Insertion Sort (Ordenação por Inserção)
3. Merge Sort (Ordenação por Fusão)
4. Quick Sort (Ordenação Rápida)
5. Heap Sort (Ordenação por Montículo)
6. Counting Sort (Ordenação por Contagem)

## Tipos de Arrays de Entrada
1. Aleatório
2. Invertido
3. Já Ordenado
4. Quase Ordenado

## Estrutura do Projeto
- `helpers.h`: Arquivo de cabeçalho contendo declarações de funções e definições de tipos.
- `helpers.c`: Implementação dos algoritmos de ordenação e funções auxiliares.
- `sort_exec.c`: Programa principal que executa as comparações de ordenação e exibe os resultados.

## Detalhes da Implementação

### Algoritmos de Ordenação
- **Bubble Sort**: Complexidade de tempo O(n^2), Complexidade de espaço O(1)
- **Insertion Sort**: Complexidade de tempo O(n^2), Complexidade de espaço O(1)
- **Merge Sort**: Complexidade de tempo O(n log n), Complexidade de espaço O(n)
- **Quick Sort**: Complexidade de tempo média O(n log n), pior caso O(n^2), Complexidade de espaço O(log n)
- **Heap Sort**: Complexidade de tempo O(n log n), Complexidade de espaço O(1)
- **Counting Sort**: Complexidade de tempo O(n + k), Complexidade de espaço O(n + k) (onde k é o intervalo de entrada)

### Funções Auxiliares
- `generate_array`: Cria arrays de um tipo especificado (aleatório, invertido, ordenado, quase ordenado)
- `get_average`: Calcula a média de um array de números decimais
- `randomize_array`: Embaralha um array aleatoriamente
- `flip_array`: Inverte a ordem dos elementos em um array
- `swap`: Troca dois valores inteiros

### Lógica do Programa Principal
1. O usuário insere os parâmetros:
   - Tamanho inicial do array
   - Tamanho final do array
   - Incremento entre os tamanhos dos arrays
   - Número de repetições para cada teste
2. Para cada tipo de array (aleatório, invertido, ordenado, quase ordenado):
   - Para cada tamanho de array, do inicial ao final, com incremento especificado:
   - Gera um array do tipo e tamanho atual
   - Executa cada algoritmo de ordenação em uma cópia do array, medindo o tempo de execução
   - Repete o processo para o número especificado de repetições
   - Calcula e armazena o tempo médio de execução para cada algoritmo
3. Exibe os resultados no console e grava em um arquivo de log

## Como Usar
1. Compile o projeto:
   ```
   gcc sort_exec.c helpers.c -o main
   ```
2. Execute o executável:
   ```
   ./main
   ```
3. Siga as instruções para inserir:
   - Tamanho inicial do array
   - Tamanho final do array
   - Incremento entre os tamanhos dos arrays
   - Número de repetições para cada teste
4. O programa exibirá os resultados no console e também em um arquivo de log chamado `log_file.txt`

## Formato de Saída
Os resultados são apresentados em formato tabular, mostrando o tempo de execução (em segundos) para cada algoritmo de ordenação, considerando diferentes tamanhos e tipos de arrays.

Exemplo:
```
[[ALEATÓRIO]]
   n     Bubble     Insertion    Merge       Quick        Heap      Counting
-----------------------------------------------------------------------------
 1000    0.000123    0.000098    0.000052    0.000047    0.000056    0.000031
 2000    0.000486    0.000391    0.000112    0.000102    0.000124    0.000064
 ...
```

## Notas
- O projeto utiliza temporizadores de alta resolução para uma medição precisa do tempo.
- Uma função de limpeza de cache foi implementada para minimizar o impacto do cache nas execuções subsequentes.
- O código foi projetado para ser portátil, com compilação condicional para sistemas Windows e Unix-like.

<!-- ## Melhorias Potenciais
- Implementar algoritmos de ordenação adicionais (por exemplo, Radix Sort, Shell Sort)
- Adicionar visualização dos resultados (por exemplo, gráficos)
- Ampliar a análise para incluir métricas de uso de memória
- Implementar multithreading para execução paralela dos testes -->

## Conclusão
Este projeto fornece uma estrutura abrangente para comparar o desempenho de algoritmos de ordenação em diferentes tipos e tamanhos de entrada.
