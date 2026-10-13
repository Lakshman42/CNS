SHA-3 Capacity Lane Propagation Analysis:
- The 1600-bit SHA-3 state consists of 5 × 5 = 25 lanes of 64 bits each.
- A block size (rate r) of 1024 bits occupies 1024 / 64 = 16 lanes (rows y = 0, 1, 2 and lane (0, 3)).
- The capacity c = 1600 − 1024 = 576 bits occupies the remaining 9 lanes (initially all zeros).
- Because every column x ∈ {0..4} already contains at least 3 nonzero rate lanes in rows y = 0, 1, 2, the very first operation of Round 1—the Theta (θ) column-parity mixing step—XORs nonzero column parity bits D[x] into all 5 rows of every column, making all 9 capacity lanes nonzero after a single θ step (1 round).
