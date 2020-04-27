#include "CBaseEntityList.h"


CBaseEntityList::CBaseEntityList(MemoryManagement *memManager)
{
	m_memManager = memManager;
}

CBaseEntityList::~CBaseEntityList()
{
	//m_memManager = nullptr;
}

// Local player is 0 or you can use the dwLocalPlayer offset to find the player.
// ENTITY LIST RUNS TO 64
uintptr_t CBaseEntityList::GetPlayerByIndex(int index)
{
	return m_memManager->Read<uintptr_t>(m_memManager->GetClientModule() + Offsets::signatures::dwEntityList + (index * 0x10));
}