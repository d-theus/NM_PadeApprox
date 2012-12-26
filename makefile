SRC=main.cpp\
    texport.cpp\
    calc.cpp\
    gaussian_el.cpp

OBJ=main.o\
    calc.o\
    texport.o\
    gaussian_el.o

TGT=program

FLG=-std=c++11

all:$(TGT)

$(TGT):$(OBJ)
	g++ $(FLG) -o $(TGT) $(OBJ)

$(OBJ):
	g++ $(FLG) -c $(SRC) 

clean:
	rm *.o|\
	rm $(TGT)|\
	rm *.log|\
	rm *.tex|\
	rm *.dvi|\
	rm *.aux
