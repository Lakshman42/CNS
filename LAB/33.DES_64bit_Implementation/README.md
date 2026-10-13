Data Encryption Standard (DES) Implementation:
- Block Size: 64 bits (split into 32-bit L and R halves).
- Key Size: 56 effective bits (from a 64-bit key with 8 parity bits), generating sixteen 48-bit round subkeys K1..K16.
- Structure: 16-round Feistel network where L_i = R_{i-1} and R_i = L_{i-1} ⊕ F(R_{i-1}, K_i), followed by a 32-bit swap.
- Decryption: Uses the exact same algorithm as encryption with the 16 subkeys applied in reverse order (K16 down to K1).
