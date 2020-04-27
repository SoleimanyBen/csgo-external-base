#pragma once
#include <iostream>
#include <Windows.h>
#include "tlhelp32.h"

class MemoryManagement
{
public:
	MemoryManagement(std::wstring processName);
	~MemoryManagement();

	template<class T>
	T Read(DWORD address);

	template<class T>
	void Write(DWORD address, T value);

	bool Attach();

	DWORD GetModuleBase(std::wstring moduleName);
	bool GetProcessID(std::wstring processName);

	DWORD GetClientModule();
	DWORD GetEngineModule();

private:
	DWORD m_processID;
	HANDLE m_hProcess;

	DWORD m_clientModuleBase;
	DWORD m_engineModuleBase;
};

template<class T>
T MemoryManagement::Read(DWORD address)
{
	T temp;

	ReadProcessMemory(m_hProcess, (PVOID)address, &temp, sizeof(T), 0);

	return temp;
}

template<class T>
void MemoryManagement::Write(DWORD address, T value)
{
	WriteProcessMemory(m_hProcess, (LPVOID)address, &value, sizeof(T), NULL);
}