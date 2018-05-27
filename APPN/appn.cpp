#include "appn.h"
#include "jpeg.h"
#include <stdlib.h>
#include <assert.h>
#include <endian.h>
#include <stdio.h>
#include <stdint.h>
int read_appn(JPEG &img){
    uint16_t len; 
    fread(&len, sizeof(uint16_t) , 1, img.m_fp);
    len = be16toh(len) - 2;
    fseek(img.m_fp,len, SEEK_CUR);
    return 0;
}
