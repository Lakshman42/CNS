S-DES in Counter (CTR) Mode:
- Counter starts at 0000 0000 and increments by 1 for each block (0, 1, 2).
- Keystream block O_i = S-DES_Enc(Counter_i, K), and C_i = P_i ⊕ O_i.
- With key 01111 11101 and plaintext 0000 0001 0000 0010 0000 0100, the output ciphertext is 0011 1000 0100 1111 0011 0010.
- Decryption XORs the identical keystream with C_i to recover the plaintext.
