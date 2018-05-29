#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include "jpeg.h"


class HuffmanTableImpl : public HuffmanTable
{
    private:
	int word[255];
	int length[255];
        int word2[65525];
        int length2[65525];
    public:
        HuffmanTableImpl();
        HuffmanTableImpl(std::vector<int> a ,std::vector<uint8_t> b);
        std::pair<int,uint8_t> query(uint16_t a);
        void print();
};
