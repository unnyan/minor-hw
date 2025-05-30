#pragma once
#include <array>           // for std::size
#include "button.h"        // for Button
#include "led.h"           // for led
#include "modemanager.h"   // for mode manager
#include "imode.h"         // for imode
#include "treemode.h"      // for Tree mode
#include "chessmode.h"     // for Chess mode
#include "LedManagerTask.hpp"  // for LedManager
#include "MeasureTask.hpp"      // for Measuring (MeasureTask)

constexpr std::size_t gpioaOdrAddress = 0x40020014;
constexpr std::size_t gpiocOdrAddress = 0x40020814;
constexpr std::size_t gpiocIdrAddress = 0x40020810;

Button<gpiocIdrAddress, 13U, true> button;

Led<gpioaOdrAddress, 5U> led1;
Led<gpiocOdrAddress, 9U> led2;
Led<gpiocOdrAddress, 8U> led3;
Led<gpiocOdrAddress, 5U> led4;

using tLeds = std::array<ILedToggleable*, 4>;
tLeds leds = {&led1, &led2, &led3, &led4};

ChessMode<leds> chessMode;
TreeMode<leds> treeMode;
std::array<IMode*, 2> modes = {&treeMode, &chessMode};

ModeManager<modes> modeManager;

OsWrapper::MailBox<bool, 1U> mailBox;

LedManagerTask ledManagerTask (modeManager, 500ms, mailBox);
ButtonTask buttonTask(button, 200ms, mailBox);
MeasureTask measureTask;
