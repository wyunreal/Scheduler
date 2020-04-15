#include <Arduino.h>
#include "Scheduler.h"

class SampleEvent : public SchedulerEvent
{
public:
    virtual void execute()
    {
        Serial.println("Event executed");
    }
};

SampleEvent event;

Scheduler scheduler(50, 10);

void setup()
{
    Serial.begin(115200);
    event.enable(true, 100);
    scheduler.registerEvent(&event);
    scheduler.begin();
}

void loop()
{
    scheduler.execute();
}
