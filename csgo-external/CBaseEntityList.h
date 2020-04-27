#pragma once

#include "memorymanagement.h"
#include "CBasePlayer.h"
#include "Offsets.h"

class CBaseEntityList
{
public:
	CBaseEntityList(MemoryManagement *memManager);
	~CBaseEntityList();

	uintptr_t GetPlayerByIndex(int index);
private:
	MemoryManagement *m_memManager;

	uintptr_t m_baseEntityList;
};