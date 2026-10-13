Disjoint Subkey Subsets in DES:
1. PC-1 splits the 56 non-parity key bits into two disjoint 28-bit registers: C0 (28 bits) and D0 (28 bits).
2. In every round, C_i and D_i rotate independently without mixing bits between C and D.
3. PC-2 takes 24 bits exclusively from C_i (indices 1..28) to form the first 24 bits of K_i (which feed S-boxes S1..S4), and 24 bits exclusively from D_i (indices 29..56) to form the second 24 bits of K_i (which feed S-boxes S5..S8).
