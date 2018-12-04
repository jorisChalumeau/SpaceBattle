QT += network widgets

HEADERS       = server.h \
    server.h
SOURCES       = server.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneserver
INSTALLS += target
