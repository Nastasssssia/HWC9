#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
В файле .txt строка из маленьких и больших английских букв, знаков
препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
все пробелы. Результат записать в файл .txt.
*/

#define MAXELEMENTS 1000

void remove_duplicates_and_spaces(const char *input, char *output)
{
    int seen[256] = {0};
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];

        if (ch != ' ' && seen[(unsigned char)ch] == 0)
        {
            seen[(unsigned char)ch] = 1;
            output[j++] = ch;
        }
    }
    output[j] = '\0';
}

void input_array(char *string)
{
    FILE *in = fopen("input.txt", "r");
    if (in == NULL)
    {
        perror("Error opening input file");
        return;
    }

    fgets(string, MAXELEMENTS, in);
    fclose(in);
}

void output_array(const char *output)
{
    FILE *out = fopen("output.txt", "w");
    if (out == NULL)
    {
        perror("Error opening output file");
        return;
    }

    fprintf(out, "%s", output);
    fclose(out);
}

int main(void)
{
    char string_file[MAXELEMENTS];
    char result[MAXELEMENTS];

    // Считываем строку из файла
    input_array(string_file);

    // Удаляем повторяющиеся символы и пробелы
    remove_duplicates_and_spaces(string_file, result);

    // Записываем результат в выходной файл
    output_array(result);

    return 0;
}
