Answers to the Questions

a. Are there any limitations on the value of b?

No. The shift b only translates the result: E(p) = (a·p + b) mod 26. Adding a constant mod 26 is always one-to-one, because if a·p + b ≡ a·q + b (mod 26), then b cancels and leaves a·p ≡ a·q. So whether the cipher is one-to-one depends only on a. Any b from 0 to 25 works (other integers reduce mod 26). The value b = 0 is allowed, but then the cipher is purely multiplicative with no shift, so it is somewhat weaker. Also, a = 1 with b = 0 is the identity and encrypts nothing.

b. Which values of a are not allowed?

The cipher is one-to-one if and only if gcd(a, 26) = 1. Since 26 = 2 × 13, a must not share a factor with 2 or 13.
