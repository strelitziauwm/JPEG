#include "jpeg.h"
#include <stdio.h>

JPEG::JPEG()
{
}

JPEG::JPEG(char *path)
{
    m_fp = fopen(path,"r");
    return;
}
