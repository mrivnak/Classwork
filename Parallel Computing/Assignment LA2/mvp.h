double* mvp(double* mat, double* vec, int n);

double dot(double* a, double* b, int size);

double* allocMat(int rows, int cols);
double* allocVec(int size);

void assignMat(double* mat, int rows, int cols);
void assignVec(double* vec, int size);

void freeMat(double* mat);
void freeVec(double* vec);

void printMatVec(double* mat, double* vec, double* res, int rows, int cols);

void printMat(double* mat, int rows, int cols);
void printVec(double* vec, int size);
