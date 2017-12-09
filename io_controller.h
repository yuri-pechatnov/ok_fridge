#pragma once


class IOController {
public:
    virtual ~IOController();
    virtual void output(string message);
};

typedef std::shared_ptr<IOController> IOControllerPtr;
typedef std::vector<IOControllerPtr> IOControllerList;
