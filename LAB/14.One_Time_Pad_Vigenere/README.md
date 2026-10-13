(a) Encryption of "send more money" (13 letters) with key stream [9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9]:
  C_i = (P_i + K_i) mod 26  -->  "beok jdms xzpmh" (BEOKJDMSXZPMH).
(b) Finding Alternate Key for "cash not needed" (13 letters):
  Since P'_i = (C_i − K'_i) mod 26, we compute K'_i = (C_i − P'_i) mod 26:
  Key stream = [25, 4, 16, 19, 9, 9, 25, 5, 21, 21, 9, 8, 4] (i.e., Z E Q T J J Z F V V J I E).
Perfect Secrecy Demonstration: Because any 13-letter plaintext can be produced from the same ciphertext by choosing the corresponding key stream, an attacker with infinite computing power learns nothing without the key.
