CXX ?= g++
AR ?= ar
CXXFLAGS ?= -std=c++17 -O0 -g -Wall -Wextra -Wpedantic
CPPFLAGS ?= -Iinclude

OBJDIR := build/make
LIB := $(OBJDIR)/libembeddedcore.a
APP := $(OBJDIR)/DeviceSimulator
LIB_OBJS := $(OBJDIR)/sensor.o $(OBJDIR)/diagnostics.o
APP_OBJ := $(OBJDIR)/main.o
DEPS := $(LIB_OBJS:.o=.d) $(APP_OBJ:.o=.d)

.PHONY: all clean run
all: $(APP)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/sensor.o: src/sensor.cpp | $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR)/diagnostics.o: src/diagnostics.cpp | $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR)/main.o: app/main.cpp | $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(LIB): $(LIB_OBJS)
	$(AR) rcs $@ $^

$(APP): $(APP_OBJ) $(LIB)
	$(CXX) $(APP_OBJ) $(LIB) -o $@

run: $(APP)
	./$(APP)

clean:
	rm -rf $(OBJDIR)

-include $(DEPS)
