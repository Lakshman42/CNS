Hill Cipher Chosen-Plaintext Attack (Program 38):
By choosing plaintext blocks that form the n × n identity matrix I (for 2 × 2: "BA" = [1, 0] and "AB" = [0, 1]), the encryption equation C = P · K mod 26 simplifies to C = I · K = K. The resulting ciphertext blocks directly reveal the entire secret key matrix K without even needing matrix inversion.
