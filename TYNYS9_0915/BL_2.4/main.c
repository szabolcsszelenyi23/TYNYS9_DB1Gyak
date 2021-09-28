#include <stdio.h>
#include <stdlib.h>

struct Auto {
    char rendszam[6];
    char tipus[20];
    double ar;
};

void pelda_3_felvisz();
void pelda_3_olvas();

int main()
{
    printf("Hello world!\n");
    pelda_3_felvisz();
    pelda_3_olvas();
    return 0;
}

void pelda_3_felvisz(){
    struct Auto autok[3];
    FILE *fdata;
    int i = 0;
    for (i=0; i< 3; i++) {
        printf("rsz:");
        scanf("%s",&autok[i].rendszam);
        printf("tipus:");
        scanf("%s",&autok[i].tipus);
        printf("ar:");
        scanf("%d",&autok[i].ar);
    }
    fdata = fopen("Autok.dat", "wb");
    for (i=0; i< 3; i++) {
        fwrite(&(autok[i]), sizeof(struct Auto),1, fdata);
    }
    fclose(fdata);
}

void pelda_3_olvas(int poz){
    FILE *fdata;
    fdata = fopen("Autok.dat", "rb");
    struct Auto aurek;
    if (fdata == NULL) {
        printf ("file hiba\n");
        return;
    }
    fseek(fdata, (poz-1)* sizeof(struct Auto),0 );
    fread(&aurek, sizeof(struct Auto),1, fdata);
    printf ("rsz: %s\n", aurek.rendszam);
    printf ("tip: %s\n", aurek.tipus);
    printf ("ar: %d\n", aurek.ar);
    fclose(fdata);
}
