#ifndef KEEPALIVE_H
#define KEEPALIVE_H

#include <lwip/sockets.h>

#ifdef __cplusplus
extern "C" {
#endif

  void setKeepAlive(WiFiClient &wclient) {
    int flags = 1;
    wclient.setSocketOption(SOL_SOCKET, SO_KEEPALIVE, (const void *)&flags, sizeof(flags));
    flags = 10;
    wclient.setSocketOption(IPPROTO_TCP, TCP_KEEPIDLE, (const void *)&flags, sizeof(flags));
    flags = 5;
    wclient.setSocketOption(IPPROTO_TCP, TCP_KEEPCNT, (const void *)&flags, sizeof(flags));
    flags = 5;
    wclient.setSocketOption(IPPROTO_TCP, TCP_KEEPINTVL, (const void *)&flags, sizeof(flags));
  }

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
