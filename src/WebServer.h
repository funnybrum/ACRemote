#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include "ACController.h"

class WebServer {
    public:
        WebServer(int port);
        void begin();
        void loop();
    private:
      ESP8266WebServer *_server;
      
      void handle_root();
      void handle_exec();
      void handle_getPower();
};

extern WebServer webServer;

#endif
