#include "jpeg.h"
#include <stdlib.h>
#include <assert.h>
#include <endian.h>
#include <stdio.h>
#include <stdint.h>
int read_huffman(JPEG &img){
    uint16_t len; 
    fread(&len, sizeof(uint16_t) , 1, img.m_fp);
    len = be16toh(len);
    len -= 2;
    while(len > 0)
    {
    }
    return 0;
}
