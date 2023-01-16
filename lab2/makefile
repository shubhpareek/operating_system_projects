all: bin/mat

bin/mat: libs/liball.a src/mainfile.cpp include/functions.h | bin
	g++ src/mainfile.cpp -L${PWD}/libs -lall -I${PWD}/include -o $@ 
	@echo "COMPILATION COMPLETED "
	
build/%.o: src/%.cpp | build
	g++ -c -fPIC $< -o $@
	
build: 
	mkdir build

run:    bin/mat
	chmod +x tst.sh && ./tst.sh -1

bin:
	mkdir bin

libs_dir : 
	mkdir -p libs
	
libs/liball.a  :build/addsc.o build/divsc.o build/filread.o build/mulsc.o  build/subsc.o build/add.o build/determinant.o build/mul.o build/sub.o build/transpose.o build/logger.o | libs_dir 
	ar rcs -o $@ $^

libs : libs/libscal.a libs/libmat.so

libs/libscal.a :  build/addsc.o build/divsc.o build/mulsc.o  build/subsc.o  | libs_dir
	ar rcs -o $@ $^

libs/libmat.so : build/add.o build/determinant.o build/mul.o build/sub.o build/transpose.o |  libs_dir
	g++ -shared -o  $@ $^

clean:
	rm -rf rm build/ libs/ bin/ loggfile
	
tests: bin/mat
	chmod +x tst.sh && ./tst.sh 0
test1: bin/mat
	chmod +x tst.sh && ./tst.sh 1	
test2: bin/mat
	chmod +x tst.sh && ./tst.sh 2
test3: bin/mat
	chmod +x tst.sh && ./tst.sh 3
test4: bin/mat
	chmod +x tst.sh && ./tst.sh 4
test5: bin/mat
	chmod +x tst.sh && ./tst.sh 5
test6: bin/mat
	chmod +x tst.sh && ./tst.sh 6
test7: bin/mat
	chmod +x tst.sh && ./tst.sh 7
	
.PHONY: clean all tests

