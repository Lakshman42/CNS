DES Reverse Key Schedule for Decryption:
During encryption, the 28-bit halves (C0, D0) undergo left circular shifts of [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1] totaling 28 bits, meaning C16 = C0 and D16 = D0.
Therefore, decryption can generate K16 down to K1 directly from (C0, D0) using right circular shifts with the schedule:
  [0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]
