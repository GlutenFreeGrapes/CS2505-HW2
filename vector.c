#include "vector.h"

double dot_product(const double vec1[], int v1_len, const double vec2[], int v2_len)
{
    double result = 0.0;
    if (v1_len == v2_len)
    {
        while (v1_len > 0)
        {
            result += (vec1[v1_len - 1] * vec2[v1_len - 1]);
            v1_len--;
        }
    }
    return result;
}

double angle_between(const double vec1[], int v1_len, const double vec2[], int v2_len)
{
    const double RADIANS_TO_DEGREES = 180 / M_PI;
    double mag_v1 = 0.0;
    double mag_v2 = 0.0;
    int iterations = v1_len;
    while (iterations > 0)
    {
        mag_v1 += pow(vec1[iterations - 1],2);
        mag_v2 += pow(vec2[iterations - 1],2);
        iterations--;
    }
    mag_v1 = sqrt(mag_v1);
    mag_v2 = sqrt(mag_v2);
    double dot_product_v1_v2 = dot_product(vec1, v1_len, vec2, v2_len);
    double result = acos(dot_product_v1_v2 / (mag_v1 * mag_v2)) * RADIANS_TO_DEGREES;
    return result;
}

void subtract(double v1_dir, double v1_mag, double v2_dir, double v2_mag, double* new_dir, double* new_mag)
{
    const double RADIANS_TO_DEGREES = 180 / M_PI;
    double v1_x = v1_mag * cos(v1_dir / RADIANS_TO_DEGREES);
    double v1_y = v1_mag * sin(v1_dir / RADIANS_TO_DEGREES);
    double v2_x = v2_mag * cos(v2_dir / RADIANS_TO_DEGREES);
    double v2_y = v2_mag * sin(v2_dir / RADIANS_TO_DEGREES);
    double new_x = v2_x - v1_x;
    double new_y = v2_y - v1_y;
    *new_mag = sqrt(pow(new_x,2) + pow(new_y,2));
    *new_dir = atan2(new_y , new_x) * RADIANS_TO_DEGREES + 180;
}
