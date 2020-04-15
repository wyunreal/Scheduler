#include <Arduino.h>
#include <Scheduler.h>

// First create an event class, defining at least its execute method.
class SampleEvent : public SchedulerEvent
{
public:
    virtual void execute()
    {
        Serial.println("Event executed");
    }
};

// Create event and scheduler instances.
SampleEvent event;
Scheduler scheduler;

void setup()
{
    Serial.begin(115200);

    // Event should be enabled, passing a boolean to specify if the
    // event is periodic or not, and an integer with the amount in MS
    // for the time the event should wait before being executed.
    event.enable(true, 100);

    // Event should be registered with the scheduler.
    scheduler.registerEvent(&event);

    // Scheduler should be started.
    scheduler.begin();
}

void loop()
{
    // Once in the main loop, the scheduler should be executed
    // This is what makes this library able running timed based events
    // synchronously within the main loop.
    scheduler.execute();
}
