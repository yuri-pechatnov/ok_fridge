#pragma once


class ExternalModule {
public:
    virtual ~ExternalModule();
    virtual void receiveMessage(string message);
};

typedef std::shared_ptr<ExternalModule> ExternalModulePtr;
typedef std::vector<ExternalModulePtr> ExternalModuleList;
