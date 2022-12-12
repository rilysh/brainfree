#include <stdio.h>

unsigned int MAX_CHAR_READ =  65536;
unsigned int MAX_ARRAY_SIZE = 300000;

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "error: expect a file\n");
        return 1;
    }
    unsigned char ptr[MAX_ARRAY_SIZE], arr[MAX_ARRAY_SIZE];
    unsigned int poi = 0, idx = 0, stack[MAX_CHAR_READ], stackp = 0, targets[MAX_ARRAY_SIZE];
    register size_t length;
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    length = fread_unlocked(ptr, 1, MAX_CHAR_READ, fp);
    fclose(fp);
    
    for (; poi < length; poi++) {
        (ptr[poi] == '[') ? (stack[stackp++] = poi) : ' ';
        (ptr[poi] == ']') ? ({
            stackp--;
            targets[poi] = stack[stackp];
            targets[stack[stackp]] = poi;
        }) : ' ';
    }

    for (poi = 0; poi < length; poi++) {
        switch (ptr[poi]) {
            case '>': idx++; break;
            case '<': idx--; break;
            case '+': arr[idx]++; break;
            case '-': arr[idx]--; break;
            case '.': fwrite_unlocked(&arr[idx], sizeof(arr[idx]), 1, stdout);  break;
            case ',': arr[idx] = (unsigned int)getc_unlocked(stdin); break;
            case '[': !arr[idx] ? (poi = targets[poi]) : ' '; break;
            case ']': arr[idx] ? (poi = targets[poi]) : ' '; break;
        }
    }
}
