SRC=main.cpp\
    texport.cpp

OBJ=main.o\
    texport.o

TGT=program

all:$(TGT)

$(TGT):$(OBJ)
	g++ -o $(TGT) $(OBJ)

$(OBJ):
	g++ -c $(SRC)

clean:
	rm *.o 
	rm $(TGT) 
	rm *.log 
	rm *.tex
	rm *.dvi
