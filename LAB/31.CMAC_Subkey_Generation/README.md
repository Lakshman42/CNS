Answers to the Questions:
(a) Constants Needed for 64-bit and 128-bit Blocks:
  - 64-bit block size : R_64  = 0x1B (binary 000...00011011, representing irreducible polynomial x^64 + x^4 + x^3 + x + 1).
  - 128-bit block size: R_128 = 0x87 (binary 000...10000111, representing irreducible polynomial x^128 + x^7 + x^2 + x + 1).
(b) How Left Shift and XOR Accomplish the Desired Result:
In the finite field GF(2^b), multiplying an element L by x corresponds to a 1-bit left shift. If the most significant bit (coefficient of x^{b-1}) is 0, shifting left stays within degree < b. If the MSB is 1, shifting left produces an x^b term, which is reduced modulo the irreducible polynomial x^b + R_b by XORing with R_b. Thus K1 = L · x and K2 = L · x^2 in GF(2^b).
