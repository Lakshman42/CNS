
Key as a sequence of alphabets: Each key letter defines a shift (A=0, B=1, ..., Z=25). With the key KEY, the shifts are 10, 4, 24, and they repeat.
Encryption: C = (P + K) mod 26, where K is the key letter used for that position. For example, A with K (shift 10) becomes K, then t with E (shift 4) becomes x.
Decryption: P = (C - K + 26) mod 26. The + 26 keeps the result non-negative in C.
Key position: The counter k advances only on letters, so spaces and punctuation don't consume key characters.
Case: Upper and lower case are preserved, and non-letters pass through unchanged.
Strength: The same plaintext letter can map to different ciphertext letters (the two ts above become x and r), which flattens letter frequencies and defeats simple frequency analysis. It can still be broken by the Kasiski test or index of coincidence once the key length is found, especially with a short or repeating key.
