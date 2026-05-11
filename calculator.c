#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *data;
    float a, b, result;
    char op;

    data = getenv("QUERY_STRING");

    sscanf(data, "a=%f&op=%c&b=%f", &a, &op, &b);

    printf("Content-Type:text/html\n\n");

    printf("<html><body>");

    printf("<h1>Calculator Result</h1>");

    switch(op) {

        case '+':
            result = a + b;
            printf("<h2>Result = %.2f</h2>", result);
            break;

        case '-':
            result = a - b;
            printf("<h2>Result = %.2f</h2>", result);
            break;

        case '*':
            result = a * b;
            printf("<h2>Result = %.2f</h2>", result);
            break;

        case '/':
            if(b != 0) {
                result = a / b;
                printf("<h2>Result = %.2f</h2>", result);
            }
            else {
                printf("<h2>Division by zero not allowed</h2>");
            }
            break;

        default:
            printf("<h2>Invalid Operator</h2>");
    }

    printf("</body></html>");

    return 0;
}