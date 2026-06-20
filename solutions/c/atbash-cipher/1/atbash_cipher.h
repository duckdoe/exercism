#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int count_output(const char *input);

char *atbash_encode(const char *input);
char *atbash_decode(const char *input);

bool is_number(char c);
bool is_small_letter(char c);
bool is_captial_letter(char c);

#endif
