all:
	cp GoGetter GoGetter.py
	python GoGetter.py > GoGetter.sh
	sh GoGetter.sh > GoGetter.c
	gcc -Wall -o GoGetter.c.out GoGetter.c
	./GoGetter.c.out > GoGetter.cpp
	g++ -Wall -o GoGetter.cpp.out GoGetter.cpp
	./GoGetter.cpp.out > GoGetter.js
	echo "\nPlease execute this JavaScript file in your browser.\nSave whatever displayed in web page. Then rename it to 'GoGetter.java'\n"
	read -p "If you have finished, just press Enter key ..." a
	javac GoGetter.java
	java GoGetter > GoGetter.tex
	pdflatex GoGetter.tex

clean:
	rm -f *~ *.aux *.log *.out *.class *.o *.out

cleanall:
	rm -f *~ *.aux *.log *.out *.class *.o *.out *.py *.sh *.c *.cpp *.js *.java *.tex *.pdf
