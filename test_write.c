#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
// File descriptor
// Each file --> file descriptor
// Number >= 0
// Standart input         -- stdin  -- 0
// Standart output        -- stdout -- 1
// Standart error putput  -- stderr -- 2
int main(){
    /*char *buf = "HELLO SYSCALLS!\n";
    int sym_num = strlen(buf);
    int written_count;
    written_count = write(1, buf, sym_num);
    if(written_count != sym_num) {
        write(2, "COuld not open file!", 21);
    }*/

    int fd = open("test_binary", O_WRONLY | O_TRUNC);
    printf("new_fd: %d\n", fd);
    if(fd == -1) {
        perror("Could not open file\n");
    }
    int arr[] = {1, 2, 3, 4};
    int written_count;
    written_count = write(1, arr, sizeof(int) * 4);
    if(written_count != sizeof(int) * 4) {
        write(2, "COuld not open the file!", 21);
    }
    close(fd);
    return 0;
}