#pragma warning(push)
#pragma warning(disable: 26495) 
#pragma warning(disable: 26812)
#include "gtest/gtest.h"
#pragma warning(pop)
#include <vector>
#include <string>
#include <numeric>
#include <windows.h>


class MathOperations {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
    double average(const std::vector<double>& values) {
        if (values.empty()) return 0.0;
        double sum = std::accumulate(values.begin(), values.end(), 0.0);
        return sum / values.size();
    }
    std::string concat(const std::string& a, const std::string& b) { return a + b; }
    std::string concat(const std::vector<std::string>& strs) {
        std::string result;
        for (const std::string& s : strs) result += s;
        return result;
    }
};

// --- ÒÅÑÒÛ Ñ ÎØÈÁÊÀÌÈ

// ÒÅÑÒ 1: Óñïåøíûé (2+2=4)
TEST(MathLogic, AddInt_Success) {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    MathOperations calc;
    EXPECT_EQ(4, calc.add(2, 2));
}

// ÒÅÑÒ 2: ÏĞÎÂÀËÜÍÛÉ (2+2=5)
TEST(MathLogic, AddInt_Fail) {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    MathOperations calc;
    EXPECT_EQ(5, calc.add(2, 2));
}

// ÒÅÑÒ 3: Óñïåøíûé (Double)
TEST(MathLogic, AddDouble_Success) {
    MathOperations calc;
    EXPECT_DOUBLE_EQ(4.7, calc.add(2.5, 2.2));
}

// ÒÅÑÒ 4: ÏĞÎÂÀËÜÍÛÉ (Double)
TEST(MathLogic, AddDouble_Fail) {
    MathOperations calc;
    EXPECT_DOUBLE_EQ(10.0, calc.add(2.5, 2.2));
}

// ÒÅÑÒ 5: Óñïåøíûé (Ñòğîêè)
TEST(MathLogic, Concat_Success) {
    MathOperations calc;
    EXPECT_EQ("AB", calc.concat("A", "B"));
}

// ÒÅÑÒ 6: ÏĞÎÂÀËÜÍÛÉ (Ñòğîêè)
TEST(MathLogic, Concat_Fail) {
    MathOperations calc;
    EXPECT_EQ("A B", calc.concat("A", "B"));
}