#include "memorymanagement.h"


MemoryManagement::MemoryManagement(std::wstring processName) : m_processID(0)
{
	GetProcessID(processName);

	m_clientModuleBase = GetModuleBase(L"client_panorama.dll");
	m_engineModuleBase = GetModuleBase(L"engine.dll");

	Attach(); // set process handle
}

MemoryManagement::~MemoryManagement()
{
	CloseHandle(m_hProcess);
}

bool MemoryManagement::Attach()
{
	m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_processID);

	if (!m_hProcess)
	{
		CloseHandle(m_hProcess);
		return false;
	}

	return true;
}

bool MemoryManagement::GetProcessID(std::wstring processName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 pEntry;

	pEntry.dwSize = sizeof(PROCESSENTRY32);

	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		std::cout << "Invalid handle error. Ending task..." << std::endl;
		CloseHandle(hSnapshot);
		return false;
	}

	if (Process32First(hSnapshot, &pEntry))
	{
		do
		{
			if (pEntry.szExeFile == processName)
			{
				std::cout << "Process " << pEntry.szExeFile << " found" << std::endl;
				std::cout << pEntry.th32ProcessID << std::endl;
				m_processID = pEntry.th32ProcessID;

				CloseHandle(hSnapshot);

				return true;
			}
		} while (Process32Next(hSnapshot, &pEntry));
	}

	CloseHandle(hSnapshot);

	return false;
}

DWORD MemoryManagement::GetModuleBase(std::wstring moduleName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_processID);
	MODULEENTRY32 pEntry;

	pEntry.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &pEntry))
	{
		do
		{
			if (pEntry.szModule == moduleName)
			{
				std::wcout << "Found " << pEntry.szModule << " at " << "0x" << std::hex << pEntry.modBaseAddr << std::endl;
				CloseHandle(hSnapshot);
				return (DWORD)pEntry.modBaseAddr;
			}
		} while (Module32Next(hSnapshot, &pEntry));
	}

	CloseHandle(hSnapshot);

	return NULL;
}

DWORD MemoryManagement::GetClientModule()
{
	return m_clientModuleBase;
}

DWORD MemoryManagement::GetEngineModule()
{
	return m_engineModuleBase;
}