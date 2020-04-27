#pragma once
#include "memorymanagement.h"
#include "Offsets.h"
#include <vector>

struct CBasePlayer_t
{
public:
	char pad_0000[244]; //0x0000
	int32_t m_iTeamNum; //0x00F4
	char pad_00F8[8]; //0x00F8
	int32_t m_iHealth; //0x0100
	char pad_0104[16]; //0x0104
	float m_vecVelocity; //0x0114
	char pad_0118[41744]; //0x0118
	int32_t m_iGlowIndex; //0xA428
	char pad_A42C[4075]; //0xA42C
	int32_t m_iCrosshairId; //0xB417
	char pad_B41B[4468]; //0xB41B
}; //Size: 0x32E1

class CBasePlayer
{
public:
	CBasePlayer(MemoryManagement *mem);
	CBasePlayer(MemoryManagement *mem, uintptr_t baseAddress);
	~CBasePlayer();

	int GetHealth();
	int GetActiveWeapon();
	int GetTeamNum();

	bool IsPlantingBomb();

	void SetNewMemManager(MemoryManagement *mem);
	void SetNewBasePtr(uintptr_t baseAddress);

	void SetNewGlowAddress();

	void ReadPlayerStruct();

	CBasePlayer_t GetPlayerStruct();


	uintptr_t GetBasePtr();

	MemoryManagement *memManager;
private:
	// Base pointer address that we use for our offsets
	uintptr_t m_ptrBaseAddress;
	uintptr_t m_ptrGlowAddress;

	CBasePlayer_t m_pPlayer;
};