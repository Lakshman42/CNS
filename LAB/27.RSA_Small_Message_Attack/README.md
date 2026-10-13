Answer to the Question:
Is encrypting each alphabetic character (0..25) separately using RSA secure?
No, it is completely insecure regardless of how large e and n are!
Most Efficient Attack (Forward-Search / Dictionary Attack):
Because there are only 26 possible plaintext values (0 through 25) and the public key (e, n) is known to everyone, an attacker simply encrypts all 26 values C_m = m^e mod n for m ∈ {0..25} and stores them in a 26-entry lookup table. Every intercepted ciphertext block is then decrypted in O(1) time by table lookup. Furthermore, it reduces RSA to a simple monoalphabetic substitution cipher vulnerable to frequency analysis.
