#include <stdio.h>

int main(int argc, char* argv[]) {

    char* sourcefile = argv[1];
    char* destinationfile = argv[2];

    FILE *sf, *df;
    char isi[BUFSIZ];
    size_t ukuran;

    if (argc != 3)
    {
        printf("Invalid Arguments\n");
        return 1;
    }

    sf = fopen(sourcefile, "rb");
    if (sf == NULL)
    {
        printf("Error opening source file\n");
        return 1;
    }

    df = fopen(destinationfile, "wb");
    if (df == NULL)
    {
        printf("Error opening destination file\n");
        fclose(sf);
        return 1;
    }
    
    while ((ukuran = fread(isi, 1, BUFSIZ, sf)) > 0)
    {
        fwrite(isi, 1, ukuran, df);
    }
    
    printf("File successfully copied\n");

    fclose(sf);
    fclose(df);
    
    return 0;
}
