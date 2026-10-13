# CSA51 — Cryptography and Network Security Laboratory (List of 40 Programs)

This directory contains the C/C++ implementations, theoretical explanations (`README.md`), and execution output screenshots (`Exp_<N>_Output.png`) for all **40 programs** specified in the University Practical Examination List of Programs.

| Exp # | Folder | Source File | Topic / Description |
| :---: | :--- | :--- | :--- |
| 1 | `1.Ceaser_Cipher` | `Exp1_ceaser_cipher.cpp` | Caesar Cipher (shift $k \in [1, 25]$) |
| 2 | `2.Monoalphabetic_Cipher` | `Monoalphabetic_Cipher.cpp` | Monoalphabetic Substitution Cipher |
| 3 | `3.Playfair_Cipher` | `Playfair_Cipher.cpp` | Playfair $5 \times 5$ Matrix Cipher |
| 4 | `4.Vigenere_Cipher` | `Vigenèr_Cipher.cpp` | Polyalphabetic (Vigenère) Substitution Cipher |
| 5 | `5.Affine_Ceaser_Cipher` | `affine_cipher.cpp` | Affine Caesar Cipher $C = (ap + b) \bmod 26$ |
| 6 | `6.Break_Affine_Cipher` | `Break_Affine_Cipher.cpp` | Cryptanalysis of Affine Cipher ('B' and 'U' most frequent) |
| 7 | `7.Simple_Substitution_Decrypt` | `Simple_Substitution_Decrypt.cpp` | Decryption of Simple Substitution Ciphertext (`53‡‡†305...`) |
| 8 | `8.Keyword_Monoalphabetic_Cipher` | `Keyword_Monoalphabetic_Cipher.cpp` | Keyword-Based Monoalphabetic Cipher (`CIPHER`) |
| 9 | `9.Playfair_PT109_Decrypt` | `Playfair_PT109_Decrypt.cpp` | Playfair Decryption of JFK's PT-109 Wireless Message |
| 10 | `10.Playfair_Fixed_Matrix` | `Playfair_Fixed_Matrix.cpp` | Playfair Encryption with Predefined $5 \times 5$ Matrix |
| 11 | `11.Playfair_Keyspace` | `Playfair_Keyspace.cpp` | Playfair Total Key Space ($2^{84}$) vs. Unique Keys ($2^{79}$) |
| 12 | `12.Hill_Cipher` | `Hill_Cipher.cpp` | $2 \times 2$ Hill Cipher Encryption & Decryption ($K = \begin{pmatrix}9&4\\5&7\end{pmatrix}$) |
| 13 | `13.Hill_Known_Plaintext_Attack` | `Hill_Known_Plaintext_Attack.cpp` | Known-Plaintext Attack on Hill Cipher |
| 14 | `14.One_Time_Pad_Vigenere` | `One_Time_Pad_Vigenere.cpp` | One-Time Pad Vigenère (`send more money` $\rightarrow$ `cash not needed`) |
| 15 | `15.Additive_Cipher_Frequency_Attack` | `Additive_Cipher_Frequency_Attack.cpp` | Automated Letter Frequency Attack on Additive Cipher |
| 16 | `16.Monoalphabetic_Frequency_Attack` | `Monoalphabetic_Frequency_Attack.cpp` | Automated Letter Frequency Attack on Monoalphabetic Cipher |
| 17 | `17.DES_Decryption_Key_Schedule` | `DES_Decryption_Key_Schedule.cpp` | DES Decryption Reverse Subkey Generation ($K_{16} \dots K_1$) |
| 18 | `18.DES_Disjoint_Subkey_Subsets` | `DES_Disjoint_Subkey_Subsets.cpp` | DES Disjoint 28-Bit Subkey Subset Verification (PC-2) |
| 19 | `19.3DES_CBC_Mode` | `3DES_CBC_Mode.cpp` | 3DES Encryption & Decryption in CBC Mode |
| 20 | `20.ECB_CBC_Error_Propagation` | `ECB_CBC_Error_Propagation.cpp` | Error Propagation Analysis in ECB vs. CBC Modes |
| 21 | `21.ECB_CBC_CFB_Padding` | `ECB_CBC_CFB_Padding.cpp` | ECB, CBC, and CFB Modes with `10*` Bit Padding |
| 22 | `22.SDES_CBC_Mode` | `SDES_CBC_Mode.cpp` | Simplified DES (S-DES) in CBC Mode |
| 23 | `23.SDES_CTR_Mode` | `SDES_CTR_Mode.cpp` | Simplified DES (S-DES) in Counter (CTR) Mode |
| 24 | `24.RSA_Private_Key_Extended_Euclid` | `RSA_Private_Key_Extended_Euclid.cpp` | RSA Private Key Recovery ($e = 31, n = 3599$) via Extended Euclid |
| 25 | `25.RSA_Common_Factor_Attack` | `RSA_Common_Factor_Attack.cpp` | Factorization of RSA Modulus via Common Factor with Plaintext |
| 26 | `26.RSA_Leaked_Private_Key` | `RSA_Leaked_Private_Key.cpp` | RSA Leaked Private Key & Modulus Reuse Attack |
| 27 | `27.RSA_Small_Message_Attack` | `RSA_Small_Message_Attack.cpp` | Forward-Search Attack on Character-by-Character RSA ($0..25$) |
| 28 | `28.Diffie_Hellman_Key_Exchange` | `Diffie_Hellman_Key_Exchange.cpp` | Diffie-Hellman Key Exchange vs. Flawed $x^a \bmod q$ Variant |
| 29 | `29.SHA3_Keccak_Capacity_Lanes` | `SHA3_Keccak_Capacity_Lanes.cpp` | SHA-3 (Keccak) 1024-Bit Block Capacity Lane Propagation |
| 30 | `30.CBC_MAC_Forgery` | `CBC_MAC_Forgery.cpp` | CBC-MAC Two-Block Existential Forgery ($X \parallel (X \oplus T)$) |
| 31 | `31.CMAC_Subkey_Generation` | `CMAC_Subkey_Generation.cpp` | CMAC Subkey Generation ($K_1, K_2$) for 64-Bit and 128-Bit Blocks |
| 32 | `32.DSA_vs_RSA_Signatures` | `DSA_vs_RSA_Signatures.cpp` | Randomized DSA vs. Deterministic RSA Digital Signatures |
| 33 | `33.DES_64bit_Implementation` | `DES_64bit_Implementation.cpp` | 64-Bit Data Encryption Standard (DES) Implementation |
| 34 | `34.Block_Modes_Padding_Motivation` | `Block_Modes_Padding_Motivation.cpp` | Unambiguous Unpadding Motivation for `10*` Padding |
| 35 | `35.OTP_Vigenere_Random_Keystream` | `OTP_Vigenere_Random_Keystream.cpp` | One-Time Pad Vigenère Stream Cipher (`3, 19, 5, ...`) |
| 36 | `36.Affine_Caesar_One_To_One` | `Affine_Caesar_One_To_One.cpp` | Affine Caesar One-to-One Bijection & Coprime Verification |
| 37 | `37.Monoalphabetic_Attack_Top10` | `Monoalphabetic_Attack_Top10.cpp` | Top-10 Candidate Attack on Monoalphabetic Cipher |
| 38 | `38.Hill_Chosen_Plaintext_Attack` | `Hill_Chosen_Plaintext_Attack.cpp` | Chosen-Plaintext Attack on Hill Cipher ($P = I$) |
| 39 | `39.Additive_Cipher_Attack_Top10` | `Additive_Cipher_Attack_Top10.cpp` | Top-10 Candidate Frequency Attack on Additive Cipher |
| 40 | `40.Monoalphabetic_Cipher_Attack_Top10` | `Monoalphabetic_Cipher_Attack_Top10.cpp` | Top-10 Ranked Frequency Attack on Monoalphabetic Cipher |
