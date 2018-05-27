#include "soi.h"
#include "jpeg.h"
#include <stdlib.h>
#include <assert.h>
#include <endian.h>
#include <stdio.h>
#include <stdint.h>
int read_soi(JPEG &img){
    uint16_t marker; 
    fread(&marker, sizeof(uint16_t) , 1, img.m_fp);
    marker = be16toh(marker);
    if(marker != 0xffd8)
    {
        fprintf(stderr,"SOI no match\n");
        return -1;
    }
    return 0;
}
