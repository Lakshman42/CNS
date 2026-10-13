Answers to the Questions:
1. What happens if Alice and Bob send x_A^a mod q and x_B^a mod q instead of a^x mod q?
To agree on a shared key without commuting exponents, they cannot simply raise the other's message to their secret x. If they combine their messages by multiplication: K = (x_A^a · x_B^a) mod q = (x_A · x_B)^a mod q, they would still need each other's raw secrets.
2. Can Eve break the system without finding the secret numbers?
Yes! If they use K = Y_A · Y_B mod q = (x_A^a · x_B^a) mod q, Eve sees both Y_A and Y_B on the channel and immediately computes K = (Y_A · Y_B) mod q without finding x_A or x_B.
3. Can Eve find the secret numbers?
Yes! Because a and q are public, if gcd(a, q − 1) = 1, Eve uses the Extended Euclidean Algorithm to compute d = a^-1 mod (q − 1) and recovers x_A = (x_A^a)^d mod q in polynomial time.
