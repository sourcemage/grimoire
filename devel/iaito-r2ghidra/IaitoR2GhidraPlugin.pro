# Built as an extra plugin subdirectory of iaito's own source tree, next to
# src/plugins/sample-cpp, so it picks up iaito's internal (unexported)
# headers the same way iaito's own plugins do.

HEADERS        += R2GhidraDecompiler.h R2GhidraPlugin.h ../IaitoPlugin.h
SOURCES        += R2GhidraDecompiler.cpp R2GhidraPlugin.cpp

INCLUDEPATH    += ../ ../../ ../../core ../../common ../../widgets ../../dialogs

QMAKE_CXXFLAGS += $$system("pkg-config --cflags r_core")
LIBS           += $$system("pkg-config --libs r_core")
LIBS           += -Wl,-rpath=$$(R2GHIDRA_PLUGDIR) -L$$(R2GHIDRA_PLUGDIR) -lcore_r2ghidra

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
TARGET          = R2GhidraIaitoPlugin
