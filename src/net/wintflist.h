#pragma once

#include <list>
#include "wintf.h"

struct WIntfList : std::list<WIntf> {
    friend struct WNetInfo;

private: // singleton
    WIntfList();

public:
    WIntf* findByName(std::string name);
    WIntf* findByIp(WIp ip);
    static WMac getMac(char* intfName);
    static WIntfList& instance() {
        static WIntfList wintfList;
        return wintfList;
    }
    int command(struct WIntfList);
};
