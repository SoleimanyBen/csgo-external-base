#include "Glow.h"


Glow::Glow(MemoryManagement *mem)
{
	memManager = mem;
	m_ptrBaseAddress = mem->Read<uintptr_t>(mem->GetClientModule() + Offsets::signatures::dwGlowObjectManager);
}

void Glow::Activate()
{

}

void Glow::WriteGlowStructAtIndex(int index)
{
	Glow_t glowStruct;

	glowStruct.m_fGlowR = 1.0;
	glowStruct.m_fGlowG = 0.0;
	glowStruct.m_fGlowB = 0.0;
	glowStruct.m_fGlowA = 1.0;
	glowStruct.m_bRenderWhenOccluded = true;
	glowStruct.m_bRenderWhenUnoccluded = false;

	//uintptr_t base = GetGlowStructAtIndex(index);

	std::cout << "Writing glow manually for " << index << std::endl;

	memManager->Write<float>(m_ptrBaseAddress + (index * 0x42) + 0x4, 1.0);
	memManager->Write<float>(m_ptrBaseAddress + (index * 0x42) + 0x8, 0.0);
	memManager->Write<float>(m_ptrBaseAddress + (index * 0x42) + 0xC, 0.0);
	memManager->Write<float>(m_ptrBaseAddress + (index * 0x42) + 0x10, 1.0);
	memManager->Write<bool>(m_ptrBaseAddress + (index * 0x42) + 0x24, true);
	//memManager->Write<Glow_t>(m_ptrBaseAddress + (index * 0x38), glowStruct);
}

uintptr_t Glow::GetGlowStructAtIndex(int index)
{
	return memManager->Read<uintptr_t>(m_ptrBaseAddress + (index * 0x38));
}