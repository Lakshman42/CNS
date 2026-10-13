Automated Frequency Attack on Monoalphabetic Substitution:
1. Counts the frequency of each letter A–Z in the ciphertext and sorts them from most frequent to least frequent.
2. Maps the sorted ciphertext letters onto the standard English frequency order ("ETAOINSHRDLCUMWFGYPBVKJXQZ").
3. Generates the top N candidate plaintexts by systematically permuting adjacent frequency ranks to account for sample variance in short ciphertexts.
