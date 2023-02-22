#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Function {
public:
    virtual void Calculate() = 0;
protected:
    double a,b,c;
};

class Ellipse : public Function {
public:
    void Calculate() override {
        cout << "Функция расчета точек эллипса\n";
            cout << "Введите длину полуосей эллипса a, b: ";
            cin >> a;
            b = a;
            if (a == 0 || b == 0) {
                throw exception("Ошибка. Длинна полуосей не может равняться нулю\n");
            }
            else {
                int size = a+b+1;
                double* x_arr = new double[size];
                double* y_arr = new double[size];
                int x = -((a+b)/2);
                for (int i = 0; i < size; i++) {
                        x_arr[i] = x;
                        y_arr[i] = sqrt(b*b*(1-((x*x)/(a*a))));
                        x++;
                }
                cout << "Полученные координаты точек эллипса:\n";
                cout << "\tX:" << "\tY:" << endl;
                for (int i = 0; i < size; i++) {
                    cout << "\t" << x_arr[i] << "\t" << y_arr[i] << endl;
                }
                delete[] x_arr;
                delete[] y_arr;
            }
        }
};

class Hiperbola : public Function{
public:
    void Calculate() override {
        cout << "Функция расчета точек ветвей гиперболы\n";
        cout << "Введите коэффициент k: ";
        cin >> a;
        if (a == 0) {
            throw exception ("Ошибка. Коэффициент k не должен равняться 0\n");
        }
        else {
            cout << "Введите количество необходимых к получению точек по осям x,y: ";
            int points;
            cin >> points;
            int size = points * 2;
            double* x_arr = new double[size];
            double* y_arr = new double[size];
            int x = -(points);
            int divide_line = 0;
            for (int i = 0; i < size; ) {
                if (x < 0) {
                    x_arr[i] = x;
                    y_arr[i] = a / x;
                    x++;
                    i++;
                }
                if (x == 0) {
                    x++;
                    divide_line = i;
                    continue;
                }
                if (x > 0) {
                    x_arr[i] = x;
                    y_arr[i] = a / x;
                    x++;
                    i++;
                }
            }
            cout << "Полученные координаты точек ветвей гиперболы:\n";
            cout << "\tX:" << "\tY:" << endl;
            for (int i = 0; i < size; i++) {
                if (i == divide_line) {
                    cout << "---------------\n";
                }
                cout << "\t" << x_arr[i] << "\t" << y_arr[i] << endl;
            }
            delete[] x_arr;
            delete[] y_arr;
        }
    }
};

class Parabola : public Function {
public:
    void Calculate() override {
        cout << "Функция расчета точек параболы квадратичной функции\n";
        cout << "Введите коэффициенты a,b,c для параболы\n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;
        cout << "Введите количество необходимых к получению точек по осям x,y: ";
        int points;
        cin >> points;
        double* x_arr = new double[points];
        double* y_arr = new double[points];
        int x = -(points / 2);
        for (int i = 0; i < points; i++) {
            x_arr[i] = x;
            y_arr[i] = a * x * x + b * x + c;
            x++;
        }
        cout << "Полученные координаты точек параболы:\n";
        cout << "\tX:" << "\tY:" << endl;
        for (int i = 0; i < points; i++) {
            cout << "\t" << x_arr[i] << "\t" << y_arr[i] << endl;
        }
        delete [] x_arr;
        delete [] y_arr;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    try {
        Ellipse ellipse;
        Parabola parabola;
        Hiperbola hiperbola;
        Function* func = &ellipse;
        func->Calculate();
        cout << "///////////////////////////////////////////////////////////////////////\n";
        func = &parabola;
        func->Calculate();
        cout << "///////////////////////////////////////////////////////////////////////\n";
        func = &hiperbola;
        func->Calculate();
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    
    return 0;
}