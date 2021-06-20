#include <stdio.h>
#include <stdint.h>

// GNU poke -> dump

typedef struct {
    char name[10];
    uint32_t lst[3]; //32bits -> 4 bytes
    uint8_t flag;
} SEG;

int main() {
    SEG slb = {
            .name = "abcdefghqw",
            .lst  = {12345678, 6789, 1012},
            .flag = 2
    };

    FILE *f;
    f = fopen("./nice.dat", "w+");
    fwrite(&slb, sizeof(SEG), 1, f);
    fwrite(&slb, sizeof(SEG), 1, f);


/*
Result binary
76543210  0011 2233 4455 6677 8899 aabb ccdd eeff  0123456789ABCDEF
00000000: 6162 6364 6566 6768 7177 e55d 4e61 bc00  abcdefghqw.]Na..
                   char name[10];^ [-------] [---  -> Little Endian u16
00000010: 851a 0000 f403 0000 0260 e55d            .........`.]
          ---] [-------]
*/

//<http://www.catb.org/esr/structure-packing/>
    fclose(f);

    f = fopen("./nice.dat", "r");
    SEG newslb = {0};
    fread(&newslb, sizeof(SEG), 1, f);
    fclose(f);

    printf("%s\n", newslb.name);
    printf("%d %d %d\n", newslb.lst[0], newslb.lst[1], newslb.lst[2]);
    printf("%d\n", newslb.flag);

};