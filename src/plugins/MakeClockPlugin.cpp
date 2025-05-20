#include "plugins/MakeClockPlugin.h"

void MakeClockPlugin::setup()
{
  // loading screen
  Screen.setPixel(4, 7, 1);
  Screen.setPixel(5, 7, 1);
  Screen.setPixel(7, 7, 1);
  Screen.setPixel(8, 7, 1);
  Screen.setPixel(10, 7, 1);
  Screen.setPixel(11, 7, 1);

  previousMinutes = -1;
  previousHour = -1;
}

void MakeClockPlugin::loop()
{
  if (getLocalTime(&timeinfo))
  {
    if (previousHour != timeinfo.tm_hour || previousMinutes != timeinfo.tm_min)
    {
      std::vector<int> hh = {(timeinfo.tm_hour - timeinfo.tm_hour % 10) / 10, timeinfo.tm_hour % 10};
      std::vector<int> mm = {(timeinfo.tm_min - timeinfo.tm_min % 10) / 10, timeinfo.tm_min % 10};
      
      Screen.clear();                          // index 1 - bold digits
      Screen.drawCharacter(1, 0, Screen.readBytes(fonts[1].data[hh[0]]), 8, Screen.getCurrentBrightness());
      Screen.drawCharacter(9, 0, Screen.readBytes(fonts[1].data[hh[1]]), 8, Screen.getCurrentBrightness());
      Screen.drawCharacter(1, 9, Screen.readBytes(fonts[1].data[mm[0]]), 8, Screen.getCurrentBrightness());
      Screen.drawCharacter(9, 9, Screen.readBytes(fonts[1].data[mm[1]]), 8, Screen.getCurrentBrightness());
    }

    previousMinutes = timeinfo.tm_min;
    previousHour = timeinfo.tm_hour;
  }
}

const char *MakeClockPlugin::getName() const
{
  return "MakeClock";
}
