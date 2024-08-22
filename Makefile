cmake:
	cmake -B build
	cmake --build build 
	./build/weetracer > image.ppm
	open image.ppm

clean:
	rm -rf ./build
	mkdir ./build

PHONY: cmake clean
