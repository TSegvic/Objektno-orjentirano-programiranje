#include <iostream>
#include <iomanip>


struct Matrica {
    float** data;   
    int red;      
    int stupac;
    void init(int m, int n) {
        red = m;
        stupac = n;
        data = new float* [red];
        for (int i = 0; i < red; i++) {
            data[i] = new float[stupac];
        }
    }
    void input() {
        std::cout << "Unesite elemente matrice (" << red << "x" << stupac << "):\n";
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < stupac; j++) {
                std::cin >> data[i][j];
            }
        }
    }    
    void generate(float a, float b) {
        float step = (b - a) / (red * stupac - 1); 
        float value = a;
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < stupac; j++) {
                data[i][j] = value;
                value += step;
            }
        }
    }
    Matrica add(Matrica& other) 
    {
        Matrica result;
        result.init(red,stupac);
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < stupac; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrica subtract(Matrica& other) 
    {
        Matrica result;
        result.init(red, stupac);
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < stupac; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrica multiply(Matrica& other)
    {
        Matrica result;
        result.init(red, other.stupac);
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < other.stupac; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < stupac; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    Matrica transpose()
    {
        Matrica result;
        result.init(stupac, red);
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < stupac; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
    void print()
    {
        for (int i = 0; i < red; i++) {
            for (int j = 0; j < stupac; j++) {
                std::cout << std::setw(10) << std::fixed << std::setprecision(4) << data[i][j];
            }
            std::cout << std::endl;
        }
    }
    void clear() {
        for (int i = 0; i < red; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
        red = 0;
        stupac = 0;
    }
};

int main() {
    Matrica mat1, mat2, result;

    
    mat1.init(2, 3);
    mat1.input();
    mat1.print();

    
    mat2.init(2, 3);
    mat2.generate(1.0, 10.0);
    mat2.print();


    result = mat1.add(mat2);
    std::cout << "Rezultat sabiranja matrica:\n";
    result.print();

    
    result = mat1.transpose();
    std::cout << "Transponirana matrica:\n";
    result.print();

 
    mat1.clear();
    mat2.clear();
    result.clear();

    return 0;
}
