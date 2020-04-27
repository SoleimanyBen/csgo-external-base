#include "CBaseLocalPlayer.h"

CBaseLocalPlayer::CBaseLocalPlayer(MemoryManagement *mem) : CBasePlayer(mem)
{
	PopulatePlayerStruct();
	//SetNewBasePtr(mem->Read<uintptr_t>(mem->GetClientModule() + Offsets::signatures::dwLocalPlayer));
}

int CBaseLocalPlayer::GetInCrosshair()
{
	return memManager->Read<int>(GetBasePtr() + Offsets::netvars::m_iCrosshairId);
}

void CBaseLocalPlayer::ForceShoot()
{

}

void CBaseLocalPlayer::PopulatePlayerStruct()
{
	m_pPlayer = memManager->Read<CBasePlayer_t>(GetBasePtr());
}

int CBaseLocalPlayer::GetHealthFromStruct()
{
	return m_pPlayer.m_iHealth;
}