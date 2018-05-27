#include <endian.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argv,char **argc)
{
    uint16_t marker;

    FILE *fp = fopen(argc[1],"r");
    while(1)
    {
        fread(&marker, sizeof(uint16_t), 1, fp);
        marker = be16toh(marker);
        printf("%02X\n",marker);
        if(marker >> 8 == 0xff)
        {
            if(marker == 0xffd8 || marker == 0xffd9)
                continue;
            uint16_t Lf;
            fread(&Lf, sizeof(uint16_t), 1, fp);
            Lf = be16toh(Lf);
            Lf -= 2;
            fseek(fp, Lf, SEEK_CUR);
        }
        else
        {
            break;
        }
    }
    return 0;
}
