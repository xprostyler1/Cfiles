#include <tchar.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// askisi 1 petradonakis askisi sxolis
#define file1 "base.dbs"
#define file2 "report1.txt"
FILE *F2;
int fn1;

struct base{
    char name[51];
    char address[61];
    char telephone[31];
    int spoudes;
    int kids;};


void openfiles()
{
    fn1 = open(file1, 0);
    F2 = fopen(file2, "w");
}

    void closefiles() {
        close(fn1);
        fclose(F2);
    }


    void ipalilos() {
        int k1, k2, position1, g1;
        long pos1;
        struct base basi;

        printf("Dose k1 kai k2");
        scanf("%d %d", &k1, &k2);
        while (!eof(fn1) && (k1 <= k2)) {
            pos1 = (long) (k1 - 1) * (sizeof(struct base));
            position1 = lseek(fn1, pos1, 0);
            g1 = read(fn1, &basi, sizeof(struct base));

            if ((basi.spoudes == 3) && (basi.kids == 4)) {
                fprintf(F2, "\n %s %s %d", basi.name, basi.address, basi.kids);
            }
            k1++;
        }

    }

int main(int argc,_TCHAR *argv[])
{
    openfiles();
    closefiles();
    ipalilos();
    return 0;
}test1
