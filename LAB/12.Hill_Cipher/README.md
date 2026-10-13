(a) Encryption Calculation:
Each letter pair (p1, p2) is multiplied by K = [[9, 4], [5, 7]] mod 26.
For example, "ME" = (12, 4):
  c1 = (9×12 + 4×4) mod 26 = 124 mod 26 = 20 ('U')
  c2 = (5×12 + 7×4) mod 26 = 88 mod 26 = 10 ('K')
Full Ciphertext: UKIXUKYDROMEIWSZXWIOKUNUKHXHROAJROANQYEBTLKJEGAD

(b) Decryption Calculation:
det(K) = 9×7 − 4×5 = 43 ≡ 17 (mod 26). Since 17 × 23 = 391 = 15×26 + 1, det(K)^-1 = 23.
K^-1 = 23 × [[7, -4], [-5, 9]] mod 26 = [[5, 12], [15, 25]].
Multiplying each ciphertext pair by K^-1 mod 26 recovers "MEETMEATTHEUSUALPLACEATTENRATHERTHANEIGHTOCLOCKX".
