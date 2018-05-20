RACK_DIR ?= ../..
SLUG = Autodafe-DrumKit
VERSION = 0.6.0

SOURCES = $(wildcard src/*.cpp)

include ../../plugin.mk
