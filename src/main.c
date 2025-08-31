#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file_contents(const char *filename);
void tokenize(const char *filename);


int main(int argc, char *argv[]) {
    // Disable output buffering
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    if (argc < 3) {
        fprintf(stderr, "Usage: ./your_program tokenize <filename>\n");
        return 1;
    }

    const char *command = argv[1];

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    fprintf(stderr, "Logs from your program will appear here!\n");
    if (strcmp(command, "tokenize") == 0) {
        tokenize(argv[2]);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}

char *read_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error reading file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(file_contents, 1, file_size, file);
    if (bytes_read < file_size) {
        fprintf(stderr, "Error reading file contents\n");
        free(file_contents);
        fclose(file);
        return NULL;
    }

    file_contents[file_size] = '\0';
    fclose(file);

    return file_contents;
}


void tokenize(const char *filename) {
    int i = 0;
    int line_number = 1;
    int error_encountered = 0;
        
    char *file_contents = read_file_contents(filename);

    // Uncomment this block to pass the first stage
    if (strlen(file_contents) > 0) {
        // fprintf(stderr, "Scanner not implemented\n");
        while (file_contents[i] != '\0') {
            /**
             * 10 is newline
             */
            if (file_contents[i] == 10) {
                line_number++;
            }
            /**
             * 32 is space
             * 9 is tab
             * 13 is carriage return
             */
            if (file_contents[i] == 32 || file_contents[i] == 9 || file_contents[i] == 13) {
                // do nothing
            } else if (file_contents[i] == '(') {
                printf("LEFT_PAREN ( null\n");
            } else if (file_contents[i] == ')') {
                printf("RIGHT_PAREN ) null\n");
            } else if (file_contents[i] == '{') {
                printf("LEFT_BRACE { null\n");
            } else if (file_contents[i] == '}') {
                printf("RIGHT_BRACE } null\n");
            } else if (file_contents[i] == ',') {
                printf("COMMA , null\n");
            } else if (file_contents[i] == ';') {
                printf("SEMICOLON ; null\n");
            } else if (file_contents[i] == '.') {
                printf("DOT . null\n");
            } else if (file_contents[i] == '+') {
                printf("PLUS + null\n");
            } else if (file_contents[i] == '-') {
                printf("MINUS - null\n");
            } else if (file_contents[i] == '*') {
                printf("STAR * null\n");
            } else if (file_contents[i] == '=' && file_contents[i+1] == '=') {
                printf("EQUAL_EQUAL == null\n");
                i++;
            } else if (file_contents[i] == '=' && file_contents[i+1] != '=') {
                printf("EQUAL = null\n");
            } else if (file_contents[i] == '!' && file_contents[i+1] == '=') {
                printf("BANG_EQUAL != null\n");
                i++;
            } else if (file_contents[i] == '!' && file_contents[i+1] != '=') {
                printf("BANG ! null\n");
            } else if (file_contents[i] == '<' && file_contents[i+1] == '=') {
                printf("LESS_EQUAL <= null\n");
                i++;
            } else if (file_contents[i] == '<' && file_contents[i+1] != '=') {
                printf("LESS < null\n");
            } else if (file_contents[i] == '>' && file_contents[i+1] == '=') {
                printf("GREATER_EQUAL >= null\n");
                i++;
            } else if (file_contents[i] == '>' && file_contents[i+1] != '=') {
                printf("GREATER > null\n");
            } else if (file_contents[i] == '/' && file_contents[i+1] != '/') {
                printf("SLASH / null\n");
            } else if (file_contents[i] == '/' && file_contents[i+1] == '/') {
                while (file_contents[i] != 10 && i < strlen(file_contents)) {
                    i++;
                }
            } else if (file_contents[i] != 10) {
                fprintf(stderr, "[line %d] Error: Unexpected character: %c\n", line_number, file_contents[i]);
                error_encountered = 1;
            }
            i++;
        }
    } 
    printf("EOF  null\n"); // Placeholder, replace this line when implementing the scanner
    if (error_encountered) {
        exit((int)(65));   
    }
    exit(0);
    
    free(file_contents);
    
}