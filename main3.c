#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
числа и иные символы. Требуется все числа, которые встречаются в строке,
поместить в отдельный целочисленный массив. Например, если дана строка
"data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
массив по возрастанию в файл .txt.

*/

#define MAXELEMENTS 1000
#define MAXNUMBERS 100

void input_array(char *string)
{
    FILE *in = fopen("input.txt", "r");
    if (in == NULL)
    {
        perror("Error opening input file");
        return;
    }

    fscanf(in, "%[^\n]", string);
    fclose(in);
}

int extract_numbers(char *str, int nums[])
{
    int i = 0, j = 0, num = 0;
    int found_digit = 0;

    while (str[i] != '\0')
    {

        if (str[i] >= '0' && str[i] <= '9')
        {
            found_digit = 1;
            num = num * 10 + (str[i] - '0');
        }
        else if (found_digit)
        {

            nums[j++] = num;
            num = 0;
            found_digit = 0;
        }
        i++;
    }

    if (found_digit)
    {
        nums[j++] = num;
    }

    return j;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void output_array(const int *numbers, int count)
{
    FILE *out = fopen("output.txt", "w");
    if (out == NULL)
    {
        perror("Error opening output file");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(out, "%d ", numbers[i]);
    }

    fclose(out);
}

int main(void)
{
    char string_file[MAXELEMENTS];
    int numbers[MAXNUMBERS];

    // Считываем строку из файла
    input_array(string_file);

    // Извлекаем числа из строки
    int count = extract_numbers(string_file, numbers);

    // Сортируем массив чисел с помощью qsort
    qsort(numbers, count, sizeof(int), compare);

    // Записываем отсортированные числа в выходной файл
    output_array(numbers, count);

    return 0;
}