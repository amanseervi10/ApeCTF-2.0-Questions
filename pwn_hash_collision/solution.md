### Ozymandias

 Inspiration - "Time erodes all, even the strongest walls."
 
 And so, given a wise input, that takes too long, the flag shall present itself to thee.
 
## Logic

Basically leaving the shit things in the code, we need to focus that there is an insertion taking place unordered_map.
The thing is that hashmap takes O(1) in general, which is what the knowledge of most people is aquainted to.
Under the hood, if somehow we can break the hash function, we can make this insertion complexity to O(n).

This blog explains in detail as to how : https://codeforces.com/blog/entry/62393

### Primes

So basically we need to take that list of primes and try numbers from it.
This can be done using a simple python script. I have done it using the pwntools library.

The code can be found in script.py

### Additional things 

The time constraint for 5 second is actually taken after a bit of experimenting.
On my system the code actually broke at the prime number : 42043

But when i ran it on my free t2.mircro ec2 instance, then it break much before at just 20753.
But nonetheless, since it works and is just as random to an ignorant solver, i went ahead with 5 seconds.

Also I put the sleep(1) in the processInput() function to prevent people to just brute it using a simple for loop from 1 to 1e6.

There is also a Anti dos signal in place, which prevents any kind of dos attack by closing connections which have neem inactive for a while.
