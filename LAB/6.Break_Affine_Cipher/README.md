Frequency Assumption: In English text, the two most common letters are E (index 4) and T (index 19). Mapping E -> B (1) and T -> U (20) gives two linear congruences mod 26.
Solving for Key (a, b):
  1. 4a + b ≡ 1 (mod 26)
  2. 19a + b ≡ 20 (mod 26)
Subtracting equation (1) from (2) gives 15a ≡ 19 (mod 26). Since 15^-1 mod 26 = 7, we get a = (19 × 7) mod 26 = 133 mod 26 = 3.
Substituting a = 3 into (1): 4(3) + b ≡ 1 (mod 26) => 12 + b ≡ 1 (mod 26) => b = 15.
Decryption Formula: With a = 3 (so a^-1 = 9) and b = 15, each letter is recovered using P = 9 × (C − 15) mod 26.
