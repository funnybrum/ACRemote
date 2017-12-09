#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <ESP8266WebServer.h>

class WebServer {
    public:
        void begin();
        void loop();
    private:
      ESP8266WebServer *_server;
      
      void handle_root();
      void handle_on();
      void handle_off();
};


#endif
