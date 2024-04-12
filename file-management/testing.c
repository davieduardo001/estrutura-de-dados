#include<stdio.h>
#include<stdlib.h>



int main() {

    FILE *file;
    file = fopen("test.txt", "w");
    fprintf(file,"aaaaa");
    fclose(file);

    return 0;
}