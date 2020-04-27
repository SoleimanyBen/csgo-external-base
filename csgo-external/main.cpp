#include "MemoryManagement.h"
#include "CBasePlayer.h"
#include "CBaseEntityList.h"
#include "CBaseLocalPlayer.h"
#include <vector>
#include "Glow.h"

int main()
{
	MemoryManagement *mem = new MemoryManagement(L"csgo.exe");

	CBaseEntityList entityList(mem);
	Glow glow(mem);

	std::vector<CBasePlayer_t> playerList;



	//glow.WriteGlowStructAtIndex(playerStruct.m_iGlowIndex);




	for (int i = 1; i < 32; i++)
	{
		uintptr_t base = entityList.GetPlayerByIndex(i);
		CBasePlayer player(mem, base);

		CBasePlayer_t playerStruct = player.GetPlayerStruct();
		

		if (playerStruct.m_iGlowIndex > 0) 
		{
			std::cout << "GLOW INDEX OF PLAYER " << i << ": " << playerStruct.m_iGlowIndex << std::endl;
			glow.WriteGlowStructAtIndex(playerStruct.m_iGlowIndex);
		}
	}

	//CBasePlayer player(mem, base);
	//CBaseLocalPlayer localPlayer(mem);
	////TriggerBot triggerBot(mem);

	//while (true)
	//{
	//	std::cout << "LOCAL PLAYER HP: " << localPlayer.GetHealthFromStruct() << std::endl;
	//	//std::cout << "LOCAL PLAYER CROSSHAIR ID: " << localPlayer.GetInCrosshair() << std::endl;
	//	//std::cout << "ENTITY 2 HP: " << player.GetHealth() << std::endl;
	//	Sleep(200);
	//}
	//std::cout << "Current player health: " << player.GetHealth();
}