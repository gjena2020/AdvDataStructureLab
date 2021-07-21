#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Utility function to print the array
void print_arr(int arr[], int arr_len) {
    for (int i = 0; i < arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// KMP string search function
void string_search(char *string, char *pattern, int *lookup_table, int s_len, int p_len) {
    int i = 0, j = 0;
    while (i < s_len && j < p_len) {
        if (string[i] == pattern[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = lookup_table[j - 1];
        } else {
            i++;
        }
    }
    if (j == p_len)
        printf("Found pattern at index: %d\n", (i - j));
    else
        printf("Could not find the pattern\n");
}

// Function to build lookup table using pattern
int *build_lookup_table(char *pattern, int p_len) {
    int *table = (int *) malloc(p_len * sizeof(int));
    memset(table, 0, p_len);

    int idx = 0;
    int j = 1;
    while (j < p_len) {
        if (pattern[idx] == pattern[j]) {
            idx++;
            table[j] = idx;
            j++;
        } else if (idx > 0) {
            idx = table[idx - 1];
        } else {
            j++;
        }
    }
    return table;
}

// Driver function
int main() {
    char *string = "ABCABAB ABABABAABAC";
    char *pattern = "ABABAABA";
    int s_len = strlen(string);
    int p_len = strlen(pattern);

    int* lookup_table = build_lookup_table(pattern, p_len);
    printf("Lookup table: ");
    print_arr(lookup_table, p_len);
    string_search(string, pattern, lookup_table, s_len, p_len);

    return 0;
}
