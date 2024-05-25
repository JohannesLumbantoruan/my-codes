#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int** arr, int* size, int data);
void unshift(int** arr, int* size, int data);
void pop(int** arr, int* size);
void shift(int** arr, int* size);
void print_arr(int* arr, int size, char text[]);

int main() {
  int size = 5;
  int* numbers = (int*)calloc(size, sizeof(int));

  for (int i = 0; i < 5; i++) {
    numbers[i] = (i + 1) * 5;
  }

  push(&numbers, &size, 50);

  print_arr(numbers, size, "push");

  pop(&numbers, &size);

  print_arr(numbers, size, "pop");

  unshift(&numbers, &size, 100);

  print_arr(numbers, size, "unshift");

  shift(&numbers, &size);

  print_arr(numbers, size, "shift");

  free(numbers);

  return 0;
}

void push(int** arr, int* size, int data) {
  *arr = (int*)realloc(*arr, (*size + 1) * sizeof(int));

  (*arr)[*size] = data;

  (*size)++;
}

void unshift(int** arr, int* size, int data) {
  *arr = (int*)realloc(*arr, (*size + 1) * sizeof(int));

  memmove((*arr) + 1, *arr, (*size) * sizeof(int));
  (*arr)[0] = data;

  (*size)++;
}

void pop(int** arr, int* size) {
  *arr = (int*)realloc(*arr, (*size - 1) * sizeof(int));

  (*size)--;
}

void shift(int** arr, int* size) {
  memmove(*arr, (*arr) + 1, (*size - 1) * sizeof(int));

  *arr = (int*)realloc(*arr, (*size - 1) * sizeof(int));

  (*size)--;
}

void print_arr(int* arr, int size, char text[]) {
  printf("%s: ", text);

  for (int i = 0; i < size; i++) {
    if (i == 0) {
      printf("[%d, ", arr[i]);
    } else if (i == size - 1) {
      printf("%d]\n", arr[i]);
    } else {
      printf("%d, ", arr[i]);
    }
  }
}