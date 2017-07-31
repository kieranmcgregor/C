// Test 1: (this is in parentheses))
// Test 2: ((this is in parentheses)
// Test 3: {{this is in correct braces}
// Test 4: 'this is in single quotes''
// Test 5: ""this is outside double quote"
// Test 6: 'hello \t tab \l invalid at i=14 \ooo octal \xhh hex \xhy invalid at i=53'
// Test 7: this is a test (([{)'"\y
// Test 8: (([{)\y'"
// Test 9: "( this is not an error"
// Test 10: '"( this is not an error'
// Test 11: "') this is not an error"
// Test 11: "\" no error " double quote error"

#include <stdio.h>
/* checks for basis syntax (i.e. unbalanced brackets, braces & parentheses,
quotes, both single and double, excape sequences and comments) in a C program */

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000
#define IN 1
#define OUT 0

int get_line(char line[], int lim);
int quoted_checker(char prior, int state);
void par_checker(char line[], int len);
void bck_checker(char line[], int len);
void brc_checker(char line[], int len);
void quote_checker(char line[], int len);
void escape_checker(char line[], int len);

int main()
{
    int line_num; // current line number
    int len; // length of current line
    char line[MAXLINE]; // current line of chars

    line_num = 1;

    printf("Please enter a string: *Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("Line: %d) %s", line_num, line);

        par_checker(line, len);
        bck_checker(line, len);
        brc_checker(line, len);
        quote_checker(line, len);
        escape_checker(line, len);

        line_num++;
    }
    return 0;
}


int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && (c != '\n') && (i != lim); i++)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

int quoted_checker(char prior, int state)
{
    if (prior != '\\')
    {
        state = !state;
    }

    return state;
}

void par_checker(char line[], int len)
{
    int i, o_len, c_len, sing_state, doub_state;
    int popen[MAXLINE]; // open parentheses '(' in current line
    int pclose[MAXLINE]; // close parentheses ')' in current line

    o_len = c_len = 0;
    sing_state = OUT;
    doub_state = OUT;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\'')
        {
            sing_state = quoted_checker(line[i - 1], sing_state);
        }
        else if (line[i] == '\"')
        {
            doub_state = quoted_checker(line[i - 1], doub_state);
        }

        if (sing_state == OUT && doub_state == OUT)
        {
            if (line[i] == '(')
            {
                popen[o_len] = i;
                o_len++;
            }
            else if (line[i] == ')')
            {
                if (o_len > 0)
                {
                    o_len--;
                    popen[o_len] = '\0';
                }
                else
                {
                    pclose[c_len] = i;
                    c_len++;
                }
            }
        }
    }

    if (o_len > 0 || c_len > 0)
    {
        printf("ERROR: ");
        if (o_len > 0)
        {
            printf("Open parentheses remain at indeces:\n");
            for (i = 0; i < o_len; i++)
            {
                printf("%d ", popen[i]);
            }
        }
        else
        {
            printf("Closed parentheses remain at indeces:\n");
            for (i = 0; i < c_len; i++)
            {
                printf("%d ", pclose[i]);
            }
        }
        printf("\n");
    }
}

void bck_checker(char line[], int len)
{
    int i, o_len, c_len, sing_state, doub_state;
    int kopen[MAXLINE]; // open brackets '[' in current line
    int kclose[MAXLINE]; // close brackets ']' in current line

    o_len = c_len = 0;

    sing_state = OUT;
    doub_state = OUT;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\'')
        {
            sing_state = quoted_checker(line[i - 1], sing_state);
        }
        else if (line[i] == '\"')
        {
            doub_state = quoted_checker(line[i - 1], doub_state);
        }

        if (sing_state == OUT && doub_state == OUT)
        {
            if (line[i] == '[')
            {
                kopen[o_len] = i;
                o_len++;
            }
            else if (line[i] == ']')
            {
                if (o_len > 0)
                {
                    o_len--;
                    kopen[o_len] = '\0';
                }
                else
                {
                    kclose[c_len] = i;
                    c_len++;
                }
            }
        }
    }

    if (o_len > 0 || c_len > 0)
    {
        printf("ERROR: ");
        if (o_len > 0)
        {
            printf("Open brackets remain at indeces:\n");
            for (i = 0; i < o_len; i++)
            {
                printf("%d ", kopen[i]);
            }
        }
        else
        {
            printf("Closed brackets remain at indeces:\n");
            for (i = 0; i < c_len; i++)
            {
                printf("%d ", kclose[i]);
            }
        }
        printf("\n");
    }
}

void brc_checker(char line[], int len)
{
    int i, o_len, c_len, sing_state, doub_state;
    int bopen[MAXLINE]; // open braces '{' in current line
    int bclose[MAXLINE]; // close braces '}' in current line

    o_len = c_len = 0;

    sing_state = OUT;
    doub_state = OUT;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\'')
        {
            sing_state = quoted_checker(line[i - 1], sing_state);
        }
        else if (line[i] == '\"')
        {
            doub_state = quoted_checker(line[i - 1], doub_state);
        }

        if (sing_state == OUT && doub_state == OUT)
        {
            if (line[i] == '{')
            {
                bopen[o_len] = i;
                o_len++;
            }
            else if (line[i] == '}')
            {
                if (o_len > 0)
                {
                    o_len--;
                    bopen[o_len] = '\0';
                }
                else
                {
                    bclose[c_len] = i;
                    c_len++;
                }
            }
        }
    }

    if (o_len > 0 || c_len > 0)
    {
        printf("ERROR: ");
        if (o_len > 0)
        {
            printf("Open braces remain at indeces:\n");
            for (i = 0; i < o_len; i++)
            {
                printf("%d ", bopen[i]);
            }
        }
        else
        {
            printf("Closed braces remain at indeces:\n");
            for (i = 0; i < c_len; i++)
            {
                printf("%d ", bclose[i]);
            }
        }
        printf("\n");
    }
}

void quote_checker(char line[], int len)
{
    int i, slen, dlen, state;
    int sing_quo[MAXLINE]; // single quotes ' in current line
    int doub_quo[MAXLINE]; // double quotes " in current line

    slen = 0;
    dlen = 0;

    state = OUT;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\'' && state == OUT)
        {
            state = IN;
            sing_quo[slen] = i;
            slen++;
        }
        else if (line[i] == '\"' && state == OUT)
        {
            state = IN;
            doub_quo[dlen] = i;
            dlen++;
        }
        else if (line[i] == '\'' && state == IN)
        {
            if (slen > 0)
            {
                state = quoted_checker(line[i - 1], state);
                if (state == OUT)
                {
                    slen--;
                    sing_quo[slen] = '\0';
                }
            }
        }
        else if (line[i] == '\"' && state == IN)
        {
            if (dlen > 0)
            {
                state = quoted_checker(line[i - 1], state);
                if (state == OUT)
                {
                    dlen--;
                    doub_quo[dlen] = '\0';
                }
            }
        }
    }

    if (slen > 0)
    {
        printf("ERROR: Uneven single quotes remain at index:\n");
        for (i = 0; i < slen; i++)
        {
            printf("%d", sing_quo[i]);
        }
        printf("\n");
    }
    else if (dlen > 0)
    {
        printf("ERROR: Uneven double quotes remain at index:\n");
        for (i = 0; i < dlen; i++)
        {
            printf("%d", doub_quo[i]);
        }
        printf("\n");
    }
}

void escape_checker(char line[], int len)
{
    int i, elen, sing_state, doub_state;
    int esc_seq[MAXLINE]; // invalid escape sequences in current line
    int esc_char;
    char let;

    elen = 0;
    esc_char = 0;
    sing_state = OUT;
    doub_state = OUT;

    for (i = 0; i < len; i++)
    {
        let = line[i];

        if (line[i] == '\'')
        {
            sing_state = quoted_checker(line[i - 1], sing_state);
        }
        else if (line[i] == '\"')
        {
            doub_state = quoted_checker(line[i - 1], doub_state);
        }

        if (sing_state == IN || doub_state == IN)
        {
            if (line[i] == '\\' && esc_char == 0)
            {
                esc_char++;
            }
            else if (esc_char > 2)
            {
                if (let != 'o' && let != 'h')
                {
                    esc_seq[elen] = (i - esc_char);
                    elen++;
                }
                esc_char = 0;
            }
            else if (esc_char > 1)
            {
                if (let != 'o' && let != 'h')
                {
                    esc_seq[elen] = (i - esc_char);
                    elen++;
                    esc_char = 0;
                }
                else
                {
                    esc_char++;
                }
            }
            else if (esc_char > 0)
            {
                if ((let != 'n') && (let != 't') && (let != 'v') && (let != 'b') && (let != 'r') &&
                    (let != 'f') && (let != 'a') && (let != '\\') && (let != '?') && (let != '\'')
                    && (let != '\"') && (let != 'o') && (let != 'x'))
                {
                    esc_seq[elen] = (i - esc_char);
                    elen++;
                    esc_char = 0;
                }
                else if (let == 'o' || let == 'x')
                {
                    esc_char++;
                }
                else
                {
                    esc_char = 0;
                }
            }
            else
            {
                esc_char = 0;
            }
        }
        else
        {
            if (line[i] == '\\')
            {
                esc_seq[elen] = i;
                elen++;
            }
        }
    }

    if (elen > 0)
    {
        printf("ERROR: Invalid escape sequence at indeces:\n");
        for (i = 0; i < elen; i++)
        {
            printf("%d ", esc_seq[i]);
        }
        printf("\n");
    }
}
