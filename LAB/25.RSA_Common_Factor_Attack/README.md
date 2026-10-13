Answer to the Question:
Does knowing that a plaintext block M shares a common factor with n = pq help us?
Yes—it completely breaks the RSA key!
Since n = p·q is the product of two primes, any plaintext block M (with 1 < M < n) that shares a common factor with n must be a multiple of either p or q. Even more importantly, its ciphertext C = M^e mod n also shares that exact same prime factor with n.
By computing p = gcd(C, n) using the Euclidean algorithm in O(log n) time, we immediately find p, compute q = n / p, calculate φ(n) = (p − 1)(q − 1), and recover the private key d = e^-1 mod φ(n) to decrypt all blocks.
