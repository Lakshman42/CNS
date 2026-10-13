S-DES in CBC Mode Verification:
- 10-bit Key: 01111 11101 -> generates subkeys K1 and K2 via P10, left shifts, and P8.
- Initialization Vector (IV): 1010 1010.
- Plaintext blocks: P1 = 0000 0001, P2 = 0010 0011.
- CBC Encryption:
  C1 = S-DES_Enc(P1 ⊕ IV) = 1111 0100
  C2 = S-DES_Enc(P2 ⊕ C1) = 0000 1011
- CBC Decryption recovers 0000 0001 0010 0011.
