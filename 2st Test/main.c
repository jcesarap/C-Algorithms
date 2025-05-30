#include <stdbool.h>
#include <stdio.h>

// ——— In short, to loop over a loop:
// Do the inner loop and its conditions
// Do a "do" and stablish the break conditions

void sort_array(int array[], int size) {
  bool modified = false; // Declared outside for
  do {                   // At least once
    modified = false;
    for (int i = 0; i < size - 1; i++) { // For each element
      if (array[i] > array[i + 1]) {     // If elements are equal
        // Replace them
        int aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
        modified = true; // Mark that there's has been a replacement
      }
      // If no element is replaced, rune has gone through all elements, and they're all in order
      // So there's no increment, and therefore
    }
    // After finishing the loop, the do is called again, restarting the loop
  } while (modified); // Loop "Forever", as long as there are modifications in the loop
}

// Print the array up to the given size
void print_array(int array[], int size) {
  printf("\n ——— Current sorted array ———");
  int cont = 0;
  for (int i = 0; i < 10; i++) { // You can also print up to current iteration
    printf("\n %d: %d", cont, array[i]);
    cont++;
  }
}

int main() {
  int array[10] = {1};
  int total = 10;
  for (int i = 0; i != total; i++) {
    // Prompt
    printf("\nEnter a number: ");
    scanf("%d", &array[i]);
    // Sort and Print
    sort_array(array, i); // 1 up to current index - so the random numbers are not shown, but they're still there
    print_array(array, i);
  }
  return 0;
}
