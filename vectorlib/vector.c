#include <stdio.h>
#include <math.h>

#include "vector.h"

Vector create_vector(double x, double y) {
    Vector v;
    v.x = x;
    v.y = y;
    return v;
}

void print_vector(Vector v) {
    printf("Vector(%f, %f)", v.x, v.y);
}

double magnitude(Vector v) {
    return sqrt((v.x * v.x) + (v.y * v.y));
}

Vector add(Vector v, Vector u) {
    return create_vector(
        v.x + u.x,
        v.y + u.y
    );
}

Vector substract(Vector v, Vector u) {
    return create_vector(
        v.x - u.x,
        v.y - u.y
    );
}

Vector scalar_product(Vector v, int n) {
    return create_vector(
        v.x * n,
        v.y * n
    );
}

double dot_product(Vector v, Vector u) {
    return (v.x * u.x) + (v.y * u.y);
}

