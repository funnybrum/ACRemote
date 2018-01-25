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
      ESP8266HTTPUpdateServer *_httpUpdater;
      
      void handle_root();
      void handle_exec();
      void handle_reset();
};

extern WebServer webServer;

#endif
