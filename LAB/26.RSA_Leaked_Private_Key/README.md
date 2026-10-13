Answer to the Question:
Is it safe for Bob to generate a new public/private key pair (e2, d2) using the same modulus n after leaking his old private key d1?
No, it is completely unsafe!
Knowing both e1 and d1 gives the attacker a multiple of φ(n), because e1·d1 − 1 = k·φ(n). Using a standard probabilistic algorithm (writing e1·d1 − 1 = 2^s · t and finding a nontrivial square root of 1 mod n), the attacker can quickly factor n into p and q. Once p and q are known, the attacker knows φ(n) and can immediately compute Bob's new private key d2 = e2^-1 mod φ(n). Bob must generate new primes p and q.
