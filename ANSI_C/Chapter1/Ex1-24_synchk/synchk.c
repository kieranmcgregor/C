// Test 1: (this is in parentheses))
// Test 2: ((this is in parentheses)
// Test 3: {{this is in correct braces}
// Test 4: 'this is in single quotes''
// Test 5: ""this is outside double quote"
// Test 6: \t tab \l nothing \ooo octal \xhh hex \xhy nothing

#include <stdio.h>
/* checks for basis syntax (i.e. unbalanced brackets, braces & parentheses,
quotes, both single and double, excape sequences and comments) in a C program */

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000

int get_line(char line[], int lim);
void par_checker(int popen[], int pclose[], char line[], int len);
void bck_checker(int kopen[], int kclose[], char line[], int len);
void brc_checker(int bopen[], int bclose[], char line[], int len);
void squo_checker(int sing_quo[], char line[], int len);
void dquo_checker(int doub_quo[], char line[], int len);
void escape_checker(int esc_seq[], char line[], int len);

int main()
{
    int line_num; // current line number
    int len; // length of current line
    char line[MAXLINE]; // current line of chars
    int popen[MAXLINE]; // open parentheses '(' in current line
    int pclose[MAXLINE]; // close parentheses ')' in current line
    int kopen[MAXLINE]; // open brackets '[' in current line
    int kclose[MAXLINE]; // close brackets ']' in current line
    int bopen[MAXLINE]; // open braces '{' in current line
    int bclose[MAXLINE]; // close braces '}' in current line
    int sing_quo[MAXLINE]; // single quotes ' in current line
    int doub_quo[MAXLINE]; // double quotes " in current line
    int esc_seq[MAXLINE]; // invalid escape sequences in current line

    line_num = 1;

    printf("Please enter a string:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("Line: %d\n%s", line_num, line);

        par_checker(popen, pclose, line, len);
        bck_checker(kopen, kclose, line, len);
        brc_checker(bopen, bclose, line, len);
        squo_checker(sing_quo, line, len);
        dquo_checker(doub_quo, line, len);
        escape_checker(esc_seq, line, len);

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

void par_checker(int popen[], int pclose[], char line[], int len)
{
    int i, o_len, c_len;

    o_len = c_len = 0;

    for (i = 0; i < len; i++)
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

void bck_checker(int kopen[], int kclose[], char line[], int len)
{
    int i, o_len, c_len;

    o_len = c_len = 0;

    for (i = 0; i < len; i++)
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

void brc_checker(int bopen[], int bclose[], char line[], int len)
{
    int i, o_len, c_len;

    o_len = c_len = 0;

    for (i = 0; i < len; i++)
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

void squo_checker(int sing_quo[], char line[], int len)
{
    int i, slen;

    slen = 0;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\'')
        {
            if (slen > 0)
            {
                slen--;
                sing_quo[slen] = '\0';
            }
            else
            {
                sing_quo[slen] = i;
                slen++;
            }
        }
    }

    if (slen > 0)
    {
        printf("ERROR: ");
        printf("Uneven single quotes remain at index:\n");
        for (i = 0; i < slen; i++)
        {
            printf("%d", sing_quo[i]);
        }
        printf("\n");
    }
}

void dquo_checker(int doub_quo[], char line[], int len)
{
    int i, dlen;

    dlen = 0;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\"')
        {
            if (dlen > 0)
            {
                dlen--;
                doub_quo[dlen] = '\0';
            }
            else
            {
                doub_quo[dlen] = i;
                dlen++;
            }
        }
    }

    if (dlen > 0)
    {
        printf("ERROR: ");
        printf("Uneven double quotes remain at index:\n");
        for (i = 0; i < dlen; i++)
        {
            printf("%d", doub_quo[i]);
        }
        printf("\n");
    }
}

void escape_checker(int esc_seq[], char line[], int len)
{
    int i, elen;
    int esc_char;
    char let;

    let = line[i];

    esc_char = 0;

    for (i = 0; i < len; i++)
    {
        if (line[i] == '\\' && esc_char == 0)
        {
            esc_char++;
        }
        else if (esc_char > 2)
        {
            if (let != 'o' || let != 'h')
            {
                esc_seq[elen] = (i - esc_char);
                elen++;
            }
            esc_char = 0;
        }
        else if (esc_char > 1)
        {
            if (let != 'o' || let != 'h')
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
            if ((let != 'n') || (let != 't') || (let != 'v') || (let != 'b') || (let != 'r') || (let != 'f') || (let != 'a') || (let != '\\') || (let != '?') || (let != '\'') || (let != '\"') || (let != 'o') || (let != 'x'))
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
        // else
        // {
        //     esc_char = 0;
        // }
    }

    printf("%d\n", elen);

    if (elen > 0)
    {
        printf("ERROR: ");
        printf("Invalid escape sequence at indeces:\n");
        for (i = 0; i < elen; i++)
        {
            printf("%d ", esc_seq[i]);
        }
        printf("\n");
    }
}
