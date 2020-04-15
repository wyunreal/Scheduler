#ifndef SCHEDULER_H
#define SCHEDULER_H

class SchedulerEvent
{
  friend class Scheduler;

public:
  SchedulerEvent();
  void enable(bool isPeriodicEvent, long aTimeLapse);
  void disable();
  virtual void notifyElapsedTime(long aTimeLapse);
  virtual bool hasTimedOut();
  void reset();
  virtual void execute() = 0;
  bool isPeriodicEvent() { return isPeriodic; }

protected:
  bool isPeriodic;
  long timeLapse;
  long elapsedTime;
  bool isEnabled;
};

class Scheduler
{
public:
  Scheduler();
  Scheduler(int aTimeUnitInMs, int aEventsMaxCount);
  void begin();
  void execute();
  void registerEvent(SchedulerEvent *event);

  void notifyTick();
  int getTimeUnitInMs() { return timeUnit; }

private:
  int eventsMaxCount;
  int timeUnit;
  SchedulerEvent **events;
  int eventsCount;
};

extern Scheduler scheduler;

#endif
