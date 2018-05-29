#pragma once
#include <stdio.h>
#include <stdint.h>
#include <vector>
class DQT
{
    public:
        uint8_t pi,ti;
        uint16_t qk[64];
};
class Component
{
    public:
        uint8_t Ci,H,V,Tq;
};
class Scan
{
    public:
        std::vector<Component> component;
}; 
class HuffmanTable
{
    public:
        std::pair<int,uint8_t> query(uint16_t a);
};
class JPEG
{
    public:
        FILE *m_fp;
        DQT dqt[4];
        HuffmanTable huffman[2][2];
        std::vector<Scan> scan;
        std::vector<Component> component;
    public:
        JPEG();
        JPEG(char *);
};
