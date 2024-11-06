#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.

*/

#define MAX_LENGTH 1000

void count_words_ending_with_a(const char *input_file, const char *output_file)
{
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (in == NULL || out == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[MAX_LENGTH];
    int count = 0;

    if (fgets(line, MAX_LENGTH, in) != NULL)
    {
        // Разбиваем строку на слова
        char *word = strtok(line, " ");

        // Обрабатываем каждое слово
        while (word != NULL)
        {
            int len = strlen(word);

            if (len > 0 && tolower(word[len - 1]) == 'a')
            {
                count++;
            }

            word = strtok(NULL, " ");
        }
    }

    fprintf(out, "%d", count);

    fclose(in);
    fclose(out);
}

int main()
{
    count_words_ending_with_a("input.txt", "output.txt");
    return 0;
}
