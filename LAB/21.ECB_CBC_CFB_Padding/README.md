Motivation for Always Adding a Padding Block:
If padding were omitted when the plaintext is already a multiple of the block size, the receiver could not tell whether a trailing sequence of `100...0` bits in the final decrypted block is genuine plaintext data or padding that should be stripped.
By always appending padding (adding an extra dummy block `1000...0` when the message is already block-aligned), the receiver can unconditionally scan backward from the end of the decrypted message and remove the last `1` bit and all following `0` bits without any ambiguity.
