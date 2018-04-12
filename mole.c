//
// Find the start index of the hammer with the highest number of mole.
// Return the last index occurance.
//
// by Rudy Zulkarnain
// April 10th, 2018
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MY_MAX(x,y) (x>y?x:y)

// 
// Helper function to print the array
//
void my_print_array(int test_index, int arr[], int arr_size)
{
    printf("Test%d: [", test_index);
    for (int i = 0; i < arr_size; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

//
// max_hit, return the last index of maximum hit
// width defined the hammer size
//
// return -1, if no hit found
//
int max_hit(int *arr, int arr_size, int width)
{
    int i;
    int max_hit_var = 0;
    int count = 0;
    int start_index = 0;
    int last_max_hit_var = 0;

    if (arr_size == 0 || arr == NULL) {
       return -1;
    }

    for (i=0; i<arr_size; i++) {
        if (arr[i] == 1) {
           count++;
        }

        max_hit_var = MY_MAX(max_hit_var, count);
        
        if (max_hit_var != last_max_hit_var) {
            // find the last occurence 
            start_index = (i+1) - width;
            last_max_hit_var = max_hit_var;
        }

        if (start_index > 0 && arr[start_index] == 0) {
            count = count - arr[start_index - 1];
        }

        // printf("i=%d, max_hit_var=%d, start_index=%d, count=%d\n", 
        //      i, max_hit_var, start_index, count);
    }

    return (count == 0) ? -1 : start_index + 1; // 1 based number
}

int main()
{
    int hammer_width = 4;
    int test1_arr[] = { 0, 1, 0, 1, 1, 0, 1, 0 };
    int test1_arr_size = sizeof(test1_arr)/sizeof(test1_arr[0]);

    int test2_arr[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int test2_arr_size = sizeof(test2_arr)/sizeof(test2_arr[0]);

    int test3_arr[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    int test3_arr_size = sizeof(test3_arr)/sizeof(test3_arr[0]);

    int test4_arr[] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    int test4_arr_size = sizeof(test4_arr)/sizeof(test4_arr[0]);

    printf("---- mole max hit tests ----\n");

    my_print_array(1, test1_arr, test1_arr_size);
    printf("Last Index max_hit=%d\n", 
           max_hit(test1_arr, test1_arr_size, 4));

    my_print_array(2, test2_arr, test2_arr_size);
    printf("Last index max_hit=%d\n", 
           max_hit(test2_arr, test2_arr_size, 4));

    my_print_array(3, test3_arr, test3_arr_size);
    printf("Last index max_hit=%d\n", 
           max_hit(test3_arr, test3_arr_size, 4));

    my_print_array(4, test4_arr, test4_arr_size);
    printf("Last index max_hit=%d\n", 
           max_hit(test4_arr, test4_arr_size, 4));

    return 0;
}
