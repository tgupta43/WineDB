#
#
CC=g++
#
CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient



all: mainwine

mainwine: mainwine.o dbconnect.o printMeFirst.o displayByScore.o displayByPrice.o topTen.o newWine.o updateWine.o display.o
	$(CC) mainwine.o dbconnect.o printMeFirst.o displayByScore.o displayByPrice.o topTen.o newWine.o updateWine.o display.o -o mainwine $(LFLAGS)

dbconnect.o: dbconnect.cpp
	$(CC) $(CFLAGS) dbconnect.cpp

displayByScore.o: displayByScore.cpp
	$(CC) $(CFLAGS) displayByScore.cpp

displayByPrice.o: displayByPrice.cpp
	$(CC) $(CFLAGS) displayByPrice.cpp

topTen.o: topTen.cpp
	$(CC) $(CFLAGS) topTen.cpp

newWine.o: newWine.cpp
	$(CC) $(CFLAGS) newWine.cpp

updateWine.o: updateWine.cpp
	$(CC) $(CFLAGS) updateWine.cpp

display.o: display.cpp
	$(CC) $(CFLAGS) display.cpp

printMeFirst.o: printMeFirst.cpp
	$(CC) $(CFLAGS) printMeFirst.cpp

mainwine.o: mainwine.cpp
	$(CC) $(CFLAGS) mainwine.cpp

clean:
	rm *.o mainwine

run:
	./winedb "select * from wineInfo" 
