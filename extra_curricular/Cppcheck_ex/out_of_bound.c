#include <stdio.h>
#include <stdlib.h>


void literal_access() {
    int innocent_arr[5] = {0};
    int out_of_bound_value = innocent_arr[5];
}

void arg_access(int idx) {
    int innocent_arr[5] = {0};
    int maybe_out_of_bound_value = innocent_arr[idx];
}

void branch_access(int idx) {
    int innocent_arr[5] = {0};
    int out_of_bound_value;
    if (idx > 5)
        out_of_bound_value = innocent_arr[idx];
}

int main(int argc, char* argv[]) {
    int input_idx;
    scanf("%d", &input_idx);

    literal_access();
    arg_access(input_idx);
    branch_access(input_idx);

    if (argc > 1)
    {
        arg_access(atoi(argv[1]));
    }
}
