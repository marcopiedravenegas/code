// Tomasulo's algorithm simulation
// Parses a MIPS32 binary and runs a dynamic scheduling simulation
// Marco Piedra Venegas

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const size_t buffer_size = 1048576;

void run_tomasulo(char* filename);

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s file\nfile: MIPS32 binary", argv[0]);
        exit(1);
    } else {
        parse_binary(argv[1]);
    }
    return 0;
}

void run_tomasulo(char* filename) {
    FILE* file = NULL;
    char buffer[buffer_size];
    size_t filesize = 0;
    if(memset(buffer, 0, buffer_size)) {
        if(file = fopen(filename, "r")) {
            if(filesize = fread(buffer, sizeof(char), buffer_size, file)) {
                printf("read %d byte(s) from %s\n", filesize, filename);
            } else {
                if(feof(file)) {
                    perror("file %s is empty\n", filename);
                } else if(ferror(file)) {
                    perror("error when reading from %s\n", filename);
                }
            }
            fclose(file);
        } else{
            perror("error when opening %s: %s\n", filename, strerror(errno));
        }
    } else {
        perror("cannot allocate memory\n");
    }
}
