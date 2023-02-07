#include <stdio.h>

int main(int argc, char* argv[]) {

    char* sc = argv[1];
    char* dt = argv[2];

    FILE *sf, *df;
    char karakter;

    if (argc != 3)
    {
        printf("Invalid Argument");
        return 1;
    }

    sf = fopen(sc, "r");
    if (sf == NULL)
    {
        printf("Cannot find the source file");
        return 1;
    }

    df = fopen(dt, "");
    if (df == NULL)
    {
        printf("Cannot find the destination");
        fclose(sf);
        return 1;
    }
    
    while (1)
    {
        karakter = fgetc(sf);

        if (karakter != EOF)
        {
            fputc(karakter, df);
        }
        
    }
    
    printf("Copy File Successfully");

    fclose(sf);
    fclose(df);
    
    return 0;
}