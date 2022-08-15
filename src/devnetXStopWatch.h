/// \file      devnetXStopWatch.h
/// \brief     A simple Arduino Stop Watch Library.
/// \author    Alexej Goujine (dev@devnetx.at)
/// \copyright Copyright (c) 2020-2022 devnetX Development

#pragma once
#include <Arduino.h>

class devnetXStopWatch
{
	public:

		/// Construct a new StopWatch object
		/// 
		devnetXStopWatch(void)
		{
			this->StartTime = 0;
			this->StopTime = 0;
			this->StopFunction = NULL;
		}

		/// Start the StopWatch
		/// 
		void Start(void)
		{
			this->StartTime = micros();
		}

		/// Stops the StopWatch, triggers the OnStop callback and returns the time difference
		/// 
		/// @return uint32_t time difference (StopTime - StartTime)
		uint32_t Stop(void)
		{
			this->StopTime = micros();

			// Trigger callback if defined
			if (this->StopFunction != NULL)
				(*this->StopFunction)();

			return (this->StopTime - this->StartTime);
		}
		
		/// Returns the difference between start and stop times
		/// 
		/// @return uint32_t Duration
		uint32_t GetDuration(void)
		{
			return (this->StopTime - this->StartTime);
		}

		/// Defines the callback
		/// 
		/// @param func Callback function
		void OnStop(void (*func)())
		{
			this->StopFunction = func;
		}

	private:

		uint32_t StartTime;
		uint32_t StopTime;

		void (*StopFunction)();

};
