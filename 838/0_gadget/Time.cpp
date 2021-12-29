//
// Created by Jason Luo on 2021/11/5.
//
#include "cstdio"
#include "iostream"

int main() {
    auto t1 = std::chrono::steady_clock::now();

//    sleep(1);
//InsertSort(A, n);
    /// do something

    auto t2 = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "elapsed time: "
              << dt
              << "ns"
              << std::endl;
}