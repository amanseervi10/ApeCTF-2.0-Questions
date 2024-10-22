### Guesseth Thou Not

A witless wanderer, cursed to guess forever. Too high? Too low? He knoweth not, nor careth.
 
## Logic

A simple question based on binary search.
If the user enters less or more than the required number, he/she gets the response too low/too high respectively. The flag reveals itself if the guess is just right.

## Taking one level up

The participants may solve this without actually even scripting.
By just slowly trying to reach the number in doing binary search in a more humaly manner.

One way to force them to either manually do bionary search perfectly or write a script is to allow them only 9 tries (since search space is from 1 to 1e9) and change the number to be guesses everytime connects to the server.
So like we have a file, which stores the number, and we read the number from the same.

Before exiting the program, a new random number is generated and the file gets updated.

Even better, even within a program the number could change every 3 seconds (through signals)
And so we can maybe have one more function which we should be stopping somehow, so that the number does not change and hence can be guessed.

## Script

Can find the script in the script.py file
