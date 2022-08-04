#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f_ptr = fopen("test_binary_file", "w");
    if(!f_ptr){
        perror("Couldnt open file.");
        exit(-1);
    }
    long int arr[] = {5312312312321, 13123123111241, 12231231231312, 6212312312312};
    fwrite(arr, sizeof(int), 4, f_ptr);
    fclose(f_ptr);
    return 0;
}