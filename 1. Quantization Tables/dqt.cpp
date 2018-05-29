#include "jpeg.h"
#include <stdlib.h>
#include <assert.h>
#include <endian.h>
#include <stdio.h>
#include <stdint.h>
int read_dqt(JPEG &img){
    uint16_t len; 
    fread(&len, sizeof(uint16_t) , 1, img.m_fp);
    len = be16toh(len);
    len -= 2;
    while(len > 0)
    {
        uint8_t pq, tq;
        fread(&pq,sizeof(uint8_t), 1, img.m_fp);
        tq = pq & 3;
        pq = pq >> 4;
        printf("%d %d\n",pq,tq);
        img.dqt[tq].ti = tq;
        img.dqt[tq].pi = pq;
        if(pq == 0)
        {
            for(int i=0;i < 64;i++)
            {
                fread(&(img.dqt[tq].qk[i]),sizeof(uint8_t), 1, img.m_fp);
            }
            len -= 65;
        }
        else
        {
            for(int i=0;i < 64;i++)
            {
                fread(&(img.dqt[tq].qk[i]),sizeof(uint16_t), 1, img.m_fp);
            }
            len -= 129;
        }
    }
    return 0;
}
