


double integral(double(*f)(double x), double(*g)(double x, double y), double a, double b, int n)
{
    double step = (b - a)/n;   // width of rectangle
    double area = 0.0;
    double y = 0;  // height of rectangle

    for(int i = 0; i < n; ++i)
    {
        y = f(a + (i + 0.5) * step) * g(a + (i + 0.5) * step, y);
        area += y * step  // find the area of the rectangle and add it to the previous area. Effectively summing up the area under the curve.
    }

    return area;
}

// To call:

int main()
{
    int x = 3;
    int low_end = 0;
    int high_end = 2 * M_PI;
    int steps = 100;
    cout << integral(std::powf, std::cosf, low_end, high_end, steps);
    return 0;
}