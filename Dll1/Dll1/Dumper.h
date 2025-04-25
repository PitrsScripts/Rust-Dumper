// Dumper.h
#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <utility>

class Dumper {
public:
    Dumper();
    ~Dumper();

    bool Initialize();
    void DumpAll();
    void SaveOffsetsToFile(const std::string& filename);

private:
    HMODULE m_hGameModule;
    uintptr_t m_gameBase;
    size_t m_gameSize;
    std::vector<std::pair<std::string, uintptr_t>> m_offsets;

    uintptr_t FindPattern(const std::vector<uint8_t>& pattern, const std::string& mask);
    uintptr_t ResolveRelativeAddress(uintptr_t instructionPtr, int offset, int instructionSize);
    std::string ToHexString(uintptr_t value);

    bool IsInGame();
    bool IsValidGameAddress(uintptr_t address);
    void FindCoreOffsets();
    void FindGameplayOffsets();
    void FindPlayerBase();
    void AddOffset(const std::string& name, uintptr_t offset);
    void Log(const std::string& message);
};