#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
несколько, не обрабатывать.

*/

void find_longest_word(const char *input_file, const char *output_file)
{
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (in == NULL || out == NULL)
    {
        perror("Error opening file");
        return;
    }

    char word[100];
    char longest_word[100] = "";
    int max_length = 0;

    while (fscanf(in, "%s", word) == 1)
    { // Читаем слово из файла
        int length = strlen(word);
        if (length > max_length)
        {
            max_length = length;
            strcpy(longest_word, word);
        }
    }

    fprintf(out, "%s", longest_word);

    fclose(in);
    fclose(out);
}

int main()
{
    find_longest_word("input.txt", "output.txt");
    return 0;
}
