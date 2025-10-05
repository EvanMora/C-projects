typedef struct {
    double x;
    double y;
} Vector;

Vector create_vector(double x, double y);

void print_vector(Vector v);

double magnitude(Vector v);

Vector add(Vector v, Vector u);

Vector substract(Vector v, Vector u);

Vector scalar_product(Vector v, int n);

double dot_product(Vector v, Vector u);
