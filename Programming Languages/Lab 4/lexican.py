import os

# Definitions
EOF = -1
LETTER = 0
DIGIT = 1
UNKNOWN = 99
INT_LIT = 10
INDENT = 11
ASSIGN_OP = 20
ADD_OP = 21
SUB_OP = 22
MULT_OP = 23
DIV_OP = 24
LEFT_PAREN = 25
RIGHT_PAREN = 26

# Global variables
next_token = 0
char_class = 0
lexeme = ''
next_char = ''
lex_len = 0
data = ''
char_counter = 0

def lookup(ch):
    global next_token
    if ch == '(':
        add_char()
        next_token = LEFT_PAREN
    elif ch == ')':
        add_char()
        next_token = RIGHT_PAREN
    elif ch == '+':
        add_char()
        next_token = ADD_OP
    elif ch == '-':
        add_char()
        next_token = SUB_OP
    elif ch == '*':
        add_char()
        next_token = MULT_OP
    elif ch == '/':
        add_char()
        next_token = DIV_OP
    else:
        add_char()
        next_token = EOF

    return next_token

def add_char():
    global lex_len, lexeme, next_char

    lexeme[lex_len + 1] = next_char
    lexeme[lex_len] = 0

def get_char():
    global next_char, char_class

    next_char = getc()
    if next_char:
        if next_char.isalpha:
            char_class = LETTER
        elif next_char.isdigit:
            char_class
        else:
            char_class = UNKNOWN
    else:
        char_class = EOF

def get_non_blank():
    while not next_char.isspace:
        get_char()

def lex():
    global lex_len, char_class, next_token
    lex_len = 0;
    get_non_blank()

    if char_class == LETTER:
        add_char()
        get_char()
        while char_class == LETTER or char_class == DIGIT:
            add_char()
            get_char()
        next_token = INDENT
    elif char_class == DIGIT:
        add_char()
        get_char()
        while char_class == DIGIT:
            add_char()
            get_char()
        next_token = INT_LIT
    elif char_class == UNKNOWN:
        lookup(next_char)
        get_char()
    elif char_class == EOF:
        next_token = EOF
        lexeme = 'EOF'

    print('Next token is: {}, Next lexeme is: {}'.format(next_token, lexeme))
    return next_token

def getc():
    global char_counter
    output = data[char_counter] if char_counter < len(data) else None
    return output

def main():
    global data, next_token
    with open('front.txt', 'r') as file:
        data = file.read()

        get_char()
        while True:
            lex()

            if next_token == EOF:
                break

if __name__ == '__main__':
    main()