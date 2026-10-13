Keyword Alphabet Construction: Unique letters of the keyword (e.g., CIPHER) are written first, followed by the remaining unused letters of A-Z in normal alphabetical order:
  plain : a b c d e f g h i j k l m n o p q r s t u v w x y z
  cipher: C I P H E R A B D F G J K L M N O Q S T U V W X Y Z
Advantage: Sender and receiver only need to remember a single keyword instead of memorizing a random 26-letter permutation.
Weakness: Because letters after the last keyword letter often map to themselves (U->U, V->V, W->W, X->X, Y->Y, Z->Z), it leaks even more structure than a random monoalphabetic key.
