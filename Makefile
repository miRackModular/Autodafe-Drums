RACK_DIR ?= ../..
SLUG = Autodafe-DrumKit
VERSION = 0.6.0

SOURCES = $(wildcard src/*.cpp)

include $(RACK_DIR)/plugin.mk
