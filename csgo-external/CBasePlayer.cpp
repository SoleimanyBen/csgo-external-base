#include "CBasePlayer.h"

// If we don't get a base address, we assume that we are trying to interact with the local player
CBasePlayer::CBasePlayer(MemoryManagement *mem)
{
	// Find and set local player
	SetNewBasePtr(mem->Read<uintptr_t>(mem->GetClientModule() + Offsets::signatures::dwLocalPlayer));
	SetNewMemManager(mem);
}

// If we have a base address to use from the entity list, set the base address with this constructor
CBasePlayer::CBasePlayer(MemoryManagement *mem, uintptr_t baseAddress)
{
	memManager = mem;
	m_ptrBaseAddress = baseAddress;

	ReadPlayerStruct();
}

CBasePlayer::~CBasePlayer()
{
	//m_mem = nullptr;
}

void CBasePlayer::SetNewMemManager(MemoryManagement *mem)
{
	memManager = mem;
}

void CBasePlayer::SetNewBasePtr(uintptr_t baseAddress)
{
	m_ptrBaseAddress = baseAddress;
}

void CBasePlayer::SetNewGlowAddress()
{
	m_ptrGlowAddress = memManager->Read<uintptr_t>(memManager->GetClientModule() + Offsets::signatures::dwGlowObjectManager);
}

void CBasePlayer::ReadPlayerStruct()
{
	m_pPlayer = memManager->Read<CBasePlayer_t>(m_ptrBaseAddress);
}

CBasePlayer_t CBasePlayer::GetPlayerStruct()
{
	return m_pPlayer;
}

uintptr_t CBasePlayer::GetBasePtr()
{
	return m_ptrBaseAddress;
}

int CBasePlayer::GetHealth()
{
	return memManager->Read<int>(m_ptrBaseAddress + Offsets::netvars::m_iHealth);
}

int CBasePlayer::GetActiveWeapon()
{
	return memManager->Read<int>(m_ptrBaseAddress + Offsets::netvars::m_hActiveWeapon);
}

int CBasePlayer::GetTeamNum()
{
	return memManager->Read<int>(m_ptrBaseAddress + Offsets::netvars::m_iTeamNum);
}