SRC=main.cpp\
    texport.cpp\
    calc.cpp

OBJ=main.o\
    calc.o\
    texport.o

TGT=program

FLG=-I /usr/include/eigen3/

all:$(TGT)

$(TGT):$(OBJ)
	g++ $(FLG) -o $(TGT) $(OBJ)

$(OBJ):
	g++ $(FLG) -c $(SRC) 

clean:
	rm *.o 
	rm $(TGT) 
	rm *.log 
	rm *.tex
	rm *.dvi
