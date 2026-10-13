Answers to the Questions:
(a) Are any blocks beyond P2 affected by a transmission error in C1?
No. Since P_i = D(K, C_i) ⊕ C_{i-1}, block P3 only depends on C2 and C3, neither of which was corrupted. Thus CBC self-synchronizes after two blocks.
(b) Source Bit Error in P1:
During encryption, C1 = E(K, P1 ⊕ IV) changes completely, which changes C2 = E(K, P2 ⊕ C1), and so on—propagating through ALL subsequent ciphertext blocks. However, at the receiver, the valid ciphertexts decrypt cleanly back to the exact inputs, so only P1 contains the original 1-bit source error.
