#pragma once

class WebIOController : public IOController {
public:
    void output(string message) override;
};
