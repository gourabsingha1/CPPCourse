#ifndef desktop_director_h
#define desktop_director_h

#include "desktop_builder.h"

class DesktopDirector {
private:
    DesktopBuilder* desktopBuilder;

public:
    DesktopDirector(DesktopBuilder* pDesktopBuilder) {
        desktopBuilder = pDesktopBuilder;
    }

    // Call the build functions of Builder class and actually build them
    Desktop* BuildDesktop() {
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMouse();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildMotherboard();
        return desktopBuilder->getDesktop();
    }

    Desktop* getDesktop() {
        return desktopBuilder->getDesktop();
    }
};

#endif