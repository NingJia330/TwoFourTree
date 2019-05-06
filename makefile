Compiler=g++ -g
OBJ = student.o BST.o BTree.o main.o

all:	Pex2

Pex2: ${OBJ}
	${Compiler} ${OBJ} -o Pex2

student.o: student.cpp student.h
	${Compiler} -c student.cpp

BST.o: BST.cpp BST.h student.h
	${Compiler} -c BST.cpp

BTree.o: BTree.cpp BTree.h student.h
	${Compiler} -c BTree.cpp
	
main.o: main.cpp student.h BTree.h BST.h
	${Compiler} -c main.cpp
test: Pex2 input.txt
	./Pex2 < input.txt

clean:
	rm *.o Pex2
