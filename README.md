# JPEG

This is a walkthough for writing a JPEG decoder. Assuming you know the basics for encoding and decoding. This will focus on the bit packing for the jpeg file, by reading the spec.

## Requirements

- A JPEG compression specification. [here](https://www.w3.org/Graphics/JPEG/itu-t81.pdf) or a [mirror](/third-party/itu-t81.pdf)

## Contents

1. Decoding a segment, SOI, EOI
2. Huffman tables
3. Quantization tables
4. Frame Header
5. Start of Scan
