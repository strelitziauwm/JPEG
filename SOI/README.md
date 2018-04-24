# Basics

The JPEG file starts with 0xFFD8 and ends with 0XFFD9, these are called the Start Of Image marker, and the End Of Image marker, or just SOI and EOI. Between these two markers are a sequence of segments, followed by the entropy encoded data. 

Each segment also starts with a marker. Which is in the form 0xFFXX. After the marker, the next two bytes are always the length of this segment. This is convenient for you to skip segments like APPN or COM, which contains non essential data.

Refer to Table B.1 in the spec for segment names, you should be able to read the file until Start Of Scan(SOS), which is the last segment before the entropy encoded data.

```C
uint16_t marker;

```