#pragma once
#include <cstdint>
namespace sr
{
	class Time 
	{
	public:
		Time();

		void Reset();
		void Tick();

		float GetTime() { return TicksToSeconds(m_currTicks - m_startTicks); }
		float GetDeltaTime() { return TicksToSeconds(m_deltaTicks); }

		float TicksToSeconds(uint64_t ticks) { return (float)ticks / 1000000000; }

	private:
		uint64_t m_startTicks = 0;
		uint64_t m_currTicks = 0;
		uint64_t m_prevTicks = 0;
		uint64_t m_deltaTicks = 0;
	};
}