build:
	gcc main.c ./Functii/liste.c test1.c -o lanParty -g

run:
	./lanParty c.in d.in r.out
