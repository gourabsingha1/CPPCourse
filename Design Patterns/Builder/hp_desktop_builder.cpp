#include "hp_desktop_builder.h"

// Configure functions

void HpDesktopBuilder::buildMonitor() {
    desktop->setMonitor("HP Monitor");
}
void HpDesktopBuilder::buildKeyboard() {
    desktop->setKeyboard("HP Keyboard");
}
void HpDesktopBuilder::buildMouse() {
    desktop->setMouse("HP Mouse");
}
void HpDesktopBuilder::buildSpeaker() {
    desktop->setSpeaker("HP Speaker");
}
void HpDesktopBuilder::buildRam() {
    desktop->setRam("HP RAM");
}
void HpDesktopBuilder::buildProcessor() {
    desktop->setProcessor("HP Processor");
}
void HpDesktopBuilder::buildMotherboard() {
    desktop->setMotherboard("HP Motherboard");
}