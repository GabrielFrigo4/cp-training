CC := g++
EXT := cpp
TARGET := main

WIN_FLAGS := -Wl,--stack=268435456 -std=c++23 -O2
WIN_EXE := "./$(TARGET).exe"
WIN_CLIP := win32yank -i

UNIX_FLAGS := -Wl,-z,stack-size=268435456 -std=c++23 -O2
UNIX_EXE := "./$(TARGET)"
UNIX_CLIP := wl-copy

.PHONY: win
win:
	$(CC) $(WIN_FLAGS) $(TARGET).$(EXT) -o $(TARGET)
	$(WIN_EXE)

.PHONY: win-run
win-run:
	$(WIN_EXE)

.PHONY: win-rm
win-rm:
	rm $(WIN_EXE)

.PHONY: win-clip
win-clip:
	cat $(TARGET).$(EXT) | $(WIN_CLIP)

.PHONY: unix
unix:
	g++ $(UNIX_FLAGS) $(TARGET).$(EXT) -o $(TARGET)
	$(UNIX_EXE)

.PHONY: unix-run
unix-run:
	$(UNIX_EXE)

.PHONY: unix-rm
unix-rm:
	rm $(UNIX_EXE)

.PHONY: unix-clip
unix-clip:
	cat $(TARGET).$(EXT) | $(UNIX_CLIP)
