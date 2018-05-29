#include "jpeg.h"
#include <stdlib.h>
#include <assert.h>
#include <endian.h>
#include <stdio.h>
#include <stdint.h>
int read_sof0(JPEG &img){
    uint16_t len; 
    fread(&len, sizeof(uint16_t) , 1, img.m_fp);
    len = be16toh(len);
    len -= 2;
    while(len > 0)
    {
        uint8_t P;
        uint16_t X,Y;
        uint8_t Nf;
        fread(&P,sizeof(uint8_t),1,img.m_fp);
        fread(&Y,sizeof(uint16_t),1,img.m_fp);
        fread(&X,sizeof(uint16_t),1,img.m_fp);
        fread(&Nf,sizeof(uint8_t),1,img.m_fp);
        Y = be16toh(Y);
        X = be16toh(X);
        printf("Y: %d, X: %d\n",Y,X);
        img.component.resize(Nf);
        for(int i = 0;i< Nf;i++)
        {
            uint8_t C,H,V,Tq;
            fread(&C,sizeof(uint8_t),1,img.m_fp);
            fread(&H,sizeof(uint8_t),1,img.m_fp);
            fread(&Tq,sizeof(uint8_t),1,img.m_fp);
            V = H & 15;
            H = H >> 4;
            img.component[i].Ci = C;
            img.component[i].H = H;
            img.component[i].V = V;
            img.component[i].Tq = Tq;
            printf("component: %d, H: %d, V: %d, Tq: %d\n",C,H,V,Tq);
        }
        break;
    }
    return 0;
}
