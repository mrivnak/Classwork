double* mvp1(double* mat, double* vec, int n);
double* mvp2(double** mat, double* vec, int n);

double dot(double* a, double* b, int size);

double** allocMat2(int rows, int cols);
double* allocMat1(int rows, int cols);
double* allocVec(int size);

void assignMat2(double** mat, int rows, int cols);
void assignMat1(double* mat, int rows, int cols);
void assignVec(double* vec, int size);

void freeMat2(double** mat, int rows);
void freeMat1(double* mat);
void freeVec(double* vec);

void printMatVec2(double** mat, double* vec, double* res, int rows, int cols);
void printMatVec1(double* mat, double* vec, double* res, int rows, int cols);

void printMat2(double** mat, int rows, int cols);
void printMat1(double* mat, int rows, int cols);
void printVec(double* vec, int size);
