program: Window.o TestClass.o main.o
	g++ Window.o TestClass.o main.o -o program `sdl2-config --cflags --libs` `pkg-config --cflags --libs spdlog`

Window.o: src/Window.cpp
	g++ -c src/Window.cpp -Iinclude `pkg-config --cflags spdlog`

TestClass.o: src/TestClass.cpp
	g++ -c src/TestClass.cpp -Iinclude 

main.o: main.cpp
	g++ -c main.cpp -Iinclude
