#ifndef hp_desktop_builder_h
#define hp_desktop_builder_h

#include "desktop_builder.h"

// ## Concreate Builder class

class HpDesktopBuilder : public DesktopBuilder {
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherboard();
};

#endif