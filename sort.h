#ifndef __SORT_H__
#define __SORT_H__

#include <stdbool.h>
#include <stddef.h>
#include <math.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *arr, int low, int high, size_t size);
void swap_el(int *arr, int *el_1, int *el_2, size_t size);
void quick_sort_recur(int *arr, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void isHsorted(int *arr, size_t n, size_t size);
void swapVal(int *arr, int i, int j);

#endif
