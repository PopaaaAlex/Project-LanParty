

# Numele proiectului: Lan Party

## Rularea Programului
 ./checker.sh

## Descriere:
  Acest program citeste date despre echipe din fisirile de intrare si simuleaza un turneu de la un LanParty.

## Rezolvarea Task-urilor:

  ### Task[1]:
     
  Datele despre echipe sunt citite din fișierul de intrare în fișierul main.c, iar toate informațiile sunt stocate într-o listă simplu înlănțuită, cu elementele adăugate la începutul listei.
  
  ### Task[2]:
  Echipele cu cele mai mici punctaje sunt eliminate iterativ până când numărul de echipe ajunge la o putere a lui 2. În cazul în care două echipe au același punctaj minim, este eliminată prima echipă găsită în listă.
 
  ### Task[3]:
  Se creează o coadă cu echipele rămase și încep meciurile.
  Pentru gestionarea rezultatelor meciurilor, se folosesc două stive: una pentru echipele câștigătoare și una pentru echipele învinsă, care sunt eliberate la finalul fiecărei etape.
  În cazul în care două echipe au același punctaj, este considerată câștigătoare echipa care a fost prima introdusă.
  Fiecare echipă care câștigă un meci își crește punctajul
  Odată ce rămân doar 8 echipe, se creează o listă separată pentru acestea.

  ### Task[4]:
  Odată ce rămân doar cele 8 echipe, acestea sunt utilizate pentru a crea un arbore binar de căutare (BST). În cazul în care două echipe au același punctaj, se compară numele lor pentru a decide ordinea în arbore.

  ### Task[5]:
  Din arborele creat anterior, acesta este transformat într-un AVL (arbore echilibrat) și se afișează elementele de pe al doilea nivel al arborelui.
      
  
