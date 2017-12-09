/*!
 * Run this test scenario as:
 * $ echo -e '{"type": "fetch", "productName": "milk", "userName": "Peter"}\n{"type": "fetch", "productName": "milk", "userName": "Peter"}' | ./scenario_on_fetch_verbal_command_test
 * or by analague method
 */

#include "model.h"
#include "verbal_io_controller.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>


int main() {
    Model model;
    model.ioControllers.emplace_back(new VerbalIOController(model));
    model.fridge.recognizer.updateProductList();
    while (true) {
        model.loop();
    }
    return 0;
}
