import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Lexican {
    static final int EOF = -1;
    static final int LETTER = 0;
    static final int DIGIT = 1;
    static final int UNKNOWN = 99;
    static final int INT_LIT = 10;
    static final int INDENT = 11;
    static final int ASSIGN_OP = 20;
    static final int ADD_OP = 21;
    static final int SUB_OP = 22;
    static final int MULT_OP = 23;
    static final int DIV_OP = 24;
    static final int LEFT_PAREN = 25;
    static final int RIGHT_PAREN = 26;

    static int nextToken;

    static int charClass;
    static char[] lexeme = new char[100];
    static char nextChar;
    static int lexLen;
    static String data = "";

    static int charCounter = 0;

    public static void main(String args[]) {
        Path filename = Path.of("front.txt");

        try {
            data = Files.readString(filename);
        }
        catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }

        getChar();
        do {
            lex();
        } while (nextToken != EOF);

    }

    public static int lookup(char ch) {
        switch (ch) {
            case '(':
                addChar();
                nextToken = LEFT_PAREN;
                break;
            case ')':
                addChar();
                nextToken = RIGHT_PAREN;
                break;
            case '+':
                addChar();
                nextToken = ADD_OP;
                break;
            case '-':
                addChar();
                nextToken = SUB_OP;
                break;
            case '*':
                addChar();
                nextToken = MULT_OP;
                break;
            case '/':
                addChar();
                nextToken = DIV_OP;
                break;
            default:
                addChar();
                nextToken = EOF;
                break;
        }

        return nextToken;
    }

    public static void addChar() {
        if (lexLen <= 98) {
            lexeme[lexLen++] = nextChar;
            lexeme[lexLen] = 0;
        }
        else {
            System.out.println("Error - lexeme is too long");
        }
    }

    public static void getChar() {
        try {
            nextChar = getc();
            if (Character.isAlphabetic(nextChar)) {
                charClass = LETTER;
            }
            else if (Character.isDigit(nextChar)) {
                charClass = DIGIT;
            }
            else {
                charClass = UNKNOWN;
            }
        }
        catch (IndexOutOfBoundsException e) {
            charClass = EOF;
        }
    }

    public static void getNonBlank() {
        while (nextChar == ' ') {
            getChar();
        }
    }

    public static int lex() {
        lexLen = 0;
        getNonBlank();

        switch (charClass) {
            case LETTER:
                addChar();
                getChar();
                while (charClass == LETTER || charClass == DIGIT) {
                    addChar();
                    getChar();
                }
                nextToken = INDENT;
                break;
            
            case DIGIT:
                addChar();
                getChar();
                while (charClass == DIGIT) {
                    addChar();
                    getChar();
                }
                nextToken = INT_LIT;
                break;
            
            case UNKNOWN:
                lookup(nextChar);
                getChar();
                break;

            case EOF:
                nextToken = EOF;
                lexeme[0] = 'E';
                lexeme[1] = 'O';
                lexeme[2] = 'F';
                lexeme[3] = 0;
                break;
        }

        String lexemeOut = new String(lexeme);

        // Flush lexeme buffer
        for (int i = 0; i < lexeme.length; i++) {
            lexeme[i] = 0;
        }

        System.out.printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexemeOut);
        return nextToken;
    }

    public static char getc(){
        char output = data.charAt(charCounter);
        charCounter++;
        return output;
    }
}
