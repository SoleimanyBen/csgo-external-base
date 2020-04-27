#pragma once

#include "CBasePlayer.h"
#include "Offsets.h"

class CBaseLocalPlayer : public CBasePlayer
{
public:
	CBaseLocalPlayer(MemoryManagement *mem);

	int GetInCrosshair();
	int GetHealthFromStruct();

	void ForceShoot();
	void PopulatePlayerStruct();

private:
	CBasePlayer_t m_pPlayer;
};