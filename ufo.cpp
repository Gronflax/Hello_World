//another bot of code for my online c++ course. This one is a simple hangman style game but it was intended to demonstrate most of what I have learned so far, 
// or at least parts of what I've learned. It also includes ufo_functions.cpp & ufo_functions.hpp whic I've also saved in this repository.

#include <iostream>                             //standard include
#include <vector>                               // for use of the vecotr
#include "ufo_functions.hpp"                    // header file for ufo_function.cpp

int main() {

  std::string codeword = "codecademy";
  std::string answer;
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;                                  //various variables

  greet();                                      //greet function, outputs a small structured sentence with some spacing and use of = to give it some formatting

  while (answer != codeword && misses < 7) {    //while loop that keeps the game going. Though in it's current format, the game doesn't end unless you lose. I'll 
  std::cout << "Please enter your guess: ";     //fix that at some point, this loop also takes in the users input.
  std::cin >> letter;

  for (int i = 0; i < codeword.size();i++){     //for loop to check the input against the "codeword"
    if (letter == codeword[i]){                 //bog standard if statement
      answer[i] = letter;
      guess = true;
    }
  }

  if (guess) {                                   //if guess = true do the following
    std::cout << "Correct!";                     
  } else {                                        //if not do this
    std::cout << "Incorrect! The tractor beam pulls the person in further.";
    incorrect.push_back(letter);                  // adds to the incorrect vector
    misses++;                                     // eventually ends the loop;
  }

  display_misses(misses);
  display_status(incorrect, answer);
  guess = false;
  }

end_game(answer, codeword);

}
