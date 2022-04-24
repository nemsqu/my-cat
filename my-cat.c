#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

int main(int argc, char *argv[]){
    // quit if there's nothing to print
    if(argc == 1){
        exit(0);
    }

    FILE *pfile;
    char buffer[MAXLEN];

    // loop through files
    for(int i=1; i < argc; i++){
        if((pfile = fopen(argv[i], "r")) == NULL){
            printf("my-cat: cannot open file\n");
            exit(1);
        }
        // read the file and print its contents
        while(fgets(buffer, MAXLEN, pfile) != NULL){
            printf("%s", buffer);
        }
        fclose(pfile);
    }

    return 0;
}