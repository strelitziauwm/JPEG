# JPEG

This is a helper document for those who want to write a JPEG decoder just by reading the JPEG spec. When I wrote my decoder, I had the knowledge of how a JPEG file was encoded: YCbCr, DCT, Quantization, Huffman coding, and other features like interlacing. But did not know how they were packed into bits.

This document consists of notes of how these bits are packed, and where to find the reference in the spec. If you are writing some decoder from scratch, and stuck somewhere, this doc will help you.

Most of the stuff you need are in ANNEX B, then ANNEX A. FYI. If you just need a starting point.

## Requirements

- A JPEG compression specification. [here](https://www.w3.org/Graphics/JPEG/itu-t81.pdf) or a [mirror](/third-party/itu-t81.pdf)

## Contents

1. Decoding a segment, SOI, EOI
2. Quantization tables
3. Huffman tables
4. Frame Header
5. Start of Scan
