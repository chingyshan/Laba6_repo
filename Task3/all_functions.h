#ifndef ALL_FUNCTIONS_H
#define ALL_FUNCTIONS_H
int askToRunProgram();
int calculate_sum(const char* str);
void free_matrix(char** matrix, int rows);
int get_rows();
void input_matrix(char** matrix, int rows,int MAX_COLS);
void print(char** matrix, int rows);
bool single_byte(unsigned char ch);
bool two_byte(unsigned char ch);
char* zerkalo(const char* str, int size);
void userMenu();
#endif
