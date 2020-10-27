#include <iostream>
#include <assert.h>

// Read nth bit of an 8-bit mask
bool readBit_8(uint8_t x, int idx) {
    assert(idx < 9);
    return (bool) ( x & (1 << idx) );
}

// nth bit write
void writeBit_8(uint8_t& x, int n, bool v) {
    if (v)
        x |= (0x01 << n);
    else
        x &= ~(0x01 << n); // One's compliment of the set mask
}

// Invert an 8-bit mask
void invert(uint8_t& x) {
    x = ~x;
}

// Loop over n bits of an 8-bit mask with a closure to apply on each bit given bit value and index respc.
template <typename Lambda>
void forEachnBit_8(uint8_t x, int n, Lambda fn) {
    assert(n < 9);
    uint8_t chooseBit = 0x01;
    for (int i = 0 ; i < n ; ++i) {
        fn(bool(x & chooseBit), i);
    	chooseBit <<= 1;
    }
}
