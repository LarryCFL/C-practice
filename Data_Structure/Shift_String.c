/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

char* string_shift(int left, int right, char *s)
{
    int str_len = strlen(s);
    int shift_time = abs(left-right)%str_len;
    int left_or_right = left - right;
    char *temp_s = malloc(sizeof(char) * str_len + 1);
    int index, index2;
    if(left_or_right > 0){
        index = shift_time;
        index2 = (str_len - shift_time);
    } else if (left_or_right < 0)
    {
        index = (str_len - shift_time);
        index2 = shift_time;
    } else {
        return s;
    }

    for (int i=index, j=0; i< str_len ; i++, j++) {
       *(temp_s+j) = *(s+i);
    }

    for (int i=index2, j=0; i< str_len ; i++,j++) {
       *(temp_s+i) = *(s+j);
    }

    temp_s[str_len] = '\0';

    return temp_s;
}

int main()
{
    //char *str = "abcd";
    char str[200];
    scanf("%[^\n]",str);

    int left, right = 0;
    scanf("%d", &left);
    scanf("%d", &right);

    char *str_shift = string_shift(left,right, str);



    printf("shift string: %s", str_shift);

    return 0;
}
