#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name;
    int address;
    int value;
} Memory;

int main() {
    FILE *input = fopen("input.pl", "r");
    FILE *output = fopen("output.bl", "w");

    Memory memory[5] = {0};
    char line[256];
    int DR = 0;
    int should_pop = 0;

    while (fgets(line, sizeof(line), input)) {
        char op[10];
        char mem1, mem2;
        sscanf(line, "%s %c, %c", op, &mem1, &mem2);

        if (strcmp(op, "WRITE") == 0) {
            int address, value;
            sscanf(line, "WRITE %c, %d, %d", &mem1, &address, &value);
            int idx = mem1 - 'A';
            memory[idx].name = mem1;
            memory[idx].address = address;
            memory[idx].value = value;

            fprintf(output, "0011 %04d\n", value);
            fprintf(output, "1000 %04d\n", address);
            fprintf(output, "0101\n");
        } else if (strcmp(op, "ADD") == 0) {
            sscanf(line, "ADD %c, %c", &mem1, &mem2);
            int idx1 = mem1 - 'A';
            int idx2 = mem2 - 'A';

            fprintf(output, "0001 %04d\n", memory[idx1].address);
            fprintf(output, "0100\n");
            fprintf(output, "0001 %04d\n", memory[idx2].address);
            fprintf(output, "0110\n");
            should_pop = 1;
        } else if (strcmp(op, "SUB") == 0) {
            sscanf(line, "SUB %c", &mem1);
            int idx = mem1 - 'A';

            fprintf(output, "0001 %04d\n", memory[idx].address);
            fprintf(output, "0111\n");
            should_pop = 1;
        } else if (strcmp(op, "STORE") == 0) {
            sscanf(line, "STORE %c", &mem1);
            int idx = mem1 - 'A';

            if (should_pop) {
                fprintf(output, "0101\n");
                should_pop = 0;
            }
            fprintf(output, "0010 %04d\n", memory[idx].address);
        } else if (strcmp(op, "PRINT") == 0) {
            sscanf(line, "PRINT %c", &mem1);
            int idx = mem1 - 'A';

            if (should_pop) {
                fprintf(output, "0101\n");
                should_pop = 0;
            }
            fprintf(output, "1001 %04d\n", memory[idx].address);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
