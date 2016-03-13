#pragma once

#include "control.h"
#include "command.h"
#include "nav_bridge.h"

class HumanControl: public Control {
public:
  void activateFire1() noexcept {
    cmd.activate(FIRE1);
  }

  void activateFire2() noexcept {
    cmd.activate(FIRE2);
  }

  void activateThrust() noexcept {
    cmd.activate(THRUST);
  }

  void activateRotateLeft() noexcept {
    cmd.activate(ROTATE_LEFT);
  }

  void activateRotateRight() noexcept {
    cmd.activate(ROTATE_RIGHT);
  }

  void deactivateFire1() noexcept {
    cmd.deactivate(FIRE1);
  }

  void deactivateFire2() noexcept {
    cmd.deactivate(FIRE2);
  }

  void deactivateThrust() noexcept {
    cmd.deactivate(THRUST);
  }

  void deactivateRotateLeft() noexcept {
    cmd.deactivate(ROTATE_LEFT);
  }

  void deactivateRotateRight() noexcept {
    cmd.deactivate(ROTATE_RIGHT);
  }

  void setCommand() {

  }

  Command getCommand() {
    return cmd;
  }

  void operate(NavBridge *nav) {
    auto bits = cmd.getBits();

    if (bits & ROTATE_LEFT) { nav->left(); }
    if (bits & ROTATE_RIGHT) { nav->right(); }
    if (bits & FIRE1) { nav->usePrimary(); }
    if (bits & THRUST) { nav->forward(); }
  }

protected:
  static const qint32 IDLE = 0;
  static const qint32 THRUST = 1 << 0;
  static const qint32 ROTATE_LEFT = 1 << 1;
  static const qint32 ROTATE_RIGHT = 1 << 2;
  static const qint32 FIRE1 = 1 << 3;
  static const qint32 FIRE2 = 1 << 4;

  Command cmd;
};
