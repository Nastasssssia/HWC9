#include <stdio.h>
#include <string.h>

/*
В файле .txt дана символьная строка не более 1000 символов. Необходимо
заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
строчные. Результат записать в .txt.

*/

void replace_and_save(const char *input_file, const char *output_file)
{
    FILE *f_in = fopen(input_file, "r");
    FILE *f_out = fopen(output_file, "w");

    if (f_in == NULL || f_out == NULL)
    {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(f_in)) != EOF)
    { // Читаем каждый символ из файла
        switch (ch)
        {
        case 'a':
            fputc('b', f_out); // Замена 'a' на 'b'
            break;
        case 'A':
            fputc('B', f_out); // Замена 'A' на 'B'
            break;
        case 'b':
            fputc('a', f_out); // Замена 'b' на 'a'
            break;
        case 'B':
            fputc('A', f_out); // Замена 'B' на 'A'
            break;
        default:
            fputc(ch, f_out); // Остальные символы остаются без изменений
            break;
        }
    }

    fclose(f_in);
    fclose(f_out);
}

int main()
{
    replace_and_save("input.txt", "output.txt");
    return 0;
}
