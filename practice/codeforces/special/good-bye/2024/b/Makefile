win:
	g++ -Wl,--stack=268435456 -std=c++23 -O2 main.cpp -o main
	main < input.txt

win-run:
	main < input.txt

win-del:
	del main.exe

win-clip:
	cat main.cpp | win32yank -i

unix:
	g++ -Wl,--stack=268435456 -std=c++23 -O2 main.cpp -o main
	./main < input.txt

unix-run:
	./main < input.txt

unix-rm:
	rm main

unix-clip:
	cat main.cpp | wl-copy
