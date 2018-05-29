#include "HuffmanTableImpl.h"

HuffmanTableImpl::HuffmanTableImpl()
{
}

HuffmanTableImpl::HuffmanTableImpl(std::vector<int> a ,std::vector<uint8_t> b){
    std::queue<uint16_t> q;
    q.push(0);
    q.push(1);
    int w = 0;
    for(int i=0;i<8;i++)
    {
        int remain = 8-i-1;
	for(int j=0;j<a[i];j++)
	{
	    int start = q.front();
            q.pop();
            start = start << remain;
            for(int k=start;k<start +(1 << remain);k++)
            {
                word[k] = b[w];
            }
            w++;
	}
	int l = q.size();
        if(i == 7)
        {
            if(q.empty()) return;
            int start = q.front();
            for(int i = (start>>1); i< 256;i++)
            {
                word[i] = -1;
                length[i] = 0;
            }
        }
	for(int j=0;j<l;j++)
	{
	    int a = q.front();
	    q.pop();
	    q.push(2*a);
	    q.push(2*a+1);
	}
    }
    
    for(int i=9;i<16;i++)
    {
        int remain = 16-i-1;
	for(int j=0;j<a[i];j++)
	{
	    int start = q.front();
            q.pop();
            start = start << remain;
            for(int k=start;k<start +(1 << remain);k++)
            {
                word2[k] = b[w];
            }
            w++;
	}
	int l = q.size();
	for(int j=0;j<l;j++)
	{
	    int a = q.front();
	    q.pop();
	    q.push(2*a);
	    q.push(2*a+1);
	}
    }
    return;
}
std::pair<int,uint8_t> HuffmanTableImpl::query(uint16_t a){
    char ret = (char) 255 & ((word[a>>8] != -1 ? word[a>>8] : word2[a]));
    int len = word[a>>8] != -1 ? length[a>>8]: length2[a];
    return std::pair<int,char>(len,ret);
}


void HuffmanTableImpl::print(){
    for(int i=0;i<255;i++){
        std::cout << (char) (word[i] & 255) << " ";
    }
    std::cout << std::endl;
}

