#ifndef desktop_builder_h
#define desktop_builder_h

#include "desktop.h"

// ## Builder class

class DesktopBuilder {
protected:
    Desktop* desktop;

public:
    DesktopBuilder() {
        desktop = new Desktop();
    }

    // Virtual func because ConcreateBuilder's have to implement these functions
    virtual void buildMonitor() = 0;
    virtual void buildKeyboard() = 0;
    virtual void buildMouse() = 0;
    virtual void buildSpeaker() = 0;
    virtual void buildRam() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildMotherboard() = 0;
    virtual Desktop* getDesktop() {
        return desktop;
    }
};

#endif