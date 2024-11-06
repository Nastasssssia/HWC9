#include <stdio.h>
#include <string.h>

/*
В файле .txt даны два слова не более 100 символов каждое, разделенные
одним пробелом. Найдите только те символы слов, которые встречаются в
обоих словах только один раз. Напечатайте их через пробел в файл .txt в
лексикографическом порядке.

*/

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    if (f_in == NULL || f_out == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char word1[100], word2[100];
    fscanf(f_in, "%s%s", word1, word2);

    int alpha1[26] = {0};
    int alpha2[26] = {0};

    for (int i = 0; word1[i] != '\0'; i++)
        alpha1[word1[i] - 'a']++;

    for (int i = 0; word2[i] != '\0'; i++)
        alpha2[word2[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (alpha1[i] == 1 && alpha2[i] == 1)
            fprintf(f_out, "%c ", i + 'a');
    }

    fclose(f_in);
    fclose(f_out);

    return 0;
}
