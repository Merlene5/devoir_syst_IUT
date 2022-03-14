#include "md5.c"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Format : %s <parameter1><parameter2>\n", argv[0]);
        exit(0);
    }

    FILE *f1, *f2;

    f1 = fopen(argv[1], "r"); // ouverture du premier fichier (argv[1]) en mode lecture

    if (f1 == NULL)
    {
        printf("Error, can't open %s\n", argv[1]);
        exit(1);
    }
    f2 = fopen(argv[2], "w");
    int characters = 0;
    while (1)
    {
        characters = fgetc(f1);
        fputc(characters, f2);
        if (characters == EOF)
            break;
    }

    char buffer[TAILLE_MAX];
    size_t len;
    int i;
    uint8_t result[16];

    while (fgets(buffer, TAILLE_MAX, f1) != NULL)
    {
        len = strlen(buffer);

        for (i = 0; i < 1000000; i++)
        {
            md5((uint8_t *)buffer, len, result);
        }
    }

    for (i = 0; i < 16; i++)
        printf("%2.2x", result[i]);
    printf(" est le code de : %s ", argv[1]);
    printf("\n");

    while (fgets(buffer, TAILLE_MAX, f1) != NULL)
    {
        len = strlen(buffer);

        for (i = 0; i < 1000000; i++)
        {
            md5((uint8_t *)buffer, len, result);
        }
    }

    for (i = 0; i < 16; i++)
        printf("%2.2x", result[i]);
    printf(" est le code de : %s ", argv[2]);
    printf("\n");

    fclose(f1);
    fclose(f2);

    return 0;
}