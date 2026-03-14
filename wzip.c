//
// Created  on 4/6/22.
//wzip compresses a file
//c3500
//
#include <stdio.h>
#include <stdlib.h>
// SIZE is max size of buffe
#define SIZE 64

int main(int argc, char* argv[]) {

    if(argc == 1) {
        printf("Wzip file1[file2...]\n");
        exit(1);

    }

    char buf[SIZE]; //buffer string for reading from file

    int i;

    for(i=1; i<argc; i++){ //iterate over command line arguments

        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL) {

            printf("Wzip: cannot open file\n");

            exit(1);

        }

        while (fgets(buf, SIZE, fp)!=NULL) { //read from file in buffer, if it returns NULL then no content to read from file

            char *ptr=buf;
            char current=*ptr;
            unsigned int count=0;

            while(*ptr != '\0') { //traverse till the end of string

                if(*ptr == current){

                    count++;
                    ptr++;
                    continue;

                } else if(count == 4283853284) { //check overflow

                    printf("%d%c",count,current);
                    current='\0';
                    count=0;

                } else {

                    printf("%d%c",count,current);
                    current=*ptr;
                    count=0;

                }

            }
        }
        printf("\n");

        fclose(fp);

    }

    return 0;

}

