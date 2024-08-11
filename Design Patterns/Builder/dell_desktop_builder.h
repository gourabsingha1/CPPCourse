#ifndef dell_desktop_builder_h
#define dell_desktop_builder_h

#include "desktop_builder.h"

// ## Concreate Builder class

class DellDesktopBuilder : public DesktopBuilder {
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherboard();
};

#endif