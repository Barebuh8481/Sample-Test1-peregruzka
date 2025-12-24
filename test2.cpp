//чето там не нравится визуал студио 
#pragma warning(push)
#pragma warning(disable: 26495) // Игнорируем ошибки инициализации внутри GoogleTest
#pragma warning(disable: 26812)
#include "gtest/gtest.h"
#pragma warning(pop)
#include <vector>
#include <string>
#include <numeric>

//логика из перегрузки
class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double average(const std::vector<double>& values) {
        if (values.empty()) return 0.0;
        double sum = std::accumulate(values.begin(), values.end(), 0.0);
        return sum / values.size();
    }

    std::string concat(const std::string& a, const std::string& b) {
        return a + b;
    }

    std::string concat(const std::vector<std::string>& strs) {
        std::string result;
        for (const std::string& s : strs) {
            result += s;
        }
        return result;
    }
};

// тесты

// Проверка сложения целых 
TEST(MathLogic, AddIntegers) {
    MathOperations calc;              // 1. Создали объект
    int realResult = calc.add(2, 2);  // 2. Вызвали функцию
    EXPECT_EQ(4, realResult);         // 3. Сверили: ждали 4, получили realResult
}

// Проверка сложения дробных
TEST(MathLogic, AddDoubles) {
    MathOperations calc;
    // EXPECT_DOUBLE_EQ нужен для float/double, так как у них бывает погрешность
    EXPECT_DOUBLE_EQ(5.5, calc.add(2.2, 3.3));
}

// Проверка суммы трех чисел
TEST(MathLogic, AddThreeInts) {
    MathOperations calc;
    EXPECT_EQ(100, calc.add(10, 40, 50));
}

// Проверка среднего арифметического
TEST(MathLogic, Average) {
    MathOperations calc;
    std::vector<double> data = { 10.0, 20.0, 30.0 };
    EXPECT_DOUBLE_EQ(20.0, calc.average(data)); // (10+20+30)/3 = 20
}

// Проверка склейки строк
TEST(MathLogic, ConcatTwoStrings) {
    MathOperations calc;
    EXPECT_EQ("AB", calc.concat("A", "B"));
}

// Проверка склейки вектора строк
TEST(MathLogic, ConcatVector) {
    MathOperations calc;
    std::vector<std::string> words = { "Hello", " ", "World" };
    EXPECT_EQ("Hello World", calc.concat(words));
}
