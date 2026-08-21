win:
	g++ -Wl,--stack=268435456 -std=c++23 -O2 main.cpp -o main
	cat "./input.txt" | "./main.exe"

win-run:
	cat "./input.txt" | "./main.exe"

win-rm:
	rm "./main.exe"

win-clip:
	cat "./main.cpp" | win32yank -i

unix:
	g++ -Wl,-z,stack-size=268435456 -std=c++23 -O2 main.cpp -o main
	cat "./input.txt" | "./main"

unix-run:
	cat "./input.txt" | "./main"

unix-rm:
	rm "./main"

unix-clip:
	cat "./main.cpp" | wl-copy
