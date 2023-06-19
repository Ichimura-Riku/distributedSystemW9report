#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    scanf("%s", msg);
    

    char string[100];
    strcpy(string, msg);

    int bn[100]; //デコンパイル後の値
    char stack[100] = ""; //2つ数値になるまでのstack
    char out[100] = ""; //format前の最終出力内容
    char out_s[100] = ""; //最終出力内容
    char *dc[] = {"にゃん", "にゃ～ん", "にゃおん", "にゃにゃ"};//コンパイルフォーマット
    int n = strlen(string);

    // strcat()は適切なサイズの文字配列を事前に確保する必要がある

    for (int i = 0; i < n; i++) {
        char s = string[0];
        for (int j = 0; j < n - 1; j++) {
            string[j] = string[j+1];
        }
        string[n-1] = '\0';

        if (s != ' ') {
            char temp[2] = {s, '\0'};
            strcat(stack, temp);  
        }
        if (strcmp(stack, dc[0]) == 0) {
            strcat(out, "00");
            bn[i] = 0;
        } else if (strcmp(stack, dc[1]) == 0) {
            strcat(out, "01");
            bn[i] = 1;
        } else if (strcmp(stack, dc[2]) == 0) {
            strcat(out, "10");
            bn[i] = 2;
        } else if (strcmp(stack, dc[3]) == 0) {
            strcat(out, "11");
            bn[i] = 3;
        }

        if (strlen(out) == 8) {
            int decimal = 0;
            int power = 1;
            for (int j = 7; j >= 0; j--) {
                decimal += (out[j] - '0') * power;
                power *= 2;
            }
            out_s[strlen(out_s)] = decimal;
            out[0] = '\0';
        }
    }

    printf("%s\n", out_s);
    return 0;
}
