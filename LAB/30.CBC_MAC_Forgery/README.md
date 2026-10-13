CBC-MAC Two-Block Forgery Proof:
1. For a 1-block message X, the CBC-MAC (with IV = 0) is T = E(K, X).
2. The adversary (who knows X and T, but not K) constructs the 2-block message M' = X || (X ⊕ T).
3. When the verifier computes CBC-MAC on M':
   - After block 1 (X): C1 = E(K, X) = T.
   - For block 2 (X ⊕ T): C2 = E(K, C1 ⊕ (X ⊕ T)) = E(K, T ⊕ X ⊕ T) = E(K, X) = T!
4. Thus T is a valid tag for X || (X ⊕ T), proving raw CBC-MAC is insecure for variable-length messages (which is why CMAC XORs a subkey into the final block).
