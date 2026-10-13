Automated Frequency Attack on Additive Cipher:
1. All 26 possible shift keys (k = 0..25) are tested automatically.
2. Each decrypted candidate is scored by summing standard English unigram frequencies (E=12.70%, T=9.06%, A=8.17%, O=7.51%, etc.) for every decrypted character.
3. Candidates are sorted in descending order of likelihood score and the user-specified top N (e.g., top 10) plaintexts are displayed.
