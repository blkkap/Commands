//

//wcat prints out the whole file
//c3500
//
#include <stdio.h>
#include <stdlib.h>


#define SIZE 64


int main(int argc, char* argv[]) {

    if(argc == 1) {
        printf("Wcat file[file....]\n");
        exit(1);//exit failure
    }

    char buf[SIZE];
    int i;

    for(i=1; i<argc; i++){ //iterate over command line arguments

        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL) {

            printf("wcat: cannot open file\n");
            exit(1);

        }
    while (fgets(buf, SIZE, fp)!=NULL) {

        printf("%s",buf);

        }

    printf("\n");
    fclose(fp);
    }

return 0;

}
