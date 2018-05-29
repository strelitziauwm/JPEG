#include "jpeg.h"
#include "HuffmanTableImpl.h"
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
        uint8_t Tc,Th;
        fread(&Tc,sizeof(uint8_t), 1, img.m_fp);
        Th = Tc & 15;
        Tc = Tc >> 4;
        printf("Tc: %d, Th: %d\n",Tc,Th);
        uint8_t L[16];
        fread(L, sizeof(uint8_t) , 16, img.m_fp);
        len -= 17;
        int tot = 0;
        for(int i=0;i<16;i++)
        {
            tot += L[i];
        }
        std::vector<uint8_t> words;
        words.resize(tot);
        std::vector<int> a(L,L+16);
        fread(&words[0],sizeof(uint8_t),tot,img.m_fp);
        len -= tot;
        HuffmanTableImpl h(a,words);
        img.huffman[Th][Tc] = h;
    }
    return 0;
}
