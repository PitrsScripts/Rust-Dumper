#pragma once
#include <Windows.h>
#include <vector>

class PatternScanner {
public:
    static uintptr_t FindPattern(uintptr_t start, size_t length, const char* pattern, const char* mask);
    static uintptr_t ScanModule(const char* moduleName, const char* pattern, const char* mask);
};#pragma once
