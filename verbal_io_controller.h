#pragma once

class VerbalIOController : public IOController {
public:
    void output(string message) override;
};
