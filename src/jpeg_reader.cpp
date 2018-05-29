#include <endian.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "jpeg.h"
#include "SOI/soi.h"
#include "APPN/appn.h"
#include "Quantization Tables/dqt.h"
#include "Baseline DCT/baseline_dct.h"
#include "Huffman Tables/huffman.h"

int main(int argv,char **argc)
{
    JPEG img = {argc[1]};
    read_soi(img);

    while(1)
    {
        uint16_t marker;
        fread(&marker, sizeof(uint16_t), 1, img.m_fp);
        marker = be16toh(marker);
        printf("%02X\n",marker);
        if(marker >= 0xffe0 && marker <= 0xffef)
        {
            read_appn(img);
        }
        else if(marker == 0xffdb)
        {
            read_dqt(img);
        }
        else if(marker == 0xffc0)
        {
            printf("Baseline DCT\n");
            read_sof0(img);
        }
        else if(marker == 0xffc4)
        {
            printf("Huffman Table\n");
            read_huffman(img);
        }
        else
        {
            break;
        }

    }

    return 0;
}
