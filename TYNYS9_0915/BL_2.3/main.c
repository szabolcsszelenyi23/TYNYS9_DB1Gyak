#include <stdio.h>
#include <stdlib.h>

void pelda_2();

int main()
{
    //printf("Hello world!\n");
    pelda_2();
    return 0;
}

void pelda_2(char *fnev1, char *fnev2)
{
    FILE *fp1, *fp2;
    char ch;
    int pos;
    if ((fp1 = fopen(fnev1, "r")) == NULL)
    {
        printf("\nNem lehet megnyitni a fajlt.");
        return;
    }
    else
    {
        printf("\nFajl megnyitva masolasra…\n ");
    }
    fp2 = fopen(fnev2, "w");
    fseek(fp1, 0L, SEEK_END);
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);
    while (pos--)
    {
        ch = fgetc(fp1);
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}
