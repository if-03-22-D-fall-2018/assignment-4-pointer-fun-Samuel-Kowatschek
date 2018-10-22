#include <stdio.h>

void print_integers(int int_value, int* int_pointer);

void change_integer(int int_value, int* int_pointer);

int main(int argc, char const *argv[]) {
  int int_value = 5;
  int* int_pointer = &int_value;
  /*In diesem Fall will man die Speicheradresse des integers int_value wissen,
  *weshalb man den int* int_pointer den Wert &int_value zuweist. Dieses & vor der Variable
  *wird genutzt, um die Speicheradresse einer Variable zu erfahren.
  *
  *Wir könnten auch int* int_pointer=int_value; schreiben, aber dann würde die pointervariable
  *nicht die Speicheradresse von int_value beinhalten, sondern würde den Wert von int_value
  *bekommen, was bei so kleinen Zahlen wie 5 eher unnütz ist, da wir auf diese Speicheradresse
  *keinen Zugriff haben.
  */
  print_integers(int_value, int_pointer);
  change_integer(int_value, int_pointer);
  print_integers(int_value, int_pointer);
  /*
  *In change_integers wurde zwar versucht die Werte zu ändern, es hat sich aber nichts
  *geändert, weil die Funktion ein Call-by-value macht. Heißt: es wird sozusagen nur der Wert
  *der Variable in die Methode kopiert und nicht geändert. Würde jetzt der int_pointer anders geändert werden
  *(mit *int_pointer=int_value) würde sich der Wert ändern, weil dann der Wert an der Speicheradresse geändert wird,
  *und nicht nur der Wert der kopierten Variable.
  */
  return 0;
}

void print_integers(int int_value, int* int_pointer) {
  printf("Got an integer value %d and an adress to an integer %d\n", int_value, *int_pointer);
}

void change_integer(int int_value, int* int_pointer) {
  int_value = 12;
  int_pointer = &int_value;
}
