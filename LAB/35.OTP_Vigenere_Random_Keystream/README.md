One-Time Pad Version of Vigenère Cipher (Program 35):
- Uses a non-repeating integer keystream k_i ∈ {0..25} of length equal to the number of letters in the plaintext.
- Encryption: C_i = (P_i + k_i) mod 26.
- Decryption: P_i = (C_i − k_i + 26) mod 26.
