RACK_DIR ?= ../..
SLUG = Autodafe-Drums
VERSION = 0.6.0

SOURCES = $(wildcard src/*.cpp)

include ../../plugin.mk


dist: all
	mkdir -p dist/Autodafe
	cp LICENSE* dist/Autodafe/
	cp plugin.* dist/Autodafe/
	cp -R res dist/Autodafe/
