//
// Created  on 4/1/22.
//wgrep searches each line for given keyword
//c3500
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *fp = fopen(argv[2], "r");

    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if(fp == NULL){
        printf("Cannont open file\n");
        exit(1);
    }



    char buf[128];

    // iterating over file line by line
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        if (strstr(buf, argv[1]))
        {
            fputs(buf, stdout);
        }
    }

    fclose(fp);
    return 0;
}
