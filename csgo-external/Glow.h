#include <iostream>
#include "MemoryManagement.h"
#include "Offsets.h"

struct Glow_t
{
public:
	char pad_0000[4]; //0x0000
	float m_fGlowR; //0x0004
	float m_fGlowG; //0x0008
	float m_fGlowB; //0x000C
	float m_fGlowA; //0x0010
	char pad_0014[16]; //0x0014
	bool m_bRenderWhenOccluded; //0x0024
	bool m_bRenderWhenUnoccluded; //0x0025
	char pad_0026[16]; //0x0026
};

class Glow
{
public:
	Glow(MemoryManagement *mem);

	void Activate();

	uintptr_t GetGlowStructAtIndex(int index);

	void WriteGlowStructAtIndex(int index);

	MemoryManagement *memManager;
private:

	// Base glow object manager address
	uintptr_t m_ptrBaseAddress;
};