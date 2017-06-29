pro2.exe:pro2.o Cjt_sectors.o Cjt_paisos.o Sector.o Pais.o
	g++ -o pro2.exe pro2.o {Cjt_sectors.o,Cjt_paisos.o,Pais.o,Sector.o}

pro2.o:pro2.cpp
	g++ -c pro2.cpp -I$(INCLUDES_CPP) -D_GLIBCXX_DEBUG

Cjt_sectors.o:Cjt_sectors.cpp
	g++ -c Cjt_sectors.cpp -I$(INCLUDES_CPP) -D_GLIBCXX_DEBUG

Cjt_paisos.o:Cjt_paisos.cpp
	g++ -c Cjt_paisos.cpp -I$(INCLUDES_CPP) -D_GLIBCXX_DEBUG

Sector.o:Sector.cpp
	g++ -c Sector.cpp -I$(INCLUDES_CPP) -D_GLIBCXX_DEBUG

Pais.o:Pais.cpp
	g++ -c Pais.cpp -I$(INCLUDES_CPP) -D_GLIBCXX_DEBUG

Clean:
	rm *.o
	rm *.exe