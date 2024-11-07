#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.

*/

const int line_width = 1024;

int main(void)
{

    char *input_fn = "input.txt";
    char *output_fn = "output.txt";
    char line[line_width];
    FILE *fp;
    int count = 0;

    fp = fopen(input_fn, "r");

    while (fscanf(fp, "%s", line) == 1)
        if (line[strlen(line) - 1] == 'a')
            count++;

    fclose(fp);

    fp = fopen(output_fn, "w");

    fprintf(fp, "%d", count);

    fclose(fp);
    return 0;
}
