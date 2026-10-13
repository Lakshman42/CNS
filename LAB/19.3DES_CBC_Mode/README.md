3DES in CBC Mode:
Each 64-bit block is XORed with the previous ciphertext block (or IV for C1) and encrypted using 3DES EDE: C_i = E_K3(D_K2(E_K1(P_i ⊕ C_{i-1}))).
Answers to Questions:
(a) For Security: Choose 3-key 3DES (K1 ≠ K2 ≠ K3, 168-bit key) or AES-256 in CBC mode for maximum resistance against meet-in-the-middle and brute-force attacks.
(b) For Performance: Choose AES-128 in CBC mode (or single-pass hardware-accelerated cipher) since 3DES requires 3× as many Feistel rounds (48 rounds per block) as single DES.
