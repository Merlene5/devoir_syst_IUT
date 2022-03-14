#include "md5.c"

int main(int argc, char **argv)
{
    char buffer[TAILLE_MAX];
    size_t len;
    int i;
    uint8_t result[16];

    if (argc != 2)
    {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }


    FILE *fichier = fopen(argv[1], "r");
    if (fichier == NULL)
    {
        fprintf(stderr, "Fichier %s n'existe pas. \n", argv[1]);
        return 2;
    }

    // on récupère un mot à la fois ligne par ligne
    while (fgets(buffer, TAILLE_MAX, fichier) != NULL)
    {
        len = strlen(buffer);

        for (i = 0; i < 1000000; i++)
        {
            md5((uint8_t *)buffer, len, result);
        }
    }

    // display result
    for (i = 0; i < 16; i++)
        printf("%2.2x", result[i]);
    printf(" est le code de : %s ", argv[1]);

    puts("");
    fclose(fichier);

    return 0;
}
