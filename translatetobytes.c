#include <stdio.h>
#include <math.h>

int main() {
    printf("Input must be whole octal words separated by tab\n");
    char octal_word[7] = ""; //room for 6 octal digits for a 16 bit word and "\0"
    while (scanf("%6s", octal_word)){
        char binary_word[19] = ""; //room for 18 binary digits (bit grouping) and "\0"
        int j=5;
        for (int i=17; i>=0; i-=3){
            switch(octal_word[j]){
                case '0':
                    binary_word[i]='0';
                    binary_word[i-1]='0';
                    binary_word[i-2]='0';
                    break;
                case '1':
                    binary_word[i]='1';
                    binary_word[i-1]='0';
                    binary_word[i-2]='0';
                    break;
                case '2':
                    binary_word[i]='0';
                    binary_word[i-1]='1';
                    binary_word[i-2]='0';
                    break;
                case '3':
                    binary_word[i]='1';
                    binary_word[i-1]='1';
                    binary_word[i-2]='0';
                    break;
                case '4':
                    binary_word[i]='0';
                    binary_word[i-1]='0';
                    binary_word[i-2]='1';
                    break;
                case '5':
                    binary_word[i]='1';
                    binary_word[i-1]='0';
                    binary_word[i-2]='1';
                    break;
                case '6':
                    binary_word[i]='0';
                    binary_word[i-1]='1';
                    binary_word[i-2]='1';
                    break;
                case '7':
                    binary_word[i]='1';
                    binary_word[i-1]='1';
                    binary_word[i-2]='1';
                    break;
                default:
                    printf("Octal word contains only 0-7 digits -_-");
            }
            j--;
        }
        int lower_byte = 0;
        int upper_byte = 0;
        int k=0;
        for (k=17; k>=10; k--){
            unsigned int power_of_2 = (unsigned int)pow(2, 17-k);
            lower_byte += power_of_2*(binary_word[k]-'0');
        }
        for (;k>=2; k--){
            unsigned int power_of_2 = (unsigned int)pow(2, 9-k);
            upper_byte += power_of_2*(binary_word[k]-'0');
        }
        printf("lower byte: %o\tupper byte: %o\n", lower_byte, upper_byte);
    }
    scanf("%s", octal_word);
}