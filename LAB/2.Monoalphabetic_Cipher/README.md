Key: The key is the ciphertext alphabet. Position i holds the letter that plaintext letter 'A' + i maps to (A→Q, B→W, C→E, ...).
Validation: validKey ensures the key has 26 letters with no repeats. This guarantees the mapping is one-to-one, so decryption is always possible.
Encryption: Each letter is replaced by key[c - 'A']. Case is preserved, and non-letters pass through unchanged.
Decryption: An inverse table is built, where inv[key[i]] = 'A' + i, and the same substitution is applied in reverse.
Key space: There are 26! (about 4×10²⁶) possible keys, but the cipher is still weak because letter-frequency analysis breaks it easily.
