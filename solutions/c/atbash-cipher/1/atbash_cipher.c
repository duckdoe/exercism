#include "atbash_cipher.h"

bool is_small_letter(char c)
{
    return c >= 'a' && c <= 'z';
}

bool is_captial_letter(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool is_number(char c)
{
    return c >= '0' && c <= '9';
}

int count_output(const char *input)
{
    int len = strlen(input);
    int out = 0;

    for (int i = 0; i < len; i++)
    {
        if (is_small_letter(input[i]) || is_captial_letter(input[i]) || is_number(input[i]))
            out++;
    }

    return out;
}

char *atbash_encode(const char *input)
{
    int encode_length = count_output(input);
    int spaces = (encode_length - 1) / 5;
    int len = strlen(input);
    int out = 0;
    int group = 0;

    encode_length += spaces;

    char *e = malloc(encode_length + 1);

    for (int i = 0; i < len; i++)
    {
        if (group == 5)
        {
            e[out] = ' ';
            out++;
            group = 0;
        }
        if (is_small_letter(input[i]))
        {
            int diff = (input[i] - 'a');
            char l = 'z' - diff;

            e[out] = l;
            out++;
            group++;
        }
        else if (input[i] == ' ')
        {
            continue;
        }
        else if (is_captial_letter(input[i]))
        {
            char diff = (input[i] - 'A');
            char l = 'z' - diff;

            e[out] = l;
            out++;
            group++;
        }
        else if (is_number(input[i]))
        {
            e[out] = input[i];
            out++;
            group++;
        }
        else
        {
            continue;
        }
    }

    e[encode_length] = '\0';

    return e;
}

char *atbash_decode(const char *input)
{
    int len = strlen(input);

    char *e = malloc(len + 1);
    int out = 0;

    for (int i = 0; i < len; i++)
    {
        if (is_small_letter(input[i]))
        {
            int diff = ('z' - input[i]);
            char l = 'a' + diff;

            e[out] = l;
            out++;
        }
        else if (input[i] == ' ')
        {
            continue;
        }
        else if (is_captial_letter(input[i]))
        {
            char diff = ('Z' - input[i]);
            char l = 'a' + diff;

            e[out] = l;
            out++;
        }
        else
        {
            e[out] = input[i];
            out++;
        }
    }

    e[out] = '\0';
    return e;
}