include_directories(.)

# Add client target
set(CLIENT_SOURCES
  client/ChattingTcpClient.cpp
)
add_executable(chat_client ${CLIENT_SOURCES} Protocol.h)

# Add server target
set(SERVER_SOURCES
  server/ChattingServer.h
  server/ServerMain.cpp
  server/ServerSession.cpp
  server/ServerSession.h
)
add_executable(chat_server ${SERVER_SOURCES} Protocol.h)
