Finding the RSA Private Key for (e = 31, n = 3599):
1. Factorization: Testing primes up to √3599 ≈ 59.99 finds p = 59 and q = 61 (59 × 61 = 3599).
2. Totient: φ(n) = (59 − 1)(61 − 1) = 58 × 60 = 3480.
3. Extended Euclidean Algorithm: Solving 31·d ≡ 1 (mod 3480) gives d = −449 ≡ 3031 (mod 3480), since 31 × 3031 = 93961 = 27 × 3480 + 1.
Private Key: d = 3031.
