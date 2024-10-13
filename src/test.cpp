#include <iostream>
#include <vector>

extern "C" {
    int myRiscvFunc(int x);
    int exponent(int* x, int y);
    float exponentFloat(float x, int y);
    unsigned long long cycles();
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<float> v2 = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};

    for (int &entry : v1) {
        std::cout << entry << std::endl;
    }
    //auto before = cycles();
    for (int &entry : v1) {
        entry = exponent(&entry, 2);
    }
    /*auto after = cycles();
    std::cout << "cycles elapsed: " << after - before << std::endl;*/
    for (int &entry : v1) {
        std::cout << entry << std::endl;
    }

    for (float &entry : v2) {
        std::cout << entry << std::endl;
    }
    for (float &entry : v2) {
        entry = exponentFloat(entry, 2);
    }
    for (float &entry : v2) {
        std::cout << entry << std::endl;
    }

    return 0;
}