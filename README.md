# devnetXStopWatch
A simple Arduino Stop Watch Library.
This library uses the micros() function to measure the duration of desired code execution for up to 70 minutes.

## Library Functions
### Initialization
```c++
#include <devnetXStopWatch.h>
```
Include this header file and create an instance of the class devnetXStopWatch. Use the methods below to start and stop the time measurement. There is also a callback that can be used to display the result. See example.

### Stop Watch Methods
- ```void Start()```
	Starts the time measurement.
- ```uint32_t Stop()```
	Stops the time measurement and triggers the callback function, if defined. It also returns the duration in microseconds.
- ```uint32_t GetDuration()```
	Returns the duration in microseconds.
- ```void OnStop(callback_function)```
	Defines the callback function that will be triggered by calling the Stop() method.

### OnStop Callback
```c++
SW.OnStop([]() {
	Serial.print("The operation took ");
	Serial.print(SW.GetDuration());
	Serial.println(" µSec.");
});
```
This callback definition displays the duration between the ```Start()``` and ```Stop()``` methods.

---
Have fun! :)
