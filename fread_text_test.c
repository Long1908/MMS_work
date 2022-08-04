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
    char arr[12];
    fread(arr, sizeof(char), 12, f_ptr);
    fprintf(stdout, "%s", arr);
    fclose(f_ptr);
    return 0;
}