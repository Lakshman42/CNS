Matrix construction: Keyword letters (duplicates removed) fill the 5×5 grid first, then the remaining alphabet letters follow. I and J share one cell, so J is treated as I.
Digraph preparation: Plaintext is split into letter pairs. A repeated pair like LL gets an X inserted (LXL), and an odd-length message is padded with a trailing X.
Encryption rules for each pair:
Same row: replace each letter with the one to its right (wrapping around).
Same column: replace each letter with the one below it (wrapping around).
Rectangle: replace each letter with the one in its own row but the other letter's column.
Decryption: Uses the same rules in reverse. Left shift for rows, up shift for columns, and the rectangle rule is unchanged. The code does this with shift = 4, which equals −1 mod 5.
