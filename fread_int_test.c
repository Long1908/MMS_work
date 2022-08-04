#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f_ptr = fopen("test_text_file", "r");
    if(!f_ptr)
    {
        perror("Could not open file\n");
        exit(-1);
    }
    long int arr[4];
    fread(arr, sizeof(int), 4, f_ptr);
    fprintf(stdout, "%ld %ld %ld %ld\n", arr[0], arr[1], arr[2], arr[3]);
    fclose(f_ptr);
    return 0;
}