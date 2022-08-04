// ./my_cp in_file out_file
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int arg, char **argp) {
    //Open in_file for reading
    int fd_in = open(argp[1], O_RDONLY);
    if(fd_in == -1) {
        perror("COuld not open in_file\n");
        return -1;
    }
    char cur_sym;
    int read_count;
    read(fd_in, &cur_sym, 1);
    if(read_count == -1) {
        perror("Could not open in_file \n");
        return -1;
    }
    int written_count;
    written_count = write(1, &cur_sym, 1);
    if(written_count == 0) {
        perror("Write error\n");
        return -1;
    }
    close(fd_in);
    //Open out_file for writing
    //Create out_file if it does not exist
    //Error of out_file already exists

    //For each byte from in_file
    //Write it to out_file

    //close out_file/ in_file

}