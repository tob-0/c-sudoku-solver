#ifndef HASH_H
#define HASH_H

/// @brief djb2 hashing function from Dan Bernstein.
/// @param str String to compute the hash of.
/// @return The computed hash of str.
unsigned long hash_djb2(unsigned char *str);

#endif