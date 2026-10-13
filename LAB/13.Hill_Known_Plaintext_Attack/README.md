Known-Plaintext Attack: Given two linearly independent plaintext digraphs P (2×2 matrix with gcd(det(P), 26) = 1) and their corresponding ciphertext digraphs C, the attacker solves:
  C = P · K (mod 26)  ==>  K = P^-1 · C (mod 26)
Chosen-Plaintext Attack: Even simpler—the attacker chooses plaintext digraphs "BA" = (1, 0) and "AB" = (0, 1), forming the identity matrix P = I. Then the resulting ciphertext C is directly equal to the secret key matrix K without any matrix inversion.
