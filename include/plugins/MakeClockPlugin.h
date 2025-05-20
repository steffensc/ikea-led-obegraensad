#pragma once

#include "PluginManager.h"

class MakeClockPlugin : public Plugin
{
private:
  struct tm timeinfo;

  int previousMinutes;
  int previousHour;

public:
  void setup() override;
  void loop() override;
  const char *getName() const override;
};