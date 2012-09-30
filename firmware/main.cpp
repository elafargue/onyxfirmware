/**************************************************
*                                                 *
*            Safecast Geiger Counter              *
*                                                 *
**************************************************/

#include "wirish_boards.h"
#include "power.h"
#include "safecast_config.h"

#define DISABLE_ACCEL
#include "UserInput.h"
#include "Geiger.h"
#include "GUI.h"
#include "Controller.h"
#include <stdint.h>
#include "flashstorage.h"
#include "rtc.h"
#include "accel.h"
#include "realtime.h"
#include "serialinterface.h"
#include "switch.h"
#include "buzzer.h"
#include <stdio.h>
#include <string.h>

// Force init to be called *first*, i.e. before static object allocation.
// Otherwise, statically allocated objects that need libmaple may fail.
__attribute__((constructor)) void
premain() {
  gpio_init_all();
  init();
  delay_us(100000);
}

int main(void) {

    Geiger g;
    power_initialise();
    flashstorage_initialise();
    display_initialise();
    buzzer_initialise();
    realtime_initialise();
    g.initialise();

    //buzzer_nonblocking_buzz(1);

    delay_us(10000);  // can be removed?

    #ifndef DISABLE_ACCEL
    accel_init();
    #endif

    Controller c(g);
    switch_initialise();

    // if we woke up on an alarm, we're going to be sending the system back.
    if(power_get_wakeup_source() == WAKEUP_RTC) {
      c.m_sleeping = true;
    }

    GUI m_gui(c);
    c.set_gui(m_gui);
    UserInput  u(m_gui);
    u.initialise();
    serial_initialise();
  
    const char *sbright = flashstorage_keyval_get("BRIGHTNESS");
    if(sbright != 0) {
      unsigned int c;
      sscanf(sbright, "%u", &c);
      display_brightness(c+6);
    }
 
    if(c.m_sleeping == false) {   
      const char *sbeep = flashstorage_keyval_get("GEIGERBEEP");
      if(sbeep != 0) {
        if(strcmp(sbeep,"true") == 0) g.set_beep(true);
                                 else g.set_beep(false);
      }
    }

    for(;;) {
      c.update();
      m_gui.render();
      power_wfi();
    }

    // should never get here
    for(int n=0;n<60;n++) {
      delay_us(100000);
      buzzer_blocking_buzz(1000);
    }
    return 0;
}
