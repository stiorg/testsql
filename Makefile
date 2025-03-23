testsql.exe: testsql.o sqlite3.dll
	g++ -o testsql.exe testsql.o sqlite3.dll

testsql.o: testsql.cpp
	g++ -c testsql.cpp